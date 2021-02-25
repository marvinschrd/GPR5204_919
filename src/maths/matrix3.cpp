/*
MIT License
Copyright (c) 2021 SAE Institute Geneva
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "maths/matrix3.h"

#include <cassert>

#include "maths/angle.h"
#include "maths/matrix2.h"

namespace maths
{
Matrix3f::Matrix3f(const Vector3f v1, const Vector3f v2, const Vector3f v3) {
	
	matrix_[0] = v1;
	matrix_[1] = v2;
	matrix_[2] = v3;
}
Matrix3f Matrix3f::operator+(const Matrix3f& rhs) const {
	
	float m00 = matrix_[0][0] + rhs[0][0];
	float m10 = matrix_[1][0] + rhs[1][0];
	float m20 = matrix_[2][0] + rhs[2][0];
	float m01 = matrix_[0][1] + rhs[0][1];
	float m11 = matrix_[1][1] + rhs[1][1];
	float m21 = matrix_[2][1] + rhs[2][1];
	float m02 = matrix_[0][2] + rhs[0][2];
	float m12 = matrix_[1][2] + rhs[1][2];
	float m22 = matrix_[2][2] + rhs[2][2];
	return Matrix3f(Vector3f(m00, m01,m02), Vector3f(m10, m11,m12),Vector3f(m20,m21,m22));
}
Matrix3f& Matrix3f::operator+=(const Matrix3f& rhs) {
	
	float m00 = matrix_[0][0] + rhs[0][0];
	float m10 = matrix_[1][0] + rhs[1][0];
	float m20 = matrix_[2][0] + rhs[2][0];
	float m01 = matrix_[0][1] + rhs[0][1];
	float m11 = matrix_[1][1] + rhs[1][1];
	float m21 = matrix_[2][1] + rhs[2][1];
	float m02 = matrix_[0][2] + rhs[0][2];
	float m12 = matrix_[1][2] + rhs[1][2];
	float m22 = matrix_[2][2] + rhs[2][2];

	return *this;
}
Matrix3f Matrix3f::operator-(const Matrix3f& rhs) const {
	
	float m00 = matrix_[0][0] - rhs[0][0];
	float m10 = matrix_[1][0] - rhs[1][0];
	float m20 = matrix_[2][0] - rhs[2][0];
	float m01 = matrix_[0][1] - rhs[0][1];
	float m11 = matrix_[1][1] - rhs[1][1];
	float m21 = matrix_[2][1] - rhs[2][1];
	float m02 = matrix_[0][2] - rhs[0][2];
	float m12 = matrix_[1][2] - rhs[1][2];
	float m22 = matrix_[2][2] - rhs[2][2];
	return Matrix3f(Vector3f(m00, m01, m02), Vector3f(m10, m11, m12), Vector3f(m20, m21, m22));
}
Matrix3f& Matrix3f::operator-=(const Matrix3f& rhs) {
	
	float m00 = matrix_[0][0] - rhs[0][0];
	float m10 = matrix_[1][0] - rhs[1][0];
	float m20 = matrix_[2][0] - rhs[2][0];
	float m01 = matrix_[0][1] - rhs[0][1];
	float m11 = matrix_[1][1] - rhs[1][1];
	float m21 = matrix_[2][1] - rhs[2][1];
	float m02 = matrix_[0][2] - rhs[0][2];
	float m12 = matrix_[1][2] - rhs[1][2];
	float m22 = matrix_[2][2] - rhs[2][2];

	return *this;
}
Matrix3f Matrix3f::operator*(const Matrix3f& rhs) const {
	
	return Matrix3f();
}
Matrix3f& Matrix3f::operator*=(const Matrix3f& rhs) {
	
	return *this;
}
Vector3f Matrix3f::operator*(const Vector3f& rhs) const {
	
	return Vector3f();
}
Matrix3f& Matrix3f::operator*=(const float& scalar) {
	
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			matrix_[i][j] *= scalar;
		}
	}

	return *this;
}
float Matrix3f::GetCofactor(const int row, const int column) const {
	
	const float sign = (column + row) % 2 == 0 ? 1.0f : -1.0f;
	Matrix2f tmp_mat;
	int k = 0;
	int l = 0;
	
	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			if(i != column && j != row)
			{
				tmp_mat[k][l++] = matrix_[i][j];

				if(l == size_ -1)
				{
					l = 0;
					k++;
				}
			}
		}
	}

	const float tmp_det = tmp_mat.Determinant();
	
	return sign * tmp_det;
}
float Matrix3f::Determinant() const {
	
	const float det = matrix_[0][0] * GetCofactor(0, 0)
					+ matrix_[0][1] * GetCofactor(1, 0)
					+ matrix_[0][2] * GetCofactor(2, 0);
	
	return det;
}
Matrix3f Matrix3f::Inverse() const {
	
	assert(Determinant() != 0.0f);

	if (IsOrthogonal())
	{
		return Transpose();
	}

	Matrix3f tmp_mat = Adjoint();

	tmp_mat *= (1.0f / Determinant());

	return tmp_mat;
}
Matrix3f Matrix3f::Transpose() const {
	
	return Matrix3f(Vector3f(matrix_[0][0], matrix_[1][0], matrix_[2][0]),
					Vector3f(matrix_[0][1], matrix_[1][1], matrix_[2][1]),
					Vector3f(matrix_[0][2], matrix_[1][2], matrix_[2][2]));
}
Matrix3f Matrix3f::Adjoint() const {
	
	Matrix3f tmp_mat;

	for (int i = 0; i < size_; ++i)
	{
		for (int j = 0; j < size_; ++j)
		{
			tmp_mat[i][j] = GetCofactor(j, i);
		}
	}
	
	return tmp_mat.Transpose();
}
bool Matrix3f::IsOrthogonal() const {
	
	return Determinant() == 1.0f;
}
Matrix3f Matrix3f::Identity() {
	
	return Matrix3f(Vector3f(1, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1));
}
Matrix3f Matrix3f::RotationMatrix(radian_t angle) {
	
	return Matrix3f(Vector3f(cos(angle), -sin(angle), 0),
					Vector3f(sin(angle), cos(angle), 0), 
					Vector3f(0, 0, 1));
}
Matrix3f Matrix3f::ScalingMatrix(Vector2f axisValues) {
	
	return Matrix3f(Vector3f(axisValues.x, 0, 0), Vector3f(0, axisValues.y, 0), Vector3f(0, 0, 1));
}
Matrix3f Matrix3f::TranslationMatrix(Vector2f axisValues) {
	
	return Matrix3f(Vector3f(1, 0, axisValues.x), Vector3f(0, 1, axisValues.y), Vector3f(0, 0, 1));
}
	
}//namespace maths
