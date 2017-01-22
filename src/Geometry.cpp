#include "Geometry.h"

#ifdef _WINDOWS
#include <windows.h>
#endif

#include <gl/gl.h>
#include <gl/glu.h>

Geometry::Geometry() {

	//std::vector<Box*> boxes;
	//Box* middle1 = new Box(-0.f, 0.f, -15.f, 10.f, 0.f);

	//boxes.push_back(middle1);
}

Geometry::~Geometry() {
	//for (int i = 0; i < boxes.size(); i++) {
	//	delete boxes[i];
	//}
}

void Geometry::drawGeometry() {
	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.2f);
	glTranslatef(xPos, yPos, zPos);
	glRotatef(rotation, 0.f, 1.0f, 0.f);
	glScalef(5.f, 5.f, 5.f);


	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);	// top face
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// front face
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// right face
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);	// left face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// bottom face
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// back face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glEnd();
	glPopMatrix();
	//for (int i = 0; i < boxes.size(); i++) {
	//		boxes[i]->drawBox();
	//}
}