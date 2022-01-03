#pragma once

#include <vector>

#include "keyboard_piece.h"
#include "../../include/level.h"
#include "../../include/Model_3DS.h"

class Keyboard: public Level {
private:
	KeyboardPiece keyboard;
public:
	Keyboard();
	virtual void drawScene();
};