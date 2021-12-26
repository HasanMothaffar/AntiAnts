#ifndef GAME_H
#define GAME_H

#include <vector>
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
	std::vector<std::vector<Bullet *>::iterator> toDeleteBullets;

	void loadAnts();
	void drawBullets() const;
	void drawAnts() const;

public:
	Game(Camera *, Skybox *);
	void init();
	void drawScene(int texture);
	void shootBullet();
};

#endif // !GAME_H
