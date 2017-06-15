#pragma once
#include "Vector.h"
#include "Object.h"
#include <vector>

class Ray {
public:
	Vector origin;
	Vector vector;
	Ray() {}
	Ray(const Vector& o, const Vector& v) : origin(o), vector(v) {}
	Vector pointAtParameter(float t) const { return origin + vector*t; }	
};