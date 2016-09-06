#pragma once
#include "Camera.h"
class FlyCamera : public Camera
{
private:
	float speed;
	vec3 up;
public:
	void setSpeed(float speed);
	void update(float deltaTime);
};