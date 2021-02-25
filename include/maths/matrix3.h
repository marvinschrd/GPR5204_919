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

#include <array>

#include "maths/vector2.h"
#include "maths/vector3.h"

namespace maths
{
class Matrix3f
{
public:
	
    Matrix3f() = default;

    Matrix3f(const Vector3f v1, const Vector3f v2, const Vector3f v3);

    Vector3f& operator[](size_t index) { return matrix_[index]; }

    const Vector3f& operator[](size_t index) const { return matrix_[index]; }
    
    Matrix3f operator+(const Matrix3f& rhs) const;

    Matrix3f& operator+=(const Matrix3f& rhs);

    Matrix3f operator-(const Matrix3f& rhs) const;

    Matrix3f& operator-=(const Matrix3f& rhs);

    Matrix3f operator*(const Matrix3f& rhs) const;

    Matrix3f& operator*=(const Matrix3f& rhs);

    Vector3f operator*(const Vector3f& rhs) const;

    Matrix3f& operator*=(const float& scalar);

    float GetCofactor(const int row, const int column) const;

    float Determinant() const;

    Matrix3f Inverse() const;

    Matrix3f Transpose() const;

    Matrix3f Adjoint() const;

    bool IsOrthogonal() const;

    static Matrix3f Identity();

    static Matrix3f RotationMatrix(radian_t angle);

    static Matrix3f ScalingMatrix(Vector2f axisValues);

    static Matrix3f TranslationMatrix(Vector2f axisValues);

private:

    std::array<Vector3f, 3> matrix_;
    int size_ = 3;
};
	
}//namespace maths