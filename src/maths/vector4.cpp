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

#include <maths/vector4.h>

namespace maths {
Vector4f::Vector4f(float x, float y, float z, float w)
    : x(x),
      y(y),
      z(z),
      w(w) {
}

Vector4f Vector4f::operator+(const Vector4f& rhs) const {
    return {x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w};
}

Vector4f& Vector4f::operator+=(const Vector4f& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

Vector4f Vector4f::operator-(const Vector4f& rhs) const {
    return {x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w};
}

Vector4f& Vector4f::operator-=(const Vector4f& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

Vector4f Vector4f::operator*(const float scalar) const {
    return {x * scalar, y * scalar, z * scalar, w * scalar};
}

Vector4f& Vector4f::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

Vector4f Vector4f::operator/(const float scalar) const {
    return {x / scalar, y / scalar, z / scalar, w / scalar};
}

Vector4f& Vector4f::operator/=(const float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

float Vector4f::Dot(const Vector4f& v2) const {
    return Dot(*this, v2);
}

float Vector4f::Dot(const Vector4f& v1, const Vector4f& v2) {
    return {v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w};
}

float Vector4f::Magnitude() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

float Vector4f::SqrMagnitude() const {
    return {x * x + y * y + z * z + w * w};
}

Vector4f Vector4f::Normalized() const {
    const float magnitude = Magnitude();

    return {x / magnitude,
            y / magnitude,
            z / magnitude,
            w / magnitude};
}

void Vector4f::Normalize() {
    const float magnitude = Magnitude();

    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    w /= magnitude;
}

Vector4f Vector4f::Lerp(const Vector4f& v2, const float t) const {
    return Lerp(*this, v2, t);
}

Vector4f Vector4f::Lerp(const Vector4f& v1, const Vector4f& v2, const float t) {
    return v1 + (v2 - v1) * t;
}
} // namespace maths
