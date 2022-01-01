#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <GLU.H>

#include "../../include/texture.h"
#include "../../include/Model_3DS.h"
#include "../../include/skybox.h"
#include "monitor_skybox.h"

MonitorSkybox::MonitorSkybox(float width , float height, float length): Skybox(width, height, length) {
	this->loadCircuits();
}

void MonitorSkybox::loadCircuits() {
	for (int i = 0; i < 10; i++) {
		Model_3DS *circuit = new Model_3DS();
		circuit->Load((char *) "assets/22v10.3ds");
		circuit->pos.x = 0;
		circuit->pos.y = 2;
		circuit->pos.z = - i * 10;
		circuit->Materials[0].tex.LoadBMP("assets/22v10.bmp");
		circuit->Materials[1].tex.BuildColorTexture(125, 125, 125);
		circuit->Materials[2].tex.BuildColorTexture(125, 125, 125);

		circuits.push_back(circuit);
	}
}

void MonitorSkybox::draw() const {
	// X Coordinates: [-width, width]
	// Y Coordinates: [0, length]
	// Z Coordinates: [0, height]
	
	Color color = toRGB(155.0f, 150.0f, 150.0f);
	this->drawCircuits();
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	// Right
		glColor3f(color.red, color.green, color.blue);
		glVertex3f(width, 0, 0);

		glColor3f(color.red + 0.1, color.green + 0.1, color.blue + 0.1);
		glVertex3f(width, 0, -length);

		glColor3f(color.red + 0.2, color.green + 0.2, color.blue + 0.2);
		glVertex3f(width, height, -length);

		glColor3f(color.red + 0.3, color.green + 0.3, color.blue + 0.3);
		glVertex3f(width, height, 0);

		// Front
		glColor3f(color.red, color.green, color.blue);
		glVertex3f(width, 0, 0);

		glColor3f(color.red + 0.1, color.green + 0.1, color.blue + 0.1);
		glVertex3f(width, height, 0);

		glColor3f(color.red + 0.2, color.green + 0.2, color.blue + 0.2);
		glVertex3f(-width, height, 0);

		glColor3f(color.red + 0.3, color.green + 0.3, color.blue + 0.3);
		glVertex3f(-width, 0, 0);

		// Left
		glColor3f(color.red, color.green, color.blue);
		glVertex3f(-width, 0, 0);

		glColor3f(color.red + 0.1, color.green + 0.1, color.blue + 0.1);
		glVertex3f(-width, 0, -length);

		glColor3f(color.red + 0.2, color.green + 0.2, color.blue + 0.2);
		glVertex3f(-width, height, -length);

		glColor3f(color.red + 0.3, color.green + 0.3, color.blue + 0.3);
		glVertex3f(-width, height, 0);
	glEnd();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textures["circuit"]);	
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);		
		// Bottom
		glTexCoord2d(0, 0);
		glVertex3f(-width, 0, 0);

		glTexCoord2d(1, 0);
		glVertex3f(width, 0, 0);

		glTexCoord2d(1, 1);
		glVertex3f(width, 0, -length);

		glTexCoord2d(0, 1);
		glVertex3f(-width, 0, -length);
	glEnd();

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures["windows"]);
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
	glEnd();

	glPopMatrix();
}

void MonitorSkybox::drawCircuits() const {
	
	glPushMatrix();
	glTranslatef(0, 0.1, -0.1);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glVertex3f(-width, 0, 0);
		glVertex3f(width, 0, 0);
		glVertex3f(width, 0, -20);
		glVertex3f(-width, 0, -20);
	glEnd();

	for (auto circuit: this->circuits) {
		circuit->Draw();
	}
	
	glPopMatrix();
}