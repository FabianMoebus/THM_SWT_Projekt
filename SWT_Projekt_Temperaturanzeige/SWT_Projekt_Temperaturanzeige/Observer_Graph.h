#pragma once 
#include <string>

using namespace std;

class Observer_Graph {
public:
	virtual void update(string t_orte[], double t_val[], string t_metadaten[]);
};