#pragma once

#include <Windows.h>
#include <gl.h>

#include "utility.h"
#include "skybox.h"

#define PI 3.141592653589
#define PIdiv180 (PI/180.0)

/////////////////////////////////
//Note: All angles in degrees  //
/////////////////////////////////

class Camera
{
public:
	
	Vector3dStruct View;
	Vector3dStruct Target;
	Vector3dStruct RightVector;	
	Vector3dStruct Up;
	Vector3dStruct Position;

	GLfloat RotatedX, RotatedY, RotatedZ;	
	
public:
	/* Inits the values (Position: (0|0|0) Target: (0|0|-1) ) */
	Camera();	

	/*
		Executes some glRotates and a glTranslate command
		Note: You should call glLoadIdentity before using Render
	*/
	void Render ( );	

	/* Resets that camera's vectors */
	void Reset();

	void drawCursor();

	void Move ( Vector3dStruct Direction );
	void RotateX( GLfloat Angle );
	void RotateY( GLfloat Angle );
	void RotateZ( GLfloat Angle );

	void MoveForward ( GLfloat Distance );
	void MoveBackward(GLfloat Distance);
	void MoveUpward ( GLfloat Distance );
	void MoveRight ( GLfloat Distance );
	void MoveLeft(GLfloat Distance);
	void MoveDownward(GLfloat Distance);

	
	Vector3dStruct testMoveForward ( GLfloat Distance );
	Vector3dStruct testMoveBackward(GLfloat Distance);
	Vector3dStruct testMoveUpward ( GLfloat Distance );
	Vector3dStruct testMoveRight ( GLfloat Distance );
	Vector3dStruct testMoveLeft(GLfloat Distance);
	Vector3dStruct testMoveDownward(GLfloat Distance);

	void SetRotateX(GLfloat Angle);
	void invertView();
	virtual void respondToKeyboard(bool *, Skybox *);
	virtual void respondToMouse(int, int);
	bool exceedsSkybox(Vector3dStruct, Skybox *);

};