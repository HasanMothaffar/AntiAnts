#include <Windows.h>
#include <GL.H>

#include "../../include/level.h"
#include "../../include/Model_3DS.h"
#include "monitor_level.h"
#include "monitor_camera.h"
#include "monitor_skybox.h"

/* -- PRIVATE -- */

void Monitor::loadCircuits() {
	for (int i = 0; i < 10; i++) {
		Model_3DS *circuit = new Model_3DS();
		circuit->Load((char *) "assets/22v10.3ds");
		circuit->pos.x = 0;
		circuit->pos.y = 2;
		circuit->pos.z = - i * 10;
		circuit->Materials[0].tex.LoadBMP("assets/22v10.bmp");
		circuit->Materials[1].tex.BuildColorTexture(125, 125, 125);
		circuit->Materials[2].tex.BuildColorTexture(125, 125, 125);

		circuits.push_back(circuit);
	}
}

/* -- PUBLIC -- */
Monitor::Monitor(): Level() {
	this->skybox = new MonitorSkybox(50, 50, 200);
	this->camera = new MonitorCamera();
	this->loadAnts();
	this->loadCircuits();
}

void Monitor::drawScene() {
	glTranslatef(0, -1, 0);
	this->skybox->draw();
	this->drawCircuits();
	this->drawAnts();

	glDisable(GL_TEXTURE_2D);
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}

void Monitor::drawCircuits() const {
	glPushMatrix();
	glTranslatef(0, 0.1, -0.1);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glVertex3f(-this->skybox->width, 0, 0);
		glVertex3f(this->skybox->width, 0, 0);
		glVertex3f(this->skybox->width, 0, -20);
		glVertex3f(-this->skybox->width, 0, -20);
	glEnd();

	for (auto circuit: this->circuits) {
		circuit->Draw();
	}
	
	glPopMatrix();
}