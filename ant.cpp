#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library

#include "include/ant.h"
#include "include/Model_3DS.h"

Ant::Ant(float x, float y, float z)
{
	this->model = new Model_3DS();
	this->model->Load((char *) "assets/Ant_3ds.3ds");
	this->model->pos.x = x;
	this->model->pos.y = y;
	this->model->pos.z = z;

	this->model->Materials[1].tex.LoadBMP((char *) "assets/antcolor.bmp");
	this->model->scale = 0.001;
	this->model->lit = false;

	this->x = x;
	this->y = y;
	this->z = z;

	this->width = 2;
	this->length = 2;
	this->height = 2;
}

void Ant::draw() const
{
	// X Coordinates: [-width, width]
	// Y Coordinates: [0, length]
	// Z Coordinates: [0, height]

	//glColor3f(1, 0, 0);
	//glPushMatrix();
	//glTranslatef(x, y, z);
	//glBegin(GL_QUADS);
	//// Bottom
	//glVertex3f(-width, 0, 0);
	//glVertex3f(-width, 0, -length);
	//glVertex3f(width, 0, -length);
	//glVertex3f(width, 0, 0);

	//// Front
	//glVertex3f(width, 0, 0);
	//glVertex3f(width, height, 0);
	//glVertex3f(-width, height, 0);
	//glVertex3f(-width, 0, 0);

	//// Back
	//glVertex3f(-width, 0, -length);
	//glVertex3f(width, 0, -length);
	//glVertex3f(width, height, -length);
	//glVertex3f(-width, height, -length);

	//// Left
	//glVertex3f(-width, 0, 0);
	//glVertex3f(-width, 0, -length);
	//glVertex3f(-width, height, -length);
	//glVertex3f(-width, height, 0);

	//// Right
	//glVertex3f(width, 0, 0);
	//glVertex3f(width, 0, -length);
	//glVertex3f(width, height, -length);
	//glVertex3f(width, height, 0);

	//glEnd();
	//glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	this->model->Draw();
	glPopMatrix();
}

bool Ant::collidesWithBullet(const Bullet *bullet)
{
	return (
		(bullet->real.x >= (this->x - this->width)) &&
		(bullet->real.x <= (this->x + this->width)) &&

		(bullet->real.y >= (this->y)) &&
		(bullet->real.y <= (this->y + this->height)) &&

		(bullet->real.z <= (this->z)) &&
		(bullet->real.z >= (this->z - this->length))
	);
}