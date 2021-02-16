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

#include <maths/vector3.h>

TEST(Maths, Vec3f_Addition)
{
	const maths::Vec3f a{2.0f, 3.0f, 1.0f};
	const maths::Vec3f b{1.0f, 4.0f, 3.0f};

	//Test operator +
	maths::Vec3f c = a + b;
	ASSERT_EQ(c.x, a.x + b.x);
	ASSERT_EQ(c.y, a.y + b.y);
	ASSERT_EQ(c.z, a.z + b.z);

	//Test operator +=
	const maths::Vec3f d{3.0f, 4.0f, 2.0f};
	maths::Vec3f e = d;
	e += a;
	ASSERT_EQ(e.x, d.x + a.x);
	ASSERT_EQ(e.y, d.y + a.y);
	ASSERT_EQ(e.z, d.z + a.z);
}

TEST(Maths, Vec3f_Substraction)
{
	const maths::Vec3f a{2.0f, 3.0f, 1.0f};
	const maths::Vec3f b{1.0f, 4.0f, 3.0f};

	//Test operator -
	maths::Vec3f c = a - b;
	ASSERT_EQ(c.x, a.x - b.x);
	ASSERT_EQ(c.y, a.y - b.y);
	ASSERT_EQ(c.z, a.z - b.z);

	//Test operator -=
	const maths::Vec3f d{3.0f, 4.0f, 2.0f};
	maths::Vec3f e = d;
	e -= a;
	ASSERT_EQ(e.x, d.x - a.x);
	ASSERT_EQ(e.y, d.y - a.y);
	ASSERT_EQ(e.z, d.z - a.z);
}

TEST(Maths, Vec3f_MultiplicationByScalar)
{
	const maths::Vec3f a{2.0f, 3.0f, 1.0f};
	const float b = 4.0f;

	//Test operator *
	maths::Vec3f c = a * b;
	ASSERT_EQ(c.x, a.x * b);
	ASSERT_EQ(c.y, a.y * b);
	ASSERT_EQ(c.z, a.z * b);

	//Test operator *=
	const maths::Vec3f d{3.0f, 4.0f, 2.0f};
	maths::Vec3f e = d;
	e *= b;
	ASSERT_EQ(e.x, d.x * b);
	ASSERT_EQ(e.y, d.y * b);
	ASSERT_EQ(e.z, d.z * b);
}

TEST(Maths, Vec3f_DivisionByScalar)
{
	const maths::Vec3f a{2.0f, 3.0f, 1.0f};
	const float b = 4.0f;

	//Test operator /
	maths::Vec3f c = a / b;
	ASSERT_EQ(c.x, a.x / b);
	ASSERT_EQ(c.y, a.y / b);
	ASSERT_EQ(c.z, a.z / b);

	//Test operator /=
	const maths::Vec3f d{3.0f, 4.0f, 2.0f};
	maths::Vec3f e = d;
	e /= b;
	ASSERT_EQ(e.x, d.x / b);
	ASSERT_EQ(e.y, d.y / b);
	ASSERT_EQ(e.z, d.z / b);
}

TEST(Maths, Vec3f_Magnitude)
{
	const maths::Vec3f a{ 2.0f, 3.0f, 1.0f };
	const float b = 4;

	//Test .SqrMagnitude()
	ASSERT_EQ(a.Magnitude(), sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

TEST(Maths, Vec3f_SqrMagnitude)
{
	const maths::Vec3f a{ 2.0f, 3.0f, 1.0f };
	const float b = 4;

	//Test .SqrMagnitude()
	ASSERT_EQ(a.SqrMagnitude(), (a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

TEST(Maths, Vec3f_DotProduct)
{
	const maths::Vec3f a{ 0.0f, 3.0f, 2.0f};
	const maths::Vec3f b{ 1.0f, 0.0f, 2.0f };

	//Test .Dot()
	ASSERT_EQ(a.Dot(b), a.x * b.x + a.y * b.y + a.z * b.z);

	//Test static Dot()
	ASSERT_EQ(maths::Vec3f::Dot(a, b), a.x * b.x + a.y * b.y + a.z * b.z);


	const maths::Vec3f c{ 2.0f, 3.0f, 1.0f };
	const maths::Vec3f d{ 1.0f, 1.0f, 1.0f };

	//Test .Dot()
	ASSERT_EQ(c.Dot(d), c.x * d.x + c.y * d.y + c.z * d.z);

	//Test static Dot()
	ASSERT_EQ(maths::Vec3f::Dot(c, d), c.x * d.x + c.y * d.y + c.z * d.z);
}

TEST(Maths, Vec3f_AngleBetween)
{
	const maths::Vec3f a{ 0.0f, 3.0f, 2.0f };
	const maths::Vec3f b{ 1.0f, 0.0f, 2.0f };

	//Test .AngleBetween()
	ASSERT_EQ(maths::Vec3f::AngleBetween(a, b), maths::acos(a.Dot(b) / (a.Magnitude() * b.Magnitude())));

	//Test static AngleBetween()
	ASSERT_EQ(maths::Vec3f::AngleBetween(a, b), maths::acos(maths::Vec3f::Dot(a, b) / (a.Magnitude() * b.Magnitude())));
}
