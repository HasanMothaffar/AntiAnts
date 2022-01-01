#include "include/ant.h"
#include "levels/monitor/camera.h"

/* -- STATIC -- */
Bullet* Bullet::createBullet(const Camera *camera, float speed) {
	Bullet * bullet = new Bullet;
	bullet->position = camera->Position;
	bullet->view = camera->View;
	bullet->real = Vector3dCreate(
		camera->Position.x + camera->View.x,
		camera->Position.y + camera->View.y,
		camera->Position.z + camera->View.z
	);
	bullet->speed = speed;

	return bullet;
}

/* -- PRIVATE -- */

void Bullet::shift() {
	this->real.x += this->view.x * this->speed;
	this->real.y += this->view.y * this->speed;
	this->real.z += this->view.z * this->speed;
}

/* -- PUBLIC -- */
void Bullet::draw() {
		glPushMatrix();
		glColor3f(0, 0, 1);
		glPointSize(10);
		glBegin(GL_POINTS);
		glVertex3f(this->real.x, this->real.y, this->real.z);
		glEnd();
		this->shift();
		glPopMatrix();
	}

bool Bullet::isOutOfBoundaries(const Skybox *skybox) {
	return (
		this->real.z < -skybox->length || // Back face
		this->real.z > 0 || // Front face
		this->real.x > skybox->width || // Right face
		this->real.x < -skybox->width // Left face
	);
}