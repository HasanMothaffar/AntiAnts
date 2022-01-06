#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library

#include "keyboard_piece.h"

KeyboardPiece::KeyboardPiece() {
	 X1=0;  X2=200; 
 Y1=0;  Y2=1; 
 Z1=0;  Z2=-79; 

 X11=0;  X22=1.5;  X33=10.5;  X44=12;
 Y11=4.5;  Y22=10.5; 
 Z11=0;  Z22=-3;  Z33=-9;  Z44=-12;
 x11=0;  x22=0.6;  x33=5.4;  x44=6;
 y11=3;  y22=6; 
 z11=0;  z22=-1.5;  z33=-4.5;  z44=-6;

 q1=0;  q2=1.5;  q3=70.5;  q4=72;
 a1=0;  a2=1.5;  a3=21;  a4=24;
 f1=0;  f2=1.5;  f3=15.75;  f4=18;
 s1=0;  s2=1.5;  s3=13.125;  s4=15;
 k1=0;  k2=1.5;  k3=27.25;  k4=30;

}

void KeyboardPiece::cube() const {

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.6,0.6,0.6);
	//TOP of the cube
	glVertex3f(X1, Y2, Z1);  
	glVertex3f(X2, Y2, Z1);   
	glVertex3f(X2, Y2, Z2);   
	glVertex3f(X1, Y2, Z2);    

	glColor3f(0.6,0.6,0.6);
	//BOTTEM of the cube
	glVertex3f(X1, Y1, Z1);  
	glVertex3f(X2, Y1, Z1);   
	glVertex3f(X2, Y1, Z2);   
	glVertex3f(X1, Y1, Z2);

	glColor3f(0.8,0.8,0.8);
	//BACK of the cube
	glVertex3f(X1, Y1, Z2);  
	glVertex3f(X2, Y1, Z2);   
	glVertex3f(X2, Y2, Z2);   
	glVertex3f(X1, Y2, Z2);    

	glColor3f(0.8,0.8,0.8);
	//FRONT of the cube
	glVertex3f(X1, Y1, Z1);   
	glVertex3f(X2, Y1, Z1);   
	glVertex3f(X2, Y2, Z1);    
	glVertex3f(X1, Y2, Z1);    

	glColor3f(0.6,0.6,0.6);
	//LEFT of the cube
	glVertex3f(X1, Y1, Z1);  
	glVertex3f(X1, Y1, Z2);   
	glVertex3f(X1, Y2, Z2);   
	glVertex3f(X1, Y2, Z1);  
	
	glColor3f(0.6,0.6,0.6);
	//RIGHT of the cube
	glVertex3f(X2, Y1, Z1);  
	glVertex3f(X2, Y1, Z2);   
	glVertex3f(X2, Y2, Z2);   
	glVertex3f(X2, Y2, Z1); 

	// End Drawing The Cube
	glEnd();           
	glPopMatrix();
}
void KeyboardPiece::cube2() const {

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.6,0.6,0.6);
	//BOTTEM of the cube
	glVertex3f(0, 0, 0);  
	glVertex3f(200, 0, 0);   
	glVertex3f(200, 0, -79);   
	glVertex3f(0, 0, -79);

	glEnd();           
	glPopMatrix();
}
void KeyboardPiece::Button() const {

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.8,0.8,0.8);
	//TOP of the cube
	glColor3f(0.9,0.9,0.9);
	glVertex3f(X22, Y22, Z22);  
	glVertex3f(X33, Y22, Z22);   
	glVertex3f(X33, Y22, Z33); 
	glColor3f(0.9,0.9,0.9);
	glVertex3f(X22, Y22, Z33);   

	glColor3f(0.8,0.8,0.8);
	//BACK of the cube
	glVertex3f(X11, Y11, Z44);  //3
	glVertex3f(X44, Y11, Z44);  //4       
	glVertex3f(X33, Y22, Z33);  //8  
	glColor3f(0.9,0.9,0.9);
	glVertex3f(X22, Y22, Z33);  //7  

	glColor3f(0.8,0.8,0.8);
	//FRONT of the cube
	glVertex3f(X11, Y11, Z11);  //1
	glVertex3f(X44, Y11, Z11);  //2       
	glVertex3f(X33, Y22, Z22);  //6  
	glColor3f(0.9,0.9,0.9);
	glVertex3f(X22, Y22, Z22);  //5

	glColor3f(0.8,0.8,0.8);
	//LEFT of the cube
	glVertex3f(X11, Y11, Z11);  
	glVertex3f(X11, Y11, Z44);   
	glVertex3f(X22, Y22, Z33);   
	glVertex3f(X22, Y22, Z22);  
	
	glColor3f(0.8,0.8,0.8);
	//RIGHT of the cube
	glVertex3f(X44, Y11, Z11);  
	glVertex3f(X44, Y11, Z44);   
	glVertex3f(X33, Y22, Z33);   
	glVertex3f(X33, Y22, Z22); 

	// End Drawing The Cube
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, -1, -3);
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.4,0.4,0.4);
	//TOP of the cube
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  
	glVertex3f(x33, y22, z22);   
	glVertex3f(x33, y22, z33); 
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);   

	glColor3f(0.4,0.4,0.4);
	//BACK of the cube
	glVertex3f(x11, y11, z44);  //3
	glVertex3f(x44, y11, z44);  //4       
	glVertex3f(x33, y22, z33);  //8  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);  //7  

	glColor3f(0.4,0.4,0.4);
	//FRONT of the cube
	glVertex3f(x11, y11, z11);  //1
	glVertex3f(x44, y11, z11);  //2       
	glVertex3f(x33, y22, z22);  //6  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  //5

	glColor3f(0.4,0.4,0.4);
	//LEFT of the cube
	glVertex3f(x11, y11, z11);  
	glVertex3f(x11, y11, z44);   
	glVertex3f(x22, y22, z33);   
	glVertex3f(x22, y22, z22);  
	
	glColor3f(0.4,0.4,0.4);
	//RIGHT of the cube
	glVertex3f(x44, y11, z11);  
	glVertex3f(x44, y11, z44);   
	glVertex3f(x33, y22, z33);   
	glVertex3f(x33, y22, z22); 

	// End Drawing The Cube
	glEnd(); 
	glPopMatrix();
}
void KeyboardPiece::shiftButton() const {
	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.8,0.8,0.8);
	//TOP of the cube
	glColor3f(0.9,0.9,0.9);
	glVertex3f(q2, Y22, Z22);  
	glVertex3f(q3, Y22, Z22);   
	glVertex3f(q3, Y22, Z33); 
	glColor3f(0.9,0.9,0.9);
	glVertex3f(q2, Y22, Z33);   

	glColor3f(0.8,0.8,0.8);
	//BACK of the cube
	glVertex3f(q1, Y11, Z44);  //3
	glVertex3f(q4, Y11, Z44);  //4       
	glVertex3f(q3, Y22, Z33);  //8  
	glColor3f(0.9,0.9,0.9);
	glVertex3f(q2, Y22, Z33);  //7  

	glColor3f(0.8,0.8,0.8);
	//FRONT of the cube
	glVertex3f(q1, Y11, Z11);  //1
	glVertex3f(q4, Y11, Z11);  //2       
	glVertex3f(q3, Y22, Z22);  //6  
	glColor3f(0.9,0.9,0.9);
	glVertex3f(q2, Y22, Z22);  //5

	glColor3f(0.8,0.8,0.8);
	//LEFT of the cube
	glVertex3f(q1, Y11, Z11);  
	glVertex3f(q1, Y11, Z44);   
	glVertex3f(q2, Y22, Z33);   
	glVertex3f(q2, Y22, Z22);  
	
	glColor3f(0.8,0.8,0.8);
	//RIGHT of the cube
	glVertex3f(q4, Y11, Z11);  
	glVertex3f(q4, Y11, Z44);   
	glVertex3f(q3, Y22, Z33);   
	glVertex3f(q3, Y22, Z22); 

	// End Drawing The Cube
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -1, -1);
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.4,0.4,0.4);
	//TOP of the cube
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  
	glVertex3f(x33, y22, z22);   
	glVertex3f(x33, y22, z33); 
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);   

	glColor3f(0.4,0.4,0.4);
	//BACK of the cube
	glVertex3f(x11, y11, z44);  //3
	glVertex3f(x44, y11, z44);  //4       
	glVertex3f(x33, y22, z33);  //8  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);  //7  

	glColor3f(0.4,0.4,0.4);
	//FRONT of the cube
	glVertex3f(x11, y11, z11);  //1
	glVertex3f(x44, y11, z11);  //2       
	glVertex3f(x33, y22, z22);  //6  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  //5

	glColor3f(0.4,0.4,0.4);
	//LEFT of the cube
	glVertex3f(x11, y11, z11);  
	glVertex3f(x11, y11, z44);   
	glVertex3f(x22, y22, z33);   
	glVertex3f(x22, y22, z22);  
	
	glColor3f(0.4,0.4,0.4);
	//RIGHT of the cube
	glVertex3f(x44, y11, z11);  
	glVertex3f(x44, y11, z44);   
	glVertex3f(x33, y22, z33);   
	glVertex3f(x33, y22, z22); 

	// End Drawing The Cube
	glEnd(); 
	glPopMatrix();
}
void KeyboardPiece::size1() const {

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 
	
	glColor3f(0.5,0.5,0.5);
	//TOP of the cube
	glColor3f(0.6,0.6,0.6);
	glVertex3f(a2, Y22, Z22);  
	glVertex3f(a3, Y22, Z22);   
	glVertex3f(a3, Y22, Z33); 
	glColor3f(0.6,0.6,0.6);
	glVertex3f(a2, Y22, Z33);   

	glColor3f(0.5,0.5,0.5);
	//BACK of the cube
	glVertex3f(a1, Y11, Z44);  //3
	glVertex3f(a4, Y11, Z44);  //4       
	glVertex3f(a3, Y22, Z33);  //8  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(a2, Y22, Z33);  //7  

	glColor3f(0.5,0.5,0.5);
	//FRONT of the cube
	glVertex3f(a1, Y11, Z11);  //1
	glVertex3f(a4, Y11, Z11);  //2       
	glVertex3f(a3, Y22, Z22);  //6  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(a2, Y22, Z22);  //5

	glColor3f(0.5,0.5,0.5);
	//LEFT of the cube
	glVertex3f(a1, Y11, Z11);  
	glVertex3f(a1, Y11, Z44);   
	glVertex3f(a2, Y22, Z33);   
	glVertex3f(a2, Y22, Z22);  
	
	glColor3f(0.5,0.5,0.5);
	//RIGHT of the cube
	glVertex3f(a4, Y11, Z11);  
	glVertex3f(a4, Y11, Z44);   
	glVertex3f(a3, Y22, Z33);   
	glVertex3f(a3, Y22, Z22); 

	// End Drawing The Cube
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, -1, -1);
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.4,0.4,0.4);
	//TOP of the cube
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  
	glVertex3f(x33, y22, z22);   
	glVertex3f(x33, y22, z33); 
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);   

	glColor3f(0.4,0.4,0.4);
	//BACK of the cube
	glVertex3f(x11, y11, z44);  //3
	glVertex3f(x44, y11, z44);  //4       
	glVertex3f(x33, y22, z33);  //8  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);  //7  

	glColor3f(0.4,0.4,0.4);
	//FRONT of the cube
	glVertex3f(x11, y11, z11);  //1
	glVertex3f(x44, y11, z11);  //2       
	glVertex3f(x33, y22, z22);  //6  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  //5

	glColor3f(0.4,0.4,0.4);
	//LEFT of the cube
	glVertex3f(x11, y11, z11);  
	glVertex3f(x11, y11, z44);   
	glVertex3f(x22, y22, z33);   
	glVertex3f(x22, y22, z22);  
	
	glColor3f(0.4,0.4,0.4);
	//RIGHT of the cube
	glVertex3f(x44, y11, z11);  
	glVertex3f(x44, y11, z44);   
	glVertex3f(x33, y22, z33);   
	glVertex3f(x33, y22, z22); 

	// End Drawing The Cube
	glEnd(); 
	glPopMatrix();
}
void KeyboardPiece::size2() const {

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.5,0.5,0.5);
	//TOP of the cube
	glColor3f(0.6,0.6,0.6);
	glVertex3f(f2, Y22, Z22);  
	glVertex3f(f3, Y22, Z22);   
	glVertex3f(f3, Y22, Z33); 
	glColor3f(0.6,0.6,0.6);
	glVertex3f(f2, Y22, Z33);   

	glColor3f(0.5,0.5,0.5);
	//BACK of the cube
	glVertex3f(f1, Y11, Z44);  //3
	glVertex3f(f4, Y11, Z44);  //4       
	glVertex3f(f3, Y22, Z33);  //8  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(f2, Y22, Z33);  //7  

	glColor3f(0.5,0.5,0.5);
	//FRONT of the cube
	glVertex3f(f1, Y11, Z11);  //1
	glVertex3f(f4, Y11, Z11);  //2       
	glVertex3f(f3, Y22, Z22);  //6  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(f2, Y22, Z22);  //5

	glColor3f(0.5,0.5,0.5);
	//LEFT of the cube
	glVertex3f(f1, Y11, Z11);  
	glVertex3f(f1, Y11, Z44);   
	glVertex3f(f2, Y22, Z33);   
	glVertex3f(f2, Y22, Z22);  
	
	glColor3f(0.5,0.5,0.5);
	//RIGHT of the cube
	glVertex3f(f4, Y11, Z11);  
	glVertex3f(f4, Y11, Z44);   
	glVertex3f(f3, Y22, Z33);   
	glVertex3f(f3, Y22, Z22); 

	// End Drawing The Cube
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -1, -1);
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.4,0.4,0.4);
	//TOP of the cube
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  
	glVertex3f(x33, y22, z22);   
	glVertex3f(x33, y22, z33); 
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);   

	glColor3f(0.4,0.4,0.4);
	//BACK of the cube
	glVertex3f(x11, y11, z44);  //3
	glVertex3f(x44, y11, z44);  //4       
	glVertex3f(x33, y22, z33);  //8  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);  //7  

	glColor3f(0.4,0.4,0.4);
	//FRONT of the cube
	glVertex3f(x11, y11, z11);  //1
	glVertex3f(x44, y11, z11);  //2       
	glVertex3f(x33, y22, z22);  //6  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  //5

	glColor3f(0.4,0.4,0.4);
	//LEFT of the cube
	glVertex3f(x11, y11, z11);  
	glVertex3f(x11, y11, z44);   
	glVertex3f(x22, y22, z33);   
	glVertex3f(x22, y22, z22);  
	
	glColor3f(0.4,0.4,0.4);
	//RIGHT of the cube
	glVertex3f(x44, y11, z11);  
	glVertex3f(x44, y11, z44);   
	glVertex3f(x33, y22, z33);   
	glVertex3f(x33, y22, z22); 

	// End Drawing The Cube
	glEnd(); 
	glPopMatrix();
}
void KeyboardPiece::size3() const {

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.5,0.5,0.5);
	//TOP of the cube
	glColor3f(0.6,0.6,0.6);
	glVertex3f(s2, Y22, Z22);  
	glVertex3f(s3, Y22, Z22);   
	glVertex3f(s3, Y22, Z33); 
	glColor3f(0.6,0.6,0.6);
	glVertex3f(s2, Y22, Z33);   

	glColor3f(0.5,0.5,0.5);
	//BACK of the cube
	glVertex3f(s1, Y11, Z44);  //3
	glVertex3f(s4, Y11, Z44);  //4       
	glVertex3f(s3, Y22, Z33);  //8  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(s2, Y22, Z33);  //7  

	glColor3f(0.5,0.5,0.5);
	//FRONT of the cube
	glVertex3f(s1, Y11, Z11);  //1
	glVertex3f(s4, Y11, Z11);  //2       
	glVertex3f(s3, Y22, Z22);  //6  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(s2, Y22, Z22);  //5

	glColor3f(0.5,0.5,0.5);
	//LEFT of the cube
	glVertex3f(s1, Y11, Z11);  
	glVertex3f(s1, Y11, Z44);   
	glVertex3f(s2, Y22, Z33);   
	glVertex3f(s2, Y22, Z22);  
	
	glColor3f(0.5,0.5,0.5);
	//RIGHT of the cube
	glVertex3f(s4, Y11, Z11);  
	glVertex3f(s4, Y11, Z44);   
	glVertex3f(s3, Y22, Z33);   
	glVertex3f(s3, Y22, Z22); 

	// End Drawing The Cube
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, -1, -1);
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.4,0.4,0.4);
	//TOP of the cube
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  
	glVertex3f(x33, y22, z22);   
	glVertex3f(x33, y22, z33); 
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);   

	glColor3f(0.4,0.4,0.4);
	//BACK of the cube
	glVertex3f(x11, y11, z44);  //3
	glVertex3f(x44, y11, z44);  //4       
	glVertex3f(x33, y22, z33);  //8  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);  //7  

	glColor3f(0.4,0.4,0.4);
	//FRONT of the cube
	glVertex3f(x11, y11, z11);  //1
	glVertex3f(x44, y11, z11);  //2       
	glVertex3f(x33, y22, z22);  //6  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  //5

	glColor3f(0.4,0.4,0.4);
	//LEFT of the cube
	glVertex3f(x11, y11, z11);  
	glVertex3f(x11, y11, z44);   
	glVertex3f(x22, y22, z33);   
	glVertex3f(x22, y22, z22);  
	
	glColor3f(0.4,0.4,0.4);
	//RIGHT of the cube
	glVertex3f(x44, y11, z11);  
	glVertex3f(x44, y11, z44);   
	glVertex3f(x33, y22, z33);   
	glVertex3f(x33, y22, z22); 

	// End Drawing The Cube
	glEnd(); 
	glPopMatrix();
}
void KeyboardPiece::size4() const {

	glPushMatrix();
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.5,0.5,0.5);
	//TOP of the cube
	glColor3f(0.6,0.6,0.6);
	glVertex3f(k2, Y22, Z22);  
	glVertex3f(k3, Y22, Z22);   
	glVertex3f(k3, Y22, Z33); 
	glColor3f(0.6,0.6,0.6);
	glVertex3f(k2, Y22, Z33);   

	glColor3f(0.5,0.5,0.5);
	//BACK of the cube
	glVertex3f(k1, Y11, Z44);  //3
	glVertex3f(k4, Y11, Z44);  //4       
	glVertex3f(k3, Y22, Z33);  //8  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(k2, Y22, Z33);  //7  

	glColor3f(0.5,0.5,0.5);
	//FRONT of the cube
	glVertex3f(k1, Y11, Z11);  //1
	glVertex3f(k4, Y11, Z11);  //2       
	glVertex3f(k3, Y22, Z22);  //6  
	glColor3f(0.6,0.6,0.6);
	glVertex3f(k2, Y22, Z22);  //5

	glColor3f(0.5,0.5,0.5);
	//LEFT of the cube
	glVertex3f(k1, Y11, Z11);  
	glVertex3f(k1, Y11, Z44);   
	glVertex3f(k2, Y22, Z33);   
	glVertex3f(k2, Y22, Z22);  
	
	glColor3f(0.5,0.5,0.5);
	//RIGHT of the cube
	glVertex3f(k4, Y11, Z11);  
	glVertex3f(k4, Y11, Z44);   
	glVertex3f(k3, Y22, Z33);   
	glVertex3f(k3, Y22, Z22); 

	// End Drawing The Cube
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11, -1, -1);
	//Draw The Cube Using quads
    glBegin(GL_QUADS); 

	glColor3f(0.4,0.4,0.4);
	//TOP of the cube
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  
	glVertex3f(x33, y22, z22);   
	glVertex3f(x33, y22, z33); 
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);   

	glColor3f(0.4,0.4,0.4);
	//BACK of the cube
	glVertex3f(x11, y11, z44);  //3
	glVertex3f(x44, y11, z44);  //4       
	glVertex3f(x33, y22, z33);  //8  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z33);  //7  

	glColor3f(0.4,0.4,0.4);
	//FRONT of the cube
	glVertex3f(x11, y11, z11);  //1
	glVertex3f(x44, y11, z11);  //2       
	glVertex3f(x33, y22, z22);  //6  
	glColor3f(0.5,0.5,0.5);
	glVertex3f(x22, y22, z22);  //5

	glColor3f(0.4,0.4,0.4);
	//LEFT of the cube
	glVertex3f(x11, y11, z11);  
	glVertex3f(x11, y11, z44);   
	glVertex3f(x22, y22, z33);   
	glVertex3f(x22, y22, z22);  
	
	glColor3f(0.4,0.4,0.4);
	//RIGHT of the cube
	glVertex3f(x44, y11, z11);  
	glVertex3f(x44, y11, z44);   
	glVertex3f(x33, y22, z33);   
	glVertex3f(x33, y22, z22); 

	// End Drawing The Cube
	glEnd(); 
	glPopMatrix();
}