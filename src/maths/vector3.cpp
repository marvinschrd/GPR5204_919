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

#include <maths/vector3.h>
#include <maths/angle.h>
#include <cmath>

namespace maths
{
	Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z)
	{
	}

	void Vector3f::operator+=(const Vector3f rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	void Vector3f::operator-=(const Vector3f rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	void Vector3f::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	void Vector3f::operator/=(const float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}

	radian_t Vector3f::AngleBetween(const Vector3f v2) const
	{
		float dot = Dot(v2);
		float magnitude = Magnitude();
		float otherMagnitude = v2.Magnitude();
		return { maths::acos(dot / (otherMagnitude * magnitude)) };
	}

	radian_t Vector3f::AngleBetween(const Vector3f v1, const Vector3f v2)
	{
		float dot = Dot(v1, v2);
		float otherMagnitude1 = v1.Magnitude();
		float otherMagnitude2 = v2.Magnitude();
		return { maths::acos(dot / (otherMagnitude1 * otherMagnitude2)) };
	}

	Vector3f Vector3f::Normalized() const
	{
		const float magnitude = Vector3f::Magnitude();
		return {x / magnitude, y / magnitude, z / magnitude};
	}

	void Vector3f::Normalize()
	{
		float magnitude = Vector3f::Magnitude();
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	//Vector3f Vector3f::Slerp(const Vector3f v2, const float t) const
	//{
	//	radian_t theta = maths::acos(Vector3f::Dot(*this, v2)) * t;
	//	Vector3f relativeVec = v2 - *this * Vector3f::Dot(*this, v2);
	//	//relativeVec.Normalize()
	//	return *this * maths::cos(theta) + relativeVec * maths::sin(theta);
	//}
}
