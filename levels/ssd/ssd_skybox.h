#pragma once

#include "../../include/skybox.h"

class SSDSkybox: public Skybox {

public:
	SSDSkybox(float width = 50.0f, float height = 50.0f, float length = 200.0f);
	virtual void draw() const;
};