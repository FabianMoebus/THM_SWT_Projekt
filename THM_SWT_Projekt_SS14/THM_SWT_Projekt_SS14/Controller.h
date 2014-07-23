#pragma once
#include "Model.h"
#include <string>


using namespace std;

class Controller {
private:
public:
	Model subject;
	void run(string url);
};