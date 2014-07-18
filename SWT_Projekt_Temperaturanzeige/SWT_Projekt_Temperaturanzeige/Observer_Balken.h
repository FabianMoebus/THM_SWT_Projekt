#ifndef _Observer_Balken_H__
#define _Observer_Balken_H__

#include "Observer_Graph.h"

class Observer_Balken : public Observer_Graph {
public:
	void update(string t_orte[], double t_val[], string t_metadaten[]);
};

#endif