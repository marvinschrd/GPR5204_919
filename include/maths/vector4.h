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
	 *  \brief Class used to represent a 4D vector.
	 */
	struct Vector4f
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			float coord[4]{};
		};

		Vector4f() : x(0), y(0), z(0), w(0) {};

		Vector4f(float x, float y, float z, float w);

		Vector4f operator+(const Vector4f rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; }

		void operator+=(Vector4f rhs);

		Vector4f operator-(const Vector4f rhs) const { return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w }; }

		void operator-=(Vector4f rhs);

		Vector4f operator*(const float scalar) const { return { x * scalar, y * scalar, z * scalar, w * scalar }; }

		void operator*=(float scalar);

		Vector4f operator/(const float scalar) const { return { x / scalar, y / scalar, z / scalar, w / scalar }; }

		void operator/=(float scalar);

		float Dot(const Vector4f v2) const { return { x * v2.x + y * v2.y + z * v2.z + w * v2.w }; }

		static float Dot(const Vector4f v1, const Vector4f v2) { return { v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w }; }

		float Magnitude() const { return std::sqrt(x * x + y * y + z * z + w * w); }

		float SqrMagnitude() const { return { x * x + y * y + z * z + w * w }; }

		const float& operator[](size_t component) const { return coord[component]; }

		float& operator[](size_t component) { return coord[component]; }
	};
}
