#include "Controller.h"
#include <iostream>
using namespace std;

void Controller::run(string url) {
	subject.do_update(url);
	// Ausgabe
	for (int i = 0; i < 2; i++) {
		cout << subject.t_metadaten[i] << endl;
	}
	for (int i = 0; i < 6; i++) {
		cout << subject.t_orte[i];
		cout << subject.t_val[i] << endl;
	}
	_sleep(60000);
}