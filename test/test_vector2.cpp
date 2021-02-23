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
#include "maths/vector2.h"

namespace tests
{
TEST(Maths, Vector2f_Addition)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const maths::Vector2f b{1.0f, 4.0f};

	//Test operator + .
	maths::Vector2f c = a + b;
	EXPECT_EQ(c.x, a.x + b.x);
	EXPECT_EQ(c.y, a.y + b.y);

	//Test operator += .
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e += a;
	EXPECT_EQ(e.x, d.x + a.x);
	EXPECT_EQ(e.y, d.y + a.y);
}

TEST(Maths, Vector2f_Substraction)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const maths::Vector2f b{1.0f, 4.0f};

	//Test operator - .
	maths::Vector2f c = a - b;
	EXPECT_EQ(c.x, a.x - b.x);
	EXPECT_EQ(c.y, a.y - b.y);

	//Test operator -= .
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e -= a;
	EXPECT_EQ(e.x, d.x - a.x);
	EXPECT_EQ(e.y, d.y - a.y);
}

TEST(Maths, Vector2f_MultiplicationByScalar)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const float b = 4.0f;

	//Test operator + .
	maths::Vector2f c = a * b;
	EXPECT_EQ(c.x, a.x * b);
	EXPECT_EQ(c.y, a.y * b);

	//Test operator += .
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e *= b;
	EXPECT_EQ(e.x, d.x * b);
	EXPECT_EQ(e.y, d.y * b);
}

TEST(Maths, Vector2f_DivisionByScalar)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const float b = 4.0f;

	//Test operator / .
	maths::Vector2f c = a / b;
	EXPECT_EQ(c.x, a.x / b);
	EXPECT_EQ(c.y, a.y / b);

	//Test operator /= .
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e /= b;
	EXPECT_EQ(e.x, d.x / b);
	EXPECT_EQ(e.y, d.y / b);
}

TEST(Maths, Vector2f_Magnitude)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const float b = 4;

	//Test .Magnitude() .
	EXPECT_EQ(a.Magnitude(), std::sqrt((a.x * a.x) + (a.y * a.y)));
}

TEST(Maths, Vector2f_SqrMagnitude)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const float b = 4;

	//Test .SqrMagnitude() .
	EXPECT_EQ(a.SqrMagnitude(), (a.x * a.x) + (a.y * a.y));
}

TEST(Maths, Vector2f_DotProduct)
{
	const maths::Vector2f a{0.0f, 3.0f};
	const maths::Vector2f b{1.0f, 0.0f};

	//Test .Dot() .
	EXPECT_EQ(a.Dot(b), 0.0f);

	//Test static Dot() .
	EXPECT_EQ(maths::Vector2f::Dot(a, b), 0.0f);


	const maths::Vector2f c{2.0f, 3.0f};
	const maths::Vector2f d{1.0f, 1.0f};

	//Test .Dot() .
	EXPECT_EQ(c.Dot(d), c.x * d.x + c.y * d.y);

	//Test static Dot() .
	EXPECT_EQ(maths::Vector2f::Dot(c, d), c.x * d.x + c.y * d.y);
}

TEST(Maths, Vector2f_CrossProduct)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const maths::Vector2f b{1.0f, -3.0f};

	//Test .Cross() .
	EXPECT_EQ(a.Cross(b).x, 0);
	EXPECT_EQ(a.Cross(b).y, 0);
	EXPECT_EQ(a.Cross(b).z, a.x * b.y - a.y * b.x);

	//Test static Cross() .
	EXPECT_EQ(maths::Vector2f::Cross(a, b).x, 0);
	EXPECT_EQ(maths::Vector2f::Cross(a, b).y, 0);
	EXPECT_EQ(maths::Vector2f::Cross(a, b).z, a.x * b.y - a.y * b.x);
}

TEST(Maths, Vector2f_AngleBetween)
{
	const maths::Vector2f a{0.0f, 3.0f};
	const maths::Vector2f b{1.0f, 0.0f};

	//Test .AngleBetween() .
	EXPECT_EQ(a.AngleBetween(b),
	          maths::acos(a.Dot(b) / (a.Magnitude() * b.Magnitude())));

	//Test static AngleBetween() .
	EXPECT_EQ(maths::Vector2f::AngleBetween(a, b),
	          maths::acos(maths::Vector2f::Dot(a, b) / (a.Magnitude() *
		          b.Magnitude())));
}

TEST(Maths, Vector2f_Normalize)
{
	const maths::Vector2f a{0.0f, 3.0f};
	const maths::Vector2f b = a.Normalized();

	//Test .Normalized() .
	EXPECT_EQ(b.Magnitude(), 1.0f);

	//Test .Normalize() .
	maths::Vector2f c = a;
	c.Normalize();
	EXPECT_EQ(c.Magnitude(), 1.0f);
}

TEST(Maths, Vector2f_Lerp)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const maths::Vector2f b{1.0f, 4.0f};

	const float t0 = 0.0f;
	const float t1 = 1.0f;

	//Test static Vector2f Lerp t = 0.
	maths::Vector2f c = maths::Vector2f::Lerp(a, b, t0);
	EXPECT_EQ(c.x, a.x);
	EXPECT_EQ(c.y, a.y);

	//Test static Vector2f Lerp t = 1.
	maths::Vector2f d = maths::Vector2f::Lerp(a, b, t1);
	EXPECT_EQ(d.x, b.x);
	EXPECT_EQ(d.y, b.y);

	//Test Vector2f Lerp t = 0.
	maths::Vector2f e = a.Lerp(b, t0);
	EXPECT_EQ(e.x, a.x);
	EXPECT_EQ(e.y, a.y);

	//Test Vector2f Lerp t = 1.
	maths::Vector2f f = a.Lerp(b, t1);
	EXPECT_EQ(f.x, b.x);
	EXPECT_EQ(f.y, b.y);
}

TEST(Maths, Vector2f_Slerp)
{
	float threshold = 0.0001f;
	
	const maths::Vector2f a{2.0f, 3.0f};
	const maths::Vector2f b{1.0f, 4.0f};

	const float t0 = 0.0f;
	const float t1 = 1.0f;

	//Test Vector2f Slerp t = 0.
	maths::Vector2f c = a.Slerp(b, t0);
	//Check difference between result & expected value
	//Because slerp function lose too much precision with double.
	EXPECT_TRUE(std::abs(c.x - a.x) < threshold);
	EXPECT_TRUE(std::abs(c.y - a.y) < threshold);

	//Test Vector2f Slerp t = 1.
	maths::Vector2f d = a.Slerp(b, t1);
	EXPECT_TRUE(std::abs(d.x - b.x) < threshold);
	EXPECT_TRUE(std::abs(d.y - b.y) < threshold);
}

TEST(Maths, Vector2f_Rotation)
{
	const maths::Vector2f a = maths::Vector2f{1.0f, 3.0f};
	const maths::degree_t b = maths::degree_t(45.f);
	const maths::radian_t c = b;

	//Test .Rotation() .
	EXPECT_EQ(a.Rotation(b).x,
	          (a.x * maths::cos(c)) + (a.y * -maths::sin(c)));
	EXPECT_EQ(a.Rotation(b).y,
	          (a.x * maths::sin(c)) + (a.y * maths::cos(c)));

	//Test static Rotation() .
	EXPECT_EQ(maths::Vector2f::Rotation(a, b).x,
	          (a.x * maths::cos(c)) + (a.y * -maths::sin(c)));
	EXPECT_EQ(maths::Vector2f::Rotation(a, b).y,
	          (a.x * maths::sin(c)) + (a.y * maths::cos(c)));
}
} // namespace tests
