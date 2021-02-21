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

#include <corecrt_math_defines.h>
#include "maths/vector2.h"

namespace maths
{
    Vector2f::Vector2f(float x, float y) : x(x), y(y) {}
	
    Vector2f Vector2f::operator+=(const Vector2f rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return Vector2f{x, y};
    }

    Vector2f Vector2f::operator-=(const Vector2f rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return Vector2f{x, y};
    }

    Vector2f Vector2f::operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return Vector2f{x, y};
    }

    Vector2f Vector2f::operator/=(const float scalar)
    {
        x /= scalar;
        y /= scalar;
        return Vector2f{x, y};
    }

    Vector3f Vector2f::Cross(Vector2f vec2) const
    {
        Vector3f v1 = Vector3f(x, y, 0);
        Vector3f v2 = Vector3f(vec2.x, vec2.y, 0);
        return Vector3f(0, 0, v1.x * v2.y - v1.y * v2.x);
    }

    Vector3f Vector2f::Cross(Vector2f vec1, Vector2f vec2)
    {
        Vector3f v1 = Vector3f(vec1.x, vec1.y, 0);
        Vector3f v2 = Vector3f(vec2.x, vec2.y, 0);
        return Vector3f(0, 0, v1.x * v2.y - v1.y * v2.x);
    }

    radian_t Vector2f::AngleBetween(const Vector2f v2) const
    {
        float dot = Dot(v2);
        float thisMagnitude = this->Magnitude();
        float otherMagnitude = v2.Magnitude();
        radian_t angle = maths::acos(dot / (thisMagnitude * otherMagnitude));
        return angle;
    }

    radian_t Vector2f::AngleBetween(const Vector2f v1, const Vector2f v2)
    {
        float dot = Dot(v1, v2);
        float v1Magnitude = v1.Magnitude();
        float v2Magnitude = v2.Magnitude();
        radian_t angle = maths::acos(dot / (v1Magnitude * v2Magnitude));
        return angle;
    }

    Vector2f Vector2f::Normalized() const
    {
        const float magnitude = Vector2f::Magnitude();
        return { x / magnitude, y / magnitude};
    }

    void Vector2f::Normalize()
    {
        const float magnitude = Vector2f::Magnitude();
        x /= magnitude;
        y /= magnitude;
    }

    Vector2f Vector2f::Slerp(Vector2f v2, const float t) const
    {
        const float magnitude_v1 = Magnitude();
        const float magnitude_v2 = v2.Magnitude();
        const Vector2f v1 = *this / magnitude_v1;
        v2 /= magnitude_v2;
        float dot = Dot(v1, v2);
        //Makes sure dot value cannot be under -1
        dot = fmax(dot, -1.0f);
        //Makes sure dot value cannot be over 1
        dot = fmin(dot, 1.0f);

        const radian_t theta = maths::acos(dot) * t;
        const Vector2f relative_vec = (v2 - v1 * dot).Normalized();
        const Vector2f new_vec = v1 * maths::cos(theta) + relative_vec * maths::sin(theta);
        return new_vec * (magnitude_v1 + (magnitude_v2 - magnitude_v1) * t);
    }
}
