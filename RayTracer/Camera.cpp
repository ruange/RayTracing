#include "Camera.h"
#define M_PI 3.141592


Camera::Camera(int w, int h, float f, float angle, Vector location)
{
	width = w;
	height = h;
	fov = f;
	Matrix4 cameraToWorld;
	Matrix4 rotate;
	Matrix4 translate;
	rotate.rotate(0, angle);
	translate.translate(location);
	cameraToWorld = cameraToWorld * translate;
	cameraToWorld = cameraToWorld * rotate;
	origin = cameraToWorld.matmul(location);
	width >= height ? aspectRatio = width / (float)height : aspectRatio = height / (float)width;

}

float Camera::worldX(float x)
{
	float wx = (2 * (x + 0.5) / (float)width - 1) * tan(fov / 2* M_PI / 180) * aspectRatio;
	return wx;
}

float Camera::worldY(float y)
{
	float wy = (1 - 2 * (y + 0.5) / (float)height) * tan(fov / 2 * M_PI / 180);
	return wy;
}

Vector Camera::getRayVec(int pi, int pj) {
	return Vector();

}
