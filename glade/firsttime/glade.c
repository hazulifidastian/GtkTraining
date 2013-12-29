// compile with: gcc -m32 -Wall "-Wl,--export-all-symbols" -g -o glade glade.c `pkg-config --libs --cflags gtk+-3.0` 
#include <gtk/gtk.h>

GtkBuilder * builder;

void on_window1_destroy( GtkWidget * widget, gpointer user_data ) {
    gtk_main_quit();
}

void on_button1_clicked( GtkWidget * widget, gpointer data ){
    
}

int main(int argc, char *argv[]) {
    
    GtkWidget * window;
    GtkWidget * glade;

    gtk_init( &argc, &argv );

    builder = gtk_builder_new ();
    gtk_builder_add_from_file( builder, "Seller.glade", NULL );

    window = GTK_WIDGET( gtk_builder_get_object (builder, "window1") );

    if (NULL == window)
    {
        /* Print out the error. You can use GLib's message logging  */
        fprintf(stderr, "Unable to file object with id \"window1\" \n");
        /* Your error handling code goes here */
    }

    gtk_builder_connect_signals ( builder, window ); 

    g_object_unref( G_OBJECT (builder) );

    glade = glade_widget_get_from_gobject(window);

    gtk_widget_show( window );       
    gtk_main();

    return 0;
}