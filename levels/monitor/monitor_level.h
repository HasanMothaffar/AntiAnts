#pragma once

#include "../../include/level.h"
#include "skybox.h"
#include "monitor_camera.h"

class Monitor: public Level {
public:
	Monitor(Camera *, Skybox *);
	virtual void drawScene();
};