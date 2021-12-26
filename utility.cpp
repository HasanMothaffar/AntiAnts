#include "utility.h"
#include <math.h>
#include <gl.h>			// Header File For The OpenGL32 Library

#define SQR(x) (x*x)
#define NULL_VECTOR Vector3dCreate(0.0f,0.0f,0.0f)

Vector3dStruct Vector3dCreate(GLfloat x, GLfloat y, GLfloat z)
{
	Vector3dStruct tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return tmp;
}

GLfloat LengthVector3d(Vector3dStruct* v)
{
	return (GLfloat)(sqrt(SQR(v->x) + SQR(v->y) + SQR(v->z)));
}

Vector3dStruct NormalizeVector3d(Vector3dStruct v)
{
	Vector3dStruct res;
	float L = LengthVector3d(&v);
	if (L == 0.0f) return NULL_VECTOR;
	res.x = v.x / L;
	res.y = v.y / L;
	res.z = v.z / L;
	return res;
}

Color toRGB(float r, float g, float b) {
	Color color = {
		r / 255.0f,
		g / 255.0f,
		b / 255.0f
	};

	return color;
}