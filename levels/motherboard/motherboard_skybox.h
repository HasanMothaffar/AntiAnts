#pragma once

#include "../../include/skybox.h"

class MotherboardSkybox: public Skybox {

public:
	MotherboardSkybox(float width = 50.0f, float height = 50.0f, float length = 200.0f);
	virtual void draw() const;
};