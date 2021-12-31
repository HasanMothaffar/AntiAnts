#pragma once

#include "bullet.h"

class Ant
{
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