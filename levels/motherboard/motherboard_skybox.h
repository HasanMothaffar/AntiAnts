#pragma once

#include <Windows.h>
#include <GL.H>

#include "../../include/skybox.h"

class MotherboardSkybox: public Skybox {
private:
	GLfloat motherboardX, motherboardY, motherboardZ;

public:
	MotherboardSkybox(float width = 50.0f, float height = 50.0f, float length = 200.0f);
	virtual void draw() const;
};