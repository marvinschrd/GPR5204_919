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
#include "maths/vector3.h"

namespace maths {
TEST(Maths, Vector3f_Addition) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const maths::Vector3f b{1.0f, 4.0f, 3.0f};

    // Test operator +.
    maths::Vector3f c = a + b;
    EXPECT_EQ(c.x, a.x + b.x);
    EXPECT_EQ(c.y, a.y + b.y);
    EXPECT_EQ(c.z, a.z + b.z);

    // Test operator +=.
    const maths::Vector3f d{3.0f, 4.0f, 2.0f};
    maths::Vector3f e = d;
    e += a;
    EXPECT_EQ(e.x, d.x + a.x);
    EXPECT_EQ(e.y, d.y + a.y);
    EXPECT_EQ(e.z, d.z + a.z);
}

TEST(Maths, Vector3f_Substraction) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const maths::Vector3f b{1.0f, 4.0f, 3.0f};

    // Test operator -.
    maths::Vector3f c = a - b;
    EXPECT_EQ(c.x, a.x - b.x);
    EXPECT_EQ(c.y, a.y - b.y);
    EXPECT_EQ(c.z, a.z - b.z);

    // Test operator -=.
    const maths::Vector3f d{3.0f, 4.0f, 2.0f};
    maths::Vector3f e = d;
    e -= a;
    EXPECT_EQ(e.x, d.x - a.x);
    EXPECT_EQ(e.y, d.y - a.y);
    EXPECT_EQ(e.z, d.z - a.z);
}

TEST(Maths, Vector3f_MultiplicationByScalar) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const float b = 4.0f;

    // Test operator *.
    maths::Vector3f c = a * b;
    EXPECT_EQ(c.x, a.x * b);
    EXPECT_EQ(c.y, a.y * b);
    EXPECT_EQ(c.z, a.z * b);

    // Test operator *=.
    const maths::Vector3f d{3.0f, 4.0f, 2.0f};
    maths::Vector3f e = d;
    e *= b;
    EXPECT_EQ(e.x, d.x * b);
    EXPECT_EQ(e.y, d.y * b);
    EXPECT_EQ(e.z, d.z * b);
}

TEST(Maths, Vector3f_DivisionByScalar) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const float b = 4.0f;

    // Test operator /.
    maths::Vector3f c = a / b;
    EXPECT_EQ(c.x, a.x / b);
    EXPECT_EQ(c.y, a.y / b);
    EXPECT_EQ(c.z, a.z / b);

    //Test operator /=.
    const maths::Vector3f d{3.0f, 4.0f, 2.0f};
    maths::Vector3f e = d;
    e /= b;
    EXPECT_EQ(e.x, d.x / b);
    EXPECT_EQ(e.y, d.y / b);
    EXPECT_EQ(e.z, d.z / b);
}

TEST(Maths, Vector3f_Equal) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};

    // Test operator ==.
    const maths::Vector3f c = a;
    EXPECT_TRUE(c.x == a.x);
    EXPECT_TRUE(c.y == a.y);
    EXPECT_TRUE(c.z == a.z);
}

TEST(Maths, Vector3f_NotEqual) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const maths::Vector3f b{1.0f, 4.0f, 3.0f};

    // Test operator !=.
    EXPECT_TRUE(b.x != a.x);
    EXPECT_TRUE(b.y != a.y);
    EXPECT_TRUE(b.z != a.z);
}

TEST(Maths, Vector3f_Magnitude) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const float b = 4;

    // Test .SqrMagnitude().
    EXPECT_EQ(a.Magnitude(), sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

TEST(Maths, Vector3f_SqrMagnitude) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const float b = 4;

    // Test .SqrMagnitude().
    EXPECT_EQ(a.SqrMagnitude(), (a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

TEST(Maths, Vector3f_DotProduct) {
    const maths::Vector3f a{0.0f, 3.0f, 2.0f};
    const maths::Vector3f b{1.0f, 0.0f, 2.0f};

    // Test .Dot().
    EXPECT_EQ(a.Dot(b), a.x * b.x + a.y * b.y + a.z * b.z);

    // Test static Dot().
    EXPECT_EQ(maths::Vector3f::Dot(a, b), a.x * b.x + a.y * b.y + a.z * b.z);

    const maths::Vector3f c{2.0f, 3.0f, 1.0f};
    const maths::Vector3f d{1.0f, 1.0f, 1.0f};

    // Test .Dot().
    EXPECT_EQ(c.Dot(d), c.x * d.x + c.y * d.y + c.z * d.z);

    // Test static Dot().
    EXPECT_EQ(maths::Vector3f::Dot(c, d), c.x * d.x + c.y * d.y + c.z * d.z);
}

TEST(Maths, Vector3f_CrossProduct) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const maths::Vector3f b{1.0f, -3.0f, 2.0f};

    // Test .Cross().
    EXPECT_EQ(a.Cross(b).x, a.y * b.z - a.z * b.y);
    EXPECT_EQ(a.Cross(b).y, a.z * b.x - a.x * b.z);
    EXPECT_EQ(a.Cross(b).z, a.x * b.y - a.y * b.x);

    // Test static Cross().
    EXPECT_EQ(maths::Vector3f::Cross(a, b).x, a.y * b.z - a.z * b.y);
    EXPECT_EQ(maths::Vector3f::Cross(a, b).y, a.z * b.x - a.x * b.z);
    EXPECT_EQ(maths::Vector3f::Cross(a, b).z, a.x * b.y - a.y * b.x);
}

TEST(Maths, Vector3f_AngleBetween) {
    const maths::Vector3f a{0.0f, 3.0f, 2.0f};
    const maths::Vector3f b{1.0f, 0.0f, 2.0f};

    // Test .AngleBetween().
    EXPECT_EQ(maths::Vector3f::AngleBetween(a, b),
              maths::acos(a.Dot(b) / (a.Magnitude() * b.Magnitude())));

    // Test static AngleBetween().
    EXPECT_EQ(maths::Vector3f::AngleBetween(a, b),
              maths::acos(maths::Vector3f::Dot(a, b) /
                  (a.Magnitude() * b.Magnitude())));
}

TEST(Maths, Vector3f_SubscriptOperator) {
    const maths::Vector3f a{0.0f, 3.0f, 2.0f};

    // Test operator[].
    EXPECT_EQ(a[0], 0.0f);
    EXPECT_EQ(a[1], 3.0f);
    EXPECT_EQ(a[2], 2.0f);
}

TEST(Maths, Vector3f_Normalize) {
    const maths::Vector3f a{0.0f, 3.0f, 2.0f};
    const maths::Vector3f b = a.Normalized();

    // Test .Normalized().
    EXPECT_EQ(b.Magnitude(), 1.0f);

    // Test .Normalize().
    maths::Vector3f c = a;
    c.Normalize();
    EXPECT_EQ(c.Magnitude(), 1.0f);
}

TEST(Maths, Vector3f_Lerp) {
    const maths::Vector3f a{2.0f, 3.0f, 1.0f};
    const maths::Vector3f b{1.0f, 4.0f, 3.0f};

    const float t0 = 0.0f;
    const float t1 = 1.0f;

    // Test static Vector3f Lerp t = 0.
    maths::Vector3f c = maths::Vector3f::Lerp(a, b, t0);
    EXPECT_EQ(c.x, a.x);
    EXPECT_EQ(c.y, a.y);
    EXPECT_EQ(c.z, a.z);

    // Test static Vector3f Lerp t = 1.
    maths::Vector3f d = maths::Vector3f::Lerp(a, b, t1);
    EXPECT_EQ(d.x, b.x);
    EXPECT_EQ(d.y, b.y);
    EXPECT_EQ(d.z, b.z);

    // Test Vector3f Lerp t = 0.
    maths::Vector3f e = a.Lerp(b, t0);
    EXPECT_EQ(e.x, a.x);
    EXPECT_EQ(e.y, a.y);
    EXPECT_EQ(e.z, a.z);

    // Test Vector3f Lerp t = 1.
    maths::Vector3f f = a.Lerp(b, t1);
    EXPECT_EQ(f.x, b.x);
    EXPECT_EQ(f.y, b.y);
    EXPECT_EQ(f.z, b.z);
}

TEST(Maths, Vector3f_Slerp) {
    float threshold = 0.0001f;

    maths::Vector3f a{2.0f, 3.0f, 1.0f};
    maths::Vector3f b{1.0f, 4.0f, 3.0f};

    const float t0 = 0.0f;
    const float t1 = 1.0f;

    // Test Vector3f Slerp t = 0.
    maths::Vector3f c = a.Slerp(b, t0);
    // Check difference between result & expected value.
    // Because slerp function lose too much precision with double.
    EXPECT_TRUE(std::abs(c.x - a.x) < threshold);
    EXPECT_TRUE(std::abs(c.y - a.y) < threshold);
    EXPECT_TRUE(std::abs(c.z - a.z) < threshold);

    // Test Vector3f Slerp t = 1.
    maths::Vector3f d = a.Slerp(b, t1);
    EXPECT_TRUE(std::abs(d.x - b.x) < threshold);
    EXPECT_TRUE(std::abs(d.y - b.y) < threshold);
    EXPECT_TRUE(std::abs(d.z - b.z) < threshold);
}
} // namespace maths
