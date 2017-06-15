#pragma once
#include "Vector.h"
#include "Matrix4.h"

class Camera {
public:
	int width;
	int height;
	float fov;
	float scale;
	float aspectRatio;
	Vector origin;
	Matrix4 camToWorld;
	//Matrix4 worldToCam;

	Camera(int w, int h, float f, float angle, Vector location);
	float worldX(float x);
	float worldY(float y);
	Vector getRayVec(int, int);

};