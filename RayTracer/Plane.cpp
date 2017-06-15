#include "Plane.h"

Plane::Plane(Vector p, Vector n, Vector co, bool r, float d, float a, float s) :
	Object(co, r, d, a, s)
{
	point = p;
	normal = n.normalize();
	D = fabsf(n.x *(-p.x) + n.y*(-p.y) + n.z*(p.z));
}

bool Plane::isHit(Vector & rayVector, Vector & rayOrigin)
{
	float check = rayVector.dotProduct(normal);
	if (check >= 0) return false;
	else {
		float t = -1 * ((normal.dotProduct(rayOrigin) + D) / check);
		if (t < 0) return false;
	}
	return true;
}

Vector Plane::intersectPoints(const Vector & rayVector, const Vector & rayOrigin)
{
	float check = rayVector.dotProduct(normal);
	float t = -1 * ((normal.dotProduct(rayOrigin) + D) / check);
	Vector hitPoint = (rayVector * t) + rayOrigin;
	return hitPoint;
}

Vector Plane::normalPoint(Vector hitPoint)
{
	return normal;
}
