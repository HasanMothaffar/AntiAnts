#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <GLU.H>

#include "../../include/skybox.h"
#include "../../include/utility.h"
#include "ups_skybox.h"

UPSSkybox::UPSSkybox(float width , float height, float length): Skybox(width, height, length) { }

void UPSSkybox::draw() const {
	float UPSX = 150.0f;
	float UPSY = 200.0f;
	float UPSZ = 100.0f;

	glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["ups/wall"]);
	//glColor3f(0,1,0);
		glBegin(GL_QUADS);
	//back wall
	glTexCoord2f(0,0);
	glVertex3f(-UPSX,0,UPSZ);
	glTexCoord2f(1,0);
	glVertex3f(+UPSX,0,UPSZ);
	glTexCoord2f(1,1);
	glVertex3f(+UPSX,UPSY,UPSZ);
	glTexCoord2f(0,1);
	glVertex3f(-UPSX,UPSY,UPSZ);
	//front wall
	glTexCoord2f(0,0);
	glVertex3f(-UPSX,0,-UPSZ);
	glTexCoord2f(1,0);
	glVertex3f(+UPSX,0,-UPSZ);
	glTexCoord2f(1,1);
	glVertex3f(+UPSX,UPSY,-UPSZ);
	glTexCoord2f(0,1);
	glVertex3f(-UPSX,UPSY,-UPSZ);
	//left wall
	glTexCoord2f(0,0);
	glVertex3f(-UPSX,0,-UPSZ);
	glTexCoord2f(1,0);
	glVertex3f(-UPSX,0,+UPSZ);
	glTexCoord2f(1,1);
	glVertex3f(-UPSX,UPSY,+UPSZ);
	glTexCoord2f(0,1);
	glVertex3f(-UPSX,UPSY,-UPSZ);
	//right wall
	glTexCoord2f(0,0);
	glVertex3f(UPSX,0,-UPSZ);
	glTexCoord2f(1,0);
	glVertex3f(UPSX,0,+UPSZ);
	glTexCoord2f(1,1);
	glVertex3f(UPSX,UPSY,+UPSZ);
	glTexCoord2f(0,1);
	glVertex3f(UPSX,UPSY,-UPSZ);
	glEnd();
	
	glColor3ub(255,255,255);

	//above side 
	
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-UPSX,UPSY,UPSZ);
	glTexCoord2f(1,0);
	glVertex3f(+UPSX,UPSY,UPSZ);
	glTexCoord2f(1,1);
	glVertex3d(+UPSX,UPSY,-UPSZ);
	glTexCoord2f(0,1);
	glVertex3f(-UPSX,UPSY,-UPSZ);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3f(1,1,1);

	//Surface
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-UPSX,0,UPSZ);
	glTexCoord2f(1,0);
	glVertex3f(+UPSX,0,UPSZ);
	glTexCoord2f(1,1);
	glVertex3d(+UPSX,0,-UPSZ);
	glTexCoord2f(0,1);
	glVertex3f(-UPSX,0,-UPSZ);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}