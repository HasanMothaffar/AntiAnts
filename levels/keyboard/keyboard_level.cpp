#include <Windows.h>
#include <GL.H>

#include "keyboard_level.h"
#include "keyboard_skybox.h"

#include "../../include/camera.h"
#include "../../include/ant.h"

Keyboard::Keyboard() {
	this->skybox = new KeyboardSkybox(125, 75, 150);
	this->camera = new Camera();

	this->loadAnts();
}

void Keyboard::loadAnts() {
	this->ants.push_back(Ant(-60, 0, -140));
	this->ants.push_back(Ant(60, 0, -120));
	this->ants.push_back(Ant(70, 0, -110));
	this->ants.push_back(Ant(-80, 0, -100));
	this->ants.push_back(Ant(-95, 0, -50));
	this->ants.push_back(Ant(20, 0, -40));
	this->ants.push_back(Ant(-20, 0, -25));
	this->ants.push_back(Ant(60, 0, -25));
	this->ants.push_back(Ant(-100, 0, -7));
}

void Keyboard::drawScene() {
	this->drawBullets();
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glEnable(GL_TEXTURE_2D);
	this->drawAnts();
	glPopMatrix();

	glTranslated(0, -4, -5);
	
	this->skybox->draw();
	glDisable(GL_TEXTURE_2D);
	
	glPushMatrix();
	glTranslated(-100, 0, -10);

	glPushMatrix();
	glTranslated(0, 1, 0);
	this->keyboard.cube();
	this->keyboard.cube2();
	glPopMatrix();
	//***************************** Line 1 *****************************
	glTranslatef(1, 0, -2);
	glPushMatrix();
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(16.1, 0, 0);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.2, 0, 0);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(48.3, 0, 0);
	this->keyboard.shiftButton();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(124.4, 0, 0);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(140.5, 0, 0);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(156.6, 0, 0);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(172.8, 0, 0);
	this->keyboard.size1();
	glPopMatrix();

	//***************************** Line 2 *****************************
	glPushMatrix();
	glTranslatef(0, 0, -15);
	this->keyboard.size1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.5, 0, -15);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.5, 0, -15);
	for(int i=0; i<8; i++)
	{
	    glTranslatef(15.5, 0, 0);
		this->keyboard.Button();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(167, 0, -15);
	this->keyboard.size4();
	glPopMatrix();

	//***************************** Line 3 *****************************
	glPushMatrix();
	glTranslatef(0, 0, -30);
	this->keyboard.size2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, 0, -30);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(21, 0, -30);
	for(int i=0; i<9; i++)
	{
	    glTranslatef(15.2, 0, 0);
		this->keyboard.Button();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(173, 0, -30);
	this->keyboard.size1();
	glPopMatrix();

	//***************************** Line 4 *****************************
	glPushMatrix();
	glTranslatef(0, 0, -45);
	this->keyboard.size3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18, 0, -45);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(18, 0, -45);
	for(int i=0; i<10; i++)
	{
	    glTranslatef(15, 0, 0);
		this->keyboard.Button();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(182, 0, -45);
	this->keyboard.size3();
	glPopMatrix();

	//***************************** Line 5 *****************************
	glPushMatrix();
	glTranslatef(0, 0, -60);
	this->keyboard.Button();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -60);
	for(int i=0; i<11; i++)
	{
	    glTranslatef(15, 0, 0);
	this->keyboard.Button();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(179, 0, -60);
	this->keyboard.size2();
	glPopMatrix();

	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
}