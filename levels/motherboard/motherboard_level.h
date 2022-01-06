#pragma once

#include "../../include/level.h"
#include "motherboard_skybox.h"
#include "motherboard_piece.h"

class Motherboard: public Level {
private:
	MotherboardPiece motherboard;
protected:
	virtual void loadAnts();
public:
	Motherboard();
	virtual void drawScene();
};