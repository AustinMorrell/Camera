#pragma once
#include "FlyCamera.h"

class Runit
{
public:
	virtual int Start() = 0;
	virtual bool Update() = 0;
	virtual void Draw() = 0;
	virtual void Stop() = 0;
};

class App : public Runit
{
public:
	App();
	int Start() override;
	bool Update() override;
	void Draw() override;
	void Stop() override;
	mat4 p_ViewMatrix;
	double DeltaTime;
private:
	FlyCamera Cam;
	double pastTime = 0;
	double newTime;
	mat4 view;
	mat4 projection;

	GLFWwindow* window;
};