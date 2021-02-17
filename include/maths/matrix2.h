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

#include "maths/vector2.h"

namespace maths
{
    struct Mat22f
    {
    	struct
    	{
            Vec2f v1;
    		Vec2f v2;
    	};
    	
        Mat22f() {}

        Mat22f(const Vec2f v1, const Vec2f v2) : v1(v1), v2(v2) {}

        Mat22f operator+(const Mat22f& rhs) const;

        void operator+=(const Mat22f& rhs);

        Mat22f operator-(const Mat22f& rhs) const;

        void operator-=(const Mat22f& rhs);

        Mat22f operator*(const Mat22f& rhs) const;

        void operator*=(const Mat22f& rhs);

        Vec2f operator*(const Vec2f& rhs) const;

        void operator*=(const Vec2f& rhs);

        float Determinant();

        Mat22f Inverse();

        Mat22f Transpose();

        static Mat22f Identity22();
    };
}