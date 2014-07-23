#include "Observer_Balken.h"

void Observer_Balken::update(cairo_t *cr, GtkWidget *widget, string t_orte[], double t_val[], string t_metadaten[]) {
	achsen_zeichnen(cr, widget);
	punkte_zeichnen(cr, widget, t_orte, t_val, t_metadaten);
}

void Observer_Balken::achsen_zeichnen(cairo_t *cr, GtkWidget *widget) {
	//Y-Achse
	cairo_move_to(cr, 320, 20);  
	cairo_line_to(cr, 320, 220);
	cairo_stroke(cr); 
	//X-Achse
	cairo_move_to(cr, 320, 220);  
	cairo_line_to(cr, 520, 220);
	cairo_stroke(cr); 

	//Stufungen Gradanzeige
	//25
	cairo_move_to(cr, 315, 170);  
	cairo_line_to(cr, 320, 170);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,295,174);
	cairo_show_text (cr, "25");

	//50
	cairo_move_to(cr, 315, 120);  
	cairo_line_to(cr, 320, 120);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,295,124);
	cairo_show_text (cr, "50");

	cairo_move_to(cr, 315, 70);  
	cairo_line_to(cr, 320, 70);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,295,74);
	cairo_show_text (cr, "75");

	//100
	cairo_move_to(cr, 315, 20);  
	cairo_line_to(cr, 320, 20);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,295,24);
	cairo_show_text (cr, "100");
}

void Observer_Balken::punkte_zeichnen(cairo_t *cr, GtkWidget *widget, string *t_orte, double *t_val, string *t_metadaten) {
	int d = 25; //X-Achsen Abstand zwischen den Punkten
	int x = 350;

	//Punkte zeichnen
	for (int i = 0; i < 6; i++)
	{
		
		double temp_Y_value = (t_val[i])*2; //Mit 2 Multipliziert, da die Anzeigeskala den Größenfaktor 2 hat
		double temp_Y_next_value = (t_val[i+1])*2;//Nächster Y-Punkt um eine Verbindung zu zeichnen

		cairo_rectangle(cr,x,220-temp_Y_value,15,temp_Y_value);
		cairo_set_source_rgba (cr, 1, 0, 0, 0.80);
		cairo_fill (cr);

		x=x+d; //Abstand zwischen den Punkten

	}
}
