#ifndef ANT_H
#define ANT_H

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

#endif // !ANT_H
