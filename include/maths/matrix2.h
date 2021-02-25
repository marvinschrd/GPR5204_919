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

namespace maths
{
class Matrix2f
{
public:
    
    Matrix2f() = default;

    Matrix2f(const Vector2f v1, const Vector2f v2);

    Vector2f& operator[](size_t index) { return matrix_[index]; }

    const Vector2f& operator[](size_t index) const { return matrix_[index]; }

    Matrix2f operator+(const Matrix2f& rhs) const;

    Matrix2f& operator+=(const Matrix2f& rhs);

    Matrix2f operator-(const Matrix2f& rhs) const;

    Matrix2f& operator-=(const Matrix2f& rhs);

    Matrix2f operator*(const Matrix2f& rhs) const;

    Matrix2f& operator*=(const Matrix2f& rhs);

    Matrix2f& operator*=(const float& scalar);

    Vector2f operator*(const Vector2f& rhs) const;

    float Determinant() const;

    Matrix2f Inverse() const;

    Matrix2f Transpose() const;

    bool IsOrthogonal() const;

    static Matrix2f Identity();

private:

    std::array<Vector2f, 2> matrix_;
    int size_ = 2;
};
}//namespace maths