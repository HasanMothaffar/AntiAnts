#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library

#include "keyboard_skybox.h"
#include "../../include/skybox.h"
#include "../../include/utility.h"

KeyboardSkybox::KeyboardSkybox(float width , float height, float length): Skybox(width, height, length) { }

void KeyboardSkybox::draw() const {
	// X Coordinates: [-width, width]
	// Y Coordinates: [0, length]
	// Z Coordinates: [0, height]
	
	glPushMatrix();

	// Back
	glBindTexture(GL_TEXTURE_2D, textures["pc1"]);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, -length);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, height, -length);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glColor3f(0.8,0.8,0.8);
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

	glColor3ub(134,123,90);
	glBegin(GL_QUADS);
		glVertex3f(width, 0, 0);
		glVertex3f(width, 0, -length);
		glVertex3f(width, height, -length);
		glVertex3f(width, height, 0);
	glEnd();

	glColor3ub(177,171,143);
	glBegin(GL_QUADS);
		glVertex3f(-width, 0, 0);
		glVertex3f(-width, 0, -length);
		glVertex3f(-width, height, -length);
		glVertex3f(-width, height, 0);
	glEnd();

	glPopMatrix();
}
