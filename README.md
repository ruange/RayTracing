# Ray Tracing #
In this assignment,I implemented the Ray-Tracing algorithm in c++.I didn't use any library but the CImg library,only use to read and display pixel values.

## Creating the scene:  ##
The scene is defined in an xml file.The entire scene encompassed by the label:

    <scene>...</scene>

**Lights:**

The lights are defined in label `<lights>...</lights>`.In my code,lights are all point sources and all that need specification is their position and color.

    <light>
			<position x="0" y="9" z="-15.0"/>
			<color r="1.0" g="1.0" b="1.0"/>
	</light>

**Planes:**

We need three elements to define a plane:a point in the plane、the plane's normal vector and its color.Of course,we need to define its material.

    <plane>
				<point x="0.0" y="-10.0" z="0.0"/>
				<normal x="0.0" y="10.0" z="0.0"/>
				<color r="1.0" g="1.0" b="1.0" />
				<specs ref="0" diff="0.8" ambi="0.1" spec="0.2"/>
	</plane>

**Spheres:**

We need there elements to define a sphere:radius、position of the center and its color.The normal can be calculated when we know the intersection of any rays toward the sphere.

    <sphere radius="2.0">
				<center x="-9.0" y="-8.0" z="-20.0"/>
				<color r="0.5" g="0.2" b="0.8" />
				<specs ref="0" diff="0.8" ambi="0.1" spec="0.2"/>
	</sphere>

**Triangles:**

To define a triangle,we just need three points and its color.The normal can be calculated through the crossproduct of two vectors.

    <triangle>
				<point x="2" y="0" z="-25.0"/>
				<point x="7" y="-10" z="-25.0"/>
				<point x="2" y="-10" z="-20.0"/>
				<color r="0.94" g="0.75" b="0.31"/>
				<specs ref="0" diff="0.8" ambi="0.1" spec="0.2"/>
	</triangle>

## Details: ##
First we need to specify the eye position,the for every pixel in the Width*Height screen,emit a ray from the eye through the pixel into the scene.Find the closest intersection and return the intersection、the object and its normal.

traceRay:

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

If the reflectivity is set to 1,calculate the reflection ray and recursion the above process.

When knows the intersection and object as well as its normal,we first need to determine whether the intersection is inside the shadow or not.If the intersection is inside shadow,we simplely return background color(set to (0,0,0)),otherwise we need to calculate the color and highlight at that intersection accroding to the Phong Model.Don't forget,we need to initialize a 3d array to store every pixel RGB values:`CImg<float> image(width, height, 1, 3, 1);`.Finally,just display it:`CImgDisplay main_display(image);`