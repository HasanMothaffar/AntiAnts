#pragma once

class Skybox
{
public:
	float width;
	float height;
	float length;

	Skybox(float width = 50.0f, float height = 50.0f, float length = 200.0f) {
		this->width = width;
		this->height = height;
		this->length = length;
	};

	virtual void draw() const = 0;
};