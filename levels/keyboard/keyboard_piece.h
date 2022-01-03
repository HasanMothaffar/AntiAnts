#pragma once

#include <gl.h> // Header File For The OpenGL32 Library

class KeyboardPiece
{
public:

	float X1; float X2; 
    float Y1; float Y2; 
    float Z1; float Z2; 

	float X11; float X22; float X33; float X44;
	float Y11; float Y22; 
	float Z11; float Z22; float Z33; float Z44;

	float x11; float x22; float x33; float x44;
	float y11; float y22; 
	float z11; float z22; float z33; float z44;

	float q1; float q2; float q3; float q4;
	float a1; float a2; float a3; float a4;
	float f1; float f2; float f3; float f4;
	float s1; float s2; float s3; float s4;
	float k1; float k2; float k3; float k4;

	KeyboardPiece();

	void cube() const;
	void cube2() const;
	void Button() const;
	void shiftButton() const;
	void size1() const;
	void size2() const;
	void size3() const;
	void size4() const;
};