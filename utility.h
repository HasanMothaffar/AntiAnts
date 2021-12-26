#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>		// Header File For Windows
#include <gl/GL.h>				// Header File For The OpenGL32 Library

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
	dividing 255 by each rgb component.
*/
Color toRGB(float r, float g, float b);

#endif // !"UTILITY_H"