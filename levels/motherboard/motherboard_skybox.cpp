#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <GLU.H>

#include "../../include/skybox.h"
#include "../../include/utility.h"
#include "motherboard_skybox.h"

MotherboardSkybox::MotherboardSkybox(float width, float height, float length): Skybox(width, height, length) { 
	this->motherboardX = 200;
	this->motherboardY = 200;
	this->motherboardZ = 190;
}

void MotherboardSkybox::draw() const {
	glColor3f(1, 1, 1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["motherboard/case"]);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-motherboardX,motherboardY,motherboardZ);
	glTexCoord2f(1,0);
	glVertex3f(+motherboardX,motherboardY,motherboardZ);
	glTexCoord2f(1,1);
	glVertex3d(+motherboardX,motherboardY,-motherboardZ);
	glTexCoord2f(0,1);
	glVertex3f(-motherboardX,motherboardY,-motherboardZ);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["motherboard/case"]);
	glBegin(GL_QUADS);
	//back wall
	glTexCoord2f(0,0);
	glVertex3f(-motherboardX,0,motherboardZ);
	glTexCoord2f(1,0);
	glVertex3f(+motherboardX,0,motherboardZ);
	glTexCoord2f(1,1);
	glVertex3f(+motherboardX,motherboardY,motherboardZ);
	glTexCoord2f(0,1);
	glVertex3f(-motherboardX,motherboardY,motherboardZ);
	//front wall
	glTexCoord2f(0,0);
	glVertex3f(-motherboardX,0,-motherboardZ);
	glTexCoord2f(1,0);
	glVertex3f(+motherboardX,0,-motherboardZ);
	glTexCoord2f(1,1);
	glVertex3f(+motherboardX,motherboardY,-motherboardZ);
	glTexCoord2f(0,1);
	glVertex3f(-motherboardX,motherboardY,-motherboardZ);
	//left wall
	glTexCoord2f(0,0);
	glVertex3f(-motherboardX,0,-motherboardZ);
	glTexCoord2f(1,0);
	glVertex3f(-motherboardX,0,+motherboardZ);
	glTexCoord2f(1,1);
	glVertex3f(-motherboardX,motherboardY,+motherboardZ);
	glTexCoord2f(0,1);
	glVertex3f(-motherboardX,motherboardY,-motherboardZ);
	//right wall
	glTexCoord2f(0,0);
	glVertex3f(motherboardX,0,-motherboardZ);
	glTexCoord2f(1,0);
	glVertex3f(motherboardX,0,+motherboardZ);
	glTexCoord2f(1,1);
	glVertex3f(motherboardX,motherboardY,+motherboardZ);
	glTexCoord2f(0,1);
	glVertex3f(motherboardX,motherboardY,-motherboardZ);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);


	//Surface
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["motherboard/m2"]);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-motherboardX,0,motherboardZ);
	glTexCoord2f(1,0);
	glVertex3f(+motherboardX,0,motherboardZ);
	glTexCoord2f(1,1);
	glVertex3d(+motherboardX,0,-motherboardZ);
	glTexCoord2f(0,1);
	glVertex3f(-motherboardX,0,-motherboardZ);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}