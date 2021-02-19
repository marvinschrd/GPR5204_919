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

#include "maths/vector3.h"
#include "maths/vector4.h"

namespace maths
{
    struct Mat44f
    {
        union
        {
            struct
            {
                Vector4f v1;
                Vector4f v2;
                Vector4f v3;
                Vector4f v4;
            };

            Vector4f matrix[4]{};
        };

        Mat44f() {}

        Mat44f(const Vector4f v1, const Vector4f v2, const Vector4f v3, const Vector4f v4) : v1(v1), v2(v2), v3(v3), v4(v4) {}

        Vector4f& operator[](size_t index) { return matrix[index]; }
    	
        Mat44f operator+(const Mat44f& rhs) const;

        void operator+=(const Mat44f& rhs);

        Mat44f operator-(const Mat44f& rhs) const;

        void operator-=(const Mat44f& rhs);

        Mat44f operator*(const Mat44f& rhs) const;

        void operator*=(const Mat44f& rhs);

        Vector4f operator*(const Vector4f& rhs) const;

        void operator*=(const Vector4f& rhs);

        float Determinant();

        Mat44f Inverse();

        Mat44f Transpose();

        Mat44f Adjoint();

        bool IsOrthogonal();

        static Mat44f Identity44();

        static Mat44f RotationMatrix44(radian_t angle, char axis);

        static Mat44f ScalingMatrix44(Vector3f axisValues);

        static Mat44f TranslationMatrix44(Vector3f axisValues);
    };
}


