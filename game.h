#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <string>

#include "camera.h"
#include "skybox.h"
#include "ant.h"
#include "bullet.h"

class Game {
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
	Game(Camera *, Skybox *);

	/* -- Drawing -- */
	void drawScene();
	void cleanScene();
	void shootBullet();

	bool hasEnded();
};

#endif // !GAME_H
