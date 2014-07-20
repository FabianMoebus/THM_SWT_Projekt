#include "Controller.h"
#include <iostream>
using namespace std;

void Controller::run(string url) {
	
	 subject.do_update(url);
	 cout << subject.t_metadaten[0] << endl;
	 cout << subject.t_metadaten[1] << endl;
	 for (int i = 0; i < 6; i++) {
		 cout << subject.t_orte[i] << ":  " << subject.t_val[i] << endl;
	 }
	_sleep(60000);
}