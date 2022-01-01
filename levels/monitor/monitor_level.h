#pragma once

#include <vector>

#include "../../include/level.h"
#include "../../include/Model_3DS.h"
#include "monitor_skybox.h"
#include "monitor_camera.h"

class Monitor: public Level {

private:
	std::vector<Model_3DS *> circuits;
	void loadCircuits();

public:
	Monitor();
	virtual void drawScene();
	void drawCircuits() const;
};