#include <Windows.h>
#include <GL.H>

#include "../../include/level.h"
#include "../../include/Model_3DS.h"
#include "../../include/utility.h"
#include "../../include/camera.h"
#include "monitor_level.h"
#include "monitor_skybox.h"

/* -- PRIVATE -- */

void Monitor::loadCircuits() {
	for (int i = 3; i < 8; i++) {
		Model_3DS *circuit = new Model_3DS();
		circuit->Load((char *) "assets/22v10.3ds");
		circuit->pos.x = 0;
		circuit->pos.y = 7;
		circuit->pos.z = - i * 20;
		circuit->Materials[0].tex.LoadBMP("assets/22v10.bmp");

		unsigned char color = 100;
		circuit->Materials[1].tex.BuildColorTexture(color, color, color);
		circuit->Materials[2].tex.BuildColorTexture(color, color, color);
		circuit->scale = 10;
		circuits.push_back(circuit);
	}
}


/* -- PUBLIC -- */
Monitor::Monitor(): Level() {
	this->skybox = new MonitorSkybox(50, 50, 200);
	this->camera = new Camera();
	this->quadric = gluNewQuadric();

	this->loadAnts();
	this->loadCircuits();
}

Monitor::~Monitor() {
	for (auto circuit: circuits) {
		delete circuit;
	}
}

void Monitor::drawScene() {
	glPushMatrix();
	this->drawBullets();

	glTranslatef(0, -1, 0);
	this->skybox->draw();
	this->drawCircuits();
	this->drawAnts();

	this->drawBatteries();
	glPopMatrix();
}

void Monitor::drawCircuits() const {
	for (auto circuit: this->circuits) {
		circuit->Draw();
	}
}

void Monitor::drawBatteries() const {
	float positions[] = { -this->skybox->width + 5, this->skybox->width - 5 };
	
	glDisable(GL_TEXTURE_2D);
	for (float z = -50; z >= -150; z -= 50) {
		for (auto position : positions) {
			glPushMatrix();

			glTranslatef(position, 1, z);
			glColor3f(0, 0, 0);
			gluCylinder(this->quadric, 4, 4, 10, 30, 30);

			glColor3f(1, 0, 0);
			gluCylinder(this->quadric, 3, 3, 10, 30, 30);

			glColor3f(1, 1, 0);
			gluCylinder(this->quadric, 2, 2, 10, 30, 30);

			glColor3f(1, 1, 1);
			gluCylinder(this->quadric, 1, 1, 10, 30, 30);
			
			glPopMatrix();
		}
	}
	glEnable(GL_TEXTURE_2D);
}