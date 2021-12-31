#ifndef SKYBOX_H
#define SKYBOX_H

#include <gl.h> // Header File For The OpenGL32 Library
#include "utility.h"

class Skybox
{
public:
	float width;
	float height;
	float length;

	Skybox(float width = 50.0f, float height = 50.0f, float length = 200.0f);

	void draw() const;
};

#endif // !SKYBOX_H