#pragma once

#include "utility.h"
#include "skybox.h"
#include "camera.h"

class Bullet
{
private:
	void shift();

public:
	Vector3dStruct position;
	Vector3dStruct view;
	Vector3dStruct real;

	float speed;

	static Bullet createBullet(const Camera *camera, float speed = 1.0f);

	void draw();

	/*
		Returns whether the bullet has exceeded
		the limits (faces) of the skybox. 
	*/
	bool isOutOfBoundaries(const Skybox *skybox);
};