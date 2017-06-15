#pragma once

#include "Vector.h"
#include "Matrix4.h"
#include <math.h>
#include <algorithm>


class Object {
		
	public:
		Vector color;
		bool reflective;
		float diffuse;
		float ambient;
		float specular;

		Matrix4 transform;
		Matrix4 inverse;
		Matrix4 transpose;
		Object(Vector co, bool ref, float d, float a, float s);

		virtual bool isHit(Vector & rayVector, Vector& rayOrigin) = 0;
		virtual Vector intersectPoints(const Vector &rayVec, const Vector &rayOrigin) = 0;
		virtual Vector normalPoint(Vector hitPoint) = 0;

};