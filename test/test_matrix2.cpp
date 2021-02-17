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
#include "maths/vector3.h"
#include "maths/vector4.h"
#include "maths/matrix2.h"
#include "maths/matrix3.h"
#include "maths/matrix4.h"

TEST(Maths, Mat22f_Determinant)
{
	const maths::Mat22f A = maths::Mat22f(maths::Vec2f(1, 2), maths::Vec2f(3, 1));

	//Test determinant
	const float det = A.Determinant();
	ASSERT_EQ(det, -5);
}

TEST(Maths, Mat22f_Inverse)
{
	const maths::Mat22f A = maths::Mat22f(maths::Vec2f(1, 2), maths::Vec2f(1, 3));

	//Test inverse
	const maths::Mat22f inverseA = A.Inverse();
	maths::Mat22f testInverse = maths::Mat22f(maths::Vec2f(3, -1), maths::Vec2f(-2, 1));

	ASSERT_EQ(inverseA.matrix[0][0], 3);
	ASSERT_EQ(inverseA.matrix[0][1], -1);
	ASSERT_EQ(inverseA.matrix[1][0], -2);
	ASSERT_EQ(inverseA.matrix[1][1], 1);
}

TEST(Maths, Mat22f_Identity)
{
	maths::Mat22f I = maths::Mat22f::Identity22();

	//Test identity
	ASSERT_EQ(I.matrix[0][0], 1);
	ASSERT_EQ(I.matrix[0][1], 0);
	ASSERT_EQ(I.matrix[1][0], 0);
	ASSERT_EQ(I.matrix[1][1], 1);
}