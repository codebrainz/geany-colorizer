/*
 * plugin.vala
 * 
 * Copyright 2011 Matthew Brush <mbrush@leftclick.ca>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */
 
using Gtk;
using Gdk;
using Geany;
using Scintilla;

namespace Geany
{
	private static string config_dir;

	public Plugin			geany_plugin;
	public Data			geany_data;
	public Functions		geany_functions;

	private GLib.SList<unowned Gtk.Widget>  G_destroy_widget_stack;

	public void plugin_set_info (Plugin.Info info) 
	{
		info.set(
			"Colorizer"						  			/* plugin name */, 
			"Set Scintilla appearances on-the-fly."   	/* plugin desc	*/,
			"0.1"								  		/* plugin version */,
			"Matthew Brush <mbrush@leftclick.ca>" 		/* plugin author */);
	}

	public int plugin_version_check (int abi_version) 
	{
		return Plugin.version_check (abi_version, 185);
	}

	public void plugin_init (Geany.Data data)
	{
		Gtk.MenuItem item;
		unowned Gtk.MenuShell? menu;
		
		config_dir = Path.build_path(Path.DIR_SEPARATOR_S, 
										geany_data.app.configdir, 
										"plugins",
										"colorizer");
		
		menu = (Gtk.MenuShell)geany_data.main_widgets.tools_menu;
		item = new Gtk.SeparatorMenuItem();
		menu.append(item);
		item.show();
		G_destroy_widget_stack.append(item);
		item = new Gtk.CheckMenuItem.with_label("Colorizer");
		item.toggled.connect(on_open_toggled);
		menu.append(item);
		item.show();
		G_destroy_widget_stack.append(item);
		
		geany_plugin.module_make_resident();
	}

	public void plugin_cleanup ()
	{
		foreach (var w in G_destroy_widget_stack)
			w.destroy();
	}

}
