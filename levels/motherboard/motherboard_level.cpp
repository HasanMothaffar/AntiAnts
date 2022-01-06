#include <Windows.h>
#include <GL.H>

#include "../../include/camera.h"
#include "../../include/utility.h"
#include "motherboard_level.h"
#include "motherboard_skybox.h"
#include "motherboard_piece.h"

Motherboard::Motherboard(): Level() { 
	this->skybox = new MotherboardSkybox(200, 380, 370);
	this->camera = new Camera();
	this->motherboard = MotherboardPiece();
	this->loadAnts();
}

void Motherboard::loadAnts() {
	this->ants.push_back(Ant(0, 0, -10)); //1
	this->ants.push_back(Ant(10, 0, -40)); //2
	this->ants.push_back(Ant(30, 0, -30)); //3
	this->ants.push_back(Ant(30, 0, -90)); //4
	this->ants.push_back(Ant(50, 0, -120)); //5
	this->ants.push_back(Ant(100, 0, -150)); //6
	this->ants.push_back(Ant(130, 0, -10)); //7
	this->ants.push_back(Ant(150, 0, -20)); //8
	this->ants.push_back(Ant(0, 0, -120)); //9
	this->ants.push_back(Ant(40, 0, -130)); //10
}

void Motherboard::drawScene() {
	glPushMatrix();
	glTranslatef(0, -2, -180);

	this->skybox->draw();
	this->motherboard.StartMotherboardLevel(1, textures["motherboard/cpu2"], textures["motherboard/grey"],
		textures["motherboard/whiteSlot"], textures["motherboard/blueSlot"],
		textures["motherboard/gold_metal2"], textures["motherboard/heat_sink"], textures["motherboard/BIOS2"],
		textures["motherboard/ram"], textures["motherboard/red"], textures["motherboard/cmos"],
		0, 1, textures["motherboard/copperCable2"], 1, textures["motherboard/white_black"],
		textures["motherboard/copperCable3"], textures["motherboard/black"], textures["motherboard/black2"]);
	glPopMatrix();
	this->drawBullets();

	glTranslatef(0, -1.5, 0);
	this->drawAnts();
	glEnable(GL_TEXTURE_2D);
}