// RayTracer.cpp : Defines the entry point for the console application.
#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "CImg.h"
#include "Camera.h"
#include "Triangle.h"
#include "Light.h"
#include "Loader.h"
#include <iostream>
#include <vector>

#define INFINITY 1e8 
#define MAX_DEPTH 5

using namespace cimg_library;

std::vector<Object*> objectList;
std::vector<Light*> lightList;

Vector backgroundColor(0, 0, 0);

Vector traceRay(Vector &rayVec, Vector &eye, int rayDepth);
Vector shade(Object* obj, Vector& point, Vector& normal, Vector &rayVec);
Vector getShading( Vector& rayVec, Vector & normal,  Vector& lightVec, Light* light, Object * obj);
bool inShadow(Vector& lightVec, Vector& offsetPoint, float lightDist);

int main()
{
	Loader options("models/model.xml", objectList, lightList);
	int width = options.width;
	int height = options.height;
	float fov = options.fov;
	float angle = 0;

	CImg<float> image(width, height, 1, 3, 1);
	Camera eye(width, height, fov, angle, Vector(0, 0, 0));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			float x = eye.worldX(j);
			float y = eye.worldY(i);
			Vector camVector(x, y, -1);
			Vector rayVector = eye.camToWorld.matmul(camVector);
			rayVector.normalize();
			
			Vector color = traceRay(rayVector, eye.origin, 0);
			
			image(j, i, 0) = color.x;
			image(j, i, 1) = color.y;
			image(j, i, 2) = color.z;
		}
	}
	CImgDisplay main_display(image);
	std::cin.ignore();
	return 0;
}


Vector traceRay(Vector &rayVec, Vector & eye, int rayDepth) {
	float traceClose = INFINITY;
	float tempDist;
	Object *hitObject;
	Vector *tempPoint, hitPoint, hitNormal;
	Vector localColor;
	Vector reflectColor;
	if (rayDepth > MAX_DEPTH) return backgroundColor;
	for (Object* obj : objectList) {
		if (obj->isHit(rayVec, eye)) {
			tempPoint = &obj->intersectPoints(rayVec, eye);
			tempDist = tempPoint->Distance(eye);
			if (tempDist < traceClose) {
				hitObject = obj;
				hitPoint = *tempPoint;
				hitNormal = hitObject->normalPoint(hitPoint);
				traceClose = tempDist;
			}
		}
	}
	if (traceClose < INFINITY) {
		localColor = shade(hitObject, hitPoint, hitNormal, rayVec);
		if (hitObject->reflective > 0) {
			Vector offsetPoint = hitPoint + hitNormal * 1e-3;
			Vector reflectionVector = (rayVec)-hitNormal*(2 * ((hitNormal).dotProduct(rayVec)));
			reflectColor = traceRay(reflectionVector, offsetPoint, ++rayDepth);
			localColor =  localColor + (reflectColor * hitObject->reflective);
		}
		return localColor;
	}
	else return backgroundColor;
}



Vector shade(Object* obj, Vector& point, Vector& normal, Vector &rayVec)
{
	Vector localColor;
	Vector lightVec;
	Vector offsetPoint = point + normal * 1e-3;
	bool visible = false;
	float lightDist;

	
	float tempDot;
	float diff = -INFINITY;
	float spec;
	
	for (Light* light : lightList) {
		lightVec = light->position - offsetPoint;
		lightVec.normalize();
		lightDist = light->position.Distance(offsetPoint);
		/*
		first determine whether there is an unobstructed path from the hit point to
		the light.
		*/
		visible = inShadow(lightVec, offsetPoint, lightDist);

		localColor = localColor + (getShading(rayVec, normal, lightVec, light, obj) * visible);
	}
	return localColor;
	//ambientLight



}

Vector getShading( Vector& rayVec, Vector & normal, Vector& lightVec, Light* light, Object * obj ) {

	Vector color;
	float diff = -INFINITY;
	float diffDot;
	//Specular light
	Vector reflectionVector = (rayVec)-normal*(2 * ((normal).dotProduct(rayVec)));
	float spec = reflectionVector.dotProduct(lightVec);
	//Diffuse light
	diffDot = lightVec.dotProduct((normal));
	diffDot > 0 ? diff = diffDot : diff = 0;
	//bringing it all together
	color = backgroundColor +(light->color*((obj->color * (obj->diffuse * diff)) + (obj->color * (obj->specular * powf(spec, 32))))); //specular f is 5
	return color;
}


bool inShadow(Vector& lightVec, Vector& offsetPoint, float lightDist) {
	Object *interceptObj;
	float interceptDist = INFINITY;
	Vector intersect;

	for (Object * hito : objectList) {
		if (hito->isHit(lightVec, offsetPoint)) {
			Vector tempIntersect = hito->intersectPoints(lightVec, offsetPoint);
			float tempInterceptDist = tempIntersect.Distance(offsetPoint);
			if (tempInterceptDist < interceptDist) {
				interceptDist = tempInterceptDist;
				interceptObj = hito;
				intersect = tempIntersect;
			}
		}
	}
	if (lightDist < interceptDist)
		return true;
	else return false;
}







