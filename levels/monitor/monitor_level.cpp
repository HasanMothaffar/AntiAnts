#include <Windows.h>
#include <GL.H>

#include "../../include/level.h"
#include "monitor_level.h"
#include "monitor_camera.h"
#include "monitor_skybox.h"

Monitor::Monitor(): Level() {
	this->skybox = new MonitorSkybox(50, 50, 200);
	this->camera = new MonitorCamera();
	this->loadAnts();
}

void Monitor::drawScene() {
	glTranslatef(0, -1, 0);
	this->skybox->draw();

	glDisable(GL_TEXTURE_2D);
	//this->drawAnts();
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}