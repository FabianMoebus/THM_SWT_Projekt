#include "Observer_Dots.h"

void Observer_Dots::update(cairo_t *cr, GtkWidget *widget, string t_orte[], double t_val[], string t_metadaten[]) {

	achsen_zeichnen(cr, widget);
	punkte_zeichnen(cr, widget, t_orte, t_val, t_metadaten);
}

void Observer_Dots::achsen_zeichnen(cairo_t *cr, GtkWidget *widget) {
	//Y-Achse
	cairo_move_to(cr, 20, 20);  
	cairo_line_to(cr, 20, 220);
	cairo_stroke(cr); 
	//X-Achse
	cairo_move_to(cr, 20, 220);  
	cairo_line_to(cr, 220, 220);
	cairo_stroke(cr);

	//Stufungen Gradanzeige
	//25
	cairo_move_to(cr, 15, 170);  
	cairo_line_to(cr, 20, 170);
	cairo_stroke(cr);
	//50
	cairo_move_to(cr, 15, 120);  
	cairo_line_to(cr, 20, 120);
	cairo_stroke(cr);
	//75
	cairo_move_to(cr, 15, 70);  
	cairo_line_to(cr, 20, 70);
	cairo_stroke(cr);
	//100
	cairo_move_to(cr, 15, 20);  
	cairo_line_to(cr, 20, 20);
	cairo_stroke(cr);
}

void Observer_Dots::punkte_zeichnen(cairo_t *cr, GtkWidget *widget, string *t_orte, double *t_val, string *t_metadaten) {
	int d = 30; //X-Achsen Abstand zwischen den Punkten
	int x = 50;
	int y = 20;

	//Punkte zeichnen
	for (int i = 0; i < 12; i++)
	{
		i++;
		double temp_Y_value = (t_val[i])*2; //Mit 2 Multipliziert, da die Anzeigeskala den Größenfaktor 2 hat
		double temp_Y_next_value = (t_val[i+1])*2;//Nächster Y-Punkt um eine Verbindung zu zeichnen

		cairo_rectangle(cr,x,220-temp_Y_value,-2,-2);
		cairo_stroke(cr);

		//Linien Zeichnen
		if(i<10) { //Letzter Strich wird niht gezeichnet
			cairo_move_to(cr, x, 220-temp_Y_value);  
			cairo_line_to(cr, x+d, 220-temp_Y_next_value);
			cairo_stroke(cr);
		}

		x=x+d; //Abstand zwischen den Punkten

	}
}
