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

#include "maths/matrix2.h"

namespace maths
{
	Mat22f Mat22f::operator+(const Mat22f& rhs) const
	{
		float m00 = matrix[0][0] + rhs.matrix[0][0];
		float m01 = matrix[0][1] + rhs.matrix[0][1];
		float m10 = matrix[1][0] + rhs.matrix[1][0];
		float m11 = matrix[1][1] + rhs.matrix[1][1];


		return Mat22f(Vector2f(m00,m01),Vector2f(m10,m11));
	}
	void Mat22f::operator+=(const Mat22f& rhs)
	{
		 matrix[0][0] += rhs.matrix[0][0];
		 matrix[0][1] += rhs.matrix[0][1];
		 matrix[1][0] += rhs.matrix[1][0];
		 matrix[1][1] += rhs.matrix[1][1];

	}
	Mat22f Mat22f::operator-(const Mat22f& rhs) const
	{
		float m00 = matrix[0][0] - rhs.matrix[0][0];
		float m01 = matrix[0][1] - rhs.matrix[0][1];
		float m10 = matrix[1][0] - rhs.matrix[1][0];
		float m11 = matrix[1][1] - rhs.matrix[1][1];
		
		return Mat22f(Vector2f(m00, m01), Vector2f(m10, m11));
	}
	void Mat22f::operator-=(const Mat22f& rhs)
	{
		matrix[0][0] -= rhs.matrix[0][0];
		matrix[0][1] -= rhs.matrix[0][1];
		matrix[1][0] -= rhs.matrix[1][0];
		matrix[1][1] -= rhs.matrix[1][1];
	}
	Mat22f Mat22f::operator*(const Mat22f& rhs) const
	{
		float m00 = (matrix[0][0] * rhs.matrix[0][0]) + (matrix[0][1] * rhs.matrix[1][0]);
		float m01 = (matrix[0][0] * rhs.matrix[0][1]) + (matrix[0][1] * rhs.matrix[1][1]);
		float m10 = (matrix[1][0] * rhs.matrix[0][0]) + (matrix[1][1] * rhs.matrix[1][0]);
		float m11 = (matrix[1][0] * rhs.matrix[0][1]) + (matrix[1][1] * rhs.matrix[1][1]);

		
		return Mat22f(Vector2f(m00, m01), Vector2f(m10, m11));
	}
	void Mat22f::operator*=(const Mat22f& rhs)
	{
		 matrix[0][0] = (matrix[0][0] * rhs.matrix[0][0]) + (matrix[0][1] * rhs.matrix[1][0]);
		 matrix[0][1] = (matrix[0][0] * rhs.matrix[0][1]) + (matrix[0][1] * rhs.matrix[1][1]);
		 matrix[1][0] = (matrix[1][0] * rhs.matrix[0][0]) + (matrix[1][1] * rhs.matrix[1][0]);
		 matrix[1][1] = (matrix[1][0] * rhs.matrix[0][1]) + (matrix[1][1] * rhs.matrix[1][1]);

	}
	void Mat22f::operator*=(const float& scalar)
	{
		matrix[0][0] *= scalar;
		matrix[0][1] *= scalar;
		matrix[1][0] *= scalar;
		matrix[1][1] *= scalar;
	}
	Vector2f Mat22f::operator*(const Vector2f& rhs) const
	{
		return Vector2f();
	}
	void Mat22f::operator*=(const Vector2f& rhs)
	{
	}
	float Mat22f::Determinant() const
	{
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	Mat22f Mat22f::Inverse() const
	{
		Mat22f inverse;
		inverse[0][0] = matrix[1][1];
		inverse[0][1] = - matrix[1][0];
		inverse[1][0] = - matrix[0][1];
		inverse[1][1] = matrix[0][0];

		inverse *= 1/Determinant();
		
		return inverse;
	}
	Mat22f Mat22f::Transpose() const
	{
		return Mat22f();
	}
	Mat22f Mat22f::Identity22()
	{
		return Mat22f(Vector2f(1, 0), Vector2f(0, 1));
	}
}
