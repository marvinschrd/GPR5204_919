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

#include "maths/vector2.h"

namespace maths
{
    Vec2f::Vec2f(float x, float y) : x(x), y(y) {}
	
    void Vec2f::operator+=(const Vec2f rhs)
    {
        x += rhs.x;
        y += rhs.y;
    }

    void Vec2f::operator-=(const Vec2f rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
    }

    void Vec2f::operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
    }

    void Vec2f::operator/=(const float scalar)
    {
        x /= scalar;
        y /= scalar;
    }

    Vector3f Vec2f::Cross(Vec2f vec2) const
    {
        Vector3f v1 = Vector3f(x, y, 0);
        Vector3f v2 = Vector3f(vec2.x, vec2.y, 0);
        return Vector3f(0, 0, v1.x * v2.y - v1.y * v2.x);
    }

    Vector3f Vec2f::Cross(Vec2f vec1, Vec2f vec2)
    {
        Vector3f v1 = Vector3f(vec1.x, vec1.y, 0);
        Vector3f v2 = Vector3f(vec2.x, vec2.y, 0);
        return Vector3f(0, 0, v1.x * v2.y - v1.y * v2.x);
    }

    radian_t Vec2f::AngleBetween(const Vec2f v2) const
    {
        float dot = Dot(v2);
        float thisMagnitude = this->Magnitude();
        float otherMagnitude = v2.Magnitude();
        radian_t angle = maths::acos(dot / (thisMagnitude * otherMagnitude));

        return angle;
    }

    radian_t Vec2f::AngleBetween(const Vec2f v1, const Vec2f v2)
    {
        float dot = Dot(v1, v2);
        float v1Magnitude = v1.Magnitude();
        float v2Magnitude = v2.Magnitude();
        radian_t angle = maths::acos(dot / (v1Magnitude * v2Magnitude));

        return angle;
    }
	
}