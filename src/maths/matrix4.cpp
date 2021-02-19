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

#include "maths/matrix4.h"

namespace maths
{
	Mat44f Mat44f::operator+(const Mat44f& rhs) const
	{
		return Mat44f();
	}
	void Mat44f::operator+=(const Mat44f& rhs)
	{
	}
	Mat44f Mat44f::operator-(const Mat44f& rhs) const
	{
		return Mat44f();
	}
	void Mat44f::operator-=(const Mat44f& rhs)
	{
	}
	Mat44f Mat44f::operator*(const Mat44f& rhs) const
	{
		return Mat44f();
	}
	void Mat44f::operator*=(const Mat44f& rhs)
	{
	}
	Vector4f Mat44f::operator*(const Vector4f& rhs) const
	{
		return Vector4f();
	}
	void Mat44f::operator*=(const Vector4f& rhs)
	{
	}
	float Mat44f::Determinant()
	{
		return 0.0f;
	}
	Mat44f Mat44f::Inverse()
	{
		return Mat44f();
	}
	Mat44f Mat44f::Transpose()
	{
		return Mat44f();
	}
	Mat44f Mat44f::Adjoint()
	{
		return Mat44f();
	}
	bool Mat44f::IsOrthogonal()
	{
		return false;
	}
	Mat44f Mat44f::Identity44()
	{
		return Mat44f();
	}
	Mat44f Mat44f::RotationMatrix44(radian_t angle, char axis)
	{
		return Mat44f();
	}
	Mat44f Mat44f::ScalingMatrix44(Vector3f axisValues)
	{
		return Mat44f();
	}
	Mat44f Mat44f::TranslationMatrix44(Vector3f axisValues)
	{
		return Mat44f();
	}
}