#include "Observer_Text.h"
#include "Observer_Dots.h"
#include "Observer_Balken.h"
#include <list>
#include <iostream>
#include "Controller.h"

using namespace std;

int main() {

	Controller controller;
	while (1) {
		controller.run("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt");
	}
	getchar();
	return 0;
}


