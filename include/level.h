#pragma once

#include <vector>
#include <map>
#include <string>

#include "levels\monitor\camera.h"
#include "levels\monitor\skybox.h"
#include "include\ant.h"
#include "include\bullet.h"

class Level {
private:
	Camera *camera;
	Skybox *skybox;

	std::vector<Ant *> ants;
	std::vector<Bullet *> bullets;

	std::vector<std::vector<Ant *>::iterator> toRemoveAnts;
	std::vector<std::vector<Bullet *>::iterator> toRemoveBullets;

	void loadAnts();
	void drawAnts() const;
	void drawBullets() const;

	void removeOutOfBoundariesBullets();
	void removeShotAnts();

public:
	Level(Camera *, Skybox *);

	/* -- Drawing -- */
	virtual void drawScene();
	virtual void cleanScene();
	void shootBullet();

	bool hasEnded();
};
