#pragma once

#include "Camera.h"
#include "Vector.h"
#include "Object.h"
#include "Light.h"
#include "Plane.h"
#include "Sphere.h"
#include "Triangle.h"
#include "libs/pugixml.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Loader {
public:

	Loader(const char*, vector<Object*>&, vector<Light*>&);
	int height;
	int width;
	int fov;
};

