#ifndef _Observer_Dots_H__
#define _Observer_Dots_H__

#include "Observer_Graph.h"

class Observer_Dots : public Observer_Graph {
public:
	void update(string t_orte[], double t_val[], string t_metadaten[]);
};

#endif