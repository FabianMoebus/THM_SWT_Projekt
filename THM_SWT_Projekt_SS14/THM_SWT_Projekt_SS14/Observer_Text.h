#ifndef _Observer_Text_H__
#define _Observer_Text_H__

#include "Observer_Graph.h"

class Observer_Text : public Observer_Graph {
public:
	void update(cairo_t *cr, GtkWidget *widget, string t_orte[], double t_val[], string t_metadaten[]);
};

#endif