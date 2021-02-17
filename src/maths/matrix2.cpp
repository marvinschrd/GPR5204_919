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
		return Mat22f();
	}
	void Mat22f::operator+=(const Mat22f& rhs)
	{
	}
	Mat22f Mat22f::operator-(const Mat22f& rhs) const
	{
		return Mat22f();
	}
	void Mat22f::operator-=(const Mat22f& rhs)
	{
	}
	Mat22f Mat22f::operator*(const Mat22f& rhs) const
	{
		return Mat22f();
	}
	void Mat22f::operator*=(const Mat22f& rhs)
	{
	}
	Vec2f Mat22f::operator*(const Vec2f& rhs) const
	{
		return Vec2f();
	}
	void Mat22f::operator*=(const Vec2f& rhs)
	{
	}
	float Mat22f::Determinant()
	{
		return 0.0f;
	}
	Mat22f Mat22f::Inverse()
	{
		return Mat22f();
	}
	Mat22f Mat22f::Transpose()
	{
		return Mat22f();
	}
	Mat22f Mat22f::Identity22()
	{
		return Mat22f();
	}
}
