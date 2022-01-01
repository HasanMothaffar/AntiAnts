#pragma once

#include <vector>

#include <gl.h> // Header File For The OpenGL32 Library
#include "include\utility.h"
#include "include\Model_3DS.h"

class Skybox
{
private:
	std::vector<Model_3DS *> circuits;

	void loadCircuits();

public:
	float width;
	float height;
	float length;

	Skybox(float width = 50.0f, float height = 50.0f, float length = 200.0f);

	void draw() const;
	void drawCircuits() const;
};