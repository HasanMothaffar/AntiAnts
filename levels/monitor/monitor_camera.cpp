#include <Windows.h>
#include <GL.H>

#include "../../include/camera.h"
#include "monitor_camera.h"

MonitorCamera::MonitorCamera() : Camera() { }

void MonitorCamera::respondToKeyboard(bool *keys) {
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
			MoveDownward(step);
		}
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