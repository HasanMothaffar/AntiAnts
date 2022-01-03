#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <GLU.H>

#include "../../include/skybox.h"
#include "../../include/utility.h"
#include "motherboard_skybox.h"

MotherboardSkybox::MotherboardSkybox(float width, float height, float length): Skybox(width, height, length) { }

void MotherboardSkybox::draw() const {
	glDisable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glTranslatef(0, 0, -10);
	glRectf(-2, -2, 0, 0);
	glEnable(GL_TEXTURE_2D);
}