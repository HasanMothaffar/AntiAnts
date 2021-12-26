#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include "game.h"
#include "bullet.h"

Game::Game(Camera *camera, Skybox *skybox) {
	this->camera = camera;
	this->skybox = skybox;
	this->init();
}

void Game::init() {
	this->loadAnts();
}

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
	for (auto bullet: this->bullets) bullet->draw();
}

void Game::drawScene(int texture) {
	this->skybox->draw(texture);

	glDisable(GL_TEXTURE_2D);
	this->drawAnts();
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}

void Game::shootBullet() {
	this->bullets.push_back(Bullet::createBullet(this->camera));
}