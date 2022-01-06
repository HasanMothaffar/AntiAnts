#pragma once

#include <windows.h>		// Header File For Windows
#include <gl.h>				// Header File For The OpenGL32 Library
#include <Sound.h>

#include <string>
#include <map>

extern std::map<std::string, int> textures;
extern std::map<std::string, Sound> sounds;

struct Color {
	float red, green, blue;
};

struct Vector3dStruct {
	GLfloat x, y, z;
};

Vector3dStruct Vector3dCreate ( GLfloat x, GLfloat y, GLfloat z );
Vector3dStruct NormalizeVector3d( Vector3dStruct v);

/* 
	Returns a color in the OpenGL format by
	dividing each rgb component by 255. 
*/
Color toRGB(float r, float g, float b);

void loadGameTextures();
void loadGameSounds();

void drawLevelManager();
void drawLevelCube(int);