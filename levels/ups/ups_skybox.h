#pragma once

#include "../../include/skybox.h"

class UPSSkybox: public Skybox {

public:
	UPSSkybox(float width = 50.0f, float height = 50.0f, float length = 200.0f);
	virtual void draw() const;
};