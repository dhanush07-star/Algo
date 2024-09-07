#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Hello, GTK!\n");
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    button = gtk_button_new_with_label("Click Me");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
