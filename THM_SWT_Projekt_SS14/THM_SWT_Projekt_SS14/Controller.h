#pragma once
#include "Model.h"
#include <string>


using namespace std;

class Controller {
private:
public:
	// Variablen
	Model subject;
	// Methoden
	void run(string url);
};