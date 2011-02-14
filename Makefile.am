ACLOCAL_AMFLAGS = -I m4

VALAFLAGS = --vapidir vapi \
				--pkg gtk+-2.0 \
				--pkg gio-2.0 \
				--pkg scintilla \
				--pkg geany

geanypluginsdir = $(libdir)/geany
geanyplugins_LTLIBRARIES = colorizer.la
colorizer_la_LDFLAGS = -module -avoid-version -shared
colorizer_la_CPPFLAGS = @GTK_CFLAGS@ @GIO_CFLAGS@ @GEANY_CFLAGS@ 
colorizer_la_LIBADD = @GTK_LIBS@ @GIO_LIBS@ @GEANY_LIBS@
colorizer_la_SOURCES = colorizer.vala colorizerui.vala
