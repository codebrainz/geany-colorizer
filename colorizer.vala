using Gtk;
using Gdk;
using Geany;
using Scintilla;

//----------------------------------------------------------------------
// Plugin information

public Plugin			geany_plugin;
public Data			geany_data;
public Functions		geany_functions;

public void plugin_set_info (Plugin.Info info) {
	info.set(
		"Colorizer"						  			/* plugin name */, 
		"Set Scintilla appearances on-the-fly."   	/* plugin desc	*/,
		"0.1"								  		/* plugin version */,
		"Matthew Brush <mbrush@leftclick.ca>" 		/* plugin author */);
}

public int plugin_version_check (int abi_version) {
	return Plugin.version_check (abi_version, 185);
}

//----------------------------------------------------------------------
// Static and Global variables

private static unowned Scintilla.Object? sci = null;
private static ColorizerUI? ui;
//private static Editor.Interface? iface = null;
private static const int FACELIFT_INDIC=INDIC_MAX-1;

private static int foreground_colors[33];
private static int background_colors[33];
private static bool fonts_bold[33];
private static bool fonts_italic[33];
private static bool fonts_underline[33];

private static bool in_message_window = true;

private static Gtk.MenuItem sep;
private static Gtk.CheckMenuItem item;
private static Gtk.Dialog? dialog = null;
private static Gtk.ScrolledWindow? swin = null;

private static bool colorizing = false;
private static bool styling = false;

private static string config_dir;
private static string config_file;
private static string current_theme;


//------------------------------------------------------------------------------
// Miscellaneous helper functions
private static long text_length()
{
	if (sci != null)
		return sci.send_message(Messages.GETTEXTLENGTH);
	return 0;
}

private static bool have_text()
{
	return text_length() > 0;
}

private static string? lexer_language() {
	
	if (sci == null)
		return null;
	
	char *tmp;
	long len = sci.send_message(Messages.GETLEXERLANGUAGE);
	tmp = malloc0(len+1);
	len = sci.send_message(Messages.GETLEXERLANGUAGE, 0, (long)tmp);
	if (len == 0) {
		free(tmp);
		return null;
	}
	string ret = (string)tmp;
	free(tmp);
	return ret;
}

//----------------------------------------------------------------------
// Callbacks

/* whenever a tab is activated or new document created, to update the
 * active/current scintilla */
private void on_current_document_changed(GLib.Object ignored, Geany.Document doc) 
{	
	debug("Document changed");
	if (doc.editor.sci != null) {
		
		sci = doc.editor.sci;
		
		if (colorizing && have_text()) {
		
			/* should check if we're already connected for this sci */
			if (sci != null)
				sci.sci_notify.connect(on_editor_notif);

			ui.current_lexer = (int)sci.send_message(Messages.GETLEXER);
			ui.current_style = (int)sci.send_message(Messages.GETSTYLEAT, 
									sci.send_message(Messages.GETCURRENTPOS));
			
			for (int i=0; i < 33; i++) {
				foreground_colors[i] = (int)sci.send_message(Messages.STYLEGETFORE, i);
				background_colors[i] = (int)sci.send_message(Messages.STYLEGETBACK, i);
				fonts_bold[i] = (bool)sci.send_message(Messages.STYLEGETBOLD, i);
				fonts_italic[i] = (bool)sci.send_message(Messages.STYLEGETITALIC, i);
				fonts_underline[i] = (bool)sci.send_message(Messages.STYLEGETUNDERLINE, i);
			}
						
			/* turn off the highlighting of active line */
			sci.send_message(Messages.SETCARETLINEVISIBLE, 0);
		
		}
		
	}
}

/* apply the styles stored in global arrays and update the colorizer ui */
public bool colorize_editor()
{
	
	if (have_text()) {
		
		/* put an indicator under all words with the current style */
		sci.send_message(Messages.INDICSETSTYLE, FACELIFT_INDIC, IndicatorStyles.SQUIGGLE);
		sci.send_message(Messages.INDICSETFORE, FACELIFT_INDIC, 0xBFBFBF);
		long num_chars = text_length();
		sci.send_message(Messages.SETINDICATORCURRENT, FACELIFT_INDIC);
		sci.send_message(Messages.INDICATORCLEARRANGE, 0, num_chars);
		/* this is inefficient */
		for (long p=0; p < num_chars; p++) {
			int s = (int)sci.send_message(Messages.GETSTYLEAT, p);
			if (s == ui.current_style)
				sci.send_message(Messages.INDICATORFILLRANGE, p, 1);
		}	
		
		/* set all current styles, this is inefficient */
		for (int i=0; i <= Styles.DEFAULT; i++) {
			sci.send_message(Messages.STYLESETFORE, i, foreground_colors[i]);
			sci.send_message(Messages.STYLESETBACK, i, background_colors[i]);
			sci.send_message(Messages.STYLESETBOLD, i, (long)fonts_bold[i]);
			sci.send_message(Messages.STYLESETITALIC, i, (long)fonts_italic[i]);
			sci.send_message(Messages.STYLESETUNDERLINE, i, (long)fonts_underline[i]);
		}
		
	}
	return true;
}

/* this will happen frequently, make it fast */
public void on_editor_notif(int param, Scintilla.Notification *notif)
{
	if (notif->nmhdr.code == Scintilla.Notifications.UPDATEUI) {
		
		if (colorizing) {
			
			ui.current_lexer = (int)sci.send_message(Messages.GETLEXER);
			ui.current_style = (int)sci.send_message(Messages.GETSTYLEAT,
										sci.send_message(Messages.GETCURRENTPOS));
			
			//debug("Current lexer: %s\n", lexer_language());
												
			colorize_editor();
				
			/* update the user interface */
			styling = true;
			ui.current_foreground_color = foreground_colors[ui.current_style];
			ui.current_background_color = background_colors[ui.current_style];
			ui.font_bold = fonts_bold[ui.current_style];
			ui.font_italic = fonts_italic[ui.current_style];
			ui.font_underline = fonts_underline[ui.current_style];
			styling = false;
			
		}
		
	}
}

/* when a color is changed */
private void on_fg_color_changed(int new_color)
{
	if (have_text() && !styling) {
		foreground_colors[ui.current_style] = new_color;
		sci.send_message(Messages.STYLESETFORE, ui.current_style, new_color);
	}
}
private void on_bg_color_changed(int new_color)
{
	if (have_text() && !styling) {
		if (ui.use_common_background) {
			for (int i=0; i <= Scintilla.Styles.DEFAULT; i++) {
				background_colors[i] = new_color;
				sci.send_message(Messages.STYLESETBACK, i, new_color);
			}
		}
		else {
			background_colors[ui.current_style] = new_color;
			sci.send_message(Messages.STYLESETBACK, ui.current_style, new_color);
		}
	}
}

private void on_font_bold_toggled(bool font_bold)
{
	if (have_text() && !styling) {
		fonts_bold[ui.current_style] = font_bold;
		sci.send_message(Messages.STYLESETBOLD, ui.current_style, (long)font_bold);
	}
}

private void on_font_italic_toggled(bool font_italic)
{
	if (have_text() && !styling) {
		fonts_italic[ui.current_style] = font_italic;
		sci.send_message(Messages.STYLESETITALIC, ui.current_style, (long)font_italic);
	}
}

private void on_font_underline_toggled(bool font_underline)
{
	if (have_text() && !styling) {
		fonts_underline[ui.current_style] = font_underline;
		sci.send_message(Messages.STYLESETUNDERLINE, ui.current_style, (long)font_underline);
	}
}

/* show/hide the dialog/notebook page */
public void on_open_toggled()
{
	if (sci == null)
		return;
		
	ui.current_lexer = (int)sci.send_message(Messages.GETLEXER);
	ui.current_style = (int)sci.send_message(Messages.GETSTYLEAT,
								sci.send_message(Messages.GETCURRENTPOS));
	
	bool state = item.get_active();
	
	if (state) {
		colorizing = true;
		debug("Colorizing started");
		if (in_message_window) {
			swin.show_all();
		}
		else {
			dialog.show();
		}
		on_current_document_changed(ui, Geany.Document.get_current());
	}
	else {
		colorizing = false;
		debug("Colorizing ended");
		if (in_message_window) {
			swin.hide();
		}
		else {
			dialog.hide();
		}
	}
	
}

public bool on_dialog_delete() {
	colorizing = false;
	debug("Colorizing ended");
	if (!in_message_window) {
		dialog.hide();
		item.set_active(false);
		return true;
	}	
	return false;
}

public void on_dialog_response(int response_id) {
	colorizing = false;
	debug("Colorizing ended");
	if (!in_message_window) {
		dialog.hide();
		item.set_active(false);
	}
}

//----------------------------------------------------------------------
// Plugin stuff

public void init_config_file(string path)
{
	if (!FileUtils.test(path, FileTest.EXISTS)) {
		KeyFile kf = new KeyFile();
		try {
			kf.set_string("general", "active_theme", "Default");
			kf.set_boolean("general", "in_message_window", true);
			FileUtils.set_contents(path, kf.to_data(null));
		}
		catch (KeyFileError err) {
			warning(err.message);
		}
		catch (FileError err) {
			warning(err.message);
		}
	}
	
	KeyFile kf = new KeyFile();
	try {
		kf.load_from_file(path, KeyFileFlags.NONE);
		
		if (kf.has_key("general", "active_theme")) {
			current_theme = kf.get_string("general", "active_theme");
			in_message_window = kf.get_boolean("general", "in_message_window");
		}
	}
	catch (KeyFileError err) {
		warning(err.message);
	}	
	catch (FileError err) {
		warning(err.message);
	}
}

public void save_config_file(string path) {
	if (!FileUtils.test(path, FileTest.EXISTS)) {
		KeyFile kf = new KeyFile();
		try {
			kf.set_string("general", "active_theme", current_theme);
			kf.set_boolean("general", "in_message_window", in_message_window);
			FileUtils.set_contents(path, kf.to_data(null));
		}
		catch (KeyFileError err) {
			warning(err.message);
		}
		catch (FileError err) {
			warning(err.message);
		}
	}
}

public void plugin_init (Geany.Data data)
{
	config_dir = Path.build_path(Path.DIR_SEPARATOR_S, 
									geany_data.app.configdir, 
									"plugins",
									"colorizer");
	
	if (!FileUtils.test(config_dir, FileTest.EXISTS | FileTest.IS_DIR)) {
		DirUtils.create_with_parents(config_dir, 0700);
	}
	
	config_file = Path.build_path(Path.DIR_SEPARATOR_S,
									config_dir,
									"colorizer.conf");
	
	init_config_file(config_file);
									
	debug("Config file: %s\n", config_file);
	
	/* preload the scintilla object if there's a current document */
	unowned Geany.Document? doc = Document.get_current();
	if (doc != null)
		sci = doc.editor.sci;
	
	/* signals to update current scintilla when new editor is shown/changed */
	geany_plugin.signal_connect(null, "document-activate", true, 
		(GLib.Callback)on_current_document_changed, null);
	geany_plugin.signal_connect(null, "document-open", true,
		(GLib.Callback)on_current_document_changed, null);
	geany_plugin.signal_connect(null, "document-new", true,
		(GLib.Callback)on_current_document_changed, null);

	ui = new ColorizerUI();
	ui.foreground_color_changed.connect(on_fg_color_changed);
	ui.background_color_changed.connect(on_bg_color_changed);
	ui.font_bold_toggled.connect(on_font_bold_toggled);
	ui.font_italic_toggled.connect(on_font_italic_toggled);
	ui.font_underline_toggled.connect(on_font_underline_toggled);

	if (in_message_window) {
	
		swin = new Gtk.ScrolledWindow(null, null);
		swin.set_policy(Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.AUTOMATIC);
		swin.add_with_viewport(ui);
		
		Gtk.Notebook nb = data.main_widgets.message_window_notebook as Gtk.Notebook;
		if (nb != null) {
			nb.append_page(swin, new Gtk.Label("Colorizer"));
			swin.hide();
		}
	}
	else {
		dialog = new Gtk.Dialog.with_buttons("Colorizer", 
								(Gtk.Window)geany_data.main_widgets.window,
								Gtk.DialogFlags.DESTROY_WITH_PARENT,
								Gtk.STOCK_CLOSE,
								Gtk.ResponseType.ACCEPT);
		
		dialog.delete_event.connect(on_dialog_delete);
		dialog.response.connect(on_dialog_response);
		
		Gtk.Box box = (Gtk.Box)dialog.get_content_area();
		box.pack_start(ui, true, true, 0);
	}	

	Gtk.ComboBox cb = ui.combo_lexer;
	for (int i=0; i < lexer_names.length; i++) {
		cb.append_text(lexer_names[i]);
	}
	ui.combo_lexer.set_active(1);
	
	cb = ui.combo_style;
	for (int i=0; i <= Scintilla.Styles.DEFAULT; i++) {
		cb.append_text("Style #%d".printf(i));
	}
	ui.combo_style.set_active(0);
	
	/* add item to the Tools menu */
	unowned Gtk.MenuShell? menu = (Gtk.MenuShell)geany_data.main_widgets.tools_menu;
	sep = new Gtk.SeparatorMenuItem();
	menu.append(sep);
	//sep.show();
	item = new Gtk.CheckMenuItem.with_label("Colorizer");
	item.toggled.connect(on_open_toggled);
	menu.append(item);
	item.show();
	
	geany_plugin.module_make_resident();
	
	colorizing = false;
}

/*
public Gtk.Widget plugin_configure(Gtk.Dialog dlg)
{
	Gtk.VBox vb = new Gtk.VBox(false, 0);
	Gtk.CheckButton cb = new Gtk.CheckButton.with_label(
		"Show in separate dialog instead of message window.");
	vb.pack_start(cb, false, true);
	return vb;
}
*/

public void plugin_cleanup ()
{
	save_config_file(config_file);
	sep.destroy();
	item.destroy();
	if (dialog != null)
		dialog.destroy();
	if (swin != null)
		swin.destroy();
}

/* wrong!  some are missing in real list */
public static const string[] lexer_names = {
	"Container",
	"None",
	"Python",
	"Cpp",
	"HTML",
	"XML",
	"Perl",
	"SQL",
	"VisualBasic",
	"Properties",
	"ErrorList",
	"MakeFile",
	"Batch",
	"XCode",
	"LaTeX",
	"Lua",
	"Diff",
	"Conf",
	"Pascal",
	"Avenue",
	"Ada",
	"Lisp",
	"Ruby",
	"Eiffel",
	"Eiffel (keywords)",
	"TCL",
	"NNCronTab",
	"BullAnt",
	"VBScript",
	"Baan",
	"MatLab",
	"Sol",
	"Asm",
	"Cpp (no case)",
	"Fortran",
	"F77",
	"CSS",
	"POV",
	"LOUT",
	"ESCRIPT",
	"PS",
	"NSIS",
	"MMIXAL",
	"Clarion",
	"Clarion (no case)",
	"LOT",
	"YAML",
	"TeX",
	"Metapost",
	"PowerBasic",
	"Forth",
	"Erlang",
	"Octave",
	"MSSQL",
	"Verilog",
	"Kix",
	"GUI4CLI",
	"Specman",
	"Au3",
	"APDL",
	"Bash",
	"Asn1",
	"VHDL",
	"Caml",
	"BlitzBasic",
	"PureBasic",
	"Haskell",
	"PHP Script",
	"TADS3",
	"Rebol",
	"Smalltalk",
	"FlagShip",
	"Csound",
	"FreeBasic",
	"Inno",
	"Opal",
	"Spice",
	"D",
	"CMAKE",
	"Gap",
	"PLM",
	"Progress",
	"ABAQUS",
	"Asymptote",
	"R",
	"Magik",
	"PowerShell",
	"MySQL",
	"Po",
	"Tal",
	"COBOL",
	"TACL",
	"SORCUS",
	"PowerPro",
	"Nimrod",
	"SML",
	"Markdown",
	"Txt2Tags",
	"A68K"
};
