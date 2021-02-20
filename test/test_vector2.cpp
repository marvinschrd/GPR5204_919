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

TEST(Maths, Vec2f_Addition)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const maths::Vector2f b{1.0f, 4.0f};

	//Test operator +
	maths::Vector2f c = a + b;
	ASSERT_EQ(c.x, a.x + b.x);
	ASSERT_EQ(c.y, a.y + b.y);

	//Test operator +=
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e += a;
	ASSERT_EQ(e.x, d.x + a.x);
	ASSERT_EQ(e.y, d.y + a.y);
}

TEST(Maths, Vec2f_Substraction)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const maths::Vector2f b{1.0f, 4.0f};

	//Test operator -
	maths::Vector2f c = a - b;
	ASSERT_EQ(c.x, a.x - b.x);
	ASSERT_EQ(c.y, a.y - b.y);

	//Test operator -=
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e -= a;
	ASSERT_EQ(e.x, d.x - a.x);
	ASSERT_EQ(e.y, d.y - a.y);
}

TEST(Maths, Vec2f_MultiplicationByScalar)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const float b = 4.0f;

	//Test operator +
	maths::Vector2f c = a * b;
	ASSERT_EQ(c.x, a.x * b);
	ASSERT_EQ(c.y, a.y * b);

	//Test operator +=
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e *= b;
	ASSERT_EQ(e.x, d.x * b);
	ASSERT_EQ(e.y, d.y * b);
}

TEST(Maths, Vec2f_DivisionByScalar)
{
	const maths::Vector2f a{2.0f, 3.0f};
	const float b = 4.0f;

	//Test operator /
	maths::Vector2f c = a / b;
	ASSERT_EQ(c.x, a.x / b);
	ASSERT_EQ(c.y, a.y / b);

	//Test operator /=
	const maths::Vector2f d{3.0f, 4.0f};
	maths::Vector2f e = d;
	e /= b;
	ASSERT_EQ(e.x, d.x / b);
	ASSERT_EQ(e.y, d.y / b);
}

TEST(Maths, Vec2f_Magnitude)
{
	const maths::Vector2f a{ 2.0f, 3.0f };
	const float b = 4;

	//Test .Magnitude()
	ASSERT_EQ(a.Magnitude(), std::sqrt((a.x * a.x) + (a.y * a.y)));
}

TEST(Maths, Vec2f_SqrMagnitude)
{
	const maths::Vector2f a{ 2.0f, 3.0f };
	const float b = 4;

	//Test .SqrMagnitude()
	ASSERT_EQ(a.SqrMagnitude(), (a.x * a.x) + (a.y * a.y));
}

TEST(Maths, Vec2f_DotProduct)
{
	const maths::Vector2f a{ 0.0f, 3.0f };
	const maths::Vector2f b{ 1.0f, 0.0f };

	//Test .Dot()
	ASSERT_EQ(a.Dot(b), 0.0f);

	//Test static Dot()
	ASSERT_EQ(maths::Vector2f::Dot(a, b), 0.0f);


	const maths::Vector2f c{ 2.0f, 3.0f };
	const maths::Vector2f d{ 1.0f, 1.0f };

	//Test .Dot()
	ASSERT_EQ(c.Dot(d), c.x * d.x + c.y * d.y);

	//Test static Dot()
	ASSERT_EQ(maths::Vector2f::Dot(c, d), c.x * d.x + c.y * d.y);
}

TEST(Maths, Vec2f_CrossProduct)
{
	const maths::Vector2f a{ 2.0f, 3.0f };
	const maths::Vector2f b{ 1.0f, -3.0f };

	//Test .Cross()
	ASSERT_EQ(a.Cross(b).x, 0);
	ASSERT_EQ(a.Cross(b).y, 0);
	ASSERT_EQ(a.Cross(b).z, a.x * b.y - a.y * b.x);

	//Test static Cross()
	ASSERT_EQ(maths::Vector2f::Cross(a, b).x, 0);
	ASSERT_EQ(maths::Vector2f::Cross(a, b).y, 0);
	ASSERT_EQ(maths::Vector2f::Cross(a, b).z, a.x * b.y - a.y * b.x);
}

TEST(Maths, Vec2f_AngleBetween)
{
	const maths::Vector2f a{ 0.0f, 3.0f };
	const maths::Vector2f b{ 1.0f, 0.0f };

	//Test .AngleBetween()
	ASSERT_EQ(maths::Vector2f::AngleBetween(a, b), maths::acos(a.Dot(b) / (a.Magnitude() * b.Magnitude())));

	//Test static AngleBetween()
	ASSERT_EQ(maths::Vector2f::AngleBetween(a, b), maths::acos(maths::Vector2f::Dot(a, b) / (a.Magnitude() * b.Magnitude())));
}