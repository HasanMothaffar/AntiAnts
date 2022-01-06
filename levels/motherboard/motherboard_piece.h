#pragma once

#include <Windows.h>
#include <GL.H>

class MotherboardPiece
{


public:
	MotherboardPiece(void);

public:

	/*Skybox*/ GLfloat motherboardWidth,motherboardHeight,motherboardLength , motherboardX,motherboardY,motherboardZ;

	/*Cpu*/ GLfloat cpuX1,cpuX2,cpuY,cpuZ1,cpuZ2;

	/*Heatsink*/ GLfloat heatsink_ud_x1 ,heatsink_ud_x2,heatsink_ud_y,heatsink_ud_z1,heatsink_ud_z2,
		                 heatsink_c_x1,heatsink_c_x2,heatsink_c_y,heatsink_c_z1,heatsink_c_z2;
	
	/*BIOS*/ GLfloat biosX1,biosX2,biosY,biosZ1,biosZ2,leg1X1,leg1X2,leg1Z1,leg1Z2,leg2X1,leg2X2,leg2Z1,leg2Z2;

	/*Ram*/ GLfloat ramCX,ramCY,ramCZ,ramBX1,ramBX2,ramBY,ramBZ1,ramBZ2;

	/*GPU PCI*/ GLfloat gpuSX1,gpuSX2,gpuSY,gpuSZ1,gpuSZ2;
	/* GPU Fans*/ GLfloat gpuFX,gpuFY1,gpuFY2,gpuFY3,gpuFZ;
	/*GPU*/ GLfloat gpuX1,gpuX2,gpuY,gpuZ1,gpuZ2;

	/*PCI*/ GLfloat pciX1,pciX2,pciY,pciZ1,pciZ2;

	/*Fan*/  GLfloat fanX,fanY1,fanY2,fanY3,fanZ;

	/*P4 Power*/ GLfloat p4X1,p4X2,p4Y,p4Z1,p4Z2;

	/*Inductors*/ GLfloat indWX1,indWX2,indWY,indWZ1,indWZ2,indCX1,indCX2,indCY,indCZ1,indCZ2;

	/*Transistor*/ GLfloat TransLX,TransLY,TransLZ,TransX1,TransX2,TransZ1,TransZ2;

	/*VGA Port*/ GLfloat vgaX1,vgaX2,vgaY,vgaZ1,vgaZ2;

	/*HDMI Port*/ GLfloat hdmiX1,hdmiX2,hdmiY,hdmiZ1,hdmiZ2;

	/*HDMI Port*/ GLfloat hdmi2X1,hdmi2X2,hdmi2Y,hdmi2Z1,hdmi2Z2;

	/*Old Port*/ GLfloat portX1,portX2,portY,portZ1,portZ2;

	/*Old Port 2*/ GLfloat port2X1,port2X2,port2Y,port2Z1,port2Z2;

	/*Southbridge*/ GLfloat sbX1,sbX2,sbY,sbZ;

	/*Chipset 1*/ GLfloat chipX1,chipX2,chipY,chipZ1,chipZ2;
	/*Chipset 2*/ GLfloat chip2X1,chip2X2,chip2Y,chip2Z1,chip2Z2;
	/*Full Cable*/ GLfloat cableX1,cableX2,cableY,cableZ1,cableZ2;
	GLfloat fanA;
	

public:
	//void drawSurface(int motherboardSurface);
	void drawCpu(int CPU,int grey);
	void drawHeatSink(int goldMetal,int heatSink);
	void drawBios(int BIOS);
	void drawRam(int n,GLfloat z,int BlueSlot,int WhiteSlot,int RAM);
	void drawPCI(int n,GLfloat x,GLfloat bodyX1 , GLfloat bodyX2,GLfloat bodyY , GLfloat bodyZ1 , GLfloat bodyZ2,int WhiteSlot);
	void drawCylinder(GLfloat radius, GLfloat height,int cmos,bool isCmos,int r,int g ,int b);
	void drawFan(GLfloat fanAngle , GLfloat x , GLfloat y1 ,GLfloat y2 , GLfloat y3 , GLfloat z,int black,int black2);
	void drawGPU(int red);
	void drawP4Power();
	void draw4Walls(GLfloat x1,GLfloat x2,GLfloat y,GLfloat z1,GLfloat z2);
	void drawCable(GLfloat x1,GLfloat x2,GLfloat y,GLfloat z1,GLfloat z2,int copperCable);
	void drawInductors(int copperCable);
	void drawTransistor(GLfloat lineX,GLfloat lineY,GLfloat lineZ,
		GLfloat TransistorX1,GLfloat TransistorX2,GLfloat TransistorZ1,GLfloat TransistorZ2,
		int transistor,int grey);
	void drawTransistors(int transistor,int grey);
	void drawVGA(int grey , int purple);
	void drawQuad(GLfloat x1,GLfloat x2,GLfloat y,GLfloat z1,GLfloat z2,int texture);
	void drawPorts(int hdmi);
	void drawCylinders();
	void drawSouthbridge();
	void drawChipset(int white_black);
	void drawFullCable(int copperCable2);
	void drawCables(int copperCable2);
	void StartMotherboardLevel(int motherboardSurface,int CPU,int grey,int WhiteSlot,int BlueSlot,
								   int goldMetal,int heatSink,int BIOS,int RAM,int Red,int cmos,int fanAngle,int caseT,
								   int copperCable,int purple,int white_black,int copperCable2,int black,int black2);
};

