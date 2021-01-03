/* ====================================================
#   Copyright (C) 2021  All rights reserved
#
#   Author        : kato
#   Email         : 1123629751@qq.com
#   File Name     : main.c
#   Last Modified : 2021-01-03 20:43
#   Describe      : 
#
# ====================================================*/

#include <gtk/gtk.h>

GtkWidget *g_lbl_coin;


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    // builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above
    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_lbl_coin = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_coin"));

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

void on_btn_toss_clicked()
{
    gboolean result;
	
	result = g_random_boolean();
	if (result == TRUE) {
		//g_print("Heads\n");
        gtk_label_set_text(GTK_LABEL(g_lbl_coin), "Heads");
	}
	else {
		//g_print("Tails\n");
        gtk_label_set_text(GTK_LABEL(g_lbl_coin), "Tails");
	}
}
