#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <iostream>

#include "include/ant.h"
#include "include/Model_3DS.h"

/* -- PRIVATE -- */

bool Ant::hasReachedLimit() {
	
	const float modelPositionX = this->model->pos.x;
	const float limitRight = this->x + 10;
	const float limitLeft = this->x - 10;

	return (
		(modelPositionX >= limitRight) || 
		(modelPositionX <= limitLeft)
	);  
   
}

/* -- PUBLIC -- */
Ant::Ant(float x, float y, float z)
{
	this->model = new Model_3DS();
	this->model->Load((char *) "assets/Ant_3ds.3ds");
	this->model->pos.x = x;
	this->model->pos.y = y;
	this->model->pos.z = z;

	this->model->Materials[1].tex.LoadBMP((char *) "assets/antcolor.bmp");
	this->model->scale = 0.002;
	this->model->lit = false;

	this->x = x;
	this->y = y;
	this->z = z;


	this->width = 3;
	this->length = 3;
	this->height = 3;

	this->step = -0.1;
	this->limitX = 10;
}

void Ant::draw()
{
	if (this->hasReachedLimit()) {
		this->step *= -1.0f;
		this->model->rot.y += 180;
	}

	this->model->pos.x += this->step;

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glColor3f(1, 1, 1);
	this->model->Draw();
	glPopMatrix();
}

bool Ant::collidesWithBullet(const Bullet *bullet)
{
	return (
		(bullet->real.x >= (this->model->pos.x - this->width)) &&
		(bullet->real.x <= (this->model->pos.x + this->width)) &&

		(bullet->real.y >= (this->model->pos.y)) &&
		(bullet->real.y <= (this->model->pos.y + this->height)) &&

		(bullet->real.z <= (this->model->pos.z)) &&
		(bullet->real.z >= (this->model->pos.z - this->length))
	);
}