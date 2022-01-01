#pragma once

#include <vector>

#include "../../include/utility.h"
#include "../../include/Model_3DS.h"
#include "../../include/skybox.h"

class MonitorSkybox: public Skybox
{
private:
	std::vector<Model_3DS *> circuits;
	void loadCircuits();

public:
	MonitorSkybox(float width = 50.0f, float height = 50.0f, float length = 200.0f);

	virtual void draw() const;
	void drawCircuits() const;
};