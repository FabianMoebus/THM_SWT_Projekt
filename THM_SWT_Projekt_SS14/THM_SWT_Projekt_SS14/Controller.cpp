#include "Controller.h"
#include <iostream>
using namespace std;

void Controller::run(string url) {
	subject.do_update(url);	 
	//_sleep(130000);
}


