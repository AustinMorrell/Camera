#pragma once
#include "Camera.h"
class FlyCamera : public Camera
{
private:
	double thata;
	float speed;
	vec3 up;
public:
	void setSpeed(float speed);
	void update(double deltaTime);
};