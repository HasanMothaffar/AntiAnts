#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <texture.h>
#include <math.h>

#include "../../include/camera.h"
#include "../../include/utility.h"
#include "ups_skybox.h"
#include "ups_level.h"

UPS::UPS() { 
	this->camera = new Camera();
	this->skybox = new UPSSkybox(300, 200, 200);
	this->loadAnts();
}

void UPS::loadAnts() {
	this->ants.push_back(Ant(0, 0, -2));
}

void UPS::drawScene() {
	glTranslatef(0, -2, 0);
	this->skybox->draw();
	this-> drawUPSBoard();
	this-> drawBattery(-140,-80,0,15,-95,-55);
	this-> drawBattery(-140,-80,0,15,-40,0);
	this->drawBattery(-140,-80,0,15,40,80);
	this-> drawMonitor(-150,150,0,100,-100);
		glPushMatrix();
	glRotatef(-90,1,0,0);
	glTranslatef(0,17,0);
	this-> drawCylinder(5,11);
	glTranslatef(15,0,0);
	this-> drawCylinder(5,11);
	glTranslatef(15,4,0);
this-> 	drawCylinder(5,11);
	glTranslatef(15,-9,0);
	this-> drawCylinder(5,11);

	glTranslatef(15,-19,0);
	drawCylinder(5,11);
	glTranslatef(15,-19,0);
	drawCylinder(5,11);glTranslatef(15,-19,0);
	//drawCylinder(5,11);


	glPopMatrix();
	/*glPushMatrix();
	//glRotatef(90,1,0,0);
	glTranslatef(10,0,0);
	this-> DrawRing(55,55);
	glPopMatrix();*/
	glPushMatrix();
	glTranslatef(230,0,0);
	glRotatef(90,0,1,0);
	glTranslatef(0,50,-80);
	glRotatef(-90,1,0,0);
	glRotatef(-90,1,0,0);
	glTranslatef(-5,30,0);
	//glRotatef(180,0,1,0);
	
	this-> drawCylinder(5,13);
	glRotatef(90,1,0,0);
	//drawFan(
	this-> drawFan(fanrotate,20,3,20,7,20);
	
	glPopMatrix();
	   glPushMatrix();

   glTranslatef(-5,5,40);	
    glColor3ub(148, 82, 31);
   auxSolidBox(30,10,20);
    glTranslated(0,5,0);
  // glRotatef(90,1,0,0);
   glColor3ub(230, 237, 12);
auxSolidTorus(5,12);

   glColor3f(1,1,1);
   glPopMatrix();
    glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(60,1.5,0);

   drawconverter();

   glColor3f(1,1,1);
    glPopMatrix();
	//this-> ;
	//this-> ;

	this->fanrotate += 70;

	this->drawAnts();

	glTranslatef(0, 2, 0);
	this->drawBullets();
}


void UPS::drawFan(GLfloat fanAngle , GLfloat x , GLfloat y1 ,GLfloat y2 , GLfloat y3 , GLfloat z)
{
	glColor3ub(70, 52, 235);
	////Fence
	
	//x1 = 20 , y1=3 , y2 = 10 , y3 = 4 , z = 20 
	//Left
	glBegin(GL_QUADS);
	glVertex3f(-x-5,y1,-z);
	glVertex3f(-x-5,0,-z);
	glVertex3f(-x-5,0,z);
	glVertex3f(-x-5,y1,z);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-x-5,y2,-z);
	glVertex3f(-x-5,y3,-z);
	glVertex3f(-x-5,y3,z);
	glVertex3f(-x-5,y2,z);
	glEnd();
	////////////////////////

	//Right
	glBegin(GL_QUADS);
	glVertex3f(x+5,y1,-z);
	glVertex3f(x+5,0,-z);
	glVertex3f(x+5,0,z);
	glVertex3f(x+5,y1,z);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(x+5,y2,-z);
	glVertex3f(x+5,y3,-z);
	glVertex3f(x+5,y3,z);
	glVertex3f(x+5,y2,z);
	glEnd();
	/////////////////////////


	//back
	glBegin(GL_QUADS);
	glVertex3f(-x-5,0,z);
	glVertex3f(x+5,0,z);
	glVertex3f(x+5,y1,z);
	glVertex3f(-x-5,y1,z);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-x-5,y3,z);
	glVertex3f(x+5,y3,z);
	glVertex3f(x+5,y2,z);
	glVertex3f(-x-5,y2,z);
	glEnd();
	/////////////////////////
	//front
	glBegin(GL_QUADS);
	glVertex3f(-x-5,0,-z);
	glVertex3f(x+5,0,-z);
	glVertex3f(x+5,y1,-z);
	glVertex3f(-x-5,y1,-z);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-x-5,y3,-z);
	glVertex3f(x+5,y3,-z);
	glVertex3f(x+5,y2,-z);
	glVertex3f(-x-5,y2,-z);
	glEnd();
	

	
	glRotatef(fanAngle,0,1,0);
	fanAngle+=50;
	glColor3ub(1,0,0);
	//fans
	glColor3ub(100,100,200);
    for(int i=0;i<8;i++)
    {
	glRotatef(45,0,1,0);
	glBegin(GL_QUADS);
	glVertex3f(0,y3+3,z-20);
	glVertex3f(+x-3,y3+3,z-30);
	glVertex3f(+x-3,y3,-z+15);
	glVertex3f(0,y3,-z+25);
	glEnd();
    }	
	glColor3f(1,1,1);
}
void UPS:: DrawRing(int radius,int pointSize  )
{

	glPushMatrix();
	glColor3ub(255, 255, 255);
	//glRotatef(90, 1, 0, 0);
	GL_POINT_SMOOTH;
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	double x,y;
	for (float i = -3.14; i <= 3.14; i += 0.0001)
	{
		x = radius * sin(i);
		y = radius * cos(i);
		glColor3ub(100, 64, 255);
	//	glVertex3d(0, 0, 0);
		glVertex3d(x, y, 0);
	}
	glEnd();
	glPopMatrix();
	glColor3f(1,1,1);

}
void UPS:: drawUPSBoard()
{
	GLfloat  UPSBoardX=150, UPSBoardZ=100;
	//glColor3f(1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["ups/UPSBoard"]);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-UPSBoardX,0,UPSBoardZ);
	glTexCoord2f(1,0);
	glVertex3f(+UPSBoardX,0,UPSBoardZ);
	glTexCoord2f(1,1);
	glVertex3d(+UPSBoardX,0,-UPSBoardZ);
	glTexCoord2f(0,1);
	glVertex3f(-UPSBoardX,0,-UPSBoardZ);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3f(1,1,1);
}
void UPS:: drawBatteries()
{
	
	
}
void UPS:: drawBattery(GLfloat BatteryX1,GLfloat BatteryX2,GLfloat BatteryY1,GLfloat BatteryY2,GLfloat BatteryZ1,GLfloat BatteryZ2)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["ups/batteryPlus"]);
	glBegin(GL_QUADS);
	//front face
	glTexCoord2f(0,0);
	glVertex3f(BatteryX1,BatteryY1,BatteryZ2);
	glTexCoord2f(1,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ2);
	glTexCoord2f(1,1);
	glVertex3d(BatteryX2,BatteryY2,BatteryZ2);
	glTexCoord2f(0,1);
	glVertex3f(BatteryX1,BatteryY2,BatteryZ2);
	glEnd();
	
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures["ups/batteryMinus"]);
	glBegin(GL_QUADS);
	//back face 
	glTexCoord2f(0,0);
	glVertex3f(BatteryX1,BatteryY1,BatteryZ1);
	glTexCoord2f(1,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ1);
	glTexCoord2f(1,1);
	glVertex3d(BatteryX2,BatteryY2,BatteryZ1);
	glTexCoord2f(0,1);
	glVertex3f(BatteryX1,BatteryY2,BatteryZ1);
	
	
		glColor3f(1,1,1);
	glColor3f(0.1,0.1,0.1);
	//left face
	glVertex3f(BatteryX1,BatteryY1,BatteryZ1);

	glVertex3f(BatteryX1,BatteryY1,BatteryZ2);

	glVertex3d(BatteryX1,BatteryY2,BatteryZ2);

	glVertex3f(BatteryX1,BatteryY2,BatteryZ1);

	
	
	//right face
	//glTexCoord2f(0,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ1);
	//glTexCoord2f(1,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ2);
//	glTexCoord2f(1,1);
	glVertex3d(BatteryX2,BatteryY2,BatteryZ2);
//	glTexCoord2f(0,1);
	glVertex3f(BatteryX2,BatteryY2,BatteryZ1);
	
		//down face 
	//glTexCoord2f(0,0);
	glVertex3f(BatteryX1,BatteryY1,BatteryZ2);
	//glTexCoord2f(1lkl,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ2);
	//glTexCoord2f(1,1);
	glVertex3d(BatteryX2,BatteryY1,BatteryZ1);
	//glTexCoord2f(0,1);
	glVertex3f(BatteryX1,BatteryY1,BatteryZ1);

		//up face 
	//glTexCoord2f(0,0);
	glVertex3f(BatteryX1,BatteryY2,BatteryZ2);
//	glTexCoord2f(1,0);
	glVertex3f(BatteryX2,BatteryY2,BatteryZ2);
//	glTexCoord2f(1,1);
	glVertex3d(BatteryX2,BatteryY2,BatteryZ1);
	//glTexCoord2f(0,1);
	glVertex3f(BatteryX1,BatteryY2,BatteryZ1);

		glColor3f(1,1,1);
	glColor3f(0,0,1);
	//Minus face
	//glTexCoord2f(0,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ1+5);
	//glTexCoord2f(1,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ2-30);
//	glTexCoord2f(1,1);
	glVertex3d(BatteryX2,BatteryY2/2,BatteryZ2-30);
//	glTexCoord2f(0,1);
	glVertex3f(BatteryX2,BatteryY2/2,BatteryZ1+5);
	glColor3f(1,1,1);

	glColor3f(1,0,0);
	//Plus face
	//glTexCoord2f(0,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ1+30);
	//glTexCoord2f(1,0);
	glVertex3f(BatteryX2,BatteryY1,BatteryZ2-5);
//	glTexCoord2f(1,1);
	glVertex3d(BatteryX2,BatteryY2/2,BatteryZ2-5);
//	glTexCoord2f(0,1);
	glVertex3f(BatteryX2,BatteryY2/2,BatteryZ1+30);
	glColor3f(1,1,1);
	
	glEnd();
	glColor3f(1,1,1);
	glDisable(GL_TEXTURE_2D);
}

	void UPS::drawMonitor(GLfloat MonitorX1,GLfloat MonitorX2,GLfloat MonitorY1,GLfloat MonitorY2,GLfloat MonitorZ)
	{
				glColor3f(1,0,0);
		
		glBegin(GL_QUADS);
	//	glTexCoord2f(0,0);
	glVertex3f(MonitorX1,MonitorY1,MonitorZ);
	//glTexCoord2f(1,0);
	glVertex3f(MonitorX2,MonitorY1,MonitorZ);
	//glTexCoord2f(1,1);
	glVertex3d(MonitorX2,MonitorY2,MonitorZ);
	//glTexCoord2f(0,1);
	glVertex3f(MonitorX1,MonitorY2,MonitorZ);
	   glEnd();
	   glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures["ups/digitalNumber"]);
	
	   glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(MonitorX1+100,MonitorY1+25,MonitorZ);
	glTexCoord2f(1,0);
	glVertex3f(MonitorX2-100,MonitorY1+25,MonitorZ);
	glTexCoord2f(1,1);
	glVertex3d(MonitorX2-100,MonitorY2-25,MonitorZ);
	glTexCoord2f(0,1);
	glVertex3f(MonitorX1+100,MonitorY2-25,MonitorZ);
	    glEnd();
		glDisable(GL_TEXTURE_2D);
	}
		void UPS::drawCylinder(GLfloat radius, GLfloat height )
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
	
	
    /** Draw the tube */
    glColor3ub(0,0,0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while(angle < 2*3.14 ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
			glTexCoord2f(0,0);
            glVertex3f(x, y , height);
			glTexCoord2f(1,0);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
		glTexCoord2f(1,1);
        glVertex3f(radius, 0.0, height);
		glTexCoord2f(0,1);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
	
    glColor3ub(78, 182, 194);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*3.14 ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
			glTexCoord2f(x,y);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
	
        glVertex3f(radius, 0.0, height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
}
void UPS:: DrawconverterQuad(){
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8, 0.8, 0.8);

	glVertex3d(-1, -1, 0);

	glVertex3d(-1, 1, 0);

	glVertex3d(1, -1, 0);

	glVertex3d(1, 1, 0);
	glEnd();
	glFlush();
	//����
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3d(-1, -1, 0);
	glVertex3d(-1, 1, 0);
	glVertex3d(1, 1, 0);
	glVertex3d(1, -1, 0);
	glEnd();
	glFlush();
}


void UPS:: drawconverter(){
				//glRotated(90, 1, 0, 0);
//	glRotated(-x, 1, 0, 0);
//	x += 4;
	//right(1)

	glPushMatrix();
	glScaled(9, 2, 1);
	glTranslated(0, 0.25, 0);
	this->DrawconverterQuad();
	glPopMatrix();

	//left(2)
	glPushMatrix();
	glScaled(9, 2, 1);
	glTranslated(0, 0.25, -8);
	this->DrawconverterQuad();
	glPopMatrix();

	//ground(3)
	glPushMatrix();
	glScaled(10, 1, 4);
	glTranslated(-0.09, -1.5, -1);
	glRotated(90, 1, 0, 0);
	this->DrawconverterQuad();
	glPopMatrix();

	//face(4)
	glPushMatrix();
	glScaled(9, 2, 7);
	glTranslated(-1.2, 0.25, -0.65);
	glRotated(90, 0, 1, 0);
	this->DrawconverterQuad();
	glPopMatrix();

	//back(5)
	glPushMatrix();
	glScaled(9, 2, 4);
	glTranslated(1, 0.25, -1);
	glRotated(90, 0, 1, 0);
	this->DrawconverterQuad();
	glPopMatrix();

	//jack
	
	glPushMatrix();
	glTranslated(-11, 0.25, -6.5);
	glRotated(90, 0, 1, 0);
	auxSolidBox(3.5, 1.5, 2);

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslated(-0.7, 0, -0.5);
	glRotated(90, 1, 0, 0);
	auxSolidCylinder(0.4, 2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0.5, 0, -0.5);
	glRotated(90, 1, 0, 0);
	auxSolidCylinder(0.4, 2);
	glPopMatrix();

	glColor3f(0,0,0);
	glPushMatrix();
	glTranslated(2.3, 0, -0.5);
	glRotated(90, 1, 0, 0);
	auxSolidCylinder(0.4, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.3, 0, -0.5);
	glRotated(90, 1, 0, 0);
	auxSolidCylinder(0.4, 2);
	glPopMatrix();
	glPopMatrix();
	glColor3f(1,1,1);
	//endjack

	//roof
		glPushMatrix();
	glScaled(10, 1, 1);
	glTranslated(-0.09, 2.5, -1);
	glRotated(90, 1, 0, 0);
	DrawconverterQuad();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(-2.5, 2.5, -4.8);
	glScaled(1.2, 1.2, 1.2);
	this->convertertriangle();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(6.4, 2.5, -4.8);
	glScaled(1.2, 1.2, 1.2);
	this->convertertriangle();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(6.4, 2.5, -3.19);
	glScaled(1.2, 1.2, 1.2);
	glRotated(180,1,0,0);
	this->convertertriangle();
	glPopMatrix();
	//
	
	glPushMatrix();
	glTranslated(-2.5, 2.5, -3.19);
	glScaled(1.2, 1.2, 1.2);
	glRotated(180, 1, 0, 0);
	this->convertertriangle();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(1.6, 2.5, -6);
	glScaled(1.2, 1.2, 1.2);
	glRotated(90, 0, 1, 0);
	this->convertertriangle();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(-7.3, 2.5, -6);
	glScaled(1.2, 1.2, 1.2);
	glRotated(90, 0, 1, 0);
	this->convertertriangle();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(-8.45, 2.5, -3.19);
	glScaled(1.2, 1.2, 1.2);
	glRotated(-180, 0, 1, 0);
	this->convertertriangle();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(0.6, 2.5, -3.19);
	glScaled(1.2, 1.2, 1.2);
	glRotated(-180, 0, 1, 0);
	this->convertertriangle();
	glPopMatrix();
	//
	glPushMatrix();
	glScaled(10, 1, 1);
	glTranslated(-0.09, 2.5, -7);
	glRotated(90, 1, 0, 0);
	DrawconverterQuad();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-9.75, 2.5, -4);
	glScaled(1.25, 1, 4);
	glRotated(90, 1, 0, 0);
	DrawconverterQuad();
	glPopMatrix();

	glPushMatrix();
	glTranslated(7.75, 2.5, -4);
	glScaled(1.25, 1, 4);
	glRotated(90, 1, 0, 0);
	DrawconverterQuad();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 2.5, -4);
	glScaled(1.5, 1, 4);
	glRotated(90, 1, 0, 0);
	DrawconverterQuad();
	glPopMatrix();
	
	//endRoof
	glPushMatrix();
	this->convertertriangle();
	glPopMatrix();


	glEnd();
}
//void UPS::
void UPS:: convertertriangle(){
	glBegin(GL_TRIANGLE_FAN);
	glPushMatrix();
	glColor3f(0.8, 0, 0.8);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, -1);
	glVertex3d(-1, 0,-1);	
	glPopMatrix();
	glEnd();
	glFlush();
}