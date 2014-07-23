#include <list>
#include <iostream>
#include "Controller.h"
#include "Observer_Balken.h"
#include "Observer_Dots.h"
#include "Observer_Text.h"

using namespace std;

GtkWidget *window;
GtkWidget *button_quit;
GtkWidget *frame;

Controller controller;

static void do_drawing(cairo_t *, GtkWidget *);
gboolean update_gui (gpointer data);


static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
							  gpointer user_data)
{
	//Variablen übergeben
	controller.subject.cr_ = cr;
	controller.subject.widget_ = widget;
	controller.subject.data = user_data;

	//Funktion zum zeichnen aufrufen
	do_drawing(cr, widget);

	return FALSE;
}

static void do_drawing(cairo_t *cr, GtkWidget *widget) {
	//Werte übergeben
	controller.subject.cr_ = cr;
	controller.subject.widget_ = widget;
	controller.run("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt");

	//Cairo Anzeige updaten
	gtk_widget_queue_draw(widget);
}


gboolean update_gui (gpointer data)
{
	//Updaten von Temperaturdaten und Anzeige
	controller.run("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt");
	do_drawing(controller.subject.cr_, controller.subject.widget_);

	return TRUE;
}



int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv);

	// Observer anhängen
	controller.subject.attach_observer(new Observer_Balken());
	controller.subject.attach_observer(new Observer_Dots());
	controller.subject.attach_observer(new Observer_Text());

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//Fensteranzeigename, -position und -groesse
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 810, 290); 
	gtk_window_set_title(GTK_WINDOW(window), "Wetterstation Friedberg - Projektaufgabe");

	frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), frame);

	/*Einen Button erstellen*/
	button_quit = gtk_button_new_with_label("Close");
	gtk_widget_set_size_request(button_quit, 80, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_quit, 710, 240);


	gtk_widget_show_all(window);

	g_signal_connect(window, "destroy",
		G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect(button_quit, "clicked", 
		G_CALLBACK(gtk_main_quit), NULL);

	g_signal_connect(G_OBJECT(frame), "draw", 
		G_CALLBACK(on_draw_event), NULL);

	g_timeout_add(10000,
		update_gui,
		NULL);
	
	gtk_main();

	return 0;
}


