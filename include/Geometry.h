#ifndef __GEOMETRY_H
#define __GEOMETRY_H


#include "Box.h"
#include <vector>

class Geometry {
private:
	float rotation;
	float xPos, yPos, zPos;
	std::vector<Box*> boxes;

public:
	Geometry();
	virtual ~Geometry();

	void drawGeometry();
};
#endif