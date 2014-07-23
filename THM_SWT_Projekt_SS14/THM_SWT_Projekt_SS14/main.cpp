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
GtkWidget *progress_bar;

GtkWidget *widget_;
cairo_t *cr_;

Observer_Balken *balken;
Observer_Dots *dots;
Observer_Text *text;

Controller controller;


static void do_drawing(cairo_t *, GtkWidget *);
static void draw(cairo_t *cr, GtkWidget *widget);




void quit(GtkWidget *widget, gpointer label)
{
	gtk_main_quit();
}

void draw(cairo_t *cr, GtkWidget *widget)
{

}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
							  gpointer user_data)
{
	cr_ = cr;
	widget_ = widget;

	//Funktion zum zeichnen aufrufen
	do_drawing(cr, widget);

	return FALSE;
}

static void do_drawing(cairo_t *cr, GtkWidget *widget) {


	//Cairo Anzeige updaten
	gtk_widget_queue_draw(widget);
}


gboolean update_gui (gpointer data)
{
	//Hier müssen die Tem. Werte übergeben werden
	dots->update(cr_,widget_,controller.subject.t_orte, controller.subject.t_val, controller.subject.t_metadaten);
	balken->update(cr_,widget_,controller.subject.t_orte, controller.subject.t_val, controller.subject.t_metadaten);
	text->update(cr_,widget_,controller.subject.t_orte, controller.subject.t_val, controller.subject.t_metadaten);
	/* Return true so the function will be called again; returning false removes
	* this timeout function.
	*/
	return TRUE;
}



int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv);

	// Observer anhängen
	controller.subject.attach_observer(new Observer_Balken());
	controller.subject.attach_observer(new Observer_Dots());
	controller.subject.attach_observer(new Observer_Text());
	// run
	controller.run("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt");
	//controller.subject.gui_show();

	text = new Observer_Text();
	balken = new Observer_Balken();
	dots = new Observer_Dots();


	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//Fensteranzeigename, -position und -groesse
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 850, 270); 
	gtk_window_set_title(GTK_WINDOW(window), "Wetterstation Friedberg - Projektaufgabe");

	frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), frame);

	/*Einen Button erstellen*/
	button_quit = gtk_button_new_with_label("Quit");
	gtk_widget_set_size_request(button_quit, 80, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_quit, 50, 20);


	gtk_widget_show_all(window);

	g_signal_connect(window, "destroy",
		G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect(button_quit, "clicked", 
		G_CALLBACK(quit), NULL);

	g_signal_connect(G_OBJECT(frame), "draw", 
		G_CALLBACK(on_draw_event), NULL);

	g_timeout_add (10000,
		update_gui,
		NULL);


	gtk_main();


	return 0;
}


