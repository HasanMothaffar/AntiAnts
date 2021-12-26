#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include "utility.h"
#include "skybox.h"

Skybox::Skybox(float width , float height, float length) {
	this->width = width;
	this->height = height;
	this->length = length;
}

void Skybox::draw(int texture) const {
	// X Coordinates: [-width, width]
	// Y Coordinates: [0, length]
	// Z Coordinates: [0, height]
	//glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();

	// Bottom
	//glBindTexture(GL_TEXTURE_2D, texture);
	// rgb(155, 150, 150)
	Color color = toRGB(155.0f, 150.0f, 150.0f);
	glColor3f(color.red, color.green, color.blue);

		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 1);
		glVertex3f(width, 0, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, 0, -length);

		// Back
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, -length);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, height, -length);

		// Right
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexCoord2d(0, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
		glVertex3f(width, height, -length);

		glTexCoord2d(0, 1);
		glVertex3f(width, height, 0);

		// Front
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexCoord2d(0, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, height, 0);

		glTexCoord2d(1, 1);
		glVertex3f(-width, height, 0);

		glTexCoord2d(0, 1);
		glVertex3f(-width, 0, 0);

		// Left
		glBindTexture(GL_TEXTURE_2D, texture);
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