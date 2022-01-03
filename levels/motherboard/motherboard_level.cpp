#include <Windows.h>
#include <GL.H>

#include "../../include/camera.h"
#include "motherboard_level.h"
//#include "motherboard_camera.h"
#include "motherboard_skybox.h"

Motherboard::Motherboard(): Level() { 
	this->skybox = new MotherboardSkybox(50, 50, 200);
	this->camera = new Camera();
	this->loadAnts();
}

void Motherboard::drawScene() {
	this->skybox->draw();

	// glDisable(GL_TEXTURE_2D);
	this->drawAnts();
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}