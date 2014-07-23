#include "Model.h"
#include <iostream>

void Model::do_update(string url) {
	// HTTP-Downloader
	string str;					// String der kompletten .txt Datei
	string t_daten[12];			// String-Array mit Temperatur und Orte (Orte und Temperaturwerte noch nicht getrennt)
	char tmp_str[50];			// temporäre String-Variable

	str = httpdownloader.download(url);

	int zaehler = 0;
	int j = 0;
	int b_hash = 0;

	clear_string(tmp_str, 50);

	// Output-String parsen und in arr speichern
	for(size_t i = 0; i < str.length(); i++) {

		/* Wenn Zeile mit # beginnt, nachfolgenden String speichern */
		if (str[i] == '#') {
			b_hash++;
			j = 0;
		}

		/* Erste Zeile mit # einlesen und speichern */
		if (b_hash == 1) {
			tmp_str[j] = str[i];
			j++;
			if (str[i] == '\n') {
				t_metadaten[0] = tmp_str;
				clear_string(tmp_str, 50);
				j = 0;
			}
		}

		/* Zweite Zeile mit # einlesen und speichern */
		if (b_hash == 2) {
			tmp_str[j] = str[i];
			j++;
			if (str[i] == '\n') {
				t_metadaten[1] = tmp_str;
				clear_string(tmp_str, 50);
				j = 0;
				b_hash = 0;
				continue;
			}
		}

		/* Ort und Temperatur zeilenweise einlesen */
		if (b_hash == 0) {
			if ((str[i] != ',') && (str[i] != '\n')) {
				if (str[i] == ' ') {
					continue;
				} else {
					tmp_str[j] = str[i];
					j++;
				}
			} else {
				t_daten[zaehler] = tmp_str;
				clear_string(tmp_str, 50);
				zaehler++;
				j = 0;
			}
		}
	}


	int z = 0;
	int y = 0;

	/* Orte und Temperatur den jeweiligen Arrays zuweisen 
	 * Orte ==> t_orte[]
	 * Temperaturdaten ==> t_val[]
	 */
	for (int i = 0; i < 12; i++) {
		if ((i % 2) != 0) {
			/* Temperaturwerte zuweisen */
			t_val[z] = atof(t_daten[i].c_str());
			z++;
		} else {
			/* Orte zuweisen */
			t_orte[y] = t_daten[i];
			y++;
		}
	}

	// Observer benachrichtigen
	notify();
}


void Model::attach_observer(Observer_Graph *observer) {
	// neuen Observer am Ende der Liste hinzufügen
	observer_list.push_back(observer);
}

void Model::notify() {
	std::list<Observer_Graph*>::iterator iter;
    iter = observer_list.begin();
    
    while (iter != observer_list.end()) {
		(*iter)->update(t_orte, t_val, t_metadaten);
        iter++;
    }
}

void Model::clear_string(char arg[], int length) {
	for(int i = 0; i < length; i++) {
		arg[i] = '\0';
	}
}

//void quit(GtkWidget *widget, gpointer label)
//{
//	gtk_main_quit();
//}

//gboolean Model::update_progress_bar (gpointer data)
//{

  /* Return true so the function will be called again; returning false removes
   * this timeout function.
   */
  //return TRUE;
//}

//gboolean (Model::*pmfnP)(gpointer data);

//void Model::gui_show() {
//
//	//void (Model::*test) () = &Model::call; // mydata.SetData;
//
//	// Initialize static pointer.
//	gboolean (Model::*pmfnP)(gpointer data) = &Model::update_progress_bar;
//
////	gtk_init(&argc, &argv);
//
//	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//	gtk_window_set_title(GTK_WINDOW(window), "Center");
//	gtk_window_set_default_size(GTK_WINDOW(window), 580, 270);
//	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
//
//	frame = gtk_fixed_new();
//	gtk_container_add(GTK_CONTAINER(window), frame);
//
//	/*Einen Button erstellen*/
//	button_quit = gtk_button_new_with_label("Quit");
//	gtk_widget_set_size_request(button_quit, 80, 35);
//	gtk_fixed_put(GTK_FIXED(frame), button_quit, 50, 20);
//
//	//button_draw = gtk_button_new_with_label("Draw");
//	//gtk_widget_set_size_request(button_draw, 80, 35);
//	//gtk_fixed_put(GTK_FIXED(frame), button_draw, 50, 60);
//
//  /*progress_bar = gtk_progress_bar_new();
//  gint func_ref = g_timeout_add (10000, Model::update_progress_bar, progress_bar);*/
//
//	gtk_widget_show_all(window);
//
//	g_signal_connect(window, "destroy",
//		G_CALLBACK (gtk_main_quit), NULL);
//
//
//	////g_signal_connect(button_draw, "clicked", 
//	////	G_CALLBACK(draw), NULL);
//
//	//g_signal_connect(G_OBJECT(frame), "draw", 
//	//	G_CALLBACK(on_draw_event), NULL);
//
//	//GSourceFunc tt = test;
//	Model m ;
//g_timeout_add (10000,
//			   (),
//               NULL);
//
//
//	gtk_main();
//}