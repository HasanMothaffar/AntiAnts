#pragma once

#include "../../include/skybox.h"

class KeyboardSkybox: public Skybox
{
public:
	KeyboardSkybox(float width = 125.0f, float height = 75.0f, float length = 300.0f);
	virtual void draw() const;
};