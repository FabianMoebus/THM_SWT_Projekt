#include "Controller.h"
#include <iostream>
using namespace std;


/* L�dt einmal pro Minute die aktuellen Temperaturdaten
 * von der angegebenen URL herunter.
 */
void Controller::run(string url) {
	subject.do_update(url);	 
	//_sleep(60000);
}
