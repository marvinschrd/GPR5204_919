#include <gtest/gtest.h>
#include "maths/vector2.h"

TEST(Maths, Vec2f_Addition)
{
	const maths::Vec2f a{2.0f, 3.0f};
	const maths::Vec2f b{1.0f, 4.0f};

	//Test operator +
	maths::Vec2f c = a + b;
	ASSERT_EQ(c.x, a.x + b.x);
	ASSERT_EQ(c.y, a.y + b.y);

	//Test operator +=
	const maths::Vec2f d{3.0f, 4.0f};
	maths::Vec2f e = d;
	e += a;
	ASSERT_EQ(e.x, d.x + a.x);
	ASSERT_EQ(e.y, d.y + a.y);
}

TEST(Maths, Vec2f_Substraction)
{
	const maths::Vec2f a{2.0f, 3.0f};
	const maths::Vec2f b{1.0f, 4.0f};

	//Test operator -
	maths::Vec2f c = a - b;
	ASSERT_EQ(c.x, a.x - b.x);
	ASSERT_EQ(c.y, a.y - b.y);

	//Test operator -=
	const maths::Vec2f d{3.0f, 4.0f};
	maths::Vec2f e = d;
	e -= a;
	ASSERT_EQ(e.x, d.x - a.x);
	ASSERT_EQ(e.y, d.y - a.y);
}

TEST(Maths, Vec2f_MultiplicationByScalar)
{
	const maths::Vec2f a{2.0f, 3.0f};
	const float b = 4.0f;

	//Test operator +
	maths::Vec2f c = a * b;
	ASSERT_EQ(c.x, a.x * b);
	ASSERT_EQ(c.y, a.y * b);

	//Test operator +=
	const maths::Vec2f d{3.0f, 4.0f};
	maths::Vec2f e = d;
	e *= b;
	ASSERT_EQ(e.x, d.x * b);
	ASSERT_EQ(e.y, d.y * b);
}

TEST(Maths, Vec2f_DivisionByScalar)
{
	const maths::Vec2f a{2.0f, 3.0f};
	const float b = 4.0f;

	//Test operator /
	maths::Vec2f c = a / b;
	ASSERT_EQ(c.x, a.x / b);
	ASSERT_EQ(c.y, a.y / b);

	//Test operator /=
	const maths::Vec2f d{3.0f, 4.0f};
	maths::Vec2f e = d;
	e /= b;
	ASSERT_EQ(e.x, d.x / b);
	ASSERT_EQ(e.y, d.y / b);
}