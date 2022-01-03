#include <Windows.h>
#include <GL.H>

#include "../../include/camera.h"
#include "../../include/utility.h"
#include "motherboard_level.h"
//#include "motherboard_camera.h"
#include "motherboard_skybox.h"
#include "motherboard_piece.h"

Motherboard::Motherboard(): Level() { 
	this->skybox = new MotherboardSkybox(400, 380, 380);
	this->camera = new Camera();
	this->motherboard = MotherboardPiece();
	this->loadAnts();
}

void Motherboard::loadAnts() {
	for (float x = -100; x <= 100; x += 20)
	{
		for (float z = -50; z >= -150; z -= 50)
		{
			this->ants.push_back(Ant(x, 0, z));
		}
	}
}

void Motherboard::drawScene() {
	this->skybox->draw();
	this->motherboard.StartMotherboardLevel(1, textures["motherboard/cpu2"], textures["motherboard/grey"],
		textures["motherboard/whiteSlot"], textures["motherboard/blueSlot"],
		textures["motherboard/gold_metal2"], textures["motherboard/heat_sink"], textures["motherboard/BIOS2"],
		textures["motherboard/ram"], textures["motherboard/red"], textures["motherboard/cmos"],
		0, 1, textures["motherboard/copperCable2"], 1, textures["motherboard/white_black"],
		textures["motherboard/copperCable3"], textures["motherboard/black"], textures["motherboard/black2"]);

	// glDisable(GL_TEXTURE_2D);
	this->drawAnts();
	this->drawBullets();
	glEnable(GL_TEXTURE_2D);
}