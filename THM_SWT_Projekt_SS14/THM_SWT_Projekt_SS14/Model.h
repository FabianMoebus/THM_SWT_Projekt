#pragma once 
#include <string>
#include <list>
#include "Observer_Graph.h"
#include "HTTPDownloader.h"

using namespace std;

class Model {
private:
	// Variablen 
	list<Observer_Graph *>observer_list;
	HTTPDownloader httpdownloader;
	// Methoden
	void notify();
	void clear_string(char arg[], int length);
public:
	// Variablen
	string t_orte[6];
	double t_val[6];
	string t_metadaten[2];
	GtkWidget *widget_;
	cairo_t *cr_;
	gpointer data;
	// Methoden
	void do_update(string url);		
	void attach_observer(Observer_Graph *observer);
};