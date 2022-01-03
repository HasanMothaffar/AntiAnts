#pragma once

#include "../../include/level.h"
#include "motherboard_camera.h"
#include "motherboard_skybox.h"

class Motherboard: public Level {
public:
	Motherboard();
	virtual void drawScene();
};