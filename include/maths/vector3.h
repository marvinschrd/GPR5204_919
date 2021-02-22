#pragma once

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


#include <cmath>
#include <maths/angle.h>

namespace maths
{
	/**
	 *  \brief Class used to represent a 3D vector.
	 */
	struct Vector3f
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float coord[3]{};
		};

		Vector3f() : x(0), y(0), z(0){};

		Vector3f(float x, float y, float z);

		Vector3f operator+(const Vector3f rhs) const { return {x + rhs.x, y + rhs.y, z + rhs.z}; }

		void operator+=(Vector3f rhs);

		Vector3f operator-(const Vector3f rhs) const { return {x - rhs.x, y - rhs.y, z - rhs.z}; }

		void operator-=(Vector3f rhs);

		Vector3f operator*(const float scalar) const { return {x * scalar, y * scalar, z * scalar}; }

		void operator*=(float scalar);

		Vector3f operator/(const float scalar) const { return {x / scalar, y / scalar, z / scalar}; }

		void operator/=(float scalar);

		float Dot(const Vector3f v2) const { return x * v2.x + y * v2.y + z * v2.z; }

		static float Dot(const Vector3f v1, const Vector3f v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

		/*Vector3f Cross(const Vector3f v2) const { return { y * v2.z - z * v2.y, z * v2.x - x * v2.z, x * v2.y - y * v2.x }; }

		static Vector3f Cross(const Vector3f v1, const Vector3f v2) { return { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x }; }*/

		float Magnitude() const { return std::sqrt(x * x + y * y + z * z); }

		float SqrMagnitude() const { return x * x + y * y + z * z; }

		radian_t AngleBetween(const Vector3f v2) const;

		static radian_t AngleBetween(const Vector3f v1, const Vector3f v2);

		const float& operator[](size_t component) const { return coord[component]; }

		float& operator[](size_t component) { return coord[component]; }

		Vector3f Normalized() const;

		void Normalize();

		Vector3f Lerp(const Vector3f v2, const float t) const { return *this + (v2 - *this) * t;}

		static Vector3f Lerp(const Vector3f v1, const Vector3f v2, const float t) { return  v1 + (v2 - v1) * t; }

		Vector3f Slerp(Vector3f v2, const float t) const;
	};
}
