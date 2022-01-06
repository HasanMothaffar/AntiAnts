#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

#include "../../include/level.h"
#include "../../include/camera.h"
#include "../../include/ant.h"

#include "ssd_level.h"
#include "ssd_skybox.h"

/* -- PRIVATE -- */

void SSD::loadAnts() {
	this->ants.push_back(Ant(-20, 0, -190));
	this->ants.push_back(Ant(-35, 0, -140));
	this->ants.push_back(Ant(0, 0, -130));
	this->ants.push_back(Ant(-18, 0, -115));
	this->ants.push_back(Ant(10, 0, -105));
	this->ants.push_back(Ant(-40, 0, -105));
	this->ants.push_back(Ant(-40, 0, -70));
	this->ants.push_back(Ant(15, 0, -60)); 
	this->ants.push_back(Ant(-20, 0, -25)); 
	this->ants.push_back(Ant(10, 0, -25)); 
}

void SSD::loadCircuits() {
	for (int i = 3; i < 8; i++) {
		Model_3DS *circuit = new Model_3DS();
		circuit->Load((char *) "assets/22v10.3ds");
		circuit->pos.x = 35;
		circuit->pos.y = 3;
		circuit->pos.z = - i * 11;
		circuit->Materials[0].tex.LoadBMP("assets/22v10.bmp");

		unsigned char color = 100;
		circuit->Materials[1].tex.BuildColorTexture(color, color, color);
		circuit->Materials[2].tex.BuildColorTexture(color, color, color);
		circuit->scale = 5;
		circuits.push_back(circuit);
	}
}

/* -- PUBLIC -- */
SSD::SSD(): Level() {
	this->skybox = new SSDSkybox(55.0f, 50.0f, 200.0f); 
	this->camera = new Camera();
	this->loadAnts();
	this->loadCircuits();

    lineX=0; lineY=1; lineZ=20;
    TransistorX1=-0.5; TransistorX2=1.5;
	TransistorZ1=20.5; TransistorZ2=19.5;
}

void SSD::drawScene() {
	glTranslated(0, -2, 0);
	this->skybox->draw();

	glPushMatrix();
	glTranslatef(0,0,-85);
	for (auto circuit: this->circuits) {
		circuit->Draw();
	}
	glPopMatrix();

	//*************************** Drawing the TRANSISTORS *************************
	//glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(-50.5, 0, -40);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-30.5, 0, -40);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(30.5, 0, -40);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-50.5, 0, -100);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-28.5, 0, -150);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(28.5, 0, -80);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, -100);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-10, 0, -170);
	this->trans();
	glPopMatrix();
	glPushMatrix();
	glTranslated(20, 0, -160);
	this->trans();
	glPopMatrix();

	//*************************** Drawing the first line for the FLASH MEMORY *************************
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(-45.5, 0, -40);
	this->cube(0, 15, 0, 2.5, 0, -25);
	//flashMemory();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-26.5, 0, -30);
	this->cube(0, 15, 0, 2.5, 0, -25);
	//flashMemory();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-7.5, 0, -30);
	this->cube(0, 15, 0, 2.5, 0, -25);
	//flashMemory();
	glPopMatrix();

	glPushMatrix();
	glTranslated(11.5, 0, -30);
	this->cube(0, 15, 0, 2.5, 0, -25);
	//flashMemory();
	glPopMatrix();

	glPushMatrix();
	glTranslated(30.5, 0, -40);
	this->cube(0, 15, 0, 2.5, 0, -25);
	//flashMemory();
	glPopMatrix();

	//*************************** Drawing the secund line for the FLASH MEMORY *************************
	glPushMatrix();
	glTranslated(-45.5, 0, -75);
	this->cube(0, 15, 0, 2.5, 0, -25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-26.5, 0, -65);
	this->cube(0, 15, 0, 2.5, 0, -25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-7.5, 0, -65);
	this->cube(0, 15, 0, 2.5, 0, -25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(11.5, 0, -65);
	this->cube(0, 15, 0, 2.5, 0, -25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(30.5, 0, -75);
	this->cube(0, 15, 0, 2.5, 0, -25);
	glPopMatrix();

	//*************************** Drawing the CONTROLLER *************************
	glPushMatrix();
	glTranslated(-3, 0, -165);
	this->cube(0, 15 ,0 , 4, 0, -25);
	glPopMatrix();

	//*************************** Drawing the CACHE MEMORY *************************
	glPushMatrix();
	glTranslated(-26, 0, -170);
	this->cube(0, 15, 0, 3.5, 0, -15);
	glPopMatrix();

	//*************************** Drawing more memoris *************************
	glPushMatrix();
	glTranslated(-45.5, 0, -110);
	this->cube2(0, 6, 0, 2, 0, -10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-37.5, 0, -110);
	this->cube2(0, 6, 0, 2, 0, -10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-45.5, 0, -125);
	this->cube2(0, 6, 0, 2, 0, -10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-37.5, 0, -125);
	this->cube2(0, 6, 0, 2, 0, -10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-25, 0, -95);
	this->cube2(0, 10, 0, 2, 0, -6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-25, 0, -105);
	this->cube2(0, 10, 0, 2, 0, -6);
	glPopMatrix();

	this->drawAnts();

	glTranslatef(0, 2, 0);
	this->drawBullets();
}

void SSD::cube(float X1, float X2, float Y1, float Y2, float Z1, float Z2){

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.2,0.2,0.2);
	//TOP of the cube
	glVertex3f(X1, Y2, Z1);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(X2, Y2, Z1);
	glVertex3f(X2, Y2, Z2);
	glVertex3f(X1, Y2, Z2);    

	glColor3f(0.2,0.2,0.2);
	//BOTTEM of the cube
	glVertex3f(X1, Y1, Z1);  
	glVertex3f(X2, Y1, Z1);   
	glVertex3f(X2, Y1, Z2);   
	glVertex3f(X1, Y1, Z2);

	glColor3f(0.2,0.2,0.2);
	//BACK of the cube
	glVertex3f(X1, Y1, Z2);  
	glVertex3f(X2, Y1, Z2);   
	glVertex3f(X2, Y2, Z2);   
	glVertex3f(X1, Y2, Z2);    

	glColor3f(0.2,0.2,0.2);
	//FRONT of the cube
	glVertex3f(X1, Y1, Z1);   
	glVertex3f(X2, Y1, Z1);   
	glVertex3f(X2, Y2, Z1);    
	glVertex3f(X1, Y2, Z1);    

	glColor3f(0.2,0.2,0.2);
	//LEFT of the cube
	glVertex3f(X1, Y1, Z1);  
	glVertex3f(X1, Y1, Z2);   
	glVertex3f(X1, Y2, Z2);   
	glVertex3f(X1, Y2, Z1);  
	
	glColor3f(0.2,0.2,0.2);
	//RIGHT of the cube
	glVertex3f(X2, Y1, Z1);  
	glVertex3f(X2, Y1, Z2);   
	glVertex3f(X2, Y2, Z2);   
	glVertex3f(X2, Y2, Z1); 

	// End Drawing The Cube
	glEnd();           
	glPopMatrix();
}

void SSD::cube2(float q1, float q2, float w1, float w2, float r1, float r2){

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3ub(220,196,80);
	//TOP of the cube
	glVertex3f(q1, w2, r1);
	glColor3ub(217,190,64);
	glVertex3f(q2, w2, r1);
	glVertex3f(q2, w2, r2);
	glVertex3f(q1, w2, r2);    

	glColor3ub(220,196,80);
	//BOTTEM of the cube
	glVertex3f(q1, w1, r1);  
	glVertex3f(q2, w1, r1);   
	glVertex3f(q2, w1, r2);   
	glVertex3f(q1, w1, r2);

	//BACK of the cube
	glVertex3f(q1, w1, r2);  
	glVertex3f(q2, w1, r2);   
	glVertex3f(q2, w2, r2);   
	glVertex3f(q1, w2, r2);    

	//FRONT of the cube
	glVertex3f(q1, w1, r1);   
	glVertex3f(q2, w1, r1);   
	glVertex3f(q2, w2, r1);    
	glVertex3f(q1, w2, r1);    

	//LEFT of the cube
	glVertex3f(q1, w1, r1);  
	glVertex3f(q1, w1, r2);   
	glVertex3f(q1, w2, r2);   
	glVertex3f(q1, w2, r1);  
	
	//RIGHT of the cube
	glVertex3f(q2, w1, r1);  
	glVertex3f(q2, w1, r2);   
	glVertex3f(q2, w2, r2);   
	glVertex3f(q2, w2, r1); 

	// End Drawing The Cube
	glEnd();           
	glPopMatrix();
}

void SSD::trans(){

        glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures["motherboard/gold_metal2"]);
		//drawSticks
		glLineWidth(10);
	
		glBegin(GL_LINES);
		glTexCoord2f(0,0);
		glVertex3f(lineX,0,lineZ);
		glTexCoord2f(1,1);
		glVertex3f(lineX,lineY,lineZ);
		glEnd();

		glPushMatrix();
		glTranslatef(lineX+0.5,0,0);
		glBegin(GL_LINES);
		glTexCoord2f(0,0);
		glVertex3f(lineX,0,lineZ);
		glTexCoord2f(1,1);
		glVertex3f(lineX,lineY,lineZ);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(lineX+1,0,0);
		glBegin(GL_LINES);
		glTexCoord2f(0,0);
		glVertex3f(lineX,0,lineZ);
		glTexCoord2f(1,1);
		glVertex3f(lineX,lineY,lineZ);
		glEnd();
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, textures["motherboard/grey"]);
		//Draw Transistor
		//back face
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(TransistorX1,lineY,TransistorZ2);
		glTexCoord2f(1,0);
		glVertex3d(TransistorX2,lineY,TransistorZ2);
		glTexCoord2f(1,1);
		glVertex3d(TransistorX2,lineY+1,TransistorZ2);
		glTexCoord2f(0,1);
		glVertex3d(TransistorX1,lineY+1,TransistorZ2);
		glEnd();
		//front face
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(TransistorX1,lineY,TransistorZ1);
		glTexCoord2f(1,0);
		glVertex3d(TransistorX2,lineY,TransistorZ1);
		glTexCoord2f(1,1);
		glVertex3d(TransistorX2,lineY+1,TransistorZ1);
		glTexCoord2f(0,1);
		glVertex3d(TransistorX1,lineY+1,TransistorZ1);
		glEnd();
		//left face
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(TransistorX1,lineY,TransistorZ2);
		glTexCoord2f(1,0);
		glVertex3d(TransistorX1,lineY,TransistorZ1);
		glTexCoord2f(1,1);
		glVertex3d(TransistorX1,lineY+1,TransistorZ1);
		glTexCoord2f(0,1);
		glVertex3d(TransistorX1,lineY+1,TransistorZ2);
		glEnd();
		//right face
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(TransistorX2,lineY,TransistorZ2);
		glTexCoord2f(1,0);
		glVertex3d(TransistorX2,lineY,TransistorZ1);
		glTexCoord2f(1,1);
		glVertex3d(TransistorX2,lineY+1,TransistorZ1);
		glTexCoord2f(0,1);
		glVertex3d(TransistorX2,lineY+1,TransistorZ2);
		glEnd();
	
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
}
