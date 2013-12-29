/* compile with gcc -m32 -Wall "-Wl,--export-all-symbols" -g -o dialog dialog.c `pkg-config --libs --cflags gtk+-3.0 */
#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct _Data Data;

struct _Data
{
    GtkWidget * dialog1;
    GtkWidget * aboutdialog1;
    GtkWidget * button_about;
    GtkWidget * button_hider;
    GtkWidget * entry_leftopr;
    GtkWidget * entry_rightopr;
    GtkWidget * entry_result;
};

gboolean on_window1_delete_event ( GtkWidget * window, GdkEvent * event, 
    Data * data ) {
    gint response = 1;

    /* Run dialog */
    response = gtk_dialog_run( GTK_DIALOG(data->dialog1) );
    gtk_widget_hide( data->dialog1 );

    return( 1 != response );
}

void on_button_about_clicked( GtkButton * button, Data * data ) {
    /* Run dialog */
    gtk_dialog_run( GTK_DIALOG( data->aboutdialog1 ) );
    gtk_widget_hide( data->aboutdialog1 );
}

void on_button_hider_clicked( GtkButton * button, Data * data ) {
    gtk_entry_set_text( GTK_ENTRY(data->entry_leftopr), "" );
    gtk_entry_set_text( GTK_ENTRY(data->entry_rightopr), "" );
    gtk_entry_set_text( GTK_ENTRY(data->entry_result), "" );
}

void on_button_multiply_clicked( GtkButton * button, Data * data ) {
    char buff[125];
    const gchar * entry_leftopr = gtk_entry_get_text( GTK_ENTRY(data->entry_leftopr) );
    const gchar * entry_rightopr = gtk_entry_get_text( GTK_ENTRY(data->entry_rightopr) );
    
    sprintf( buff, "%d", atoi(entry_leftopr) * atoi(entry_rightopr) );
    gtk_entry_set_text( GTK_ENTRY(data->entry_result), buff );
}

void on_button_add_clicked( GtkButton * button, Data * data ) {
    char buff[125];
    const gchar * entry_leftopr = gtk_entry_get_text( GTK_ENTRY(data->entry_leftopr) );
    const gchar * entry_rightopr = gtk_entry_get_text( GTK_ENTRY(data->entry_rightopr) );

    sprintf( buff, "%d", atoi(entry_leftopr) + atoi(entry_rightopr) );
    gtk_entry_set_text( GTK_ENTRY(data->entry_result), buff );
}

void on_window1_destroy( GtkWidget * widget, gpointer user_data ) {
    gtk_main_quit();
}

int main( int argc, char * argv[] ) {
    GtkBuilder * builder;
    GtkWidget  * window;
    Data data;

    gtk_init( &argc, &argv );

    /* Create builder and load interface */
    builder = gtk_builder_new();
    gtk_builder_add_from_file( builder, "dialog.glade", NULL );

    /* Obtain widgets that we need */
    window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );
    data.dialog1 = GTK_WIDGET( gtk_builder_get_object( builder, "dialog1" ) );
    data.aboutdialog1 = GTK_WIDGET( gtk_builder_get_object( builder, "aboutdialog1" ) );
    data.button_about = GTK_WIDGET( gtk_builder_get_object( builder, "button_about" ) );
    data.button_hider = GTK_WIDGET( gtk_builder_get_object( builder, "button_hider" ) );
    data.entry_leftopr = GTK_WIDGET( gtk_builder_get_object( builder, "entry_leftopr" ) );
    data.entry_rightopr = GTK_WIDGET( gtk_builder_get_object( builder, "entry_rightopr" ) );
    data.entry_result = GTK_WIDGET( gtk_builder_get_object( builder, "entry_result" ) );

    /* Connect callbacks */
    gtk_builder_connect_signals( builder, &data );

    /* Destroy builder */
    g_object_unref( G_OBJECT( builder ) );

    /* Show main window and start main loop */
    gtk_widget_show( window );
    gtk_main();

    return( 0 );
}