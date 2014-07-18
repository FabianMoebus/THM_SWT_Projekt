#include "Observer_Text.h"
#include "Observer_Dots.h"
#include "Observer_Balken.h"
#include <list>
#include <iostream>
#include "Controller.h"
#include "Observer_Balken.h"
#include "Observer_Dots.h"
#include "Observer_Text.h"

using namespace std;

int main() {

	Controller controller;
	// Observer anhängen
	controller.subject.attach_observer(new Observer_Balken());
	controller.subject.attach_observer(new Observer_Dots());
	controller.subject.attach_observer(new Observer_Text());
	// run
	controller.run("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt");
	getchar();
	return 0;
}


