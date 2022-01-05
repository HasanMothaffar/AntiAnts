#pragma once


#include "../../include/level.h"
#include "../../include/Model_3DS.h"

#include <vector>

class UPS: public Level {
private:
	float fanrotate;
	std::vector<Model_3DS *> circuits;

	virtual void loadAnts();
public:
	UPS();
	virtual void drawScene();
	void loadCircuits();
	void drawCircuits();

	void drawUPSBoard();
	void drawBattery(GLfloat BatteryX1,GLfloat BatteryX2,GLfloat BatteryY1,GLfloat BatteryY2,GLfloat BatteryZ1,GLfloat BatteryZ2);
	void drawBatteries();
	void drawMonitor(GLfloat MonitorX1,GLfloat MonitorX2,GLfloat MonitorY1,GLfloat MonitorY2,GLfloat MonitorZ);
	void drawCylinder(GLfloat radius, GLfloat height );
	void DrawRing(int radius,int pointSize  );
	void drawFan(GLfloat fanAngle , GLfloat x , GLfloat y1 ,GLfloat y2 , GLfloat y3 , GLfloat z);
	void  DrawconverterQuad();
	void  drawconverter();
	void  convertertriangle();
	void  trans();
};