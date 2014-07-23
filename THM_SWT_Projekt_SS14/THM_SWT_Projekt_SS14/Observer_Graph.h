#ifndef _Observer_Graph_H__
#define _Observer_Graph_H__

#include <string>
#include <gtk-3.0/gtk/gtk.h>

using namespace std;

class Observer_Graph {
public:
	virtual void update(string t_orte[], double t_val[], string t_metadaten[]);
};

#endif