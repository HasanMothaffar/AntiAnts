#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <GLU.H>

#include "../../include/skybox.h"
#include "../../include/utility.h"
#include "ssd_skybox.h"

SSDSkybox::SSDSkybox(float width , float height, float length): Skybox(width, height, length) { }

void SSDSkybox::draw() const {
	glPushMatrix();

	// Bottom
	glBindTexture(GL_TEXTURE_2D, textures["ssd/cir"]);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 1);
		glVertex3f(width, 0, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, 0, -length);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	//glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_QUADS);
		// Back
		glTexCoord2d(0, 0);
		glColor3f(0.35, 0.35, 0.35);
		glVertex3f(-width, 0, -length);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
		glColor3f(0.2, 0.2, 0.2);
		glVertex3f(width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, height, -length);

		// Right
		glTexCoord2d(0, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(width, height, 0);

		// Front
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 1);
		glVertex3f(width, height, 0);
		
		glTexCoord2d(0, 1);
		glVertex3f(-width, height, 0);

		// Left
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(-width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(-width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, height, 0);
	glEnd();

	glPopMatrix();
}