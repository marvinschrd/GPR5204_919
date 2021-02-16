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

#include <maths/vector4.h>

TEST(Maths, Vec4f_Addition)
{
	const maths::Vec4f a{ 2.0f, 3.0f, 1.0f, 4.0f };
	const maths::Vec4f b{ 1.0f, 4.0f, 3.0f, 2.0f };

	//Test operator +
	maths::Vec4f c = a + b;
	ASSERT_EQ(c.x, a.x + b.x);
	ASSERT_EQ(c.y, a.y + b.y);
	ASSERT_EQ(c.z, a.z + b.z);
	ASSERT_EQ(c.w, a.w + b.w);

	//Test operator +=
	const maths::Vec4f d{ 3.0f, 4.0f, 2.0f, 1.0f };
	maths::Vec4f e = d;
	e += a;
	ASSERT_EQ(e.x, d.x + a.x);
	ASSERT_EQ(e.y, d.y + a.y);
	ASSERT_EQ(e.z, d.z + a.z);
	ASSERT_EQ(e.w, d.w + a.w);
}

TEST(Maths, Vec4f_Substraction)
{
	const maths::Vec4f a{ 2.0f, 3.0f, 1.0f, 4.0f };
	const maths::Vec4f b{ 1.0f, 4.0f, 3.0f, 2.0f };

	//Test operator -
	maths::Vec4f c = a - b;
	ASSERT_EQ(c.x, a.x - b.x);
	ASSERT_EQ(c.y, a.y - b.y);
	ASSERT_EQ(c.z, a.z - b.z);
	ASSERT_EQ(c.w, a.w - b.w);

	//Test operator -=
	const maths::Vec4f d{ 3.0f, 4.0f, 2.0f, 1.0f };
	maths::Vec4f e = d;
	e -= a;
	ASSERT_EQ(e.x, d.x - a.x);
	ASSERT_EQ(e.y, d.y - a.y);
	ASSERT_EQ(e.z, d.z - a.z);
	ASSERT_EQ(e.w, d.w - a.w);
}

TEST(Maths, Vec4f_MultiplicationByScalar)
{
	const maths::Vec4f a{ 2.0f, 3.0f, 1.0f, 4.0f };
	const float b = 4.0f;

	//Test operator *
	maths::Vec4f c = a * b;
	ASSERT_EQ(c.x, a.x * b);
	ASSERT_EQ(c.y, a.y * b);
	ASSERT_EQ(c.z, a.z * b);
	ASSERT_EQ(c.w, a.w * b);

	//Test operator *=
	const maths::Vec4f d{ 3.0f, 4.0f, 2.0f, 1.0f };
	maths::Vec4f e = d;
	e *= b;
	ASSERT_EQ(e.x, d.x * b);
	ASSERT_EQ(e.y, d.y * b);
	ASSERT_EQ(e.z, d.z * b);
	ASSERT_EQ(e.w, d.w * b);
}

TEST(Maths, Vec4f_DivisionByScalar)
{
	const maths::Vec4f a{ 2.0f, 3.0f, 1.0f, 4.0f };
	const float b = 4.0f;

	//Test operator /
	maths::Vec4f c = a / b;
	ASSERT_EQ(c.x, a.x / b);
	ASSERT_EQ(c.y, a.y / b);
	ASSERT_EQ(c.z, a.z / b);
	ASSERT_EQ(c.w, a.w / b);

	//Test operator /=
	const maths::Vec4f d{ 3.0f, 4.0f, 2.0f, 1.0f };
	maths::Vec4f e = d;
	e /= b;
	ASSERT_EQ(e.x, d.x / b);
	ASSERT_EQ(e.y, d.y / b);
	ASSERT_EQ(e.z, d.z / b);
	ASSERT_EQ(e.w, d.w / b);
}
