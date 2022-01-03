#include <windows.h>		// Header File For Windows
#include <gl/GL.h>				// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <math.h>
#include <iostream>

#include "include/camera.h"
#include "include/skybox.h"
#include "include/utility.h"

Vector3dStruct operator+(Vector3dStruct v, Vector3dStruct u)
{
	Vector3dStruct res;
	res.x = v.x + u.x;
	res.y = v.y + u.y;
	res.z = v.z + u.z;
	return res;
}

Vector3dStruct operator-(Vector3dStruct v, Vector3dStruct u)
{
	Vector3dStruct res;
	res.x = v.x - u.x;
	res.y = v.y - u.y;
	res.z = v.z - u.z;
	return res;
}


Vector3dStruct operator*(Vector3dStruct v, float r)
{
	Vector3dStruct res;
	res.x = v.x * r;
	res.y = v.y * r;
	res.z = v.z * r;
	return res;
}

Vector3dStruct CrossProduct(Vector3dStruct* u, Vector3dStruct* v)
{
	Vector3dStruct resVector;
	resVector.x = u->y * v->z - u->z * v->y;
	resVector.y = u->z * v->x - u->x * v->z;
	resVector.z = u->x * v->y - u->y * v->x;

	return resVector;
}

float operator*(Vector3dStruct v, Vector3dStruct u) //dot product
{
	return v.x * u.x + v.y * u.y + v.z * u.z;
}


/***************************************************************************************/

Camera::Camera()
{
	this->Reset();
}

void Camera::Reset() {
	Position = Vector3dCreate(0.0, 0.0, 0.0);
	Up = Vector3dCreate(0.0, 1.0, 0.0);
	View = Vector3dCreate(0.0, 0.0, -1.0);
	RightVector = Vector3dCreate(1.0, 0.0, 0.0);
	RotatedX = RotatedY = RotatedZ = 0.0;
}

void Camera::Render(void)
{
	this->drawCursor();
	Vector3dStruct ViewPoint = Position + View;
	gluLookAt(
		Position.x, Position.y, Position.z,
	    ViewPoint.x, ViewPoint.y, ViewPoint.z,
	    Up.x, Up.y, Up.z
	);
}

void Camera::drawCursor() {
	const float width = 0.2;
	const float height = 0.2;
	const float offset = 0.1;

	const float depth = -5;

	glDisable(GL_TEXTURE_2D);
	glColor3f(0, 1, 0);
	glLineWidth(4);
	glBegin(GL_LINES);
		glVertex3f(0, -height, depth);
		glVertex3f(0, -offset, depth);

		glVertex3f(0, offset, depth);
		glVertex3f(0, height, depth);

		glVertex3f(width, 0, depth);
		glVertex3f(offset, 0, depth);

		glVertex3f(-width, 0, depth);
		glVertex3f(-offset, 0, depth);
	glEnd();
	glEnable(GL_TEXTURE_2D);
}

void Camera::Move(Vector3dStruct Direction)
{
	Position = Position + Direction;
}

void Camera::RotateX(GLfloat Angle)
{
	RotatedX += Angle;
	//Rotate viewdir around the right vector:
	View = NormalizeVector3d(View * cosf(Angle * PIdiv180) + Up * sinf(Angle * PIdiv180));
	//now compute the new UpVector (by cross product)
	Up = CrossProduct(&View, &RightVector) * -1;
}

void Camera::RotateY(GLfloat Angle)
{
	RotatedY += Angle;
	//Rotate viewdir around the up vector:
	View = NormalizeVector3d(View * cosf(Angle * PIdiv180) - RightVector * sinf(Angle * PIdiv180));
	//now compute the new RightVector (by cross product)
	RightVector = CrossProduct(&View, &Up);
}

void Camera::RotateZ(GLfloat Angle)
{
	RotatedZ += Angle;
	//Rotate viewdir around the right vector:
	RightVector = NormalizeVector3d(RightVector * cosf(Angle * PIdiv180) + Up * sinf(Angle * PIdiv180));
	//now compute the new UpVector (by cross product)
	Up = CrossProduct(&View, &RightVector) * -1;
}

void Camera::MoveForward(GLfloat Distance)
{
	Position = Position + (View * Distance);
}

void Camera::MoveBackward(GLfloat Distance)
{
	Position = Position - (View * Distance);
}

void Camera::MoveRight(GLfloat Distance)
{
	Position = Position + (RightVector * Distance);
}

void Camera::MoveLeft(GLfloat Distance)
{
	Position = Position - (RightVector * Distance);
}

void Camera::MoveUpward(GLfloat Distance)
{
	Position = Position + (Up * Distance);
}

void Camera::MoveDownward(GLfloat Distance)
{
	Position = Position - (Up * Distance);
}

void Camera::SetRotateX(GLfloat Angle)
{
	View = Vector3dCreate(0.0, 0.0, -1.0);
	RightVector = Vector3dCreate(1.0, 0.0, 0.0);
	Up = Vector3dCreate(0.0, 1.0, 0.0);
	RotatedX = Angle;
}

void Camera::invertView() {
	this->View = this->View * -1;
}

void Camera::respondToKeyboard(bool *keys) {
	float step = 0.7f;
	float angle = 0.4f;

	if (keys['F']) {
		glColor3f(1, 1, 1);
		// Press F to debug;
	}

	if (keys['D'])
		MoveRight(step);
	if (keys['A'])
		MoveLeft(step);
	if (keys['W'])
		MoveForward(step);
	if (keys['S'])
		MoveBackward(step);
	if (keys['Z'])
	{
		MoveUpward(step);
	}
	if (keys['X'])
	{
		if (!(Position.y <= 0))
		{
			
		}

		MoveDownward(step);
	}
	if (keys[VK_LEFT])
	{
		RotateY(angle);
	}
	if (keys[VK_RIGHT])
	{
		RotateY(-angle);
	}
	if (keys[VK_UP])
		RotateX(-angle);
	if (keys[VK_DOWN])
		RotateX(angle);
	if (keys['L'])
		RotateZ(-step);
	if (keys['K'])
		RotateZ(step);

	if (keys['R']) 
		Reset();
	Render();
}


//void Camera::rotateXWithMouse(bool rotateRight) {
//	//mouseX = mouseX < 960 ? -mouseX: mouseX;
//	float angle = 0.4;
//	float finalAngle = mouseX < 0 ? angle: -angle;
//	this->RotateY(finalAngle);
//}

void Camera::respondToMouse(int mouseX, int mouseY) {

}

bool Camera::exceedsSkybox(const Skybox *skybox) {
	const Vector3dStruct position = this->Position;

	/*return (
		(position.x <= -skybox->width) ||
		(position.x >= skybox->width) ||

		(position.y < 0) ||
		(position.y >= skybox->height)
	);*/
	
	return false;
}