#pragma once
#include "Object.h"


class Sphere :public Object {
	public:
		float radius;
		Vector center;
		Sphere(Vector c, float r, Vector co, bool ref, float d, float a, float s /*Matrix4 x*/);
	
		
		bool isHit(Vector &rayVector, Vector &rayOrigin);
		Vector intersectPoints(const Vector &rayVector, const Vector &rayOrigin);
		Vector normalPoint(Vector hitPoint);
		
	private:
		double calcB(const Vector &rayVector, const Vector &rayOrigin);
		double calcC(const Vector &rayVector, const Vector &rayOrigin);
		double discriminant(double A, double B, double C);

};