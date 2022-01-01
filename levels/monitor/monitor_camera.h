#pragma once

#include "../../include/camera.h"

class MonitorCamera : public Camera
{
		
public:
	MonitorCamera();

	virtual void respondToKeyboard(bool *keys);
};