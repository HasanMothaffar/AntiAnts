#ifndef BULLET_H
#define BULLET_H

#include "utility.h"
#include "camera.h"

class Bullet {
public:
	Vector3dStruct position;
	Vector3dStruct view;
	Vector3dStruct real;

	float speed;

	void draw() {
		glPushMatrix();
		glColor3f(0, 0, 1);
		glPointSize(20);
		glBegin(GL_POINTS);
		glVertex3f(real.x, real.y, real.z);
		glEnd();
		shift();
		glPopMatrix();
	}

	bool isOutOfBoundaries(const Skybox &skybox) {
		return real.z < -skybox.length;
	}

	static Bullet* createBullet(const Camera &camera, float speed = 6.0f) {
		Bullet * bullet = new Bullet;

		bullet->position = camera.Position;
		bullet->view = camera.View;
		bullet->real = Vector3dCreate(
			camera.Position.x + camera.View.x,
			camera.Position.y + camera.View.y,
			camera.Position.z + camera.View.z
		);
		bullet->speed = speed;

		return bullet;
	}

private:
	void shift() {
		real.x += view.x * speed;
		real.y += view.y * speed;
		real.z += view.z * speed;
	}
};

#endif