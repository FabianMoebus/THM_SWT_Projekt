#include "Model.h"
#include <iostream>

void Model::do_update(string url) {
	string str;					// String der kompletten .txt Datei
	string t_daten[12];			// String-Array mit Temperatur und Orte (Orte und Temperaturwerte noch nicht getrennt)
	char tmp_str[50];			// temporäre String-Variable, hier werden die eingelesen Character gespeichert
								// bevor sie in t_metadaten[] bzw. t_daten[] gespeichert werden

	// komplette .txt-Datei herunterladen
	// und den Inhalt als String speichern
	str = httpdownloader.download(url);

	int zaehler = 0;			// Zählvariable für t_daten[]
	int j = 0;					// Zählvariable für tmp_str[]
	int b_hash = 0;				// zählt die Zeilen, die mit '#' beginnen

	clear_string(tmp_str, 50);

	// Output-String parsen und abspeichern
	for(size_t i = 0; i < str.length(); i++) {

		/* Wenn Zeile mit # beginnt, nachfolgenden String speichern */
		if (str[i] == '#') {
			b_hash++;
			j = 0;
		}

		/* Erste Zeile mit # einlesen und speichern 
		 * Lese solange, bis Zeilenende ('\n') nicht erreicht
		 */
		if (b_hash == 1) {
			if (str[i] != '\n') {
				tmp_str[j] = str[i];
				j++;
			} else {
				/* Zeilenende erreicht, speichere Metadaten in Zielvariable t_metadaten[]
				 * temporäre String-Variable tmp_str leeren und Zählvariable j zurücksetzen
				 */
				t_metadaten[0] = tmp_str;
				clear_string(tmp_str, 50);
				j = 0;
			}
		}

		/* Zweite Zeile mit # einlesen und speichern 
		 * Lese solange, bis Zeilenende ('\n') nicht erreicht
		 */
		if (b_hash == 2) {
			if (str[i] != '\n') {
				tmp_str[j] = str[i];
				j++;
			} else {
				t_metadaten[1] = tmp_str;
				clear_string(tmp_str, 50);
				j = 0;
				b_hash = 0;
				continue;
			}
		}

		/* Ort und Temperatur zeilenweise einlesen 
		 * Ort und Temperaturwert sind durch ',' getrennt
		 * Zeilenende wird mit '\n' abgefragt
		 */
		if (b_hash == 0) {
			if ((str[i] != ',') && (str[i] != '\n')) {
				if (str[i] == ' ') {
					// überspringe Leerzeichen
					continue;
				} else {
					tmp_str[j] = str[i];
					j++;
				}
			} else {
				/* Ort bzw. Temperaturwert vollständig eingelesen
				 * tmp_str in t_daten[] abspeichern
				 */
				t_daten[zaehler] = tmp_str;
				clear_string(tmp_str, 50);
				zaehler++;
				j = 0;
			}
		}
	}


	int z = 0;			// Zählvariable t_val[]
	int y = 0;			// Zählvariable t_orte[]

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
	// Iterator deklarieren
	std::list<Observer_Graph*>::iterator iter;
	// Iterator auf Listenanfang setzen
    iter = observer_list.begin();
    
	// Solange Listenende nicht erreicht, update-Methode des Observers ausführen
    while (iter != observer_list.end()) {
		(*iter)->update(cr_, widget_, t_orte, t_val, t_metadaten);
        // Iterator auf nächsten Observer zeigen lassen
		iter++;
    }
}

/* Übergebenen String mit '\0' überschreiben 
 */
void Model::clear_string(char arg[], int length) {
	for(int i = 0; i < length; i++) {
		arg[i] = '\0';
	}
}
