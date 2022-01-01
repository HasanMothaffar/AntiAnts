#pragma once

#include <vector>
#include <map>
#include <string>

#include "ant.h"
#include "bullet.h"
#include "camera.h"
#include "skybox.h"

class Level {
protected:
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
	Level();

	/* -- Drawing -- */
	virtual void drawScene();
	virtual void cleanScene();
	virtual void respondToKeyboard(bool *);
	void shootBullet();

	bool hasEnded();
};
