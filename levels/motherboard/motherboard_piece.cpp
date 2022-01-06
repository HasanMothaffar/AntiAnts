#include <Windows.h>
#include <GL.H>
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>

#include "../../include/utility.h"
#include "motherboard_piece.h"


MotherboardPiece::MotherboardPiece(void)
{
	/*Cpu*/  cpuX1 = 170; cpuX2=20 ; cpuY=5; cpuZ1=65; cpuZ2=40;

	/*Heatsink*/  heatsink_ud_x1=150; heatsink_ud_x2=50; heatsink_ud_y=21; heatsink_ud_z1=50; heatsink_ud_z2=115;
		                 heatsink_c_x1=145; heatsink_c_x2=55; heatsink_c_y=20; heatsink_c_z1=110; heatsink_c_z2=55;

	 /*BIOS*/ biosX1 = 100; biosX2 =150 ; biosY =10 ; biosZ1 = 120; biosZ2 =50; leg1X1 =80; leg1X2 = 100; leg1Z1 =55;
						 leg1Z2=80; leg2X1=170; leg2X2=150; leg2Z1=55; leg2Z2=80;

	/*Ram*/ ramCX=163; ramCY=15; ramCZ=41; ramBX1=168; ramBX2=0; ramBY=5; ramBZ1=37; ramBZ2=48;

	/*GPU PCI*/ gpuSX1=38; gpuSX2=60; gpuSY=5; gpuSZ1=-10; gpuSZ2=121;
	/*GPU Fans*/ gpuFX=12; gpuFY1=3; gpuFY2=10; gpuFY3=4; gpuFZ=20;
	/*GPU*/ gpuX1=32; gpuX2=52; gpuY=50; gpuZ1=5; gpuZ2=117;

	/*PCI*/ pciX1=41.5; pciX2=53; pciY=5; pciZ1=5; pciZ2=121;
	/*Fan*/ fanX=20; fanY1=3; fanY2=10; fanY3=4; fanZ=20;

	/*P4 Power*/ p4X1=140; p4X2=160; p4Y=20; p4Z1=-130; p4Z2=-150;

	/*Inductors*/ indWX1=150; indWX2=180; indWY=10; indWZ1=-50; indWZ2=-80; indCX1=165; indCX2=170; indCY=10; indCZ1=-49; indCZ2=-51;

	/*Transistor*/ TransLX=0; TransLY=2; TransLZ=175; TransX1=-0.5; TransX2=1.5; TransZ1=174.5; TransZ2=175.5;
	
	/*VGA Port*/ vgaX1=150,vgaX2=195,vgaY=8,vgaZ1=-160,vgaZ2=-185;

	/*HDMI Port*/ hdmiX1=130,hdmiX2=145,hdmiY=5,hdmiZ1=-170,hdmiZ2=-190;

	/*HDMI2 Port*/ hdmi2X1=115,hdmi2X2=125,hdmi2Y=8,hdmi2Z1=-175,hdmi2Z2=-190;

	/*Old Port */ portX1=102; portX2=110; portY=7; portZ1= -175; portZ2=-185;

	/*Old Port 2*/ port2X1=87; port2X2=95; port2Y=7; port2Z1= -175; port2Z2=-185;

	/*Southbridge*/ sbX1=10,sbX2=30,sbY=5,sbZ=140;

	/*Chipset 1*/ chipX1=20,chipX2=60,chipY=2,chipZ1=-135,chipZ2=-175;

	/*Chipset 2*/ chip2X1=-20,chip2X2=20,chip2Y=2,chip2Z1=-50,chip2Z2=-90;

	/*Full Cable*/ cableX1=100;cableX2=102;cableY=2;cableZ1=45;cableZ2=10;
	fanA=0;
}

void MotherboardPiece::StartMotherboardLevel(int motherboardSurface,int CPU,int grey,int WhiteSlot,int BlueSlot,
								   int goldMetal,int heatSink,int BIOS,int RAM,int Red,int cmos,int fanAngle,int caseT,
								   int copperCable,int purple,int white_black,int copperCable2,int black,int black2)

{

	fanA+=100;

	//CPU
	drawCpu(CPU,grey);
	//Heatsink
	drawHeatSink(goldMetal,heatSink);
	//BIOS
	drawBios(BIOS);
	//RAMs
	drawRam(1,35,BlueSlot,WhiteSlot,RAM);
	drawRam(2,49.5,BlueSlot,WhiteSlot,RAM);
	drawRam(3,77.5,BlueSlot,WhiteSlot,RAM);
	drawRam(4,92,BlueSlot,WhiteSlot,RAM);
	//GPU Slot (AGP)
	glColor3ub(55,55,55);
	drawPCI(1,-7,gpuSX1,gpuSX2,gpuSY,gpuSZ1,gpuSZ2,WhiteSlot);
	glColor3ub(255,255,255);
	//GPU
	drawGPU(Red);
	//GPU Fans
	//Fan 1
	glPushMatrix();
	glTranslatef(48,28,-23);
	glRotatef(90,0,0,1);
	drawFan(fanA,gpuFX,gpuFY1,gpuFY2,gpuFY3,gpuFZ,black,black2);
	glPopMatrix();
	//Fan 2
	glPushMatrix();
	glTranslatef(48,28,-91);
	glRotatef(90,0,0,1);
	drawFan(fanA,gpuFX,gpuFY1,gpuFY2,gpuFY3,gpuFZ,black,black2);
	glPopMatrix();
	//PCIs
	drawPCI(1,19,pciX1,pciX2,pciY,pciZ1,pciZ2,WhiteSlot);
	drawPCI(2,45.5,pciX1,pciX2,pciY,pciZ1,pciZ2,WhiteSlot);
	drawPCI(2,72,pciX1,pciX2,pciY,pciZ1,pciZ2,WhiteSlot);
	glPushMatrix();
	glTranslatef(70,0,70);
	glColor3ub(0,0,155);
	drawPCI(2,72,pciX1,pciX2,pciY,pciZ1,pciZ2,white_black);
	glColor3ub(255,255,255);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-310,0,170);
	glColor3ub(155,0,0);
	drawPCI(2,72,pciX1,pciX2,pciY,pciZ1,pciZ2,white_black);
	glColor3ub(255,255,255);
	glPopMatrix();
	//CMOS
	glPushMatrix();
	glTranslatef(-20,0,-150);
	glRotatef(90,-1,0,0);
	drawCylinder(25,15,cmos,true,155,155,155);
	glPopMatrix();
	//Fans Cylinder
	glPushMatrix();
	glTranslatef(-100,0,-150);
	glRotatef(90,-1,0,0);
	drawCylinder(5,8,cmos,false,55,55,55);
	glPopMatrix();
	//Fan
	glPushMatrix();
	glTranslatef(-100,0,-150);
	drawFan(fanA,fanX,fanY1,fanY2,fanY3,fanZ,black,black2);
	glPopMatrix();
	//P4 Power
	drawP4Power();
	//Inductors
	drawInductors(copperCable);
	glPushMatrix();
	glTranslatef(-110,0,100);
	drawInductors(copperCable);
	glPopMatrix();
	//Transistors
	drawTransistors(goldMetal,grey);
	//VGA
	drawVGA(grey,purple);
	//HDMI
	drawPorts(grey);
	//Cylinders
	drawCylinders();
	//Southbridge
	drawSouthbridge();
	//Chipset
	glDisable(GL_TEXTURE_2D);
	drawChipset(white_black);
	//Cables
	drawCables(copperCable2);
	glColor3ub(255,255,255);
}

void MotherboardPiece::drawCpu(int CPU,int grey)
{
   
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,CPU);

	//upper face
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-cpuX1,cpuY,cpuZ1);
	glTexCoord2f(1,0);
	glVertex3f(-cpuX2,cpuY,cpuZ1);
	glTexCoord2f(1,1);
	glVertex3f(-cpuX2,cpuY,-cpuZ2);
	glTexCoord2f(0,1);
	glVertex3f(-cpuX1,cpuY,-cpuZ2);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,grey);
	//front part
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-cpuX1,0,cpuZ1);
	glTexCoord2f(1,0);
	glVertex3f(-cpuX2,0,cpuZ1);
	glTexCoord2f(1,1);
	glVertex3f(-cpuX2,cpuY,cpuZ1);
	glTexCoord2f(0,1);
	glVertex3f(-cpuX1,cpuY,cpuZ1);
	glEnd();
	glColor3ub(255,255,255);
	
	//back part
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-cpuX1,0,-cpuZ2);
	glTexCoord2f(1,0);
	glVertex3f(-cpuX2,0,-cpuZ2);
	glTexCoord2f(1,1);
	glVertex3f(-cpuX2,cpuY,-cpuZ2);
	glTexCoord2f(0,1);
	glVertex3f(-cpuX1,cpuY,-cpuZ2);
	glEnd();

	//right part
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-cpuX1,0,cpuZ1);
	glTexCoord2f(1,0);
	glVertex3f(-cpuX1,0,-cpuZ2);
	glTexCoord2f(1,1);
	glVertex3f(-cpuX1,cpuY,-cpuZ2);
	glTexCoord2f(0,1);
	glVertex3f(-cpuX1,cpuY,cpuZ1);
	glEnd();

	//left part
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-cpuX2,0,cpuZ1);
	glTexCoord2f(1,0);
	glVertex3f(-cpuX2,0,-cpuZ2);
	glTexCoord2f(1,1);
	glVertex3f(-cpuX2,cpuY,-cpuZ2);
	glTexCoord2f(0,1);
	glVertex3f(-cpuX2,cpuY,cpuZ1);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glColor3ub(255,255,255);
}
void MotherboardPiece::drawHeatSink(int goldMetal,int heatSink)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,goldMetal);
	//lower face
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-heatsink_ud_x1,0,-heatsink_ud_z1);
	glTexCoord2f(1,0);
	glVertex3f(-heatsink_ud_x2,0,-heatsink_ud_z1);
	glTexCoord2f(1,1);
	glVertex3f(-heatsink_ud_x2,0,-heatsink_ud_z2);
	glTexCoord2f(0,1);
	glVertex3f(-heatsink_ud_x1,0,-heatsink_ud_z2);
	glEnd();
	//upper face
	//1.01 to avoid texture problem
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-heatsink_ud_x1,heatsink_ud_y,-heatsink_ud_z1);
	glTexCoord2f(1,0);
	glVertex3f(-heatsink_ud_x2,heatsink_ud_y,-heatsink_ud_z1);
	glTexCoord2f(1,1);
	glVertex3f(-heatsink_ud_x2,heatsink_ud_y,-heatsink_ud_z2);
	glTexCoord2f(0,1);
	glVertex3f(-heatsink_ud_x1,heatsink_ud_y,-heatsink_ud_z2);
	glEnd();
	//Heat Sink
	glBindTexture(GL_TEXTURE_2D,heatSink);
	//front face
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-heatsink_c_x1,0,-heatsink_c_z2);
	glTexCoord2f(1,0);
	glVertex3f(-heatsink_c_x2,0,-heatsink_c_z2);
	glTexCoord2f(1,1);
	glVertex3f(-heatsink_c_x2,heatsink_c_y,-heatsink_c_z2);
	glTexCoord2f(0,1);
	glVertex3f(-heatsink_c_x1,heatsink_c_y,-heatsink_c_z2);
	glEnd();
	//back face
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-heatsink_c_x1,0,-heatsink_c_z1);
	glTexCoord2f(1,0);
	glVertex3f(-heatsink_c_x2,0,-heatsink_c_z1);
	glTexCoord2f(1,1);
	glVertex3f(-heatsink_c_x2,heatsink_c_y,-heatsink_c_z1);
	glTexCoord2f(0,1);
	glVertex3f(-heatsink_c_x1,heatsink_c_y,-heatsink_c_z1);
	glEnd();
	//left face
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-heatsink_c_x1,0,-heatsink_c_z1);
	glTexCoord2f(1,0);
	glVertex3f(-heatsink_c_x1,0,-heatsink_c_z2);
	glTexCoord2f(1,1);
	glVertex3f(-heatsink_c_x1,heatsink_c_y,-heatsink_c_z2);
	glTexCoord2f(0,1);
	glVertex3f(-heatsink_c_x1,heatsink_c_y,-heatsink_c_z1);
	glEnd();
	//right face
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-heatsink_c_x2,0,-heatsink_c_z1);
	glTexCoord2f(1,0);
	glVertex3f(-heatsink_c_x2,0,-heatsink_c_z2);
	glTexCoord2f(1,1);
	glVertex3f(-heatsink_c_x2,heatsink_c_y,-heatsink_c_z2);
	glTexCoord2f(0,1);
	glVertex3f(-heatsink_c_x2,heatsink_c_y,-heatsink_c_z1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}



////////////

//BIOS
void MotherboardPiece::drawBios(int BIOS)
{
	//bodyX1 = 100 , bodyX2 = 150 , bodyY = 10 , bodyZ1 = 120 , bodyZ2 = 50

	glEnable(GL_TEXTURE_2D);
	//upeer face
	
	glBindTexture(GL_TEXTURE_2D,BIOS);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(biosX1,biosY,biosZ1);
	glTexCoord2f(1,0);
	glVertex3f(biosX2,biosY,biosZ1);
	glTexCoord2f(1,1);
	glVertex3f(biosX2,biosY,biosZ2);
	glTexCoord2f(0,1);
	glVertex3f(biosX1,biosY,biosZ2);
	glEnd();

	//right face
	
	glBegin(GL_QUADS);
	glVertex3f(biosX2,0,biosZ1);
	glVertex3f(biosX2,0,biosZ2);
	glVertex3f(biosX2,biosY,biosZ2);
	glVertex3f(biosX2,biosY,biosZ1);
	glEnd();

	//left face
	glBegin(GL_QUADS);
	glVertex3f(biosX1,0,biosZ1);
	glVertex3f(biosX1,0,biosZ2);
	glVertex3f(biosX1,biosY,biosZ2);
	glVertex3f(biosX1,biosY,biosZ1);
	glEnd();

    //front face
	glBegin(GL_QUADS);
	glVertex3f(biosX1,biosY,biosZ1);
	glVertex3f(biosX2,biosY,biosZ1);
	glVertex3f(biosX2,0,biosZ1);
	glVertex3f(biosX1,0,biosZ1);
	glEnd();

	//back face
	glBegin(GL_QUADS);
	glVertex3f(biosX1,biosY,biosZ2);
	glVertex3f(biosX2,biosY,biosZ2);
	glVertex3f(biosX2,0,biosZ2);
	glVertex3f(biosX1,0,biosZ2);
	glEnd();
	//////////////////////////


	
	//LegSide1
	//x1 = 80 , x2 = 100 , y = bodyY/2 , z1 = 55 , z2 = 80
	////
	glBegin(GL_QUADS);
	glVertex3f(leg1X1,biosY/2,leg1Z1);
	glVertex3f(leg1X1,biosY/2,leg1Z2);
	glVertex3f(leg1X2,biosY/2,leg1Z2);
	glVertex3f(leg1X2,biosY/2,leg1Z1);
	glEnd();
	////

	////
	glBegin(GL_QUADS);
	glVertex3f(leg1X1,biosY/2,leg1Z1+60);
	glVertex3f(leg1X1,biosY/2,leg1Z2+10);
	glVertex3f(leg1X2,biosY/2,leg1Z2+10);
	glVertex3f(leg1X2,biosY/2,leg1Z1+60);
	glEnd();
	////

		glBegin(GL_QUADS);
	glVertex3f(leg1X1,biosY/2,leg1Z1);
	glVertex3f(leg1X1,biosY/2,leg1Z2);
	glVertex3f(leg1X1-10,0,leg1Z2);
	glVertex3f(leg1X1-10,0,leg1Z1);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(leg1X1,biosY/2,leg1Z1+60);
	glVertex3f(leg1X1,biosY/2,leg1Z2+10);
	glVertex3f(leg1X1-10,0,leg1Z2+10);
	glVertex3f(leg1X1-10,0,leg1Z1+60);
	glEnd();
	//////////////////////////////////


	//LegSide2

	//x1 = 170 , x2 = 150 , y = 5 , z1 = 55 , z2 = 80

	glBegin(GL_QUADS);
	glVertex3f(leg2X1,biosY/2,leg2Z1);
	glVertex3f(leg2X1,biosY/2,leg2Z2);
	glVertex3f(leg2X2,biosY/2,leg2Z2);
	glVertex3f(leg2X2,biosY/2,leg2Z1);
	glEnd();
	////

	glBegin(GL_QUADS);
	glVertex3f(leg2X1,biosY/2,leg2Z1+60);
	glVertex3f(leg2X1,biosY/2,leg2Z2+10);
	glVertex3f(leg2X2,biosY/2,leg2Z2+10);
	glVertex3f(leg2X2,biosY/2,leg2Z1+60);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(leg2X1+10,0,leg2Z1);
	glVertex3f(leg2X1+10,0,leg2Z2);
	glVertex3f(leg2X2+20,biosY/2,leg2Z2);
	glVertex3f(leg2X2+20,biosY/2,leg2Z1);
	glEnd();


	glBegin(GL_QUADS);
	glVertex3f(leg2X1+10,0,leg2Z1+60);
	glVertex3f(leg2X1+10,0,leg2Z2+10);
	glVertex3f(leg2X2+20,biosY/2,leg2Z2+10);
	glVertex3f(leg2X2+20,biosY/2,leg2Z1+60);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void MotherboardPiece::drawRam(int n,GLfloat z,int BlueSlot,int WhiteSlot,int RAM)

{
	
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0,0,z);


	glBindTexture(GL_TEXTURE_2D,RAM);
    //RAM
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-ramCX,0,(ramBZ1+ramBZ2)/2);
	glTexCoord2f(1,0);
	glVertex3f(0,0,(ramBZ1+ramBZ2)/2);
	glTexCoord2f(1,1);
	glVertex3f(0,ramCY,(ramBZ1+ramBZ2)/2);
	glTexCoord2f(0,1);
	glVertex3f(-ramCX,ramCY,(ramBZ1+ramBZ2)/2);
	glEnd();

	if(n%2==0)
		glBindTexture(GL_TEXTURE_2D,BlueSlot);
	else
		glBindTexture(GL_TEXTURE_2D,WhiteSlot);

	//////Ram Body
	glBegin(GL_QUADS);
	//upper face
	glTexCoord2f(0,0);
	glVertex3f(-ramBX1,ramBY,ramBZ1);
	glTexCoord2f(1,0);
	glVertex3f(ramBX2,ramBY,ramBZ1);
	glTexCoord2f(1,1);
	glVertex3f(ramBX2,ramBY,ramBZ2);
	glTexCoord2f(0,1);
	glVertex3f(-ramBX1,ramBY,ramBZ2);
	//lower face
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-ramBX1,0,ramBZ1);
	glTexCoord2f(1,0);
	glVertex3f(ramBX2,0,ramBZ1);
	glTexCoord2f(1,1);
	glVertex3f(ramBX2,0,ramBZ2);
	glTexCoord2f(0,1);
	glVertex3f(-ramBX1,0,ramBZ2);
	//
	glVertex3f(-ramBX1,0,ramBZ1);
	glVertex3f(ramBX2,0,ramBZ1);
	glVertex3f(ramBX2,ramBY,ramBZ1);
	glVertex3f(-ramBX1,ramBY,ramBZ1);
	//front face
	glVertex3f(-ramBX1,0,ramBZ2);
	glVertex3f(ramBX2,0,ramBZ2);
	glVertex3f(ramBX2,ramBY,ramBZ2);
	glVertex3f(-ramBX1,ramBY,ramBZ2);
	//left face 
	glVertex3f(-ramBX1,0,ramBZ2);
	glVertex3f(-ramBX1,0,ramBZ1);
	glVertex3f(-ramBX1,ramBY,ramBZ1);
	glVertex3f(-ramBX1,ramBY,ramBZ2);
	//right face
	glVertex3f(ramBX2,0,ramBZ2);
	glVertex3f(ramBX2,0,ramBZ1);
	glVertex3f(ramBX2,ramBY,ramBZ1);
	glVertex3f(ramBX2,ramBY,ramBZ2);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

}

void MotherboardPiece::drawPCI(int n,GLfloat x,
			 GLfloat bodyX1 , GLfloat bodyX2,GLfloat bodyY , GLfloat bodyZ1 , GLfloat bodyZ2,
		 int WhiteSlot)
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(x,0,0);
	glBindTexture(GL_TEXTURE_2D,WhiteSlot);

	glBegin(GL_QUADS);
	//upper face
    glTexCoord2f(1,1);
    glVertex3f(bodyX1,bodyY,-bodyZ1);
	glTexCoord2f(1,0);
	glVertex3f(bodyX2,bodyY,-bodyZ1);
	glTexCoord2f(0,0);
	glVertex3f(bodyX2,bodyY,-bodyZ2);
	glTexCoord2f(0,1);
	glVertex3f(bodyX1,bodyY,-bodyZ2);


	//lower face
    glTexCoord2f(1,1);
	glVertex3f(bodyX1,0,-bodyZ1);
	glTexCoord2f(1,0);
	glVertex3f(bodyX2,0,-bodyZ1);
	glTexCoord2f(0,0);
	glVertex3f(bodyX2,0,-bodyZ2);
	glTexCoord2f(0,1);
	glVertex3f(bodyX1,0,-bodyZ2);
	
	//back face
	glColor3ub(255, 255, 255);
	glVertex3f(bodyX2,0,-bodyZ2);
	glVertex3f(bodyX1,0,-bodyZ2);
	glVertex3f(bodyX1,bodyY,-bodyZ2);
	glVertex3f(bodyX2,bodyY,-bodyZ2);

	//front face
	glVertex3f(bodyX2,0,-bodyZ1);
	glVertex3f(bodyX1,0,-bodyZ1);
	glVertex3f(bodyX1,bodyY,-bodyZ1);
	glVertex3f(bodyX2,bodyY,-bodyZ1);

	//left face 
	glVertex3f(bodyX1,0,-bodyZ1);
	glVertex3f(bodyX1,0,-bodyZ2);
	glVertex3f(bodyX1,bodyY,-bodyZ2);
	glVertex3f(bodyX1,bodyY,-bodyZ1);

	//right face
	glVertex3f(bodyX2,0,-bodyZ1);
	glVertex3f(bodyX2,0,-bodyZ2);
	glVertex3f(bodyX2,bodyY,-bodyZ2);
	glVertex3f(bodyX2,bodyY,-bodyZ1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

void MotherboardPiece::drawCylinder(GLfloat radius, GLfloat height ,int cmos,bool isCmos,int r,int g , int b)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
	if(isCmos)
	{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,cmos);
	}
	
    /** Draw the tube */
    
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while(angle < 2*3.14 ) {
            x = radius * cos(angle);
            y = radius * sin(angle);

			glTexCoord2f(0,0);
			glColor3ub(r,g,b);
            glVertex3f(x, y , height);
			glTexCoord2f(1,0);
			glColor3ub(r+20,g+20,b+20);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
		glTexCoord2f(1,1);
		glColor3ub(r,g,b);
        glVertex3f(radius, 0.0, height);
		glTexCoord2f(0,1);
		glColor3ub(r+20,g+20,b+20);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
	
    glColor3ub(r,g,b);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*3.14 ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
			glTexCoord2f(x,y);
			glColor3ub(r,g,b);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
		//glTexCoord2f(radius,height);
		glColor3ub(r+20,g+20,b+20);
        glVertex3f(radius, 0.0, height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
}

void MotherboardPiece::drawFan(GLfloat fanAngle , GLfloat x , GLfloat y1 ,GLfloat y2 , GLfloat y3 , GLfloat z,int black,int black2)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,black);

	glColor3ub(55,55,55);
	////Fence
	
	//x1 = 20 , y1=3 , y2 = 10 , y3 = 4 , z = 20 
	//Left
	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(-x-5,y1,-z); glTexCoord2f(1,0);
	glVertex3f(-x-5,0,-z); glTexCoord2f(1,1);
	glVertex3f(-x-5,0,z); glTexCoord2f(0,1);
	glVertex3f(-x-5,y1,z); 
	glEnd();
	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(-x-5,y2,-z); glTexCoord2f(1,0);
	glVertex3f(-x-5,y3,-z); glTexCoord2f(1,1);
	glVertex3f(-x-5,y3,z); glTexCoord2f(0,1);
	glVertex3f(-x-5,y2,z); 
	glEnd();
	////////////////////////

	//Right
	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(x+5,y1,-z); glTexCoord2f(1,0); 
	glVertex3f(x+5,0,-z); glTexCoord2f(1,1);
	glVertex3f(x+5,0,z);  glTexCoord2f(0,1);
	glVertex3f(x+5,y1,z);
	glEnd();

	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(x+5,y2,-z); glTexCoord2f(1,0);
	glVertex3f(x+5,y3,-z); glTexCoord2f(1,1);
	glVertex3f(x+5,y3,z); glTexCoord2f(0,1);
	glVertex3f(x+5,y2,z);
	glEnd();
	/////////////////////////


	//back
	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(-x-5,0,z); glTexCoord2f(1,0);
	glVertex3f(x+5,0,z); glTexCoord2f(1,1);
	glVertex3f(x+5,y1,z); glTexCoord2f(0,1);
	glVertex3f(-x-5,y1,z);
	glEnd();
	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(-x-5,y3,z); glTexCoord2f(1,0);
	glVertex3f(x+5,y3,z); glTexCoord2f(1,1);
	glVertex3f(x+5,y2,z); glTexCoord2f(0,1);
	glVertex3f(-x-5,y2,z);
	glEnd();
	/////////////////////////
	//front
	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(-x-5,0,-z); glTexCoord2f(1,0);
	glVertex3f(x+5,0,-z); glTexCoord2f(1,1);
	glVertex3f(x+5,y1,-z); glTexCoord2f(0,1);
	glVertex3f(-x-5,y1,-z);
	glEnd();

	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(-x-5,y3,-z); glTexCoord2f(1,0);
	glVertex3f(x+5,y3,-z); glTexCoord2f(1,1);
	glVertex3f(x+5,y2,-z); glTexCoord2f(0,1);
	glVertex3f(-x-5,y2,-z);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,black2);
	
	glRotatef(fanAngle,0,1,0);
	fanAngle+=50;
	//glColor3ub(0,0,0);
	//fans
	//glColor3ub(100,100,100);
    for(int i=0;i<8;i++)
    {
	glRotatef(45,0,1,0);
	glBegin(GL_QUADS); glTexCoord2f(0,0);
	glVertex3f(0,y3+3,z-20); glTexCoord2f(1,0);
	glVertex3f(+x-3,y3+3,z-30); glTexCoord2f(1,1);
	glVertex3f(+x-3,y3,-z+15); glTexCoord2f(0,1);
	glVertex3f(0,y3,-z+25);
	glEnd();
    }	
	glDisable(GL_TEXTURE_2D);
}

void MotherboardPiece::drawGPU(int red)
	{

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,red);

		glColor3ub(125,0,0);
		//front face
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,0,gpuZ1);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,0,gpuZ1);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY,gpuZ1);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY,gpuZ1);
		glEnd();

		//back face
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,0,-gpuZ2);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,0,-gpuZ2);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY,-gpuZ2);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2);
		glEnd();

		//front face  2
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,0,-gpuZ2+115);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,0,-gpuZ2+115);
		glTexCoord2f(1,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2+115);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2+115);
		glEnd();

		//back face  2
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,0,-gpuZ2+5);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,0,-gpuZ2+5);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY,-gpuZ2+5);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2+5);
		glEnd();

		//right face (front)
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX2,0,gpuZ1);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,0,-gpuZ2+115);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY,-gpuZ2+115);
		glTexCoord2f(0,1);
		glVertex3f(gpuX2,gpuY,gpuZ1);
		glEnd();

		//left face (front)
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,0,gpuZ1);
		glTexCoord2f(1,0);
		glVertex3f(gpuX1,0,-gpuZ2+115);
		glTexCoord2f(1,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2+115);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY,gpuZ1);
		glEnd();


		//right face (back)
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX2,0,-gpuZ2);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,0,-gpuZ2+5);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY,-gpuZ2+5);
		glTexCoord2f(0,1);
		glVertex3f(gpuX2,gpuY,-gpuZ2);
		glEnd();

		//left face (back)
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,0,-gpuZ2);
		glTexCoord2f(1,0);
		glVertex3f(gpuX1,0,-gpuZ2+5);
		glTexCoord2f(1,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2+5);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2);
		glEnd();


		//upper face 1
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,gpuY,gpuZ1);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,gpuY,gpuZ1);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY,-gpuZ2);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY,-gpuZ2);
		glEnd();

		//upper face 2
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,gpuY-5,gpuZ1);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,gpuY-5,gpuZ1);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY-5,-gpuZ2);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,gpuY-5,-gpuZ2);

		glEnd();

		//lower face 1
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,5,gpuZ1);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,5,gpuZ1);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,5,-gpuZ2);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,5,-gpuZ2);
		glEnd();

		//lower face 2
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,10,gpuZ1);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,10,gpuZ1);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,10,-gpuZ2);
		glTexCoord2f(0,1);
		glVertex3f(gpuX1,10,-gpuZ2);
		glEnd();

		//Full right face (front)
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(gpuX2,0,-gpuZ2);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,0,gpuZ1);
		glTexCoord2f(1,1);
		glVertex3f(gpuX2,gpuY,gpuZ1);
		glTexCoord2f(0,1);
		glVertex3f(gpuX2,gpuY,-gpuZ2);
		glEnd();


		

		//Traingle left face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,10,-gpuZ2+48);
		glTexCoord2f(1,0);
		glVertex3f(gpuX1,10,gpuZ1-51);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,28,gpuZ1-61);
		glEnd();
		//Traingle right face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX2,10,-gpuZ2+48);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,10,gpuZ1-51);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,28,gpuZ1-61);
		glEnd();
		//Traingle front face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,10,gpuZ1-51);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,10,gpuZ1-51);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,28,gpuZ1-61);
		glEnd();
		//Traingle back face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,10,-gpuZ2+48);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,10,-gpuZ2+48);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,28,gpuZ1-61);
		glEnd();
		//Traingle left face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,gpuY-5,-gpuZ2+48);
		glTexCoord2f(1,0);
		glVertex3f(gpuX1,gpuY-5,gpuZ1-51);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,gpuY-23,gpuZ1-61);
		glEnd();
		//Traingle right face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX2,gpuY-5,-gpuZ2+48);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,gpuY-5,gpuZ1-51);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,gpuY-23,gpuZ1-61);
		glEnd();
		//Traingle front face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,gpuY-5,gpuZ1-51);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,gpuY-5,gpuZ1-51);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,gpuY-23,gpuZ1-61);
		glEnd();
		//Traingle back face 
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(gpuX1,gpuY-5,-gpuZ2+48);
		glTexCoord2f(1,0);
		glVertex3f(gpuX2,gpuY-5,-gpuZ2+48);
		glTexCoord2f(0.5,1);
		glVertex3f((gpuX1+gpuX2)/2,gpuY-23,gpuZ1-61);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
	}

	void MotherboardPiece::draw4Walls(GLfloat x1,GLfloat x2,GLfloat y,GLfloat z1,GLfloat z2)
	{

		
		//back face
		glBegin(GL_QUADS);
		glVertex3d(x1,0,z2);
		glVertex3d(x2,0,z2);
		glVertex3d(x2,y,z2);
		glVertex3d(x1,y,z2);
		glEnd();
		//front face
		glBegin(GL_QUADS);
		glVertex3d(x1,0,z1);
		glVertex3d(x2,0,z1);
		glVertex3d(x2,y,z1);
		glVertex3d(x1,y,z1);
		glEnd();
		//left face
		glBegin(GL_QUADS);
		glVertex3d(x1,0,z2);
		glVertex3d(x1,0,z1);
		glVertex3d(x1,y,z1);
		glVertex3d(x1,y,z2);
		glEnd();
		//right face
		glBegin(GL_QUADS);
		glVertex3d(x2,0,z2);
		glVertex3d(x2,0,z1);
		glVertex3d(x2,y,z1);
		glVertex3d(x2,y,z2);
		glEnd();
	
	}

	void MotherboardPiece::drawP4Power()
	{
		glColor3ub(255,255,150);
		draw4Walls(p4X1,p4X2,p4Y,p4Z1,p4Z2);

		glPushMatrix();
		glTranslatef((p4X2-p4X1)+5,0,0);
		draw4Walls(p4X1,p4X2,p4Y,p4Z1,p4Z2);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0,0,(p4X2-p4X1)+5);
		draw4Walls(p4X1,p4X2,p4Y,p4Z1,p4Z2);
		glPopMatrix();

		glPushMatrix();
		glTranslatef((p4X2-p4X1)+5,0,(p4X2-p4X1)+5);
		draw4Walls(p4X1,p4X2,p4Y,p4Z1,p4Z2);
		glPopMatrix();


		glColor3ub(255,255,255);
	}

	void MotherboardPiece::drawCable(GLfloat x1,GLfloat x2,GLfloat y,GLfloat z1,GLfloat z2,int copperCable)
	{

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,copperCable);
		
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(x1,0,z1);
		glTexCoord2f(1,0);
		glVertex3d(x2,0,z1);
		glTexCoord2f(1,1);
		glVertex3d(x2,y,z1);
		glTexCoord2f(0,1);
		glVertex3d(x1,y,z1);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(x1,0,z2);
		glTexCoord2f(1,0);
		glVertex3d(x2,0,z2);
		glTexCoord2f(1,1);
		glVertex3d(x2,y,z2);
		glTexCoord2f(0,1);
		glVertex3d(x1,y,z2);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(x1,y,z1);
		glTexCoord2f(1,0);
		glVertex3d(x2,y,z1);
		glTexCoord2f(1,1);
		glVertex3d(x2,y,z2);
		glTexCoord2f(0,1);
		glVertex3d(x1,y,z2);
		glEnd();

		glDisable(GL_TEXTURE_2D);

		
	
	}

	void MotherboardPiece::drawInductors(int copperCable)
	{
		glColor3ub(200,200,200);
		draw4Walls(indWX1,indWX2,indWY,indWZ1,indWZ2);
		glColor3ub(255,255,50);

		//front cables
		drawCable(indCX1,indCX2,indCY,indCZ1,indCZ2,copperCable);
		glPushMatrix();
		glTranslatef(6,0,0);
		drawCable(indCX1,indCX2,indCY,indCZ1,indCZ2,copperCable);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-6,0,0);
		drawCable(indCX1,indCX2,indCY,indCZ1,indCZ2,copperCable);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-12,0,0);
		drawCable(indCX1,indCX2,indCY,indCZ1,indCZ2,copperCable);
		glPopMatrix();

		//back cables
		drawCable(indCX1,indCX2,indCY,indCZ1-30,indCZ2-30,copperCable);
		glPushMatrix();
		glTranslatef(6,0,0);
		drawCable(indCX1,indCX2,indCY,indCZ1-30,indCZ2-30,copperCable);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-6,0,0);
		drawCable(indCX1,indCX2,indCY,indCZ1-30,indCZ2-30,copperCable);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-12,0,0);
		drawCable(indCX1,indCX2,indCY,indCZ1-30,indCZ2-30,copperCable);
		glPopMatrix();

		glColor3ub(255,255,255);
	}

	void MotherboardPiece::drawTransistor(GLfloat lineX,GLfloat lineY,GLfloat lineZ,
		GLfloat TransistorX1,GLfloat TransistorX2,GLfloat TransistorZ1,GLfloat TransistorZ2,int transistor,int grey)
	{
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D,grey);

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
		

		glBindTexture(GL_TEXTURE_2D,transistor);
		
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


	void MotherboardPiece::drawTransistors(int transistor,int grey)
	{

		//1
		glPushMatrix();
		glTranslatef(1,0,0);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//2
		glPushMatrix();
		glTranslatef(50,0,0);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(20,0,10);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(180,0,-50);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//5
		glPushMatrix();
		glTranslatef(185,0,-70);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//6
		glPushMatrix();
		glTranslatef(181,0,-100);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//7
		glPushMatrix();
		glTranslatef(185,0,-100);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//8
		glPushMatrix();
		glTranslatef(185,0,-80);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//9
		glPushMatrix();
		glTranslatef(-150,0,-50);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//10
		glPushMatrix();
		glTranslatef(10,0,-100);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//11
		glPushMatrix();
		glTranslatef(20,0,-100);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//12
		glPushMatrix();
		glTranslatef(25,0,-110);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//13
		glPushMatrix();
		glTranslatef(15,0,-115);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//14
		glPushMatrix();
		glTranslatef(17,0,-130);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//15
		glPushMatrix();
		glTranslatef(-50,0,-70);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//16
		glPushMatrix();
		glTranslatef(-60,0,-72);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//17
		glPushMatrix();
		glTranslatef(-70,0,-68);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//18
		glPushMatrix();
		glTranslatef(-80,0,-74);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//19
		glPushMatrix();
		glTranslatef(-40,0,-74);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//20
		glPushMatrix();
		glTranslatef(-90,0,-64);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//21
		glPushMatrix();
		glTranslatef(-100,0,-62);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//22
		glPushMatrix();
		glTranslatef(-110,0,-66);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//23
		glPushMatrix();
		glTranslatef(-120,0,-68);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//24
		glPushMatrix();
		glTranslatef(-130,0,-74);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//25
		glPushMatrix();
		glTranslatef(-140,0,-72);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//26
		glPushMatrix();
		glTranslatef(-30,0,-72);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//27
		glPushMatrix();
		glTranslatef(-20,0,-70);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();
		//28
		glPushMatrix();
		glTranslatef(-10,0,-68);
		drawTransistor(TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2,transistor,grey);
		glPopMatrix();

	}

	void MotherboardPiece::drawVGA(int grey , int purple)
	{

		//body
		glColor3ub(100,0,211);
		draw4Walls(vgaX1,vgaX2,vgaY,vgaZ1,vgaZ2);
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(vgaX1,vgaY,vgaZ1);
		glTexCoord2f(1,0);
		glVertex3f(vgaX2,vgaY,vgaZ1);
		glTexCoord2f(1,1);
		glVertex3f(vgaX2,vgaY,vgaZ2);
		glTexCoord2f(0,1);
		glVertex3f(vgaX1,vgaY,vgaZ2);
		glEnd();
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,grey);
		//port
		glColor3ub(150,150,150);
		glPushMatrix();
		glTranslatef(0,0,-3);
		draw4Walls(vgaX1+5,vgaX2-5,vgaY/2,vgaZ2,vgaZ1-4);
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(vgaX1+5,vgaY/2,vgaZ1-4);
		glTexCoord2f(1,0);
		glVertex3f(vgaX2-5,vgaY/2,vgaZ1-4);
		glTexCoord2f(1,1);
		glVertex3f(vgaX2-5,vgaY/2,vgaZ2);
		glTexCoord2f(0,1);
		glVertex3f(vgaX1+5,vgaY/2,vgaZ2);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		//Cylinders
		//left
		glPushMatrix();
		glTranslatef(vgaX1+1,vgaY/2,(vgaZ1+vgaZ2)/2);
		glRotatef(90,1,0,0);
		auxSolidCylinder(3,20);
		glPopMatrix();
		//right
		glPushMatrix();
		glTranslatef(vgaX2-1,vgaY/2,(vgaZ1+vgaZ2)/2);
		glRotatef(90,1,0,0);
		auxSolidCylinder(3,20);
		glPopMatrix();
	
	}

	void MotherboardPiece::drawQuad(GLfloat x1,GLfloat x2,GLfloat y,GLfloat z1,GLfloat z2,int texture)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture);
		glBegin(GL_QUADS);
		//front
		glVertex3f(x1,0,z1); glTexCoord2f(0,0);
		glVertex3f(x2,0,z1); glTexCoord2f(1,0);
		glVertex3f(x2,y,z1); glTexCoord2f(1,1);
		glVertex3f(x1,y,z1); glTexCoord2f(0,1);
		//back
		glVertex3f(x1,0,z2); glTexCoord2f(0,0);
		glVertex3f(x2,0,z2); glTexCoord2f(1,0);
		glVertex3f(x2,y,z2); glTexCoord2f(1,1);
		glVertex3f(x1,y,z2); glTexCoord2f(0,1);
		//left
		glVertex3f(x1,0,z1); glTexCoord2f(0,0);
		glVertex3f(x1,0,z2); glTexCoord2f(1,0);
		glVertex3f(x1,y,z2); glTexCoord2f(1,1);
		glVertex3f(x1,y,z1); glTexCoord2f(0,1);
		//right
		glVertex3f(x2,0,z1); glTexCoord2f(0,0);
		glVertex3f(x2,0,z2); glTexCoord2f(1,0);
		glVertex3f(x2,y,z2); glTexCoord2f(1,1);
		glVertex3f(x2,y,z1); glTexCoord2f(0,1);
		//top
		glVertex3f(x1,y,z1); glTexCoord2f(0,0);
		glVertex3f(x2,y,z1); glTexCoord2f(1,0);
		glVertex3f(x2,y,z2); glTexCoord2f(1,1);
		glVertex3f(x1,y,z2); glTexCoord2f(0,1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	void MotherboardPiece::drawPorts(int hdmi)
	{
		glColor3ub(211,211,211);
		//1
		drawQuad(hdmiX1,hdmiX2,hdmiY,hdmiZ1,hdmiZ2,hdmi);
		//2
		drawQuad(hdmi2X1,hdmi2X2,hdmi2Y,hdmi2Z1,hdmi2Z2,hdmi);
		//3
		drawQuad(hdmi2X1,hdmi2X2,hdmi2Y,hdmi2Z1,hdmi2Z2,hdmi);
		//4
		drawQuad(portX1,portX2,portY,portZ1,portZ2,-1);
		glColor3ub(0,0,55);
		glPushMatrix();
		glTranslatef((portX1+portX2)/2,portY/2,(portZ1+portZ2)/2);
		glRotatef(90,1,0,0);
		auxSolidCylinder(3,15);
		glPopMatrix();
		//5
		glColor3ub(211,211,211);
		drawQuad(port2X1,port2X2,port2Y,port2Z1,port2Z2,-1);
		glColor3ub(0,55,0);
		glPushMatrix();
		glTranslatef((port2X1+port2X2)/2,port2Y/2,(port2Z1+port2Z2)/2);
		glRotatef(90,1,0,0);
		auxSolidCylinder(3,15);
		glPopMatrix();
		//6
		glColor3ub(218,165,32);
		glPushMatrix();
		glTranslatef(port2X1-10,port2Y/2,(port2Z1+port2Z2)/2);
		glRotatef(90,1,0,0);
		for(GLfloat i=0;i<3;i+=0.1)
		{
			auxSolidCylinder(i,15);
		}
		glPopMatrix();
		glColor3ub(30,30,30);
		drawQuad(port2X1-25,port2X1-20,port2Y-2,port2Z1,port2Z2,-1);
		glPushMatrix();
		glColor3ub(155,155,155);
		glTranslatef(((port2X1-25)+(port2X1-20))/2,port2Y/2,port2Z2);
		auxSolidSphere(1);
		glPopMatrix();
		
	}

	void MotherboardPiece::drawCylinders()
	{
		glColor3ub(20,20,20);
		//1
		glPushMatrix();
		glTranslatef(10,0,0);
		glRotatef(90,-1,0,0);
		drawCylinder(5,10,-1,false,155,155,155);
		glPopMatrix();
		//2
		glPushMatrix();
		glTranslatef(-1,0,0);
		glRotatef(90,-1,0,0);
		drawCylinder(5,10,-1,false,155,155,155);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(-1,0,-12);
		glRotatef(90,-1,0,0);
		drawCylinder(5,10,-1,false,155,155,155);
		glPopMatrix();
		
		//4
		glPushMatrix();
		glTranslatef(10,0,-12);
		glRotatef(90,-1,0,0);
		drawCylinder(5,10,-1,false,155,155,155);
		glPopMatrix();
		
		//5
		glPushMatrix();
		glTranslatef(10,0,-24);
		glRotatef(90,-1,0,0);
		drawCylinder(5,10,-1,false,155,155,155);
		glPopMatrix();
		//6
		glPushMatrix();
		glTranslatef(-1,0,-24);
		glRotatef(90,-1,0,0);
		drawCylinder(5,10,-1,false,155,155,155);
		glPopMatrix();

		//Between PCIs
		//7
		glPushMatrix();
		glTranslatef(80,0,-40);
		glRotatef(90,-1,0,0);
		drawCylinder(5,7,-1,false,155,155,155);
		glPopMatrix();
		//8
		glPushMatrix();
		glTranslatef(78,0,-70);
		glRotatef(90,-1,0,0);
		drawCylinder(5,7,-1,false,155,155,155);
		glPopMatrix();
		//9
		glPushMatrix();
		glTranslatef(82,0,-110);
		glRotatef(90,-1,0,0);
		drawCylinder(3,7,-1,false,155,155,155);
		glPopMatrix();
		//8
		glPushMatrix();
		glTranslatef(105,0,-30);
		glRotatef(90,-1,0,0);
		drawCylinder(5,7,-1,false,155,155,155);
		glPopMatrix();
		//9
		glPushMatrix();
		glTranslatef(105,0,-100);
		glRotatef(90,-1,0,0);
		drawCylinder(6,7,-1,false,155,155,155);
		glPopMatrix();
		//10
		glPushMatrix();
		glTranslatef(140,0,-80);
		glRotatef(90,-1,0,0);
		drawCylinder(6,7,-1,false,155,155,155);
		glPopMatrix();
		//11
		glPushMatrix();
		glTranslatef(140,0,-30);
		glRotatef(90,-1,0,0);
		drawCylinder(10,3,-1,false,155,155,155);
		glPopMatrix();
		//12
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
		glPushMatrix();
		glTranslatef(150,0,150);
		glRotatef(90,-1,0,0);
		drawCylinder(20,15,-1,false,0,51,25);
		glPopMatrix();
		glColor3ub(255,255,255);
		//13
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
		glPushMatrix();
		glTranslatef(-170,0,-160);
		glRotatef(90,-1,0,0);
		drawCylinder(20,15,-1,false,100,0,0);
		glPopMatrix();
		glColor3ub(255,255,255);
		//14
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
		glPushMatrix();
		glTranslatef(-180,0,-100);
		glRotatef(90,-1,0,0);
		drawCylinder(10,15,-1,false,153,153,0);
		glPopMatrix();
		glColor3ub(255,255,255);
	}

	void MotherboardPiece::drawSouthbridge()
	{
		glColor3ub(50,50,50);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ);
		glVertex3f(sbX2,0,sbZ);
		glVertex3f(sbX2,0,sbZ-32);
		glVertex3f(sbX1,0,sbZ-32);
		glEnd();

		glColor3ub(10,10,10);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ);
		glVertex3f(sbX2,0,sbZ);
		glVertex3f(sbX2,sbY,sbZ);
		glVertex3f(sbX1,sbY,sbZ);
		glEnd();

		glColor3ub(20,20,20);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-5);
		glVertex3f(sbX2,0,sbZ-5);
		glVertex3f(sbX2,sbY+2,sbZ-5);
		glVertex3f(sbX1,sbY+2,sbZ-5);
		glEnd();

		glColor3ub(30,30,30);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-10);
		glVertex3f(sbX2,0,sbZ-10);
		glVertex3f(sbX2,sbY+4,sbZ-10);
		glVertex3f(sbX1,sbY+4,sbZ-10);
		glEnd();

		glColor3ub(40,40,40);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-15);
		glVertex3f(sbX2,0,sbZ-15);
		glVertex3f(sbX2,sbY+6,sbZ-15);
		glVertex3f(sbX1,sbY+6,sbZ-15);
		glEnd();

		glColor3ub(40,40,40);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-16);
		glVertex3f(sbX2,0,sbZ-16);
		glVertex3f(sbX2,sbY+6,sbZ-16);
		glVertex3f(sbX1,sbY+6,sbZ-16);
		glEnd();

		glColor3ub(40,40,40);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-17);
		glVertex3f(sbX2,0,sbZ-17);
		glVertex3f(sbX2,sbY+6,sbZ-17);
		glVertex3f(sbX1,sbY+6,sbZ-17);
		glEnd();

		glColor3ub(40,40,40);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-18);
		glVertex3f(sbX2,0,sbZ-18);
		glVertex3f(sbX2,sbY+6,sbZ-18);
		glVertex3f(sbX1,sbY+6,sbZ-18);
		glEnd();

		glColor3ub(30,30,30);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-23);
		glVertex3f(sbX2,0,sbZ-23);
		glVertex3f(sbX2,sbY+4,sbZ-23);
		glVertex3f(sbX1,sbY+4,sbZ-23);
		glEnd();

		glColor3ub(20,20,20);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-28);
		glVertex3f(sbX2,0,sbZ-28);
		glVertex3f(sbX2,sbY+2,sbZ-28);
		glVertex3f(sbX1,sbY+2,sbZ-28);
		glEnd();

		glColor3ub(10,10,10);
		glBegin(GL_QUADS);
		glVertex3f(sbX1,0,sbZ-32);
		glVertex3f(sbX2,0,sbZ-32);
		glVertex3f(sbX2,sbY,sbZ-32);
		glVertex3f(sbX1,sbY,sbZ-32);
		glEnd();

		//right Wall
		glColor3ub(50,50,50);
		glBegin(GL_POLYGON);
		glVertex3f(sbX2,0,sbZ);
		glVertex3f(sbX2,sbY,sbZ);
		glVertex3f(sbX2,sbY+2,sbZ-5);
		glVertex3f(sbX2,sbY+4,sbZ-10);
		glVertex3f(sbX2,sbY+6,sbZ-15);
		glVertex3f(sbX2,sbY+6,sbZ-16);
		glVertex3f(sbX2,sbY+6,sbZ-17);
		glVertex3f(sbX2,sbY+6,sbZ-18);
		glVertex3f(sbX2,sbY+4,sbZ-23);
		glVertex3f(sbX2,sbY+2,sbZ-28);
		glVertex3f(sbX2,sbY,sbZ-32);
		glVertex3f(sbX2,0,sbZ-32);
		glEnd();
		//left Wall
		glColor3ub(50,50,50);
		glBegin(GL_POLYGON);
		glVertex3f(sbX1,0,sbZ);
		glVertex3f(sbX1,sbY,sbZ);
		glVertex3f(sbX1,sbY+2,sbZ-5);
		glVertex3f(sbX1,sbY+4,sbZ-10);
		glVertex3f(sbX1,sbY+6,sbZ-15);
		glVertex3f(sbX1,sbY+6,sbZ-16);
		glVertex3f(sbX1,sbY+6,sbZ-17);
		glVertex3f(sbX1,sbY+6,sbZ-18);
		glVertex3f(sbX1,sbY+4,sbZ-23);
		glVertex3f(sbX1,sbY+2,sbZ-28);
		glVertex3f(sbX1,sbY,sbZ-32);
		glVertex3f(sbX1,0,sbZ-32);
		glEnd();
	
	}

	void MotherboardPiece::drawChipset(int white_black)
	{

		glColor3ub(255,255,255);
		drawQuad(chipX1,chipX2,chipY,chipZ1,chipZ2,white_black);
		glColor3ub(50,50,50);
		drawQuad(chip2X1,chip2X2,chip2Y,chip2Z1,chip2Z2,white_black);
		glColor3ub(255,255,255);
	
	
	}
	void MotherboardPiece::drawFullCable(int copperCable2)
	{

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,copperCable2);
		
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(cableX1,0,cableZ1+2);
		glTexCoord2f(1,0);
		glVertex3d(cableX2,0,cableZ1+2);
		glTexCoord2f(1,1);
		glVertex3d(cableX2,cableY,cableZ1);
		glTexCoord2f(0,1);
		glVertex3d(cableX1,cableY,cableZ1);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(cableX1,0,cableZ2-2);
		glTexCoord2f(1,0);
		glVertex3d(cableX2,0,cableZ2-2);
		glTexCoord2f(1,1);
		glVertex3d(cableX2,cableY,cableZ2);
		glTexCoord2f(0,1);
		glVertex3d(cableX1,cableY,cableZ2);
		glEnd();

		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3d(cableX1,cableY,cableZ1);
		glTexCoord2f(1,0);
		glVertex3d(cableX2,cableY,cableZ1);
		glTexCoord2f(1,1);
		glVertex3d(cableX2,cableY,cableZ2);
		glTexCoord2f(0,1);
		glVertex3d(cableX1,cableY,cableZ2);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		
		//drawCable(cablecableX1,cablecableX2,cablecableY,cablecableZ1,cablecableZ2,copperCable2);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,copperCable2);
		glBegin(GL_QUADS);
		//right
		glTexCoord2f(0,0);
		glVertex3f(cableX2,0,cableZ2-2);
		glTexCoord2f(1,0);
		glVertex3f(cableX2,0,cableZ1+2);
		glTexCoord2f(1,1);
		glVertex3f(cableX2,cableY,cableZ1);
		glTexCoord2f(0,1);
		glVertex3f(cableX2,cableY,cableZ2);
		//left
		glTexCoord2f(0,0);
		glVertex3f(cableX1,0,cableZ2-2);
		glTexCoord2f(1,0);
		glVertex3f(cableX1,0,cableZ1+2);
		glTexCoord2f(1,1);
		glVertex3f(cableX1,cableY,cableZ1);
		glTexCoord2f(0,1);
		glVertex3f(cableX1,cableY,cableZ2);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	void MotherboardPiece::drawCables(int copperCable2)
	{
		//1
		drawFullCable(copperCable2);
		//2
		glPushMatrix();
		glTranslatef(2.5,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(5,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(7.5,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();

		//2
		glPushMatrix();
		glTranslatef(20,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(22.5,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(25,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();

		//2
		glPushMatrix();
		glTranslatef(40,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(42.5,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(45,0,0);
		drawFullCable(copperCable2);
		glPopMatrix();


		//2
		glPushMatrix();
		glTranslatef(-40,0,60);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(-42.5,0,60);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(-45,0,60);
		drawFullCable(copperCable2);
		glPopMatrix();


		//2
		glPushMatrix();
		glTranslatef(-50,0,60);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(-52.5,0,60);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(-55,0,60);
		drawFullCable(copperCable2);
		glPopMatrix();
		//2
		glPushMatrix();
		glTranslatef(-100,0,10);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(-105,0,10);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(-110,0,10);
		drawFullCable(copperCable2);
		glPopMatrix();

		//2
		glPushMatrix();
		glTranslatef(-280,0,-10);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(-285,0,-10);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(-290,0,-10);
		drawFullCable(copperCable2);
		glPopMatrix();

		//3
		glPushMatrix();
		glTranslatef(-140,0,-100);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(-135,0,-100);
		drawFullCable(copperCable2);
		glPopMatrix();

		//3
		glPushMatrix();
		glTranslatef(-260,0,-100);
		drawFullCable(copperCable2);
		glPopMatrix();
		//4
		glPushMatrix();
		glTranslatef(-262.5,0,-100);
		drawFullCable(copperCable2);
		glPopMatrix();
		//3
		glPushMatrix();
		glTranslatef(-265,0,-100);
		drawFullCable(copperCable2);
		glPopMatrix();
	
	
	}

	