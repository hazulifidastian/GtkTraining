#include <gtk/gtk.h>

int main( int argc, char * argv[] ) {
    GtkWidget * window;
    GtkWidget * table;

    GtkWidget * frame1;
    GtkWidget * frame2;
    GtkWidget * frame3;
    GtkWidget * frame4;

    gtk_init( &argc, &argv );

    window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER );
    gtk_window_set_default_size( GTK_WINDOW(window), 250, 250 );
    gtk_window_set_title( GTK_WINDOW(window), "GtkFrame" );

    gtk_container_set_border_width( GTK_CONTAINER(window), 10 );

    table = gtk_grid_new();
    gtk_grid_set_row_spacing( GTK_GRID(table), 10 );
    gtk_grid_set_column_spacing( GTK_GRID(table), 10 );
    gtk_container_add( GTK_CONTAINER(window), table );

    frame1 = gtk_frame_new( "Shadow In" );
    gtk_frame_set_shadow_type( GTK_FRAME(frame1), GTK_SHADOW_IN );
    gtk_widget_set_size_request( frame1, 50, 75 );
    frame2 = gtk_frame_new( "Shadow Out" );
    gtk_frame_set_shadow_type( GTK_FRAME(frame2), GTK_SHADOW_OUT );
    gtk_widget_set_size_request( frame2, 50, 75 );
    frame3 = gtk_frame_new( "Shadow Etched In" );
    gtk_frame_set_shadow_type( GTK_FRAME(frame3), GTK_SHADOW_ETCHED_IN );
    gtk_widget_set_size_request( frame3, 50, 75 );
    frame4 = gtk_frame_new( "Shadow Etched Out" );
    gtk_frame_set_shadow_type( GTK_FRAME(frame4), GTK_SHADOW_ETCHED_OUT );
    gtk_widget_set_size_request( frame4, 50, 75 );

    gtk_grid_attach( GTK_GRID(table), frame1, 0, 0, 1, 1 );
    gtk_grid_attach( GTK_GRID(table), frame2, 1, 0, 1, 1 );
    gtk_grid_attach( GTK_GRID(table), frame3, 0, 1, 1, 1 );
    gtk_grid_attach( GTK_GRID(table), frame4, 1, 1, 1, 1 );

    g_signal_connect_swapped( G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window) );

    gtk_widget_show_all( window );
    gtk_main();
    return 0;
}