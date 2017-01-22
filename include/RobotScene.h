#ifndef __GL_COMPONENT
#define __GL_COMPONENT

#define PI 3.14159
#define TWO_PI PI*2.0
#define HALF_PI PI/2.0

#include <vector>

class Robot;
class Collectible;
class Geometry;
class Box;

class RobotScene
{
private:
	Robot *theRobot;
	Geometry *landscape;
	std::vector<Collectible*> collectibles;
	std::vector<Box*> boxes;
	float rotationAngle;

	int m_windowWidth;
	int m_windowHeight;

public:
	RobotScene();
	virtual ~RobotScene();

	bool Init();
	bool Shutdown();
	float robotXPos, robotYPos, robotZPos;

	void SetupProjection(int width, int height);

	void moveRobotForward();
	void stopRobot();
	void startRobot();
	void turnRobot(int);
	void Prepare(float dt);
	void Render();
	void drawBitmapText(char *, float, float, float);
};

#endif