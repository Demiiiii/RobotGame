#ifndef __BOX_H
#define __BOX_H

class Box {
private:
	float rotation;
	float xPos, yPos, zPos, size;
	bool isGround;

public: 
	Box(float, float, float, float, float, bool);
	virtual ~Box();

	void drawBox();

};

#endif