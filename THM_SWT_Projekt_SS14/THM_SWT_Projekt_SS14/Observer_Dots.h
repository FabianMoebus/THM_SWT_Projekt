#ifndef _Observer_Dots_H__
#define _Observer_Dots_H__

#include "Observer_Graph.h"

class Observer_Dots : public Observer_Graph {
public:
	void update(cairo_t *cr, GtkWidget *widget, string t_orte[], double t_val[], string t_metadaten[]);
private:
	void achsen_zeichnen(cairo_t *cr, GtkWidget *widget);
	void punkte_zeichnen(cairo_t *cr, GtkWidget *widget, string *t_orte, double *t_val, string *t_metadaten);
};

#endif