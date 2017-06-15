#pragma once
#include "Object.h"

class Plane :public Object {
public:
	Vector point;
	Vector normal;
	float D;
	Plane(Vector p, Vector n, Vector co, bool r, float d, float a, float s);

	bool isHit(Vector &rayVector, Vector &rayOrigin);
	Vector intersectPoints(const Vector &rayVector, const Vector &rayOrigin);
	Vector normalPoint(Vector hitPoint);
};