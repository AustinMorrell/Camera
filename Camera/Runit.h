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

private:
	FlyCamera Cam;

	mat4 view;
	mat4 projection;

	GLFWwindow* window;
};