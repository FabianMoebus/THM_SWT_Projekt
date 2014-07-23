#include "Observer_Text.h" 

void Observer_Text::update(cairo_t *cr, GtkWidget *widget, string t_orte[], double t_val[], string t_metadaten[]) {
	int d = 30;

	for (int i = 0; i < 6; i++)
	{
		
		cairo_set_source_rgba (cr, 0, 0, 0, 1.0); //Farbe setzen

		//Wetterdaten Ort-Label
		cairo_set_font_size (cr, 14.0);
		cairo_move_to(cr,600,d);
		cairo_show_text (cr, t_orte[i].c_str());

		//Wetterdaten Temperatur-Label
		cairo_set_font_size (cr, 14.0);
		cairo_move_to(cr,700,d);
		cairo_show_text(cr,to_string(t_val[i]).c_str());
		d= d+33; //Absatz für nächsten Eintrag
	}
	d = d+35;
	//metadaten anzeigen
	cairo_set_source_rgba (cr, 0, 0, 0, 0.8);
	cairo_set_font_size (cr, 14.0);
	cairo_move_to(cr,-8,270);
	cairo_show_text (cr, t_metadaten[0].c_str());
}
