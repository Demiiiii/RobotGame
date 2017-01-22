#ifdef _WINDOWS
#include <windows.h>
#endif

#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>
#include "RobotScene.h"
#include "Robot.h"
#include "Collectible.h"
#include "Geometry.h"
#include "Box.h"

// disable implicit float-double casting
#pragma warning(disable:4305)

RobotScene::RobotScene()
{
}

RobotScene::~RobotScene()
{
}

bool RobotScene::Init()
{	
	theRobot = new Robot;
	landscape = new Geometry;

	Box* ground = new Box(100.0f, -12.0f, 0.f, 1000.f, 0.0f, 1);
	Box* middle1 = new Box(-4.0f, -2.0f, -60.f, 10.0f, -30.f, 0);
	Box* middle2 = new Box(4.0f, 8.0f, -62.f, 10.0f, 40.f, 0);

	Collectible* object3 = new Collectible(-15.0f, -3.5f, -25.f);
	Collectible* object1 = new Collectible(1.0f, -3.5f, -74.f);
	Collectible* object2 = new Collectible(35.0f, -3.5f, -150.f);
	
	collectibles.push_back(object1);
	collectibles.push_back(object2);
	collectibles.push_back(object3);

	boxes.push_back(ground);
	boxes.push_back(middle1);
	boxes.push_back(middle2);

	robotXPos = 0.f;
	robotYPos = 0.f;
	robotZPos = -30.f;

	theRobot->setNotMoving();

	rotationAngle = 0.0f;

	glClearColor(0.0, 0.6, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	return true;
}

bool RobotScene::Shutdown()
{
	delete theRobot;
	for (int i = 0; i < collectibles.size(); i++) {
		delete collectibles[i];
	}
	collectibles.clear();

	for (int i = 0; i < boxes.size(); i++) {
		delete boxes[i];
	}
	boxes.clear();

	delete landscape;

	return true;
}

void RobotScene::SetupProjection(int width, int height)
{
	if (height == 0)					// don't want a divide by zero
	{
		height = 1;					
	}

	glViewport(0, 0, width, height);		// reset the viewport to new dimensions
	glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
	glLoadIdentity();						// reset projection matrix

	// calculate aspect ratio of window
	gluPerspective(52.0f,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);

	glMatrixMode(GL_MODELVIEW);				// set modelview matrix
	glLoadIdentity();						// reset modelview matrix

	m_windowWidth = width;
	m_windowHeight = height;
}

void RobotScene::Prepare(float dt)
{
	rotationAngle += 0.0f * dt;					// increase our rotation angle counter
	if (rotationAngle >= 360.0f)					// if we've gone in a circle, reset counter
		rotationAngle = 0.0f;

	theRobot->Prepare(dt);
}

void RobotScene::Render()
{

	// clear screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// load the identity matrix (clear to default position and orientation)
	glLoadIdentity();

	glPushMatrix();							// put current matrix on stack
		glLoadIdentity();					// reset matrix
		glTranslatef(0.0f, 0.0f, 0.0f);	// move to (0, 0, -30)
	//	glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);	// rotate the robot on its y-axis
		theRobot->DrawRobot(robotXPos, robotYPos, robotZPos, rotationAngle);		// draw the robot
	glPopMatrix();	

	for (int i = 0; i < collectibles.size(); i++) {
		glPushMatrix();
			glLoadIdentity();
			collectibles[i]->drawCollectible();
		glPopMatrix();
		}

	for (int i = 0; i < boxes.size(); i++) {
		glPushMatrix();
		glLoadIdentity();
		boxes[i]->drawBox();
		glPopMatrix();
	}


}

void RobotScene::stopRobot() {
	theRobot->setNotMoving();
}

void RobotScene::startRobot() {
	theRobot->setMoving();
}

void RobotScene::moveRobotForward()
{
	theRobot->setMoving();
	robotZPos -= 1.f * cos((rotationAngle * 3.14)/ 180);
	robotXPos -= 1.f * sin((rotationAngle * 3.14) / 180);
}

void RobotScene::turnRobot(int direction)
{

//	glPushMatrix();
//		glTranslatef(0.0f, 0.0f, 0.0f);
		if (direction == 1)
		rotationAngle -= 20.f;
		else rotationAngle += 20.f;
//		glTranslatef(savedXPos, savedYPos, savedZPos);
//	glPopMatrix();

}