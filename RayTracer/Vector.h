#pragma once

#include <math.h>
class Vector {
public:
	float x, y, z;
	Vector(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
	Vector() : x(0), y(0), z(0) {}
	Vector& normalize();
	Vector cross(const Vector& v1);
	float dotProduct(const Vector& v)const;
	float magnitude ();
	float Distance(Vector & b);
	Vector operator * (const float &f) const { return Vector(x*f, y*f, z*f); }
	Vector operator * (const Vector &v) const { return Vector(x*v.x, y*v.y, z*v.z); }
	Vector operator / (const float &f) const { return Vector(x / f, y / f, z / f); }
	Vector operator - (const Vector &v) const { return Vector(x - v.x, y - v.y, z - v.z); }
	Vector operator + (const Vector &v) const { return Vector(x + v.x, y + v.y, z + v.z); }

};

