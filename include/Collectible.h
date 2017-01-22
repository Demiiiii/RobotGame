#ifndef __COLLECTIBLE_H
#define __COLLECTIBLE_H

const char UNCOLLECTED = 0;
const char COLLECTED = 1;

class Collectible {
private:
	bool bCollected;
	float rotation;
	float xPos, yPos, zPos;

public:
	Collectible(float, float, float);
	virtual ~Collectible();

	bool checkCollision(float, float);
	bool isCollected();
	void drawCollectible();
	void update();
	void setCollected();
	float getZPos();
};
#endif