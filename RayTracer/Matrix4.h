#pragma once
#include "Vector.h"

class Matrix4 {
public:
	float matrix[4][4];
	Matrix4();
	Vector matmul(Vector&);
	void rotate(int axis, float angle);
	void translate(Vector& direction);

	Matrix4 operator * (const Matrix4& mat) const;
};