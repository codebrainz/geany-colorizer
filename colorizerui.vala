using Gtk;
using Gdk;
using Pango;
//using Geany;

namespace Geany
{
	
	public class FaceliftUI : Gtk.VBox
	{
		
		Gtk.ComboBox comboLexer;
		Gtk.ComboBox comboStyle;
		Gtk.Notebook notebookMain;
		Gtk.ColorSelection colorselForeground;
		Gtk.ColorSelection colorselBackground;

		Gtk.CheckButton checkUseCommonBackground;

		Gtk.CheckButton checkFontBold;
		Gtk.CheckButton checkFontItalic;
		Gtk.CheckButton checkFontUnderline;
		
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
		
		public FaceliftUI()
		{
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
		
		public int current_lexer
		{
			get { return comboLexer.get_active(); }
			set { comboLexer.set_active(value); }
		}
		
		public int current_style
		{
			get { return comboStyle.get_active(); }
			set { comboStyle.set_active(value); }
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
			lexer_changed(comboLexer.get_active());
		}
		
		private void on_combo_style_changed()
		{
			style_changed(comboStyle.get_active());
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
		
		public void connect_signals()
		{
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
						
			colorselForeground.has_opacity_control = false;
			colorselForeground.has_palette = true;
			colorselForeground.homogeneous = true;
			colorselBackground.has_opacity_control = false;
			colorselBackground.has_palette = true;
			colorselBackground.homogeneous = true;
			
			checkUseCommonBackground.set_active(true);
			
			// Box along the top with lexer and style
			Gtk.HBox hbox = new Gtk.HBox(false, 6);
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
	
	public static int main(string[] args)
	{
		Gtk.init(ref args);
		
		Gtk.Window win = new Gtk.Window();
		FaceliftUI ui = new FaceliftUI();
		
		win.add(ui);
		win.destroy.connect(Gtk.main_quit);
		win.show_all();
		
		Gtk.main();
		
		return 0;
	}
	
}


















