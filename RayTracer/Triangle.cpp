#include "Triangle.h"
constexpr float kEpsilon = 1e-8;

Triangle::Triangle(Vector p1, Vector p2, Vector p3, Vector co, bool r, float d, float a, float s)
	: Object(co, r, d, a, s)
{
	t1 = p1;
	t2 = p2;
	t3 = p3;
	normal = computeNormal(p1, p2, p3);
	normal.normalize();
}

bool Triangle::isHit(Vector & rayVector, Vector & rayOrigin)
{
	float check = rayVector.dotProduct(normal);

	if (fabs(check) <kEpsilon) return false;
	
	float dist = normal.dotProduct(t1);
	float t = (normal.dotProduct(rayOrigin) + dist)/ check;

	if (t < 0) return false;
	Vector hitPoint = rayOrigin + (rayVector * t);
	return (inTriangle(hitPoint));
}

Vector Triangle::intersectPoints(const Vector & rayVector, const Vector & rayOrigin)
{

	float check = rayVector.dotProduct(normal);

	float dist = normal.dotProduct(t1);
	float t = (normal.dotProduct(rayOrigin) + dist) / check;
	
	Vector hitPoint = rayOrigin + (rayVector * t);

	return hitPoint;
}

Vector Triangle::normalPoint(Vector hitPoint)
{
	return normal;
}

bool Triangle::inTriangle(Vector point)
{
	//vectors
	Vector v0 = t2 - t1;
	Vector v1 = t3 - t1;
	Vector v2 = point - t1;

	float d00, d01, d02, d11, d12;
	d00 = v0.dotProduct(v0);
	d01 = v0.dotProduct(v1);
	d02 = v0.dotProduct(v2);
	d11 = v1.dotProduct(v1);
	d12 = v1.dotProduct(v2);

	float invDenom = 1 / (d00 * d11 - d01 * d01);
	float u = (d11 *d02 - d01 *d12) * invDenom;
	float v = (d00 *d12 - d01 *d02) * invDenom;
	return ((u >= 0) && (v >= 0) && (u + v < 1));
}

Vector Triangle::computeNormal(Vector &p1, Vector &p2, Vector &p3) {
	
	Vector v = p1 - p2;
	Vector w = p3 - p1;
	
	return v.cross(w);
}
