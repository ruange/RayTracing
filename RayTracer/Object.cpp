#include "Object.h"

Object::Object(Vector co, bool ref, float d, float a, float s)
{
	this->color = co;
	this->reflective = ref;
	this->diffuse = d;
	this->ambient = a;
	this->specular = s;
}
