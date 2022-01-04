#include <Windows.h>
#include <math.h>
#include <gl.h>			// Header File For The OpenGL32 Library
#include <map>
#include <string>
//#include <Sound.h>

#include "include/texture.h"
#include "include/utility.h"

#define SQR(x) (x*x)
#define NULL_VECTOR Vector3dCreate(0.0f,0.0f,0.0f)

std::string textureNames[] = {
	"circuit",
	"windows",
	"pc1",
	"levelsBanner",
	"one",
	"two",
	"three",
	"four",
	"five",
	"motherboard/case",
	"motherboard/m2",
	"motherboard/cpu2",
	"motherboard/grey",
	"motherboard/whiteSlot",
	"motherboard/blueSlot",
	"motherboard/gold_metal2",
	"motherboard/heat_sink",
	"motherboard/BIOS2",
	"motherboard/ram",
	"motherboard/red",
	"motherboard/cmos",
	"motherboard/copperCable2",
	"motherboard/white_black",
	"motherboard/copperCable3",
	"motherboard/black",
	"motherboard/black2",
	"ups/batteryMinus",
	"ups/batteryPlus",
	"ups/digitalNumber",
	"ups/UPSBoard",
	"ups/wall",
	"ssd/cir"
};

std::string soundNames[] = {
	"shot",
};

std::map<std::string, int> textures;
std::map<std::string, Sound> sounds;

Vector3dStruct Vector3dCreate(GLfloat x, GLfloat y, GLfloat z)
{
	Vector3dStruct tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return tmp;
}

GLfloat LengthVector3d(Vector3dStruct* v)
{
	return (GLfloat)(sqrt(SQR(v->x) + SQR(v->y) + SQR(v->z)));
}

Vector3dStruct NormalizeVector3d(Vector3dStruct v)
{
	Vector3dStruct res;
	float L = LengthVector3d(&v);
	if (L == 0.0f) return NULL_VECTOR;
	res.x = v.x / L;
	res.y = v.y / L;
	res.z = v.z / L;
	return res;
}

Color toRGB(float r, float g, float b) {
	Color color = {
		r / 255.0f,
		g / 255.0f,
		b / 255.0f
	};

	return color;
}

void loadGameTextures() {
	for (auto name: textureNames) {
		std::string filepath = "assets/" + name + ".bmp";
		std::pair<std::string, int> texture (name, LoadTexture(filepath.c_str(), 255));

		textures.insert(texture);
	}
}

void loadGameSounds() {
	/*INIT initialize = INIT();
	initialize.InitOpenAL();

	std::pair<std::string, Sound> sound1 ("shot", Sound("assets/sounds/shot.wav"));
	sounds.insert(sound1);*/
}


void drawLevelCube(int texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Back Face
	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Face
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Right face

	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// Left Face
	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawLevelManager()
{
	
	glTranslatef(-3,0,-15);
	//Banner
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["levelsBanner"]);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(1,2,3);
	glTexCoord2f(1,0);
	glVertex3f(5,2,3);
	glTexCoord2f(1,1);
	glVertex3f(5,4,3);
	glTexCoord2f(0,1);
	glVertex3f(1,4,3);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//level 1
	glPushMatrix();
	glTranslatef(-3,0,0);
	drawLevelCube(textures["one"]);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3,-3,0);
	drawLevelCube(textures["one"]);
	glPopMatrix();

	//level 2
	glPushMatrix();
	glTranslatef(0,0,0);
	drawLevelCube(textures["two"]);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-3,0);
	drawLevelCube(textures["two"]);
	glPopMatrix();

	//level 3
	glPushMatrix();
	glTranslatef(3,0,0);
	drawLevelCube(textures["three"]);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3,-3,0);
	drawLevelCube(textures["three"]);
	glPopMatrix();

	//level 4
	glPushMatrix();
	glTranslatef(6,0,0);
	drawLevelCube(textures["four"]);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(6,-3,0);
	drawLevelCube(textures["four"]);
	glPopMatrix();

	//level 5
	glPushMatrix();
	glTranslatef(9,0,0);
	drawLevelCube(textures["five"]);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(9,-3,0);
	drawLevelCube(textures["five"]);
	glPopMatrix();

	//Surface
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glBegin(GL_QUADS);
	glColor4ub(81, 65, 79, 100);
	glVertex3f(40, -1, -50);
	glVertex3f(-40, -1, -50);
	glVertex3f(-40, -1, +50);
	glVertex3f(40, -1, +50);
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
	glColor3ub(255,255,255);
}