#include "include/ant.h"
#include "include/camera.h"

/* -- STATIC -- */
Bullet Bullet::createBullet(const Camera *camera, float speed) {
	Bullet bullet;
	bullet.position = camera->Position;
	bullet.view = camera->View;
	bullet.real = Vector3dCreate(
		camera->Position.x + camera->View.x,
		camera->Position.y + camera->View.y,
		camera->Position.z + camera->View.z
	);
	bullet.speed = speed;

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
		glDisable(GL_TEXTURE_2D);

		glPushMatrix();
		glTranslatef(0, -0.5, 0);
		glColor3f(1, 0, 0);
		glPointSize(15);
		glBegin(GL_POINTS);
		glVertex3f(this->real.x, this->real.y, this->real.z);
		glEnd();
		this->shift();
		glPopMatrix();

		glEnable(GL_TEXTURE_2D);
	}

bool Bullet::isOutOfBoundaries(const Skybox *skybox) {
	return (
		this->real.z < -skybox->length || // Back face
		this->real.z > skybox->length || // Front face
		this->real.x > skybox->width || // Right face
		this->real.x < -skybox->width // Left face
	);
}