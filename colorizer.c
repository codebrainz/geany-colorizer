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
extern gint* theme_data;
extern gint theme_data_length1;
extern gint theme_data_length2;
extern gint theme_data_length3;
gint* theme_data = NULL;
gint theme_data_length1 = 0;
gint theme_data_length2 = 0;
gint theme_data_length3 = 0;
extern GtkMenuItem* sep;
GtkMenuItem* sep = NULL;
extern GtkCheckMenuItem* item;
GtkCheckMenuItem* item = NULL;
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
void init_config_file (const char* path);
void save_config_file (const char* path);
void create_dir (const char* path);
void save_theme (void);
void on_current_document_changed (GObject* ignored, struct GeanyDocument* doc);
void on_editor_notif (gint param, struct SCNotification* notif);
static void _on_editor_notif_scintilla_object_sci_notify (ScintillaObject* _sender, gint param, struct SCNotification* notif, gpointer self);
void geany_colorizer_ui_set_current_lexer (GeanyColorizerUI* self, gint value);
void geany_colorizer_ui_set_current_style (GeanyColorizerUI* self, gint value);
gint geany_colorizer_ui_get_current_lexer (GeanyColorizerUI* self);
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
void on_theme_changed (const char* theme_name);
void on_open_toggled (void);
void on_theme_save_clicked (void);
void plugin_init (GeanyData* data);
GeanyColorizerUI* geany_colorizer_ui_new (const char* themedir);
GeanyColorizerUI* geany_colorizer_ui_construct (GType object_type, const char* themedir);
static void _on_fg_color_changed_geany_colorizer_ui_foreground_color_changed (GeanyColorizerUI* _sender, gint color, gpointer self);
static void _on_bg_color_changed_geany_colorizer_ui_background_color_changed (GeanyColorizerUI* _sender, gint color, gpointer self);
static void _on_font_bold_toggled_geany_colorizer_ui_font_bold_toggled (GeanyColorizerUI* _sender, gboolean font_bold, gpointer self);
static void _on_font_italic_toggled_geany_colorizer_ui_font_italic_toggled (GeanyColorizerUI* _sender, gboolean font_italic, gpointer self);
static void _on_font_underline_toggled_geany_colorizer_ui_font_underline_toggled (GeanyColorizerUI* _sender, gboolean font_italic, gpointer self);
static void _on_lexer_changed_geany_colorizer_ui_lexer_changed (GeanyColorizerUI* _sender, gint lexer_id, gpointer self);
static void _on_theme_changed_geany_colorizer_ui_theme_changed (GeanyColorizerUI* _sender, const char* theme_name, gpointer self);
static void _on_theme_save_clicked_geany_colorizer_ui_theme_save_button_clicked (GeanyColorizerUI* _sender, gpointer self);
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
				g_warning ("colorizer.vala:92: %s", err->message);
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
				g_warning ("colorizer.vala:95: %s", err->message);
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
		}
	}
	goto __finally1;
	__catch1_g_key_file_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("colorizer.vala:108: %s", err->message);
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
			g_warning ("colorizer.vala:111: %s", err->message);
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
				g_warning ("colorizer.vala:124: %s", err->message);
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
				g_warning ("colorizer.vala:127: %s", err->message);
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


void save_theme (void) {
	char* theme_file_path;
	GError * _inner_error_ = NULL;
	theme_file_path = g_build_path (G_DIR_SEPARATOR_S, theme_dir, current_theme, NULL);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				GKeyFile* kf;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < 100)) {
					break;
				}
				kf = g_key_file_new ();
				{
					char* _tmp1_;
					char* _tmp2_;
					char* theme_lex_file;
					char* _tmp9_;
					theme_lex_file = (_tmp2_ = g_build_path (G_DIR_SEPARATOR_S, theme_file_path, _tmp1_ = g_strdup_printf ("%d.conf", i), NULL), _g_free0 (_tmp1_), _tmp2_);
					{
						gint j;
						j = 0;
						{
							gboolean _tmp3_;
							_tmp3_ = TRUE;
							while (TRUE) {
								char* _tmp4_;
								char* _tmp5_;
								char* _tmp6_;
								char* _tmp7_;
								char* _tmp8_;
								if (!_tmp3_) {
									j++;
								}
								_tmp3_ = FALSE;
								if (!(j < 33)) {
									break;
								}
								g_key_file_set_integer (kf, _tmp4_ = g_strdup_printf ("%d", j), "foreground", theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 0]);
								_g_free0 (_tmp4_);
								g_key_file_set_integer (kf, _tmp5_ = g_strdup_printf ("%d", j), "background", theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 1]);
								_g_free0 (_tmp5_);
								g_key_file_set_integer (kf, _tmp6_ = g_strdup_printf ("%d", j), "bold", theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 2]);
								_g_free0 (_tmp6_);
								g_key_file_set_integer (kf, _tmp7_ = g_strdup_printf ("%d", j), "italic", theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 3]);
								_g_free0 (_tmp7_);
								g_key_file_set_integer (kf, _tmp8_ = g_strdup_printf ("%d", j), "underline", theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 4]);
								_g_free0 (_tmp8_);
							}
						}
					}
					g_file_set_contents (theme_lex_file, _tmp9_ = g_key_file_to_data (kf, NULL, NULL), -1, &_inner_error_);
					_g_free0 (_tmp9_);
					if (_inner_error_ != NULL) {
						_g_free0 (theme_lex_file);
						if (_inner_error_->domain == G_KEY_FILE_ERROR) {
							goto __catch3_g_key_file_error;
						}
						if (_inner_error_->domain == G_FILE_ERROR) {
							goto __catch3_g_file_error;
						}
						_g_free0 (theme_lex_file);
						_g_key_file_free0 (kf);
						_g_free0 (theme_file_path);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return;
					}
					_g_free0 (theme_lex_file);
				}
				goto __finally3;
				__catch3_g_key_file_error:
				{
					GError * err;
					err = _inner_error_;
					_inner_error_ = NULL;
					{
						g_warning ("colorizer.vala:166: %s", err->message);
						_g_error_free0 (err);
					}
				}
				goto __finally3;
				__catch3_g_file_error:
				{
					GError * err;
					err = _inner_error_;
					_inner_error_ = NULL;
					{
						g_warning ("colorizer.vala:169: %s", err->message);
						_g_error_free0 (err);
					}
				}
				__finally3:
				if (_inner_error_ != NULL) {
					_g_key_file_free0 (kf);
					_g_free0 (theme_file_path);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return;
				}
				_g_key_file_free0 (kf);
			}
		}
	}
	_g_free0 (theme_file_path);
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
						theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 0] = (gint) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETFORE, (uptr_t) ((gulong) i), (sptr_t) 0);
						theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 1] = (gint) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETBACK, (uptr_t) ((gulong) i), (sptr_t) 0);
						theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 2] = (gint) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETBOLD, (uptr_t) ((gulong) i), (sptr_t) 0);
						theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 3] = (gint) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETITALIC, (uptr_t) ((gulong) i), (sptr_t) 0);
						theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 4] = (gint) scintilla_send_message (sci, (unsigned int) SCI_STYLEGETUNDERLINE, (uptr_t) ((gulong) i), (sptr_t) 0);
					}
				}
			}
			scintilla_send_message (sci, (unsigned int) SCI_SETCARETLINEVISIBLE, (uptr_t) ((gulong) 0), (sptr_t) 0);
		}
	}
}


gboolean colorize_editor (void) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	if (have_text ()) {
		_tmp0_ = !styling;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
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
				gboolean _tmp1_;
				_tmp1_ = TRUE;
				while (TRUE) {
					gint s;
					if (!_tmp1_) {
						p++;
					}
					_tmp1_ = FALSE;
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
				gboolean _tmp2_;
				_tmp2_ = TRUE;
				while (TRUE) {
					if (!_tmp2_) {
						i++;
					}
					_tmp2_ = FALSE;
					if (!(i <= STYLE_DEFAULT)) {
						break;
					}
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETFORE, (uptr_t) ((gulong) i), (sptr_t) ((glong) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 0]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETBACK, (uptr_t) ((gulong) i), (sptr_t) ((glong) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 1]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETBOLD, (uptr_t) ((gulong) i), (sptr_t) ((glong) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 2]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETITALIC, (uptr_t) ((gulong) i), (sptr_t) ((glong) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 3]));
					scintilla_send_message (sci, (unsigned int) SCI_STYLESETUNDERLINE, (uptr_t) ((gulong) i), (sptr_t) ((glong) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 4]));
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
			geany_colorizer_ui_set_current_foreground_color (ui, theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 0]);
			geany_colorizer_ui_set_current_background_color (ui, theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 1]);
			geany_colorizer_ui_set_font_bold (ui, (gboolean) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 2]);
			geany_colorizer_ui_set_font_italic (ui, (gboolean) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 3]);
			geany_colorizer_ui_set_font_underline (ui, (gboolean) theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 4]);
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
		theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 0] = new_color;
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
						theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + i) * theme_data_length3) + 1] = new_color;
						scintilla_send_message (sci, (unsigned int) SCI_STYLESETBACK, (uptr_t) ((gulong) i), (sptr_t) ((glong) new_color));
					}
				}
			}
		} else {
			theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 1] = new_color;
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
		theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 2] = (gint) font_bold;
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
		theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 3] = (gint) font_italic;
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
		theme_data[(((geany_colorizer_ui_get_current_lexer (ui) * theme_data_length2) + geany_colorizer_ui_get_current_style (ui)) * theme_data_length3) + 4] = (gint) font_underline;
		scintilla_send_message (sci, (unsigned int) SCI_STYLESETUNDERLINE, (uptr_t) ((gulong) geany_colorizer_ui_get_current_style (ui)), (sptr_t) ((glong) font_underline));
	}
}


void on_lexer_changed (gint lexer) {
	g_debug ("colorizer.vala:322: Lexer changed to %d", lexer);
}


void on_theme_changed (const char* theme_name) {
	char* _tmp0_;
	g_return_if_fail (theme_name != NULL);
	current_theme = (_tmp0_ = g_strdup (theme_name), _g_free0 (current_theme), _tmp0_);
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
		g_debug ("colorizer.vala:344: Colorizing started");
		gtk_widget_show_all ((GtkWidget*) swin);
		on_current_document_changed ((GObject*) ui, document_get_current ());
	} else {
		colorizing = FALSE;
		g_debug ("colorizer.vala:350: Colorizing ended");
		gtk_widget_hide ((GtkWidget*) swin);
	}
}


void on_theme_save_clicked (void) {
	save_theme ();
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


static void _on_theme_changed_geany_colorizer_ui_theme_changed (GeanyColorizerUI* _sender, const char* theme_name, gpointer self) {
	on_theme_changed (theme_name);
}


static void _on_theme_save_clicked_geany_colorizer_ui_theme_save_button_clicked (GeanyColorizerUI* _sender, gpointer self) {
	on_theme_save_clicked ();
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _on_open_toggled_gtk_check_menu_item_toggled (GtkCheckMenuItem* _sender, gpointer self) {
	on_open_toggled ();
}


void plugin_init (GeanyData* data) {
	gint* _tmp0_;
	char* _tmp3_;
	char* _tmp4_;
	char* default_theme_dir;
	char* _tmp5_;
	struct GeanyDocument* doc;
	GeanyColorizerUI* _tmp6_;
	GtkScrolledWindow* _tmp7_;
	GtkNotebook* _tmp8_;
	GtkNotebook* nb;
	GtkComboBox* cb;
	GtkComboBox* _tmp11_;
	GtkMenuShell* menu;
	GtkMenuItem* _tmp14_;
	GtkCheckMenuItem* _tmp15_;
	g_return_if_fail (data != NULL);
	theme_data = (_tmp0_ = g_new0 (gint, (100 * 33) * 5), theme_data = (g_free (theme_data), NULL), theme_data_length1 = 100, theme_data_length2 = 33, theme_data_length3 = 5, _tmp0_);
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
				if (!(i < 100)) {
					break;
				}
				{
					gint j;
					j = 0;
					{
						gboolean _tmp2_;
						_tmp2_ = TRUE;
						while (TRUE) {
							if (!_tmp2_) {
								j++;
							}
							_tmp2_ = FALSE;
							if (!(j < 33)) {
								break;
							}
							theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 0] = 0x000000;
							theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 1] = 0xffffff;
							theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 2] = 0;
							theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 3] = 0;
							theme_data[(((i * theme_data_length2) + j) * theme_data_length3) + 4] = 0;
						}
					}
				}
			}
		}
	}
	config_dir = (_tmp3_ = g_build_path (G_DIR_SEPARATOR_S, geany_data->app->configdir, "plugins", "colorizer", NULL), _g_free0 (config_dir), _tmp3_);
	create_dir (config_dir);
	theme_dir = (_tmp4_ = g_build_path (G_DIR_SEPARATOR_S, config_dir, "themes", NULL), _g_free0 (theme_dir), _tmp4_);
	create_dir (theme_dir);
	default_theme_dir = g_build_path (G_DIR_SEPARATOR_S, theme_dir, "Default", NULL);
	create_dir (default_theme_dir);
	config_file = (_tmp5_ = g_build_path (G_DIR_SEPARATOR_S, config_dir, "colorizer.conf", NULL), _g_free0 (config_file), _tmp5_);
	init_config_file (config_file);
	g_debug ("colorizer.vala:397: Config file: %s\n", config_file);
	doc = document_get_current ();
	if (doc != NULL) {
		sci = (ScintillaObject*) doc->editor->sci;
	}
	plugin_signal_connect (geany_plugin, NULL, "document-activate", TRUE, (GCallback) on_current_document_changed, NULL);
	plugin_signal_connect (geany_plugin, NULL, "document-open", TRUE, (GCallback) on_current_document_changed, NULL);
	plugin_signal_connect (geany_plugin, NULL, "document-new", TRUE, (GCallback) on_current_document_changed, NULL);
	ui = (_tmp6_ = g_object_ref_sink (geany_colorizer_ui_new (theme_dir)), _g_object_unref0 (ui), _tmp6_);
	g_signal_connect (ui, "foreground-color-changed", (GCallback) _on_fg_color_changed_geany_colorizer_ui_foreground_color_changed, NULL);
	g_signal_connect (ui, "background-color-changed", (GCallback) _on_bg_color_changed_geany_colorizer_ui_background_color_changed, NULL);
	g_signal_connect (ui, "font-bold-toggled", (GCallback) _on_font_bold_toggled_geany_colorizer_ui_font_bold_toggled, NULL);
	g_signal_connect (ui, "font-italic-toggled", (GCallback) _on_font_italic_toggled_geany_colorizer_ui_font_italic_toggled, NULL);
	g_signal_connect (ui, "font-underline-toggled", (GCallback) _on_font_underline_toggled_geany_colorizer_ui_font_underline_toggled, NULL);
	g_signal_connect (ui, "lexer-changed", (GCallback) _on_lexer_changed_geany_colorizer_ui_lexer_changed, NULL);
	g_signal_connect (ui, "theme-changed", (GCallback) _on_theme_changed_geany_colorizer_ui_theme_changed, NULL);
	g_signal_connect (ui, "theme-save-button-clicked", (GCallback) _on_theme_save_clicked_geany_colorizer_ui_theme_save_button_clicked, NULL);
	swin = (_tmp7_ = g_object_ref_sink ((GtkScrolledWindow*) gtk_scrolled_window_new (NULL, NULL)), _g_object_unref0 (swin), _tmp7_);
	gtk_scrolled_window_set_policy (swin, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_scrolled_window_add_with_viewport (swin, (GtkWidget*) ui);
	nb = _g_object_ref0 ((_tmp8_ = data->main_widgets->message_window_notebook, GTK_IS_NOTEBOOK (_tmp8_) ? ((GtkNotebook*) _tmp8_) : NULL));
	if (nb != NULL) {
		GtkLabel* _tmp9_;
		gtk_notebook_append_page (nb, (GtkWidget*) swin, (GtkWidget*) (_tmp9_ = g_object_ref_sink ((GtkLabel*) gtk_label_new ("Colorizer"))));
		_g_object_unref0 (_tmp9_);
		gtk_widget_hide ((GtkWidget*) swin);
	}
	cb = _g_object_ref0 (geany_colorizer_ui_get_combo_lexer (ui));
	{
		gint i;
		i = 0;
		{
			gboolean _tmp10_;
			_tmp10_ = TRUE;
			while (TRUE) {
				if (!_tmp10_) {
					i++;
				}
				_tmp10_ = FALSE;
				if (!(i < G_N_ELEMENTS (lexer_names))) {
					break;
				}
				gtk_combo_box_append_text (cb, lexer_names[i]);
			}
		}
	}
	gtk_combo_box_set_active (geany_colorizer_ui_get_combo_lexer (ui), 1);
	cb = (_tmp11_ = _g_object_ref0 (geany_colorizer_ui_get_combo_style (ui)), _g_object_unref0 (cb), _tmp11_);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp12_;
			_tmp12_ = TRUE;
			while (TRUE) {
				char* _tmp13_;
				if (!_tmp12_) {
					i++;
				}
				_tmp12_ = FALSE;
				if (!(i <= STYLE_DEFAULT)) {
					break;
				}
				gtk_combo_box_append_text (cb, _tmp13_ = g_strdup_printf ("Style #%d", i));
				_g_free0 (_tmp13_);
			}
		}
	}
	gtk_combo_box_set_active (geany_colorizer_ui_get_combo_style (ui), 0);
	menu = GTK_MENU_SHELL (geany_data->main_widgets->tools_menu);
	sep = (_tmp14_ = (GtkMenuItem*) g_object_ref_sink ((GtkSeparatorMenuItem*) gtk_separator_menu_item_new ()), _g_object_unref0 (sep), _tmp14_);
	gtk_menu_shell_append (menu, (GtkWidget*) sep);
	item = (_tmp15_ = g_object_ref_sink ((GtkCheckMenuItem*) gtk_check_menu_item_new_with_label ("Colorizer")), _g_object_unref0 (item), _tmp15_);
	g_signal_connect (item, "toggled", (GCallback) _on_open_toggled_gtk_check_menu_item_toggled, NULL);
	gtk_menu_shell_append (menu, (GtkWidget*) ((GtkMenuItem*) item));
	gtk_widget_show ((GtkWidget*) item);
	plugin_module_make_resident (geany_plugin);
	colorizing = FALSE;
	_g_object_unref0 (cb);
	_g_object_unref0 (nb);
	_g_free0 (default_theme_dir);
}


void plugin_cleanup (void) {
	save_config_file (config_file);
	gtk_object_destroy ((GtkObject*) sep);
	gtk_object_destroy ((GtkObject*) item);
	gtk_object_destroy ((GtkObject*) swin);
}




