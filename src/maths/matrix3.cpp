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

namespace maths
{
	Mat33f Mat33f::operator+(const Mat33f& rhs) const
	{
		return Mat33f();
	}
	void Mat33f::operator+=(const Mat33f& rhs)
	{
	}
	Mat33f Mat33f::operator-(const Mat33f& rhs) const
	{
		return Mat33f();
	}
	void Mat33f::operator-=(const Mat33f& rhs)
	{
	}
	Mat33f Mat33f::operator*(const Mat33f& rhs) const
	{
		return Mat33f();
	}
	void Mat33f::operator*=(const Mat33f& rhs)
	{
	}
	Vec3f Mat33f::operator*(const Vec3f& rhs) const
	{
		return Vec3f();
	}
	void Mat33f::operator*=(const Vec3f& rhs)
	{
	}
	float Mat33f::Determinant()
	{
		return 0.0f;
	}
	Mat33f Mat33f::Inverse()
	{
		return Mat33f();
	}
	Mat33f Mat33f::Transpose()
	{
		return Mat33f();
	}
	Mat33f Mat33f::Adjoint()
	{
		return Mat33f();
	}
	bool Mat33f::IsOrthogonal()
	{
		return false;
	}
	Mat33f Mat33f::Identity33()
	{
		return Mat33f();
	}
	Mat33f Mat33f::RotationMatrix33(radian_t angle)
	{
		return Mat33f();
	}
	Mat33f Mat33f::ScalingMatrix33(Vec2f axisValues)
	{
		return Mat33f();
	}
	Mat33f Mat33f::TranslationMatrix33(Vec2f axisValues)
	{
		return Mat33f();
	}
}