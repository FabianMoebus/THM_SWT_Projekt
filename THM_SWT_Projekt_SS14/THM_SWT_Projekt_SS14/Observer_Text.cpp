#include "Observer_Text.h" 

void Observer_Text::update(cairo_t *cr, GtkWidget *widget, string t_orte[], double t_val[], string t_metadaten[]) {
	int d = 30;
	for (int i = 0; i < 12; i++)
	{
		//Wetterdaten Ort-Label
		cairo_set_font_size (cr, 14.0);
		cairo_move_to(cr,620,d);
		cairo_show_text (cr, t_orte[i].c_str());

		////Wetterdaten Temperatur-Label
		cairo_set_font_size (cr, 14.0);
		cairo_move_to(cr,720,d);
		//cairo_show_text (cr, t_val[i].c_str();
		d= d+38; //Absatz für nächsten Eintrag
	}
}
