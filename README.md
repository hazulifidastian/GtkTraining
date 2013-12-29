GtkTraining
===========

Gtk training from zetcode http://zetcode.com/tutorials/gtktutorial/ and others, with modification for Gtk 3 compatibility

My Requirements
===============

TDM64 bundle with GCC 4.8.1 : http://tdm-gcc.tdragon.net/

gtk+-bundle_3.6.4-20130921_win32.zip : http://win32builder.gnome.org/

Glade : http://ftp.gnome.org/pub/GNOME/binaries/win32/glade/

Compiling
=========

gcc -m32 -Wall -g -o glade glade.c `pkg-config --libs --cflags gtk+-3.0` 

or,

If using glade for ui designer, compile with this
gcc -m32 -Wall "-Wl,--export-all-symbols" -g -o glade glade.c `pkg-config --libs --cflags gtk+-3.0` 