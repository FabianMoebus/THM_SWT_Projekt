#include "Observer_Dots.h"

void Observer_Dots::update(cairo_t *cr, GtkWidget *widget, string t_orte[], double t_val[], string t_metadaten[]) {

	achsen_zeichnen(cr, widget);
	punkte_zeichnen(cr, widget, t_orte, t_val, t_metadaten);
}

void Observer_Dots::achsen_zeichnen(cairo_t *cr, GtkWidget *widget) {
	//cairo_set_source_rgba (cr, 0, 0, 0, 1.0);
	//Y-Achse
	cairo_move_to(cr, 40, 20);  
	cairo_line_to(cr, 40, 220);
	cairo_stroke(cr); 
	//X-Achse
	cairo_move_to(cr, 40, 220);  
	cairo_line_to(cr, 240, 220);
	cairo_stroke(cr);

	//Stufungen Gradanzeige
	//25
	cairo_move_to(cr, 35, 170);  
	cairo_line_to(cr, 40, 170);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,15,174);
	cairo_show_text (cr, "25");

	//50
	cairo_move_to(cr, 35, 120);  
	cairo_line_to(cr, 40, 120);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,15,124);
	cairo_show_text (cr, "50");

	//75
	cairo_move_to(cr, 35, 70);  
	cairo_line_to(cr, 40, 70);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,15,74);
	cairo_show_text (cr, "75");

	//100
	cairo_move_to(cr, 35, 20);  
	cairo_line_to(cr, 40, 20);
	cairo_stroke(cr);
	//Grad anzeigen
	cairo_set_font_size (cr, 10.0);
	cairo_move_to(cr,15,24);
	cairo_show_text (cr, "100");
}

void Observer_Dots::punkte_zeichnen(cairo_t *cr, GtkWidget *widget, string *t_orte, double *t_val, string *t_metadaten) {
	int d = 30; //X-Achsen Abstand zwischen den Punkten
	int x = 70;
	int y = 235;

	//Punkte zeichnen
	for (int i = 0; i < 6; i++) {
		cairo_set_source_rgba (cr, 0, 0, 0, 1.0);

		double temp_Y_value = (t_val[i])*2; //Mit 2 Multipliziert, da die Anzeigeskala den Größenfaktor 2 hat
		double temp_Y_next_value = (t_val[i+1])*2;//Nächster Y-Punkt um eine Verbindung zu zeichnen

		cairo_rectangle(cr,x,220-temp_Y_value,-2,-2);
		cairo_stroke(cr);

		//Linien Zeichnen
		
		if(i<5) { //Letzter Strich wird niht gezeichnet
			cairo_set_source_rgba (cr, 0, 0, 0, 0.4);
			cairo_move_to(cr, x, 220-temp_Y_value);  
			cairo_line_to(cr, x+d, 220-temp_Y_next_value);
			cairo_stroke(cr);
		}

	//Ort anzeigen
	cairo_set_source_rgba (cr, 0, 0, 0, 1.0);
	cairo_set_font_size (cr, 14.0);
	cairo_move_to(cr,x-4,240);
	cairo_show_text (cr, to_string(i+1).c_str());

	x=x+d; //Abstand zwischen den Punkten
	}
}
