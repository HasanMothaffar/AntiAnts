#pragma once

#include "bullet.h"
#include "Model_3DS.h"

class Ant
{
private:
	Model_3DS *model;

public:
	float width;
	float length;
	float height;

	float x;
	float y;
	float z;

	Ant(float x, float y, float z);

	void draw() const;
	bool collidesWithBullet(const Bullet *bullet);
};