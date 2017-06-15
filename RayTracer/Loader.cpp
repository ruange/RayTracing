#include "Loader.h"

Loader::Loader(const char* filename, vector<Object*>& objectList, vector<Light*>& lightList)
{
	pugi::xml_document doc;

	if (!doc.load_file(filename)) {
		std::cout << "Error loading xml file" << std::endl;
		exit(0);
	}

	pugi::xml_node scene = doc.child("scene");

	pugi::xml_node resolution = scene.child("resolution");
	this->width = resolution.attribute("width").as_int();
	this->height = resolution.attribute("height").as_int();

	pugi::xml_node camera = scene.child("camera");
	pugi::xml_node specs = camera.child("specs");
	this->fov = specs.attribute("fov").as_int();

	pugi::xml_node lights = scene.child("lights");
	//Load light list
	float r, g, b, x, y, z, nx, ny, nz;

	for (pugi::xml_node light = lights.first_child(); light; light = light.next_sibling()) {
		pugi::xml_node lightPosition = light.child("position");
		x = lightPosition.attribute("x").as_float();
		y = lightPosition.attribute("y").as_float();
		z = lightPosition.attribute("z").as_float();


		pugi::xml_node lightColor = light.child("color");
		r = lightColor.attribute("r").as_float();
		g = lightColor.attribute("g").as_float();
		b = lightColor.attribute("b").as_float();

		lightList.push_back(new Light(Vector(x, y, z), Vector(r, g, b)));
	}

	pugi::xml_node objects = scene.child("objects");
	pugi::xml_node planes = objects.child("planes");
	pugi::xml_node spheres = objects.child("spheres");
	pugi::xml_node triangles = objects.child("triangles");

	float ref, diff, ambi, spec;
	//Load Planes
	for (pugi::xml_node_iterator it = planes.begin(); it != planes.end(); ++it) {

		
		pugi::xml_node planePoint = it->child("point");
		x = planePoint.attribute("x").as_float();
		y = planePoint.attribute("y").as_float();
		z = planePoint.attribute("z").as_float();

		pugi::xml_node planeNormal = it->child("normal");
		nx = planeNormal.attribute("x").as_float();
		ny = planeNormal.attribute("y").as_float();
		nz = planeNormal.attribute("z").as_float();

		pugi::xml_node planeColor = it->child("color");
		r = planeColor.attribute("r").as_float();
		g = planeColor.attribute("g").as_float();
		b = planeColor.attribute("b").as_float();

		pugi::xml_node planeSpecs = it->child("specs");
		ref = planeSpecs.attribute("ref").as_float();
		diff = planeSpecs.attribute("diff").as_float();
		ambi = planeSpecs.attribute("ambi").as_float();
		spec = planeSpecs.attribute("spec").as_float();
		
		objectList.push_back(new Plane(Vector(x, y, z), Vector(nx, ny, nz), Vector(r, g, b), ref, diff, ambi, spec));
	}


	for (pugi::xml_node_iterator it = spheres.begin(); it != spheres.end(); ++it) {
		float radius = it->first_attribute().as_float();

		pugi::xml_node sphereCenter = it->child("center");
		x = sphereCenter.attribute("x").as_float();
		y = sphereCenter.attribute("y").as_float();
		z = sphereCenter.attribute("z").as_float();

		pugi::xml_node sphereColor = it->child("color");
		r = sphereColor.attribute("r").as_float();
		g = sphereColor.attribute("g").as_float();
		b = sphereColor.attribute("b").as_float();
		
		pugi::xml_node sphereSpecs = it->child("specs");
		ref = sphereSpecs.attribute("ref").as_float();
		diff = sphereSpecs.attribute("diff").as_float();
		ambi = sphereSpecs.attribute("ambi").as_float();
		spec = sphereSpecs.attribute("spec").as_float();
	
		objectList.push_back(new Sphere(Vector(x, y, z), radius, Vector(r, g, b), ref, diff, ambi, spec));
	}

	for (pugi::xml_node_iterator it = triangles.begin(); it != triangles.end(); ++it) {

		pugi::xml_node pointA = it->child("point");
		x = pointA.attribute("x").as_float();
		y = pointA.attribute("y").as_float();
		z = pointA.attribute("z").as_float();
		Vector A(x, y, z);

		pugi::xml_node pointB = pointA.next_sibling();
		x = pointB.attribute("x").as_float();
		y = pointB.attribute("y").as_float();
		z = pointB.attribute("z").as_float();
		Vector B(x, y, z);

		pugi::xml_node pointC = pointB.next_sibling();
		x = pointC.attribute("x").as_float();
		y = pointC.attribute("y").as_float();
		z = pointC.attribute("z").as_float();
		Vector C(x, y, z);

		pugi::xml_node colorTriangle = it->child("color");
		r = colorTriangle.attribute("r").as_float();
		g = colorTriangle.attribute("g").as_float();
		b = colorTriangle.attribute("b").as_float();

		pugi::xml_node triangleSpecs = it->child("specs");
		ref = triangleSpecs.attribute("ref").as_float();
		diff = triangleSpecs.attribute("diff").as_float();
		ambi = triangleSpecs.attribute("ambi").as_float();
		spec = triangleSpecs.attribute("spec").as_float();

		objectList.push_back(new Triangle(A, B, C, Vector(r, g, b), ref, diff, ambi, spec));


	}


}
