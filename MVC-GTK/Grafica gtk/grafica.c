/*
Ejemplo GTK3

Instalar:
aptitude install libgtk-3-devel
aptitude install glade
aptitude install pkg-config

Compilar con:
gcc `pkg-config --cflags gtk+-3.0` -o grafica grafica.c `pkg-config --libs gtk+-3.0`

Ejecutar:
./grafica
*/

#include <gtk/gtk.h>

GtkBuilder      *builder;

void funcionCallbackDeBoton (GtkWidget *widget,gpointer   data)
{
  g_print ("Click en boton\n");

  GtkWidget* entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));

  const gchar* text;
  text = gtk_entry_get_text(GTK_ENTRY(entry));

  printf("%s\r\n",text);
}

void on_window_main_destroy()
{
    gtk_main_quit();
}


int main(int argc, char *argv[])
{
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "./ventana.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    GtkWidget *button;
    button = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    g_signal_connect (button, "clicked", G_CALLBACK (funcionCallbackDeBoton), NULL);

    g_signal_connect (window, "delete-event", G_CALLBACK (on_window_main_destroy), NULL);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}


