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

#include <gtest/gtest.h>

#include "maths/vector4.h"

namespace maths {
TEST(Maths, Vector4f_Addition) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};
    const maths::Vector4f b{1.0f, 4.0f, 3.0f, 2.0f};

    //Test operator +.
    maths::Vector4f c = a + b;
    EXPECT_EQ(c.x, a.x + b.x);
    EXPECT_EQ(c.y, a.y + b.y);
    EXPECT_EQ(c.z, a.z + b.z);
    EXPECT_EQ(c.w, a.w + b.w);

    //Test operator +=.
    const maths::Vector4f d{3.0f, 4.0f, 2.0f, 1.0f};
    maths::Vector4f e = d;
    e += a;
    EXPECT_EQ(e.x, d.x + a.x);
    EXPECT_EQ(e.y, d.y + a.y);
    EXPECT_EQ(e.z, d.z + a.z);
    EXPECT_EQ(e.w, d.w + a.w);
}

TEST(Maths, Vector4f_Substraction) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};
    const maths::Vector4f b{1.0f, 4.0f, 3.0f, 2.0f};

    //Test operator -.
    maths::Vector4f c = a - b;
    EXPECT_EQ(c.x, a.x - b.x);
    EXPECT_EQ(c.y, a.y - b.y);
    EXPECT_EQ(c.z, a.z - b.z);
    EXPECT_EQ(c.w, a.w - b.w);

    //Test operator -=.
    const maths::Vector4f d{3.0f, 4.0f, 2.0f, 1.0f};
    maths::Vector4f e = d;
    e -= a;
    EXPECT_EQ(e.x, d.x - a.x);
    EXPECT_EQ(e.y, d.y - a.y);
    EXPECT_EQ(e.z, d.z - a.z);
    EXPECT_EQ(e.w, d.w - a.w);
}

TEST(Maths, Vector4f_MultiplicationByScalar) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};
    const float b = 4.0f;

    //Test operator *.
    maths::Vector4f c = a * b;
    EXPECT_EQ(c.x, a.x * b);
    EXPECT_EQ(c.y, a.y * b);
    EXPECT_EQ(c.z, a.z * b);
    EXPECT_EQ(c.w, a.w * b);

    //Test operator *=.
    const maths::Vector4f d{3.0f, 4.0f, 2.0f, 1.0f};
    maths::Vector4f e = d;
    e *= b;
    EXPECT_EQ(e.x, d.x * b);
    EXPECT_EQ(e.y, d.y * b);
    EXPECT_EQ(e.z, d.z * b);
    EXPECT_EQ(e.w, d.w * b);
}

TEST(Maths, Vector4f_DivisionByScalar) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};
    const float b = 4.0f;

    //Test operator /.
    maths::Vector4f c = a / b;
    EXPECT_EQ(c.x, a.x / b);
    EXPECT_EQ(c.y, a.y / b);
    EXPECT_EQ(c.z, a.z / b);
    EXPECT_EQ(c.w, a.w / b);

    //Test operator /=.
    const maths::Vector4f d{3.0f, 4.0f, 2.0f, 1.0f};
    maths::Vector4f e = d;
    e /= b;
    EXPECT_EQ(e.x, d.x / b);
    EXPECT_EQ(e.y, d.y / b);
    EXPECT_EQ(e.z, d.z / b);
    EXPECT_EQ(e.w, d.w / b);
}

TEST(Maths, Vector4f_Equal) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};

    // Test operator ==.
    const maths::Vector4f c = a;
    EXPECT_TRUE(c.x == a.x);
    EXPECT_TRUE(c.y == a.y);
    EXPECT_TRUE(c.z == a.z);
    EXPECT_TRUE(c.w == a.w);
}

TEST(Maths, Vector4f_NotEqual) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};
    const maths::Vector4f b{1.0f, 4.0f, 3.0f, 2.0f};

    // Test operator !=.
    EXPECT_TRUE(b.x != a.x);
    EXPECT_TRUE(b.y != a.y);
    EXPECT_TRUE(b.z != a.z);
    EXPECT_TRUE(b.w != a.w);
}

TEST(Maths, Vector4f_Magnitude) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};
    const float b = 4.0f;

    //Test .SqrMagnitude().
    EXPECT_EQ(a.Magnitude(),
              sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w)));
}

TEST(Maths, Vector4f_SqrMagnitude) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 4.0f};
    const float b = 4;

    //Test .SqrMagnitude().
    EXPECT_EQ(a.SqrMagnitude(),
              (a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w));
}

TEST(Maths, Vector4f_DotProduct) {
    const maths::Vector4f a{0.0f, 3.0f, 2.0f, 1.0f};
    const maths::Vector4f b{1.0f, 0.0f, 2.0f, 3.0f};

    //Test .Dot().
    EXPECT_EQ(a.Dot(b), a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);

    //Test static Dot().
    EXPECT_EQ(maths::Vector4f::Dot(a, b),
              a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);

    const maths::Vector4f c{2.0f, 3.0f, 1.0f, 0.0f};
    const maths::Vector4f d{1.0f, 1.0f, 1.0f, 1.0f};

    //Test .Dot().
    EXPECT_EQ(c.Dot(d), c.x * d.x + c.y * d.y + c.z * d.z + c.w * d.w);

    //Test static Dot().
    EXPECT_EQ(maths::Vector4f::Dot(c, d),
              c.x * d.x + c.y * d.y + c.z * d.z + c.w * d.w);
}

TEST(Maths, Vector4f_SubscriptOperator) {
    const maths::Vector4f a{0.0f, 3.0f, 2.0f, 1.0f};

    // Test operator[].
    EXPECT_EQ(a[0], 0.0f);
    EXPECT_EQ(a[1], 3.0f);
    EXPECT_EQ(a[2], 2.0f);
    EXPECT_EQ(a[3], 1.0f);
}

TEST(Maths, Vector4f_Normalize) {
    const maths::Vector4f a{0.0f, 3.0f, 2.0f, 1.0f};
    const maths::Vector4f b = a.Normalized();

    //Test .Normalized().
    EXPECT_FLOAT_EQ(b.Magnitude(), 1.0f);

    //Test .Normalize().
    maths::Vector4f c = a;
    c.Normalize();
    EXPECT_FLOAT_EQ(c.Magnitude(), 1.0f);
}

TEST(Maths, Vector4f_Lerp) {
    const maths::Vector4f a{2.0f, 3.0f, 1.0f, 0.0f};
    const maths::Vector4f b{1.0f, 4.0f, 3.0f, 2.0f};

    const float t0 = 0.0f;
    const float t1 = 1.0f;

    //Test static Vector3f Lerp t = 0.
    maths::Vector4f c = maths::Vector4f::Lerp(a, b, t0);
    EXPECT_EQ(c.x, a.x);
    EXPECT_EQ(c.y, a.y);
    EXPECT_EQ(c.z, a.z);
    EXPECT_EQ(c.w, a.w);

    //Test static Vector3f Lerp t = 1.
    maths::Vector4f d = maths::Vector4f::Lerp(a, b, t1);
    EXPECT_EQ(d.x, b.x);
    EXPECT_EQ(d.y, b.y);
    EXPECT_EQ(d.z, b.z);
    EXPECT_EQ(d.w, b.w);

    //Test Vector3f Lerp t = 0.
    maths::Vector4f e = a.Lerp(b, t0);
    EXPECT_EQ(e.x, a.x);
    EXPECT_EQ(e.y, a.y);
    EXPECT_EQ(e.z, a.z);
    EXPECT_EQ(e.w, a.w);

    //Test Vector3f Lerp t = 1.
    maths::Vector4f f = a.Lerp(b, t1);
    EXPECT_EQ(f.x, b.x);
    EXPECT_EQ(f.y, b.y);
    EXPECT_EQ(f.z, b.z);
    EXPECT_EQ(f.w, b.w);
}
} // namespace maths
