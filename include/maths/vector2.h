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

#pragma once

#include "maths/vector3.h"
#include "maths/angle.h"

namespace maths
{
/**
* \brief Class used to represent a 2D vector.
*/
class Vector2f
{
public:

	union
	{
		struct
		{
			float x;
			float y;
		};

		float coord[2]{};
	};

	Vector2f() = default;

	Vector2f(const float x, const float y) : x(x), y(y) {}

	Vector2f operator+(const Vector2f rhs) const
	{
		return Vector2f(x + rhs.x, y + rhs.y);
	}

	Vector2f& operator+=(Vector2f rhs);

	Vector2f operator-(const Vector2f rhs) const
	{
		return Vector2f(x - rhs.x, y - rhs.y);
	}

	Vector2f& operator-=(Vector2f rhs);

	Vector2f operator*(const float scalar) const
	{
		return Vector2f(x * scalar, y * scalar);
	}

	Vector2f& operator*=(float scalar);

	Vector2f operator/(const float scalar) const
	{
		return Vector2f(x / scalar, y / scalar);
	}

	Vector2f& operator/=(float scalar);

	bool operator==(const Vector2f rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator!=(const Vector2f rhs) const
	{
		return x != rhs.x || y != rhs.y;
	}

	const float operator[](const size_t component) const
	{
		return coord[component];
	}

	float& operator[](const size_t component) { return coord[component]; }

	float Magnitude() const { return std::sqrt(x * x + y * y); }

	float SqrMagnitude() const { return x * x + y * y; }

	float Dot(const Vector2f v2) const { return x * v2.x + y * v2.y; }

	static float Dot(const Vector2f v1, const Vector2f v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	Vector3f Cross(Vector2f vec2) const;

	static Vector3f Cross(Vector2f vec1, Vector2f vec2);

	radian_t AngleBetween(Vector2f v2) const;

	static radian_t AngleBetween(Vector2f v1, Vector2f v2);

	Vector2f Normalized() const;

	void Normalize();

	Vector2f Lerp(const Vector2f v2, const float t) const
	{
		return *this + (v2 - *this) * t;
	}

	static Vector2f Lerp(const Vector2f v1, const Vector2f v2,
	                     const float t) { return v1 + (v2 - v1) * t; }

	Vector2f Slerp(Vector2f v2, float t) const;

	Vector2f Rotation(radian_t angle) const;

	static Vector2f Rotation(Vector2f v1, radian_t angle);
};
} // namespace maths
