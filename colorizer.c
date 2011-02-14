/* colorizer.c generated by valac 0.10.0, the Vala compiler
 * generated from colorizer.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <geanyplugin.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <Scintilla.h>
#include <SciLexer.h>
#include <ScintillaWidget.h>
#include <glib/gstdio.h>
#include <gdk/gdk.h>


#define GEANY_TYPE_COLORIZER_UI (geany_colorizer_ui_get_type ())
#define GEANY_COLORIZER_UI(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GEANY_TYPE_COLORIZER_UI, GeanyColorizerUI))
#define GEANY_COLORIZER_UI_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GEANY_TYPE_COLORIZER_UI, GeanyColorizerUIClass))
#define GEANY_IS_COLORIZER_UI(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GEANY_TYPE_COLORIZER_UI))
#define GEANY_IS_COLORIZER_UI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GEANY_TYPE_COLORIZER_UI))
#define GEANY_COLORIZER_UI_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GEANY_TYPE_COLORIZER_UI, GeanyColorizerUIClass))

typedef struct _GeanyColorizerUI GeanyColorizerUI;
typedef struct _GeanyColorizerUIClass GeanyColorizerUIClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))


extern GeanyPlugin* geany_plugin;
GeanyPlugin* geany_plugin = NULL;
extern GeanyData* geany_data;
GeanyData* geany_data = NULL;
extern GeanyFunctions* geany_functions;
GeanyFunctions* geany_functions = NULL;
extern ScintillaObject* sci;
ScintillaObject* sci = NULL;
extern GeanyColorizerUI* ui;
GeanyColorizerUI* ui = NULL;
extern gint foreground_colors[33];
gint foreground_colors[33] = {0};
extern gint background_colors[33];
gint background_colors[33] = {0};
extern gboolean fonts_bold[33];
gboolean fonts_bold[33] = {0};
extern gboolean fonts_italic[33];
gboolean fonts_italic[33] = {0};
extern gboolean fonts_underline[33];
gboolean fonts_underline[33] = {0};
extern gint* theme_data;
extern gint theme_data_length1;
extern gint theme_data_length2;
extern gint theme_data_length3;
gint* theme_data = NULL;
gint theme_data_length1 = 0;
gint theme_data_length2 = 0;
gint theme_data_length3 = 0;
extern gboolean in_message_window;
gboolean in_message_window = TRUE;
extern GtkMenuItem* sep;
GtkMenuItem* sep = NULL;
extern GtkCheckMenuItem* item;
GtkCheckMenuItem* item = NULL;
extern GtkDialog* dialog;
GtkDialog* dialog = NULL;
extern GtkScrolledWindow* swin;
GtkScrolledWindow* swin = NULL;
extern gboolean colorizing;
gboolean colorizing = FALSE;
extern gboolean styling;
gboolean styling = FALSE;
extern char* config_dir;
char* config_dir = NULL;
extern char* config_file;
char* config_file = NULL;
extern char* theme_dir;
char* theme_dir = NULL;
extern char* current_theme;
char* current_theme = NULL;

void plugin_set_info (PluginInfo* info);
gint plugin_version_check (gint abi_version);
GType geany_colorizer_ui_get_type (void) G_GNUC_CONST;
#define FACELIFT_INDIC (INDIC_MAX - 1)
glong text_length (void);
gboolean have_text (void);
char* lexer_language (void);
void on_current_document_changed (GObject* ignored, struct GeanyDocument* doc);
void on_editor_notif (gint param, struct SCNotification* notif);
static void _on_editor_notif_scintilla_object_sci_notify (ScintillaObject* _sender, gint param, struct SCNotification* notif, gpointer self);
void geany_colorizer_ui_set_current_lexer (GeanyColorizerUI* self, gint value);
void geany_colorizer_ui_set_current_style (GeanyColorizerUI* self, gint value);
gboolean colorize_editor (void);
gint geany_colorizer_ui_get_current_style (GeanyColorizerUI* self);
void geany_colorizer_ui_set_current_foreground_color (GeanyColorizerUI* self, gint value);
void geany_colorizer_ui_set_current_background_color (GeanyColorizerUI* self, gint value);
void geany_colorizer_ui_set_font_bold (GeanyColorizerUI* self, gboolean value);
void geany_colorizer_ui_set_font_italic (GeanyColorizerUI* self, gboolean value);
void geany_colorizer_ui_set_font_underline (GeanyColorizerUI* self, gboolean value);
void on_fg_color_changed (gint new_color);
void on_bg_color_changed (gint new_color);
gboolean geany_colorizer_ui_get_use_common_background (GeanyColorizerUI* self);
void on_font_bold_toggled (gboolean font_bold);
void on_font_italic_toggled (gboolean font_italic);
void on_font_underline_toggled (gboolean font_underline);
void on_lexer_changed (gint lexer);
void on_open_toggled (void);
gboolean on_dialog_delete (void);
void on_dialog_response (gint response_id);
void init_config_file (const char* path);
void save_config_file (const char* path);
void create_dir (const char* path);
void plugin_init (GeanyData* data);
GeanyColorizerUI* geany_colorizer_ui_new (const char* themedir);
GeanyColorizerUI* geany_colorizer_ui_construct (GType object_type, const char* themedir);
static void _on_fg_color_changed_geany_colorizer_ui_foreground_color_changed (GeanyColorizerUI* _sender, gint color, gpointer self);
static void _on_bg_color_changed_geany_colorizer_ui_background_color_changed (GeanyColorizerUI* _sender, gint color, gpointer self);
static void _on_font_bold_toggled_geany_colorizer_ui_font_bold_toggled (GeanyColorizerUI* _sender, gboolean font_bold, gpointer self);
static void _on_font_italic_toggled_geany_colorizer_ui_font_italic_toggled (GeanyColorizerUI* _sender, gboolean font_italic, gpointer self);
static void _on_font_underline_toggled_geany_colorizer_ui_font_underline_toggled (GeanyColorizerUI* _sender, gboolean font_italic, gpointer self);
static void _on_lexer_changed_geany_colorizer_ui_lexer_changed (GeanyColorizerUI* _sender, gint lexer_id, gpointer self);
static gboolean _on_dialog_delete_gtk_widget_delete_event (GtkWidget* _sender, GdkEvent* event, gpointer self);
static void _on_dialog_response_gtk_dialog_response (GtkDialog* _sender, gint response_id, gpointer self);
GtkComboBox* geany_colorizer_ui_get_combo_lexer (GeanyColorizerUI* self);
GtkComboBox* geany_colorizer_ui_get_combo_style (GeanyColorizerUI* self);
static void _on_open_toggled_gtk_check_menu_item_toggled (GtkCheckMenuItem* _sender, gpointer self);
void plugin_cleanup (void);

const char* lexer_names[99] = {"Container", "None", "Python", "Cpp", "HTML", "XML", "Perl", "SQL", "VisualBasic", "Properties", "ErrorList", "MakeFile", "Batch", "XCode", "LaTeX", "Lua", "Diff", "Conf", "Pascal", "Avenue", "Ada", "Lisp", "Ruby", "Eiffel", "Eiffel (keywords)", "TCL", "NNCronTab", "BullAnt", "VBScript", "Baan", "MatLab", "Sol", "Asm", "Cpp (no case)", "Fortran", "F77", "CSS", "POV", "LOUT", "ESCRIPT", "PS", "NSIS", "MMIXAL", "Clarion", "Clarion (no case)", "LOT", "YAML", "TeX", "Metapost", "PowerBasic", "Forth", "Erlang", "Octave", "MSSQL", "Verilog", "Kix", "GUI4CLI", "Specman", "Au3", "APDL", "Bash", "Asn1", "VHDL", "Caml", "BlitzBasic", "PureBasic", "Haskell", "PHP Script", "TADS3", "Rebol", "Smalltalk", "FlagShip", "Csound", "FreeBasic", "Inno", "Opal", "Spice", "D", "CMAKE", "Gap", "PLM", "Progress", "ABAQUS", "Asymptote", "R", "Magik", "PowerShell", "MySQL", "Po", "Tal", "COBOL", "TACL", "SORCUS", "PowerPro", "Nimrod", "SML", "Markdown", "Txt2Tags", "A68K"};


static void __geany_vala_plugin_SET_INFO (PluginInfo *self, const char* name, const char* description, const char* version, const char* author) {
	g_return_if_fail (name != NULL);
	(*self).name = name;
	(*self).description = description;
	(*self).version = version;
	(*self).author = author;
}


void plugin_set_info (PluginInfo* info) {
	__geany_vala_plugin_SET_INFO (info, "Colorizer", "Set Scintilla appearances on-the-fly.", "0.1", "Matthew Brush <mbrush@leftclick.ca>");
}


static gint __geany_vala_plugin_VERSION_CHECK (gint abi_version, gint api_required) {
	gint result = 0;
	if (abi_version != GEANY_ABI_VERSION) {
		result = -1;
		return result;
	}
	if (GEANY_API_VERSION < api_required) {
		result = api_required;
		return result;
	}
	result = 0;
	return result;
}


gint plugin_version_check (gint abi_version) {
	gint result = 0;
	result = __geany_vala_plugin_VERSION_CHECK (abi_version, 185);
	return result;
}


glong text_length (void) {
	glong result = 0L;
	if (sci != NULL) {
		result = scintilla_send_message (sci, (unsigned int) SCI_GETTEXTLENGTH, (uptr_t) 0, (sptr_t) 0);
		return result;
	}
	result = (glong) 0;
	return result;
}


gboolean have_text (void) {
	gboolean result = FALSE;
	result = text_length () > 0;
	return result;
}


char* lexer_language (void) {
	char* result = NULL;
	gchar* tmp = NULL;
	glong len;
	char* ret;
	if (sci == NULL) {
		result = NULL;
		return result;
	}
	len = scintilla_send_message (sci, (unsigned int) SCI_GETLEXERLANGUAGE, (uptr_t) 0, (sptr_t) 0);
	tmp = g_malloc0 ((gsize) (len + 1));
	len = scintilla_send_message (sci, (unsigned int) SCI_GETLEXERLANGUAGE, (uptr_t) ((gulong) 0), (sptr_t) ((glong) tmp));
	if (len == 0) {
		g_free (tmp);
		result = NULL;
		return result;
	}
	ret = g_strdup ((const char*) tmp);
	g_free (tmp);
	result = ret;
	return result;
}


static void _on_editor_notif_scintilla_object_sci_notify (ScintillaObject* _sender, gint param, struct SCNotification* notif, gpointer self) {
	on_editor_notif (param, notif);
}


void on_current_document_changed (GObject* ignored, struct GeanyDocument* doc) {
	g_return_if_fail (ignored != NULL);
	g_return_if_fail (doc != NULL);
	if (doc->editor->sci != NULL) {
		gboolean _tmp0_ = FALSE;
		sci = (ScintillaObject*) doc->editor->sci;
		if (colorizing) {
			_tmp0_ = have_text ();
		} else {
			_tmp0_ = FALSE;
		}
		if (_tmp0_) {
			if (sci != NULL) {
				g_signal_connect (sci, "sci-notify", (GCallback) _on_editor_notif_scintilla_object_sci_notify, NULL);
			}
			geany_colorizer_ui_set_current_lexer (ui, (gint) scintilla_send_message (sci, (unsigned int) SCI_GETLEXER, (uptr_t) 0, (sptr_t) 0));
			geany_colorizer_ui_set_current_style (ui, (gint) scintilla_send_message (sci, (unsigned int) SCI_GETSTYLEAT, (uptr_t) ((gulong) scintilla_send_message (sci, (unsigned int) SCI_GETCURRENTPOS, (uptr_t) 0, (sptr_t) 0)), (sptr_t) 0));
			{
				gint i;
				i = 0;
				{
					gboolean _tmp1_;
					_tmp1_ = TRUE;
					while (TRUE) {
						if (!_tmp1_) {
							i++;
						}
						_tmp1_ = FALSE;
						if (!(i < 33)) {
							break;
						}
						foreground_colors[i] = (gint) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETFORE, (uptr_t) ((gulong) i), (sptr_t) 0);
						background_colors[i] = (gint) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETBACK, (uptr_t) ((gulong) i), (sptr_t) 0);
						fonts_bold[i] = (gboolean) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETBOLD, (uptr_t) ((gulong) i), (sptr_t) 0);
						fonts_italic[i] = (gboolean) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETITALIC, (uptr_t) ((gulong) i), (sptr_t) 0);
						fonts_underline[i] = (gboolean) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETUNDERLINE, (uptr_t) ((gulong) i), (sptr_t) 0);
					}
				}
			}
			scintilla_send_message (sci, (unsigned int) SCI_SETCARETLINEVISIBLE, (uptr_t) ((gulong) 0), (sptr_t) 0);
		}
	}
}


gboolean colorize_editor (void) {
	gboolean result = FALSE;
	if (have_text ()) {
		glong num_chars;
		scintilla_send_message (sci, (unsigned int) SCI_INDICSETSTYLE, (uptr_t) ((gulong) FACELIFT_INDIC), (sptr_t) ((glong) INDIC_TT));
		scintilla_send_message (sci, (unsigned int) SCI_INDICSETFORE, (uptr_t) ((gulong) FACELIFT_INDIC), (sptr_t) ((glong) 0xBFBFBF));
		num_chars = text_length ();
		scintilla_send_message (sci, (unsigned int) SCI_SETINDICATORCURRENT, (uptr_t) ((gulong) FACELIFT_INDIC), (sptr_t) 0);
		scintilla_send_message (sci, (unsigned int) SCI_INDICATORCLEARRANGE, (uptr_t) ((gulong) 0), (sptr_t) num_chars);
		{
			glong p;
			p = (glong) 0;
			{
				gboolean _tmp0_;
				_tmp0_ = TRUE;
				while (TRUE) {
					gint s;
					if (!_tmp0_) {
						p++;
					}
					_tmp0_ = FALSE;
					if (!(p < num_chars)) {
						break;
					}
					s = (gint) scintilla_send_message (sci, (unsigned int) SCI_GETSTYLEAT, (uptr_t) ((gulong) p), (sptr_t) 0);
					if (s == geany_colorizer_ui_get_current_style (ui)) {
						scintilla_send_message (sci, (unsigned int) SCI_INDICATORFILLRANGE, (uptr_t) ((gulong) p), (sptr_t) ((glong) 1));
					}
				}
			}
		}
		{
			gint i;
			i = 0;
			{
				gboolean _tmp1_;
				_tmp1_ = TRUE;
				while (TRUE) {
					if (!_tmp1_) {
						i++;
					}
					_tmp1_ = FALSE;
					if (!(i <= STYLE_DEFAULT)) {
						break;
					}
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETFORE, (uptr_t) ((gulong) i), (sptr_t) ((glong) foreground_colors[i]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETBACK, (uptr_t) ((gulong) i), (sptr_t) ((glong) background_colors[i]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETBOLD, (uptr_t) ((gulong) i), (sptr_t) ((glong) fonts_bold[i]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETITALIC, (uptr_t) ((gulong) i), (sptr_t) ((glong) fonts_italic[i]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETUNDERLINE, (uptr_t) ((gulong) i), (sptr_t) ((glong) fonts_underline[i]));
				}
			}
		}
	}
	result = TRUE;
	return result;
}


void on_editor_notif (gint param, struct SCNotification* notif) {
	if ((*notif).nmhdr.code == SCN_UPDATEUI) {
		if (colorizing) {
			geany_colorizer_ui_set_current_lexer (ui, (gint) scintilla_send_message (sci, (unsigned int) SCI_GETLEXER, (uptr_t) 0, (sptr_t) 0));
			geany_colorizer_ui_set_current_style (ui, (gint) scintilla_send_message (sci, (unsigned int) SCI_GETSTYLEAT, (uptr_t) ((gulong) scintilla_send_message (sci, (unsigned int) SCI_GETCURRENTPOS, (uptr_t) 0, (sptr_t) 0)), (sptr_t) 0));
			colorize_editor ();
			styling = TRUE;
			geany_colorizer_ui_set_current_foreground_color (ui, foreground_colors[geany_colorizer_ui_get_current_style (ui)]);
			geany_colorizer_ui_set_current_background_color (ui, background_colors[geany_colorizer_ui_get_current_style (ui)]);
			geany_colorizer_ui_set_font_bold (ui, fonts_bold[geany_colorizer_ui_get_current_style (ui)]);
			geany_colorizer_ui_set_font_italic (ui, fonts_italic[geany_colorizer_ui_get_current_style (ui)]);
			geany_colorizer_ui_set_font_underline (ui, fonts_underline[geany_colorizer_ui_get_current_style (ui)]);
			styling = FALSE;
		}
	}
}


void on_fg_color_changed (gint new_color) {
	gboolean _tmp0_ = FALSE;
	if (have_text ()) {
		_tmp0_ = !styling;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		foreground_colors[geany_colorizer_ui_get_current_style (ui)] = new_color;
		scintilla_send_message (sci, (unsigned int) SCI_STYLESETFORE, (uptr_t) ((gulong) geany_colorizer_ui_get_current_style (ui)), (sptr_t) ((glong) new_color));
	}
}


void on_bg_color_changed (gint new_color) {
	gboolean _tmp0_ = FALSE;
	if (have_text ()) {
		_tmp0_ = !styling;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		if (geany_colorizer_ui_get_use_common_background (ui)) {
			{
				gint i;
				i = 0;
				{
					gboolean _tmp1_;
					_tmp1_ = TRUE;
					while (TRUE) {
						if (!_tmp1_) {
							i++;
						}
						_tmp1_ = FALSE;
						if (!(i <= STYLE_DEFAULT)) {
							break;
						}
						background_colors[i] = new_color;
						scintilla_send_message (sci, (unsigned int) SCI_STYLESETBACK, (uptr_t) ((gulong) i), (sptr_t) ((glong) new_color));
					}
				}
			}
		} else {
			background_colors[geany_colorizer_ui_get_current_style (ui)] = new_color;
			scintilla_send_message (sci, (unsigned int) SCI_STYLESETBACK, (uptr_t) ((gulong) geany_colorizer_ui_get_current_style (ui)), (sptr_t) ((glong) new_color));
		}
	}
}


void on_font_bold_toggled (gboolean font_bold) {
	gboolean _tmp0_ = FALSE;
	if (have_text ()) {
		_tmp0_ = !styling;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		fonts_bold[geany_colorizer_ui_get_current_style (ui)] = font_bold;
		scintilla_send_message (sci, (unsigned int) SCI_STYLESETBOLD, (uptr_t) ((gulong) geany_colorizer_ui_get_current_style (ui)), (sptr_t) ((glong) font_bold));
	}
}


void on_font_italic_toggled (gboolean font_italic) {
	gboolean _tmp0_ = FALSE;
	if (have_text ()) {
		_tmp0_ = !styling;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		fonts_italic[geany_colorizer_ui_get_current_style (ui)] = font_italic;
		scintilla_send_message (sci, (unsigned int) SCI_STYLESETITALIC, (uptr_t) ((gulong) geany_colorizer_ui_get_current_style (ui)), (sptr_t) ((glong) font_italic));
	}
}


void on_font_underline_toggled (gboolean font_underline) {
	gboolean _tmp0_ = FALSE;
	if (have_text ()) {
		_tmp0_ = !styling;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		fonts_underline[geany_colorizer_ui_get_current_style (ui)] = font_underline;
		scintilla_send_message (sci, (unsigned int) SCI_STYLESETUNDERLINE, (uptr_t) ((gulong) geany_colorizer_ui_get_current_style (ui)), (sptr_t) ((glong) font_underline));
	}
}


void on_lexer_changed (gint lexer) {
	g_debug ("colorizer.vala:236: Lexer changed to %d", lexer);
}


void on_open_toggled (void) {
	gboolean state;
	if (sci == NULL) {
		return;
	}
	geany_colorizer_ui_set_current_lexer (ui, (gint) scintilla_send_message (sci, (unsigned int) SCI_GETLEXER, (uptr_t) 0, (sptr_t) 0));
	geany_colorizer_ui_set_current_style (ui, (gint) scintilla_send_message (sci, (unsigned int) SCI_GETSTYLEAT, (uptr_t) ((gulong) scintilla_send_message (sci, (unsigned int) SCI_GETCURRENTPOS, (uptr_t) 0, (sptr_t) 0)), (sptr_t) 0));
	state = gtk_check_menu_item_get_active (item);
	if (state) {
		colorizing = TRUE;
		g_debug ("colorizer.vala:253: Colorizing started");
		if (in_message_window) {
			gtk_widget_show_all ((GtkWidget*) swin);
		} else {
			gtk_widget_show ((GtkWidget*) dialog);
		}
		on_current_document_changed ((GObject*) ui, document_get_current ());
	} else {
		colorizing = FALSE;
		g_debug ("colorizer.vala:264: Colorizing ended");
		if (in_message_window) {
			gtk_widget_hide ((GtkWidget*) swin);
		} else {
			gtk_widget_hide ((GtkWidget*) dialog);
		}
	}
}


gboolean on_dialog_delete (void) {
	gboolean result = FALSE;
	colorizing = FALSE;
	g_debug ("colorizer.vala:277: Colorizing ended");
	if (!in_message_window) {
		gtk_widget_hide ((GtkWidget*) dialog);
		gtk_check_menu_item_set_active (item, FALSE);
		result = TRUE;
		return result;
	}
	result = FALSE;
	return result;
}


void on_dialog_response (gint response_id) {
	colorizing = FALSE;
	g_debug ("colorizer.vala:288: Colorizing ended");
	if (!in_message_window) {
		gtk_widget_hide ((GtkWidget*) dialog);
		gtk_check_menu_item_set_active (item, FALSE);
	}
}


void init_config_file (const char* path) {
	GKeyFile* kf;
	GError * _inner_error_ = NULL;
	g_return_if_fail (path != NULL);
	if (!g_file_test (path, G_FILE_TEST_EXISTS)) {
		GKeyFile* kf;
		kf = g_key_file_new ();
		{
			char* _tmp0_;
			g_key_file_set_string (kf, "general", "active_theme", "Default");
			g_key_file_set_boolean (kf, "general", "in_message_window", TRUE);
			g_file_set_contents (path, _tmp0_ = g_key_file_to_data (kf, NULL, NULL), -1, &_inner_error_);
			_g_free0 (_tmp0_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_KEY_FILE_ERROR) {
					goto __catch0_g_key_file_error;
				}
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch0_g_file_error;
				}
				_g_key_file_free0 (kf);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		goto __finally0;
		__catch0_g_key_file_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("colorizer.vala:308: %s", err->message);
				_g_error_free0 (err);
			}
		}
		goto __finally0;
		__catch0_g_file_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("colorizer.vala:311: %s", err->message);
				_g_error_free0 (err);
			}
		}
		__finally0:
		if (_inner_error_ != NULL) {
			_g_key_file_free0 (kf);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_g_key_file_free0 (kf);
	}
	kf = g_key_file_new ();
	{
		gboolean _tmp1_;
		g_key_file_load_from_file (kf, path, G_KEY_FILE_NONE, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_KEY_FILE_ERROR) {
				goto __catch1_g_key_file_error;
			}
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch1_g_file_error;
			}
			_g_key_file_free0 (kf);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp1_ = g_key_file_has_key (kf, "general", "active_theme", &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_KEY_FILE_ERROR) {
				goto __catch1_g_key_file_error;
			}
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch1_g_file_error;
			}
			_g_key_file_free0 (kf);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		if (_tmp1_) {
			char* _tmp2_;
			char* _tmp3_;
			gboolean _tmp4_;
			_tmp2_ = g_key_file_get_string (kf, "general", "active_theme", &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_KEY_FILE_ERROR) {
					goto __catch1_g_key_file_error;
				}
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch1_g_file_error;
				}
				_g_key_file_free0 (kf);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			current_theme = (_tmp3_ = _tmp2_, _g_free0 (current_theme), _tmp3_);
			_tmp4_ = g_key_file_get_boolean (kf, "general", "in_message_window", &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_KEY_FILE_ERROR) {
					goto __catch1_g_key_file_error;
				}
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch1_g_file_error;
				}
				_g_key_file_free0 (kf);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			in_message_window = _tmp4_;
		}
	}
	goto __finally1;
	__catch1_g_key_file_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("colorizer.vala:325: %s", err->message);
			_g_error_free0 (err);
		}
	}
	goto __finally1;
	__catch1_g_file_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("colorizer.vala:328: %s", err->message);
			_g_error_free0 (err);
		}
	}
	__finally1:
	if (_inner_error_ != NULL) {
		_g_key_file_free0 (kf);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_key_file_free0 (kf);
}


void save_config_file (const char* path) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (path != NULL);
	if (!g_file_test (path, G_FILE_TEST_EXISTS)) {
		GKeyFile* kf;
		kf = g_key_file_new ();
		{
			char* _tmp0_;
			g_key_file_set_string (kf, "general", "active_theme", current_theme);
			g_key_file_set_boolean (kf, "general", "in_message_window", in_message_window);
			g_file_set_contents (path, _tmp0_ = g_key_file_to_data (kf, NULL, NULL), -1, &_inner_error_);
			_g_free0 (_tmp0_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_KEY_FILE_ERROR) {
					goto __catch2_g_key_file_error;
				}
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch2_g_file_error;
				}
				_g_key_file_free0 (kf);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		goto __finally2;
		__catch2_g_key_file_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("colorizer.vala:341: %s", err->message);
				_g_error_free0 (err);
			}
		}
		goto __finally2;
		__catch2_g_file_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("colorizer.vala:344: %s", err->message);
				_g_error_free0 (err);
			}
		}
		__finally2:
		if (_inner_error_ != NULL) {
			_g_key_file_free0 (kf);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_g_key_file_free0 (kf);
	}
}


void create_dir (const char* path) {
	g_return_if_fail (path != NULL);
	if (!g_file_test (path, G_FILE_TEST_EXISTS)) {
		g_mkdir_with_parents (path, 0700);
	}
}


static void _on_fg_color_changed_geany_colorizer_ui_foreground_color_changed (GeanyColorizerUI* _sender, gint color, gpointer self) {
	on_fg_color_changed (color);
}


static void _on_bg_color_changed_geany_colorizer_ui_background_color_changed (GeanyColorizerUI* _sender, gint color, gpointer self) {
	on_bg_color_changed (color);
}


static void _on_font_bold_toggled_geany_colorizer_ui_font_bold_toggled (GeanyColorizerUI* _sender, gboolean font_bold, gpointer self) {
	on_font_bold_toggled (font_bold);
}


static void _on_font_italic_toggled_geany_colorizer_ui_font_italic_toggled (GeanyColorizerUI* _sender, gboolean font_italic, gpointer self) {
	on_font_italic_toggled (font_italic);
}


static void _on_font_underline_toggled_geany_colorizer_ui_font_underline_toggled (GeanyColorizerUI* _sender, gboolean font_italic, gpointer self) {
	on_font_underline_toggled (font_italic);
}


static void _on_lexer_changed_geany_colorizer_ui_lexer_changed (GeanyColorizerUI* _sender, gint lexer_id, gpointer self) {
	on_lexer_changed (lexer_id);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _on_dialog_delete_gtk_widget_delete_event (GtkWidget* _sender, GdkEvent* event, gpointer self) {
	gboolean result;
	result = on_dialog_delete ();
	return result;
}


static void _on_dialog_response_gtk_dialog_response (GtkDialog* _sender, gint response_id, gpointer self) {
	on_dialog_response (response_id);
}


static void _on_open_toggled_gtk_check_menu_item_toggled (GtkCheckMenuItem* _sender, gpointer self) {
	on_open_toggled ();
}


void plugin_init (GeanyData* data) {
	gint* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	char* default_theme_dir;
	char* _tmp3_;
	struct GeanyDocument* doc;
	GeanyColorizerUI* _tmp4_;
	GtkComboBox* cb;
	GtkComboBox* _tmp10_;
	GtkMenuShell* menu;
	GtkMenuItem* _tmp13_;
	GtkCheckMenuItem* _tmp14_;
	g_return_if_fail (data != NULL);
	theme_data = (_tmp0_ = g_new0 (gint, (100 * 33) * 5), theme_data = (g_free (theme_data), NULL), theme_data_length1 = 100, theme_data_length2 = 33, theme_data_length3 = 5, _tmp0_);
	config_dir = (_tmp1_ = g_build_path (G_DIR_SEPARATOR_S, geany_data->app->configdir, "plugins", "colorizer", NULL), _g_free0 (config_dir), _tmp1_);
	create_dir (config_dir);
	theme_dir = (_tmp2_ = g_build_path (G_DIR_SEPARATOR_S, config_dir, "themes", NULL), _g_free0 (theme_dir), _tmp2_);
	create_dir (theme_dir);
	default_theme_dir = g_build_path (G_DIR_SEPARATOR_S, theme_dir, "Default", NULL);
	create_dir (default_theme_dir);
	config_file = (_tmp3_ = g_build_path (G_DIR_SEPARATOR_S, config_dir, "colorizer.conf", NULL), _g_free0 (config_file), _tmp3_);
	init_config_file (config_file);
	g_debug ("colorizer.vala:380: Config file: %s\n", config_file);
	doc = document_get_current ();
	if (doc != NULL) {
		sci = (ScintillaObject*) doc->editor->sci;
	}
	plugin_signal_connect (geany_plugin, NULL, "document-activate", TRUE, (GCallback) on_current_document_changed, NULL);
	plugin_signal_connect (geany_plugin, NULL, "document-open", TRUE, (GCallback) on_current_document_changed, NULL);
	plugin_signal_connect (geany_plugin, NULL, "document-new", TRUE, (GCallback) on_current_document_changed, NULL);
	ui = (_tmp4_ = g_object_ref_sink (geany_colorizer_ui_new (theme_dir)), _g_object_unref0 (ui), _tmp4_);
	g_signal_connect (ui, "foreground-color-changed", (GCallback) _on_fg_color_changed_geany_colorizer_ui_foreground_color_changed, NULL);
	g_signal_connect (ui, "background-color-changed", (GCallback) _on_bg_color_changed_geany_colorizer_ui_background_color_changed, NULL);
	g_signal_connect (ui, "font-bold-toggled", (GCallback) _on_font_bold_toggled_geany_colorizer_ui_font_bold_toggled, NULL);
	g_signal_connect (ui, "font-italic-toggled", (GCallback) _on_font_italic_toggled_geany_colorizer_ui_font_italic_toggled, NULL);
	g_signal_connect (ui, "font-underline-toggled", (GCallback) _on_font_underline_toggled_geany_colorizer_ui_font_underline_toggled, NULL);
	g_signal_connect (ui, "lexer-changed", (GCallback) _on_lexer_changed_geany_colorizer_ui_lexer_changed, NULL);
	if (in_message_window) {
		GtkScrolledWindow* _tmp5_;
		GtkNotebook* _tmp6_;
		GtkNotebook* nb;
		swin = (_tmp5_ = g_object_ref_sink ((GtkScrolledWindow*) gtk_scrolled_window_new (NULL, NULL)), _g_object_unref0 (swin), _tmp5_);
		gtk_scrolled_window_set_policy (swin, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
		gtk_scrolled_window_add_with_viewport (swin, (GtkWidget*) ui);
		nb = _g_object_ref0 ((_tmp6_ = data->main_widgets->message_window_notebook, GTK_IS_NOTEBOOK (_tmp6_) ? ((GtkNotebook*) _tmp6_) : NULL));
		if (nb != NULL) {
			GtkLabel* _tmp7_;
			gtk_notebook_append_page (nb, (GtkWidget*) swin, (GtkWidget*) (_tmp7_ = g_object_ref_sink ((GtkLabel*) gtk_label_new ("Colorizer"))));
			_g_object_unref0 (_tmp7_);
			gtk_widget_hide ((GtkWidget*) swin);
		}
		_g_object_unref0 (nb);
	} else {
		GtkDialog* _tmp8_;
		GtkBox* box;
		dialog = (_tmp8_ = g_object_ref_sink ((GtkDialog*) gtk_dialog_new_with_buttons ("Colorizer", GTK_WINDOW (geany_data->main_widgets->window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_STOCK_CLOSE, GTK_RESPONSE_ACCEPT, NULL)), _g_object_unref0 (dialog), _tmp8_);
		g_signal_connect ((GtkWidget*) dialog, "delete-event", (GCallback) _on_dialog_delete_gtk_widget_delete_event, NULL);
		g_signal_connect (dialog, "response", (GCallback) _on_dialog_response_gtk_dialog_response, NULL);
		box = _g_object_ref0 (GTK_BOX (gtk_dialog_get_content_area (dialog)));
		gtk_box_pack_start (box, (GtkWidget*) ui, TRUE, TRUE, (guint) 0);
		_g_object_unref0 (box);
	}
	cb = _g_object_ref0 (geany_colorizer_ui_get_combo_lexer (ui));
	{
		gint i;
		i = 0;
		{
			gboolean _tmp9_;
			_tmp9_ = TRUE;
			while (TRUE) {
				if (!_tmp9_) {
					i++;
				}
				_tmp9_ = FALSE;
				if (!(i < G_N_ELEMENTS (lexer_names))) {
					break;
				}
				gtk_combo_box_append_text (cb, lexer_names[i]);
			}
		}
	}
	gtk_combo_box_set_active (geany_colorizer_ui_get_combo_lexer (ui), 1);
	cb = (_tmp10_ = _g_object_ref0 (geany_colorizer_ui_get_combo_style (ui)), _g_object_unref0 (cb), _tmp10_);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp11_;
			_tmp11_ = TRUE;
			while (TRUE) {
				char* _tmp12_;
				if (!_tmp11_) {
					i++;
				}
				_tmp11_ = FALSE;
				if (!(i <= STYLE_DEFAULT)) {
					break;
				}
				gtk_combo_box_append_text (cb, _tmp12_ = g_strdup_printf ("Style #%d", i));
				_g_free0 (_tmp12_);
			}
		}
	}
	gtk_combo_box_set_active (geany_colorizer_ui_get_combo_style (ui), 0);
	menu = GTK_MENU_SHELL (geany_data->main_widgets->tools_menu);
	sep = (_tmp13_ = (GtkMenuItem*) g_object_ref_sink ((GtkSeparatorMenuItem*) gtk_separator_menu_item_new ()), _g_object_unref0 (sep), _tmp13_);
	gtk_menu_shell_append (menu, (GtkWidget*) sep);
	item = (_tmp14_ = g_object_ref_sink ((GtkCheckMenuItem*) gtk_check_menu_item_new_with_label ("Colorizer")), _g_object_unref0 (item), _tmp14_);
	g_signal_connect (item, "toggled", (GCallback) _on_open_toggled_gtk_check_menu_item_toggled, NULL);
	gtk_menu_shell_append (menu, (GtkWidget*) ((GtkMenuItem*) item));
	gtk_widget_show ((GtkWidget*) item);
	plugin_module_make_resident (geany_plugin);
	colorizing = FALSE;
	_g_object_unref0 (cb);
	_g_free0 (default_theme_dir);
}


void plugin_cleanup (void) {
	save_config_file (config_file);
	gtk_object_destroy ((GtkObject*) sep);
	gtk_object_destroy ((GtkObject*) item);
	if (dialog != NULL) {
		gtk_object_destroy ((GtkObject*) dialog);
	}
	if (swin != NULL) {
		gtk_object_destroy ((GtkObject*) swin);
	}
}




