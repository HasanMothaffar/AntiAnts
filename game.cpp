#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include "game.h"
#include "bullet.h"

/* -- PRIVATE -- */
void Game::loadAnts() {
	for (float x = -this->skybox->width + 20; x <= this->skybox->width - 20; x += 20)
	{
		for (float z = -50; z >= -150; z -= 50)
		{
			this->ants.push_back(new Ant(x, 0, z));
		}
	}
}

void Game::drawAnts() const {
	for (auto ant: this->ants) ant->draw();
}

void Game::drawBullets() const {
	if (this->bullets.size() != 0) {
		int x = 0;
	}
	for (auto bullet: this->bullets) bullet->draw();
}

void Game::removeOutOfBoundariesBullets() {
	for (auto it = this->bullets.begin(); it != this->bullets.end(); it++)
	{
		if ((*it)->isOutOfBoundaries(this->skybox))
		{
			this->toRemoveBullets.push_back(it);
		}
	}
}

void Game::removeShotAnts() {
	for (auto antIterator = this->ants.begin(); antIterator != this->ants.end(); antIterator++) {
		for (auto bulletIterator = this->bullets.begin(); bulletIterator != this->bullets.end(); bulletIterator++) {
			if ((*(*antIterator)).collidesWithBullet(*bulletIterator)) {
				this->toRemoveAnts.push_back(antIterator);
				this->toRemoveBullets.push_back(bulletIterator);
			}
		}
	}
}

/* -- PUBLIC -- */
Game::Game(Camera *camera, Skybox *skybox) {
	this->camera = camera;
	this->skybox = skybox;
	this->loadAnts();
}

void Game::drawScene(int texture) {
	this->skybox->draw(texture);

	glDisable(GL_TEXTURE_2D);
	this->drawAnts();
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}

void Game::cleanScene() {
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

void Game::shootBullet() {
	this->bullets.push_back(Bullet::createBullet(this->camera));
}

bool Game::hasEnded() {
	return this->ants.size() == 0;
}