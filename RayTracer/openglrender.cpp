//opengl render result
//注释RayTracer.cpp中的main，运行此处的main

#include<stdio.h>
#include <glut.h>
#include "Vector.h"
#include<Windows.h>

void InitGL(int Width, int Height)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void ReSizeGLScene(int Width, int Height)
{
	if (Height == 0)
		Height = 1;
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void DrawCenterSphere(double radius) {
	
	glutSolidSphere(radius, 100, 100);

	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 0, 0, 0, 1.0f };
	GLfloat material_Ks[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);
}

void DrawLeftSphere(double radius) {

	glutSolidSphere(radius, 100, 100);

	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 0.5, 0.2, 0.8, 1.0f };
	GLfloat material_Ks[] = { 0.8, 0.8f, 0.8, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);
}

void DrawRightSphere(double radius) {

	glutSolidSphere(radius, 100, 100);

	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 0.5, 0.2, 0.8, 1.0f };
	GLfloat material_Ks[] = { 0.8, 0.8f, 0.8, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);
}

void DrawFrontPlane() {
	
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0);

	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 0.7, 0.7, 0.7, 1.0f };
	GLfloat material_Ks[] = { 0, 0, 0, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);

	glVertex3f(15.0, -10.0, 0);
	glVertex3f(15.0, 10, 0);
	glVertex3f(-15, 10, 0);
	glVertex3f(-15, -10.0, 0);
	glEnd();
}

void DrawRightPlane() {

	glBegin(GL_POLYGON);
	glNormal3f(-1.0, 0.0, 0.0);

	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 0.0f, 0.0f, 1, 1.0f };
	GLfloat material_Ks[] = { 0, 0, 0, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);

	glVertex3f(0, 10, -30);
	glVertex3f(0, -10, -30);
	glVertex3f(0, -10, 30);
	glVertex3f(0, 10, 30);
	glEnd();
}

void DrawLeftPlane() {

	glBegin(GL_POLYGON);
	glNormal3f(1.0, 0.0, 0.0);

	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 1, 0.0f, 0.0f, 1.0f };
	GLfloat material_Ks[] = { 0, 0, 0, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);

	glVertex3f(0, -10, -30);
	glVertex3f(0, 10, -30);
	glVertex3f(0, 10, 30);
	glVertex3f(0, -10, 30);
	glEnd();
}

void DrawUpPlane() {

	glBegin(GL_POLYGON);
	glNormal3f(0.0, -1.0, 0.0);

	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 1, 1, 1, 1.0f };
	GLfloat material_Ks[] = { 0, 0, 0, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);

	glVertex3f(15.0, 0, -30);
	glVertex3f(-15.0, 0, -30);
	glVertex3f(-15, 0, 30);
	glVertex3f(15, 0, 30);
	glEnd();
}

void DrawDownPlane() {

	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	GLfloat material_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat material_Kd[] = { 0.75, 0.75, 0.75, 1.0f };
	GLfloat material_Ks[] = { 0, 0, 0, 1.0f };
	GLfloat material_Se = 32.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);

	glVertex3f(15.0, 0, -30);
	glVertex3f(-15.0, 0, -30);
	glVertex3f(-15, 0, 30);
	glVertex3f(15, 0, 30);
	glEnd();
}

void DrawTriangle() {

	glBegin(GL_TRIANGLES);

	GLfloat material_Ka[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat material_Kd[] = { 0.94, 0.75, 0.31, 1.0f };
	GLfloat material_Ks[] = { 0.2, 0.2f, 0.2f, 1.0f };
	GLfloat material_Se = 30.0f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);

	glNormal3f(2, 1, 2);
	glVertex3f(2.0, 0, -25.0);
	glVertex3f(7, -10, -25);
	glVertex3f(2, -10, -20);

	glNormal3f(-2, 1, 2);
	glVertex3f(2.0, 0, -25.0);
	glVertex3f(2, -10, -20);
	glVertex3f(-3, -10, -25);

	glNormal3f(0,0,1);
	glVertex3f(2.0, 0, -25.0);
	glVertex3f(-3, -10, -25);
	glVertex3f(7, -10, -25);
	glEnd();
}

void DemoLight() {

	GLfloat light_pos[] = { 0, 9, -25, 1.0f };
	GLfloat light_Ka[] = { 0, 0, 0, 1.0f };
	GLfloat light_Kd[] = { 0.65, 0.65, 0.65, 1.0f };
	GLfloat light_Ks[] = { 0.7, 0.7, 0.7, 1.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ka);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Kd);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_Ks);

	GLfloat light_pos1[] = { 0,9,-15,1.0f };

	glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_Ka);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_Kd);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_Ks);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
}
void DrawGLScene() //The main drawing function. 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	DrawTriangle();
	glTranslatef(0.0, 0.0, -30.0);
	DrawFrontPlane();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.0, 0.0, 0.0);
	DrawRightPlane();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0, 0.0, 0.0);
	DrawLeftPlane();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 10.0, 0.0);
	DrawUpPlane();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0,-10.0, 0.0);
	DrawDownPlane();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -8.0, -15);
	DrawLeftSphere(2);
	glTranslatef(-8.0, 0.0, -5);
	DrawRightSphere(2);
	glTranslatef(16, 0, 0);
	DrawLeftSphere(2);
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(-8.0, -8.0, -20);
	DrawLeftSphere(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, -8.0, -20);
	DrawRightSphere(2);
	glPopMatrix();*/

	DemoLight();

	glutSwapBuffers();
}

//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
//	glutInitWindowSize(960, 640);
//	glutCreateWindow("opengl render");
//	glutDisplayFunc(&DrawGLScene);
//	//glutIdleFunc(&DrawGLScene);
//	InitGL(960, 640);
//	glutReshapeFunc(&ReSizeGLScene);
//	glutMainLoop();
//	return 1;
//}