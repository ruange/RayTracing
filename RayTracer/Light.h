#pragma once
#include "Vector.h"
#include "Object.h"


class Light {
public:
	Vector position;
	Vector color;
	Light(Vector p, Vector c) : position(p), color(c) {}//float t, float d, float a, float s);

	bool isHit(Vector & rayVector, Vector& rayOrigin);
	Vector intersectPoints(const Vector &rayVector, const Vector &rayOrigin);
	Vector normalPoint(Vector hitPoint);
};