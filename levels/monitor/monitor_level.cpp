#include <Windows.h>
#include <GL.H>

#include "monitor_level.h"

void Monitor::drawScene() {
	glTranslatef(0, -1, 0);
	this->skybox->draw();

	glDisable(GL_TEXTURE_2D);
	//this->drawAnts();
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}