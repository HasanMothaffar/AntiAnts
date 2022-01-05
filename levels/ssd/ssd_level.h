#pragma once

#include <vector>

#include "../../include/level.h"
#include "../../include/Model_3DS.h"

class SSD: public Level {
private:
	std::vector<Model_3DS *> circuits;
	virtual void loadAnts();

public:
	float lineX, lineY, lineZ;
    float TransistorX1, TransistorX2;
	float TransistorZ1, TransistorZ2;

	SSD();
	virtual void drawScene();

	void loadCircuits();
	void cube(float X1, float X2, float Y1, float Y2, float Z1, float Z2);
	void cube2(float q1, float q2, float w1, float w2, float r1, float r2);
	void trans();
};