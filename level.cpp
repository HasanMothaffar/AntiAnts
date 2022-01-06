#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <iostream>
#include <Sound.h>

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
	for (auto &ant: this->ants) ant.draw();
}

void Level::drawBullets() {
	for (auto &bullet: this->bullets) bullet.draw();
}

void Level::removeOutOfBoundariesBullets() {
	for (auto it = this->bullets.begin(); it != this->bullets.end(); it++)
	{
		if (it->isOutOfBoundaries(this->skybox))
		{
			std::cout << "Bullet: " << it->real.x << " " << it->real.y << " " << it->real.z << " out of boundaries\n\n";
			this->toRemoveBullets.push_back(it);
		}
	}
}

void Level::removeShotAnts() {
	for (auto antIterator = this->ants.begin(); antIterator != this->ants.end(); antIterator++) {
		for (auto bulletIterator = this->bullets.begin(); bulletIterator != this->bullets.end(); bulletIterator++) {
			if (antIterator->collidesWithBullet(&(*bulletIterator))) {
				PlaySound("assets/sounds/Explode.wav", NULL, SND_ASYNC);
				std::cout << "Ant: " << antIterator->x << " " << antIterator->y << " " << antIterator->z << " dead\n";
				std::cout << "Bullet: " << bulletIterator->real.x << " " << bulletIterator->real.y << " " << bulletIterator->real.z << " removed\n\n";
				this->toRemoveAnts.push_back(antIterator);
				this->toRemoveBullets.push_back(bulletIterator);
			}
		}
	}
}

/* -- PUBLIC -- */
Level::Level() { 
	std::cout << "Inside Level constructor. " << this->ants.size() << "\n";
}

Level::~Level() { 
	std::cout << "Inside Level destructor.\n";
	delete this->camera;
	delete this->skybox;
}

void Level::drawScene() {
	this->skybox->draw();
	this->drawAnts();
	this->drawBullets();
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
	this->camera->respondToKeyboard(keys, this->skybox);
}

void Level::respondToMouse(int mouseX, int prevMouseX) {
	this->camera->respondToMouse(mouseX, prevMouseX);
}

void Level::shootBullet() {
	this->bullets.push_back(Bullet::createBullet(this->camera));
	PlaySound("assets/sounds/shot.wav", NULL, SND_ASYNC);
}

bool Level::hasEnded() {
	return this->ants.size() == 0;
}