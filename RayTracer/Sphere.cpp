#include "Sphere.h"

Sphere::Sphere(Vector c, float r, Vector co, bool ref, float d, float a, float s /*, Matrix4 x*/)
	:Object(co, ref, d, a, s)
{
	//this->transform = x;
	this->center = c;
	this->radius = r;
	
}

bool Sphere::isHit(Vector & rayVector, Vector & rayOrigin )
{
	float t0, t1;
	Vector line = center - rayOrigin;
	float tca = line.dotProduct(rayVector);
	float d2 = line.dotProduct(line) - tca * tca;
	if (d2 > radius*radius) return false;
	float thc = sqrt(radius*radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t0 > t1) std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1; // if t0 is negative, let's use t1 instead 
		if (t0 < 0) return false; // both t0 and t1 are negative 
	}
	else return true;

}



Vector Sphere::intersectPoints(const Vector & rayVector, const Vector & rayOrigin)
{
	float t0, t1;
	Vector line = center - rayOrigin;
	float tca = line.dotProduct(rayVector);
	float d2 = line.dotProduct(line) - tca * tca;
	float thc = sqrt(radius*radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t0 > t1) std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1; // if t0 is negative, let's use t1 instead 

	}

	Vector point = rayOrigin + (rayVector * t0);
	return point;
}

Vector Sphere::normalPoint(Vector hitPoint)
{	
	return ((hitPoint - center)/radius).normalize();
}

double Sphere::calcB(const Vector & rayVector, const Vector & rayOrigin)
{
	Vector check = rayOrigin - center;
	check = check * rayVector;
	double B = (2 * (check.x + check.y + check.z));
	return B;
}

double Sphere::calcC(const Vector & rayVector, const Vector & rayOrigin)
{
	Vector temp = rayOrigin - center;
	temp = temp*temp;
	double C = (temp.x + temp.y + temp.z - (radius * radius));
	return C;
}

double Sphere::discriminant(double A, double B, double C)
{
	return (B*B) - (4 * A* C);
}
