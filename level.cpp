#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library

#include "include/level.h"
#include "include/bullet.h"
#include "include/Model_3DS.h"

/* -- PRIVATE -- */
void Level::loadAnts() {
	for (float x = -this->skybox->width + 20; x <= this->skybox->width - 20; x += 20)
	{
		for (float z = -50; z >= -150; z -= 50)
		{
			this->ants.push_back(Ant(x, 0, z));
		}
	}
}

void Level::drawAnts() {
	for (auto ant: this->ants) ant.draw();
}

void Level::drawBullets() {
	for (auto &bullet: this->bullets) bullet.draw();
}

void Level::removeOutOfBoundariesBullets() {
	for (auto it = this->bullets.begin(); it != this->bullets.end(); it++)
	{
		if (it->isOutOfBoundaries(this->skybox))
		{
			this->toRemoveBullets.push_back(it);
		}
	}
}

void Level::removeShotAnts() {
	for (auto antIterator = this->ants.begin(); antIterator != this->ants.end(); antIterator++) {
		for (auto bulletIterator = this->bullets.begin(); bulletIterator != this->bullets.end(); bulletIterator++) {
			if (antIterator->collidesWithBullet(&(*bulletIterator))) {
				this->toRemoveAnts.push_back(antIterator);
				this->toRemoveBullets.push_back(bulletIterator);
			}
		}
	}
}

/* -- PUBLIC -- */
Level::Level() { }

void Level::drawScene() {
	glTranslatef(0, -1, 0);
	glEnable(GL_TEXTURE_2D);
	this->skybox->draw();
	this->drawAnts();

	// glDisable(GL_TEXTURE_2D);
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}

void Level::cleanScene() {
	this->removeOutOfBoundariesBullets();
	this->removeShotAnts();

	for (auto it = this->toRemoveBullets.begin(); it != this->toRemoveBullets.end(); it++) {
		this->bullets.erase(*it);
	}

	this->toRemoveBullets.clear();

	for (auto it = this->toRemoveAnts.begin(); it != this->toRemoveAnts.end(); it++) {
		this->ants.erase(*it);
	}

	this->toRemoveAnts.clear();
}

void Level::respondToKeyboard(bool *keys) {
	this->camera->respondToKeyboard(keys);
}

void Level::shootBullet() {
	this->bullets.push_back(Bullet::createBullet(this->camera));
}

bool Level::hasEnded() {
	return this->ants.size() == 0;
}