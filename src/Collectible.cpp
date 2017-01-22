#ifdef _WINDOWS
#include <windows.h>
#endif

#include <gl/gl.h>
#include <gl/glu.h>

#include "Collectible.h"

Collectible::Collectible(float x, float y, float z)
{
	rotation = 0.f;

	xPos = x;
	yPos = y;
	zPos = z;

}

Collectible::~Collectible()
{

}

void Collectible::drawCollectible()
{
	rotation += 5.f; // Rotate in place every frame

	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.8f);
	glScalef(3.0f, 3.0f, 3.0f);

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.8f, 0.6f);

	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.0f, -1.0f, 0.0f);


	glEnd();
	glPopMatrix();
}

	bool Collectible::checkCollision(float xOther, float zOther) {
		if ((xOther + 0.5f > xPos && xOther - 0.5f < xPos)) {
			if ((zOther + 0.5f > zPos && zOther - 0.5f < zPos)) {
			return true;
		  }
		}
		else return false;
	}

	bool Collectible::isCollected() {
		return bCollected;
	}

	float Collectible::getZPos() {
		return zPos;
	}

	void Collectible::setCollected() {
		bCollected = COLLECTED;
	}