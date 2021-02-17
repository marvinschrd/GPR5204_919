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

TEST(Maths, Mat33f_Determinant)
{
	const maths::Mat33f a = maths::Mat33f(maths::Vec3f(1, 2, 1), maths::Vec3f(2, 1, 1), maths::Vec3f(1, 1, 2));

	//Test determinant
	ASSERT_EQ(a.Determinant(), -4);
}

TEST(Maths, Mat33f_Inverse)
{
	const maths::Mat33f a = maths::Mat33f(maths::Vec3f(0, 1, -3), maths::Vec3f(-3, -4, 4), maths::Vec3f(-2, -2, 1));

	//Test determinant
	maths::Mat33f tmp_inverse = a.Inverse();
	ASSERT_EQ(tmp_inverse.matrix[0][0], 4);
	ASSERT_EQ(tmp_inverse.matrix[0][1], 5);
	ASSERT_EQ(tmp_inverse.matrix[0][2], -8);
	ASSERT_EQ(tmp_inverse.matrix[1][0], -5);
	ASSERT_EQ(tmp_inverse.matrix[1][1], -6);
	ASSERT_EQ(tmp_inverse.matrix[1][2], 9);
	ASSERT_EQ(tmp_inverse.matrix[2][0], -2);
	ASSERT_EQ(tmp_inverse.matrix[2][1], -2);
	ASSERT_EQ(tmp_inverse.matrix[2][2], 3);	
}

TEST(Maths, Mat33f_IsOrthogonal)
{
	const maths::Mat33f a = maths::Mat33f(maths::Vec3f(0, 1, -3), 
										maths::Vec3f(-3, -4, 4), 
										maths::Vec3f(-2, -2, 1));

	//Test if matrix is orthogonal
	ASSERT_EQ(a.IsOrthogonal(), false);
	ASSERT_EQ(maths::Mat33f::Identity33().IsOrthogonal(), true);
}