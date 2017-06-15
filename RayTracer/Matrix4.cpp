#include "Matrix4.h"

Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			i == j ? matrix[i][j] = 1 : matrix[i][j] = 0;
		}
	}
}

Vector Matrix4::matmul(Vector &v)
{	
	float x, y, z, w;
	x = v.x * matrix[0][0] + v.y * matrix[1][0] + v.z * matrix[2][0] + matrix[3][0];
	y = v.x * matrix[0][1] + v.y * matrix[1][1] + v.z * matrix[2][1] + matrix[3][1];
	z = v.x * matrix[0][2] + v.y * matrix[1][2] + v.z * matrix[2][2] + matrix[3][2];
	w = v.x * matrix[0][3] + v.y * matrix[1][3] + v.z * matrix[2][3] + matrix[3][3];
	Vector result(x / w, y / w, z / w);
	return result;
}

void Matrix4::rotate(int axis, float angle)
{

	switch (axis)
	{
	case 0: //x -axis
		matrix[1][1] = cos(angle);
		matrix[2][2] = matrix[1][1];
		matrix[1][2] = -1 * sin(angle);
		matrix[2][1] = -1 * matrix[1][2];
		break;
	case 1://y-axis
		matrix[0][0] = cos(angle);
		matrix[2][2] = matrix[0][0];
		matrix[0][2] = sin(angle);
		matrix[2][0] = -1 * matrix[0][2];
	case 2://z-axis
		matrix[0][0] = cos(angle);
		matrix[1][1] = matrix[0][0];
		matrix[0][1] = -1 * sin(angle);
		matrix[1][0] = -1 * matrix[0][1];
		break;
	default:
		break;
	}
}

void Matrix4::translate(Vector& direction) 
{
	
	matrix[0][3] = direction.x;
	matrix[1][3] = direction.y;
	matrix[2][3] = direction.z;
	matrix[3][3] = 1;
}

static void multiply(const Matrix4& a, const Matrix4& b, Matrix4&c) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c.matrix[i][j] = a.matrix[i][0] * b.matrix[0][j] + a.matrix[i][1] * b.matrix[1][j] +
				a.matrix[i][2] * b.matrix[2][j] + a.matrix[i][3] * b.matrix[3][j];
		}
	}
}

Matrix4 Matrix4::operator*(const Matrix4 & mat) const
{
	Matrix4 temp;
	multiply(*this, mat, temp);
	return temp;
}
