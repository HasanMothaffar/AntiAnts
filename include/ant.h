#pragma once

#include "bullet.h"
#include "Model_3DS.h"

class Ant
{
private:
	Model_3DS *model;

	/* 
		The distance the ant moves to the right or left of the X axis.
		Positive means going to the right, and negative means to the left.
	*/
	float step;

	/*
		The distance that the ant cannot exceed on the X axis.
		This means that the ant can move in the [-limit, limit] range.
	*/
	float limitX;

	bool hasReachedLimit();

public:
	float width;
	float length;
	float height;

	float x;
	float y;
	float z;

	Ant(float x, float y, float z);

	void draw();
	bool collidesWithBullet(const Bullet *bullet);
};