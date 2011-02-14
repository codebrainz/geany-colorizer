using Gtk;
using Gdk;
using Pango;

namespace Geany
{
	
	public class ColorizerUI : Gtk.VBox
	{
		public string theme_dir;
		private Gtk.ListStore theme_model;
		
		Gtk.ComboBox comboLexer;
		Gtk.ComboBox comboStyle;
		Gtk.Notebook notebookMain;
		Gtk.ColorSelection colorselForeground;
		Gtk.ColorSelection colorselBackground;

		Gtk.CheckButton checkUseCommonBackground;

		Gtk.CheckButton checkFontBold;
		Gtk.CheckButton checkFontItalic;
		Gtk.CheckButton checkFontUnderline;
		
		Gtk.TreeView treeThemes;
		Gtk.Button buttonNew;
		Gtk.Button buttonSave;
		Gtk.Button buttonOpen;
		Gtk.Button buttonDelete;
		
		// Signals passed along from internal widgets
		public signal void foreground_color_changed(int color);
		public signal void background_color_changed(int color);
		public signal void lexer_changed(int lexer_id);
		public signal void style_changed(int style_number);
		public signal void use_common_bg_color_toggled(bool use_common);
		public signal void close_button_clicked();
		public signal void notebook_page_switched(int page_num);
		public signal void font_bold_toggled(bool font_bold);
		public signal void font_italic_toggled(bool font_italic);
		public signal void font_underline_toggled(bool font_italic);
		public signal void theme_changed(string theme_name);
		public signal void theme_save_button_clicked();
		
		private string[] _available_themes;
		public string[] available_themes
		{
			get 
			{
				_available_themes = new string[] {};
				string name;
				Dir d = Dir.open(theme_dir);
				while ( (name=d.read_name()) != null ) {
					_available_themes += name;
				}
				return _available_themes;
			}
		}
		
		private string _current_theme;
		public string current_theme
		{
			get
			{
				Gtk.TreeModel model;
				Gtk.TreeIter iter;
				Gtk.TreeSelection sel = treeThemes.get_selection();
				if (sel.get_selected(out model, out iter)) {
					model.get(iter, 0, out _current_theme);
				}
				return _current_theme;
			}
		}
		
		private void on_tree_row_activated(Gtk.TreePath path, Gtk.TreeViewColumn column)
		{
			theme_changed(current_theme);
		}
		
		public ColorizerUI(string themedir)
		{
			this.theme_dir = themedir;	
			_last_lexer = 1;
			_last_style = 0;
			init_ui();
		}
				
		public Gtk.ComboBox combo_lexer
		{
			get { return comboLexer; }
		}
		
		public Gtk.ComboBox combo_style
		{
			get { return comboStyle; }
		}
		
		private int _last_lexer;
		public int current_lexer
		{
			get { return comboLexer.get_active(); }
			set 
			{
				if (value != _last_lexer) {
					lexer_changed(value);
					_last_lexer = value;
					comboLexer.set_active(value);
				} 
			}
		}
		
		private int _last_style;
		public int current_style
		{
			get { return comboStyle.get_active(); }
			set 
			{ 
				if (value != _last_style) {
					style_changed(value);
					_last_style = value; 
					comboStyle.set_active(value);
				}
			}
		}
		
		public int current_foreground_color
		{
			get { return int_from_color(colorselForeground.current_color); }
			set 
			{
				int int_color = value;
				Gdk.Color clr = color_from_int(int_color);
				colorselForeground.current_color = clr;
			}
		}
		
		public int current_background_color
		{
			get { return int_from_color(colorselBackground.current_color); }
			set 
			{
				int int_color = value;
				Gdk.Color clr = color_from_int(int_color);
				colorselBackground.current_color = clr;
			}
		}
		
		public bool font_bold
		{
			get { return checkFontBold.get_active(); }
			set { checkFontBold.set_active(value); }
		}
		
		public bool font_italic
		{
			get { return checkFontItalic.get_active(); }
			set { checkFontItalic.set_active(value); }
		}
		
		public bool font_underline
		{
			get { return checkFontUnderline.get_active(); }
			set { checkFontUnderline.set_active(value); }
		}
				
		public bool use_common_background
		{
			get { return checkUseCommonBackground.get_active(); }
			set { checkUseCommonBackground.set_active(value); }
		}
		
		private void on_combo_lexer_changed()
		{
			if (comboLexer.get_active() != _last_lexer) {
				lexer_changed(comboLexer.get_active());
				_last_lexer = comboLexer.get_active();
			}
		}
		
		private void on_combo_style_changed()
		{
			if (comboStyle.get_active() != _last_style) {
				style_changed(comboStyle.get_active());
				_last_style = comboStyle.get_active();
			}
		}
		
		private void on_notebook_page_switched(NotebookPage page, uint page_num)
		{
			notebook_page_switched((int)page_num);
		}
		
		private void on_fg_color_changed()
		{
			foreground_color_changed(
				int_from_color(colorselForeground.current_color));
		}
		
		private void on_bg_color_changed()
		{
			background_color_changed(
				int_from_color(colorselBackground.current_color));
		}

		private void on_use_common_bg_color_toggled()
		{
			use_common_bg_color_toggled(checkUseCommonBackground.get_active());
		}
				
		private void on_font_bold_toggled()
		{
			font_bold_toggled(checkFontBold.get_active());
		}
		
		private void on_font_italic_toggled()
		{
			font_italic_toggled(checkFontItalic.get_active());
		}
		
		private void on_font_underline_toggled()
		{
			font_underline_toggled(checkFontUnderline.get_active());
		}
		
		private void on_new_theme_clicked()
		{
			Gtk.Dialog dlg = new Gtk.Dialog.with_buttons("New Theme",
										null, DialogFlags.MODAL,
										Gtk.STOCK_OK,
										Gtk.ResponseType.ACCEPT,
										Gtk.STOCK_CANCEL,
										Gtk.ResponseType.REJECT);
			
			Gtk.Entry ent = new Gtk.Entry();
			dlg.vbox.pack_start(ent, true, true, 0);
			ent.show();
										
			if (dlg.run() == Gtk.ResponseType.ACCEPT) {
				string new_dir = Path.build_path(Path.DIR_SEPARATOR_S, 
													this.theme_dir, 
													ent.text);
				DirUtils.create_with_parents(new_dir, 0700);
				this.load_themes();
			}
			
			dlg.destroy();
			
		}
		
		private void on_delete_theme_clicked()
		{
			Gtk.MessageDialog dlg = new Gtk.MessageDialog(null,
											DialogFlags.MODAL,
											MessageType.QUESTION,
											ButtonsType.YES_NO,
											"Are you sure you want to delete the theme '%s'?",
											current_theme);
			
			Gtk.ResponseType res = (Gtk.ResponseType)dlg.run();
			if (res == Gtk.ResponseType.YES || res == Gtk.ResponseType.ACCEPT) {
				string del_dir = Path.build_path(Path.DIR_SEPARATOR_S,
													this.theme_dir,
													current_theme);
				DirUtils.remove(del_dir);
				this.load_themes();
			}
			
			dlg.destroy();
		}
		
		private void on_save_theme_clicked()
		{
			debug("Theme save button clicked");
			theme_save_button_clicked();
			
		}
		
		public void connect_signals()
		{
			buttonNew.clicked.connect(on_new_theme_clicked);
			buttonDelete.clicked.connect(on_delete_theme_clicked);
			buttonSave.clicked.connect(on_save_theme_clicked);
			treeThemes.row_activated.connect(on_tree_row_activated);
			
			
			comboLexer.changed.connect(on_combo_lexer_changed);
			comboStyle.changed.connect(on_combo_style_changed);
			notebookMain.switch_page.connect(on_notebook_page_switched);
			colorselForeground.color_changed.connect(on_fg_color_changed);
			colorselBackground.color_changed.connect(on_bg_color_changed);
			checkUseCommonBackground.toggled.connect(on_use_common_bg_color_toggled);
			checkFontBold.toggled.connect(on_font_bold_toggled);
			checkFontItalic.toggled.connect(on_font_italic_toggled);
			checkFontUnderline.toggled.connect(on_font_underline_toggled);
		}
		
		private void load_themes()
		{
			theme_model = new Gtk.ListStore(1, typeof(string));
			treeThemes.set_model(theme_model);
			Gtk.TreeIter iter;
			foreach (string theme in this.available_themes) {
				theme_model.append(out iter);
				theme_model.set(iter, 0, theme);
			}
		}
		
		public void init_ui()
		{
			
			comboLexer = new Gtk.ComboBox.text();
			comboStyle = new  Gtk.ComboBox.text();
			notebookMain = new Gtk.Notebook();
			colorselForeground = new Gtk.ColorSelection();
			colorselBackground = new Gtk.ColorSelection();
			checkUseCommonBackground = new Gtk.CheckButton.with_label("Use common background");
			checkFontBold = new Gtk.CheckButton.with_label("Bold");
			checkFontItalic = new Gtk.CheckButton.with_label("Italic");
			checkFontUnderline = new Gtk.CheckButton.with_label("Underline");
			
			buttonNew = new Gtk.Button.from_stock(Gtk.STOCK_NEW);
			buttonDelete = new Gtk.Button.from_stock(Gtk.STOCK_DELETE);
			buttonSave = new Gtk.Button.from_stock(Gtk.STOCK_SAVE);
						
			colorselForeground.has_opacity_control = false;
			colorselForeground.has_palette = true;
			colorselForeground.homogeneous = true;
			colorselBackground.has_opacity_control = false;
			colorselBackground.has_palette = true;
			colorselBackground.homogeneous = true;
			
			checkUseCommonBackground.set_active(true);
			
			// Themes tab
			treeThemes = new Gtk.TreeView();
			treeThemes.set_headers_visible(false);
			treeThemes.insert_column_with_attributes(-1, "Theme",
							new Gtk.CellRendererText(), "text", 0);
			Gtk.TreeViewColumn col = treeThemes.get_column(0);
			col.sort_column_id = 0;
			col.sort_order = SortType.ASCENDING;
			theme_model = new Gtk.ListStore(1, typeof(string));
			load_themes();
			
			Gtk.HBox hbox = new Gtk.HBox(false, 6);
			hbox.set_border_width(6);
			Gtk.ScrolledWindow swin = new Gtk.ScrolledWindow(null, null);
			swin.set_policy(Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.AUTOMATIC);
			swin.set_shadow_type(Gtk.ShadowType.ETCHED_IN);
			swin.add(treeThemes);
			hbox.pack_start(swin, true, true, 0);
			Gtk.VButtonBox bb = new Gtk.VButtonBox();
			bb.set_layout(Gtk.ButtonBoxStyle.START);
			bb.set_spacing(6);
			bb.pack_start(buttonNew, true, true, 0);
			bb.pack_start(buttonDelete, true, true, 0);
			bb.pack_start(buttonSave, true, true, 0);
			hbox.pack_start(bb, false, true, 0);
			notebookMain.append_page(hbox, new Gtk.Label("Themes"));
			
			// Box along the top with lexer and style
			hbox = new Gtk.HBox(false, 6);
			hbox.pack_start(new Gtk.Label("Lexer:"), false, true, 0);
			hbox.pack_start(comboLexer, true, true, 0);
			hbox.pack_start(new Gtk.Label("Style:"), false, true, 0);
			hbox.pack_start(comboStyle, true, true, 0);
			this.pack_start(hbox, false, true, 0);
			this.pack_start(new Gtk.HSeparator(), false, true, 0);
			
			// Foreground color tab
			Gtk.VBox vbox = new Gtk.VBox(false, 6);
			vbox.set_border_width(6);
			vbox.pack_start(colorselForeground, true, true, 0);
			notebookMain.append_page(vbox, new Gtk.Label("Foreground"));
			
			// Background color tab
			hbox = new Gtk.HBox(false, 6);
			hbox.pack_start(checkUseCommonBackground, false, true, 0);
			vbox = new Gtk.VBox(false, 6);
			vbox.set_border_width(6);
			vbox.pack_start(hbox, false, true, 0);
			vbox.pack_start(new Gtk.HSeparator(), false, true, 0);
			vbox.pack_start(colorselBackground, true, true, 0);
			notebookMain.append_page(vbox, new Gtk.Label("Background"));
			
			// Font tab
			hbox = new Gtk.HBox(false, 6);
			hbox.pack_start(checkFontBold, false, true, 0);
			hbox.pack_start(checkFontItalic, false, true, 0);
			hbox.pack_start(checkFontUnderline, false, true, 0);
			vbox = new Gtk.VBox(false, 6);
			vbox.set_border_width(6);
			vbox.pack_start(hbox, false, true, 0);
			notebookMain.append_page(vbox, new Gtk.Label("Font"));
			
			this.pack_start(notebookMain, true, true, 0);
			
			this.set_border_width(6);
			this.set_spacing(6);
			this.show_all();
			
			connect_signals();
			
		}
		
		public static int int_from_color(Gdk.Color c) 
		{
			int r = (int)scale_round(c.red / 256, 255);
			int g = (int)scale_round(c.green / 256, 255);
			int b = (int)scale_round(c.blue / 256, 255);
			return (b*65536) + (g*256) + r;
		}
		/* used with above */
		private static double scale_round(double val, double factor) 
		{
			val = Math.floor(val);
			val = Math.fmax(val, 0);
			val = Math.fmin(val, factor);
			return val;
		}

		public static Gdk.Color color_from_int(int color) 
		{
			Gdk.Color c = Gdk.Color();
			int r = (color & 255);
			int g = (color >> 16) & 255;
			int b = (color >> 16) & 255;
			c.red = (uint16)(r * 256);
			c.green = (uint16)(g * 256);
			c.blue = (uint16)(b * 256);
			return c;
		}
	}
	
}


















