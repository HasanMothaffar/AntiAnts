#include <Windows.h>
#include <GL.H>

#include "../../include/level.h"
#include "monitor_level.h"
#include "monitor_camera.h"
#include "skybox.h"

Monitor::Monitor(Camera *camera, Skybox *skybox): Level(camera, skybox) {

}

void Monitor::drawScene() {
	glTranslatef(0, -1, 0);
	this->skybox->draw();

	glDisable(GL_TEXTURE_2D);
	//this->drawAnts();
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}