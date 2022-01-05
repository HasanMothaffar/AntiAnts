#pragma once

#include <vector>

#include "../../include/level.h"
#include "../../include/Model_3DS.h"
#include "monitor_skybox.h"

class Monitor: public Level {

private:
	std::vector<Model_3DS *> circuits;
	GLUquadric *quadric;

	void loadCircuits();
public:
	Monitor();
	~Monitor();
	virtual void drawScene();
	void drawCircuits() const;
	void drawBatteries() const;
};