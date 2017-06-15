#include "Vector.h"

Vector& Vector::normalize() {
	float normal = 1 / magnitude();
	x *= normal; y *= normal; z *= normal;
	return *this;
}

Vector Vector::cross(const Vector &v)
{
	float Nx = (y * v.z) - (z * v.y);
	float Ny = (z * v.x) - (x * v.z);
	float Nz = (x * v.y) - (y * v.x);
	return Vector(Nx, Ny, Nz);
}

float Vector::dotProduct(const Vector & v) const
{
	return (v.x*x + v.y * y + v.z *z);
}


float Vector::magnitude()
{
	float mag = x*x + y*y + z*z;
	if (mag > 0) {
		return sqrtf(mag);
		
	}
	return 0.0f;
}

float Vector::Distance(Vector& b) {
	float dx = x - b.x;
	float dy = y - b.y;
	float dz = z - b.z;
	return sqrtf(dx * dx + dy * dy + dz * dz);
}



