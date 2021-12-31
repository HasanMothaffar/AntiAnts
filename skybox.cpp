#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include "utility.h"
#include "texture.h"
#include "skybox.h"

Skybox::Skybox(float width , float height, float length) {
	this->width = width;
	this->height = height;
	this->length = length;
}

void Skybox::draw() const {
	// X Coordinates: [-width, width]
	// Y Coordinates: [0, length]
	// Z Coordinates: [0, height]
	
	int texture = textures["windows"];

	glPushMatrix();
	// Bottom
	glDisable(GL_TEXTURE_2D);
	Color color = toRGB(155.0f, 150.0f, 150.0f);
	glBegin(GL_QUADS);
		glColor3f(color.red, color.green, color.blue);
		glVertex3f(-width, 0, 0);

		glColor3f(color.red + 0.1, color.green + 0.1, color.blue + 0.1);
		glVertex3f(width, 0, 0);

		glColor3f(color.red + 0.2, color.green + 0.2, color.blue + 0.2);
		glVertex3f(width, 0, -length);

		glColor3f(color.red + 0.3, color.green + 0.3, color.blue + 0.3);
		glVertex3f(-width, 0, -length);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		// Back
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, -length);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, -length);

		glTexCoord2d(1, 1);
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
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, height, 0);

		glTexCoord2d(1, 1);
		glVertex3f(-width, height, 0);

		glTexCoord2d(0, 1);
		glVertex3f(-width, 0, 0);

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