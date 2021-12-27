#ifndef BULLET_H
#define BULLET_H

#include "utility.h"
#include "camera.h"
#include "skybox.h"

class Bullet {
private:
	void shift();

public:
	Vector3dStruct position;
	Vector3dStruct view;
	Vector3dStruct real;

	float speed;

	static Bullet* createBullet(const Camera *camera, float speed = 6.0f);

	void draw();
	
	/*
		Returns whether the bullet has exceeded
		the limits (faces) of the skybox. 
	*/
	bool isOutOfBoundaries(const Skybox &skybox);
};

#endif