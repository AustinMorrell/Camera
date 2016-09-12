#include "FlyCamera.h"

void Camera::setPerspective(float fieldOfView, float aspectRatio, float n, float f)
{
	projectionTransform = glm::perspective(fieldOfView, aspectRatio, n, f);
}

void Camera::setLookAt(vec3 from, vec3 to, vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);
}

void Camera::setPosition(vec3 position)
{
	worldTransform = worldTransform * glm::translate(position);
}

mat4 Camera::getWorldTransform()
{
	return worldTransform;
}

mat4 Camera::getView()
{
	return viewTransform;
}

mat4 Camera::getProjection()
{
	return projectionTransform;
}

mat4 Camera::getProjectionView()
{
	updateProjectionViewTransform();
	return projectionViewTransform;
}

void Camera::updateProjectionViewTransform()
{
	projectionViewTransform = projectionTransform * viewTransform * worldTransform;
}

void FlyCamera::setSpeed(float speed)
{
	this->speed = speed;
}

void FlyCamera::update(double deltaTime)
{
	mat4 Rotation, Scale, Trans = mat4(1);
	GLFWwindow* wind = glfwGetCurrentContext();

	float f_speed = glfwGetKey(wind, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS ? deltaTime * speed * 2 : deltaTime * speed;

	if (glfwGetKey(wind, 'W') == GLFW_PRESS)
	{
		worldTransform[3] -= getWorldTransform()[2] * f_speed;
	}
	if (glfwGetKey(wind, 'S') == GLFW_PRESS)
	{
		worldTransform[3] += getWorldTransform()[2] * f_speed;
	}
	if (glfwGetKey(wind, 'D') == GLFW_PRESS)
	{
		worldTransform[3] += getWorldTransform()[0] * f_speed;
	}
	if (glfwGetKey(wind, 'A') == GLFW_PRESS)
	{
		worldTransform[3] -= getWorldTransform()[0] * f_speed;
	}
	if (glfwGetKey(wind, 'Q') == GLFW_PRESS)
	{
		worldTransform[3] += getWorldTransform()[1] * f_speed;
	}
	if (glfwGetKey(wind, 'E') == GLFW_PRESS)
	{
		worldTransform[3] -= getWorldTransform()[1] * f_speed;
	}

	if (glfwGetMouseButton(wind, GLFW_MOUSE_BUTTON_LEFT))
	{
		double preMposX = 0, preMposY = 0;

		glfwGetCursorPos(wind, &preMposX, &preMposY);

		double MposX = 0, MposY = 0;
		glfwGetCursorPos(wind, &MposX, &MposY);

		double deltaX = MposX - preMposX, deltaY = MposY - preMposY;
		preMposX = MposX;
		preMposY = MposY;

		if (deltaY != 0)
		{
			thata = deltaY;
			Rotation[1][1] = cos(thata);
			Rotation[1][2] = -1 * sin(thata);
			Rotation[2][1] = sin(thata);
			Rotation[2][2] = cos(thata);
		}

		if (deltaX != 0)
		{
			thata = deltaX;
			Rotation[0][0] = cos(thata);
			Rotation[0][2] = sin(thata);
			Rotation[2][0] = -1 * sin(thata);
			Rotation[2][2] = cos(thata);
		}
		//worldTransform = glm::inverse(Trans * Rotation * Scale);
	}
	
	getProjectionView();
}