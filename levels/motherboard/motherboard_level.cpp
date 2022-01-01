//#include <Windows.h>
//#include <GL.H>
//
//#include "motherboard_level.h"
//#include "camera.h"
//#include "skybox.h"
//
//Motherboard::Motherboard(Camera *camera, Skybox *skybox): Level(camera, skybox) { }
//
//void Motherboard::drawScene() {
//	glTranslatef(0, -20, 0);
//	this->skybox->draw();
//
//	glDisable(GL_TEXTURE_2D);
//	//this->drawAnts();
//	this->drawBullets();
//	glEnable(GL_TEXTURE_2D);
//}