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

TEST(Maths, Matrix4f_GetCofactor)
{
	const maths::Matrix4f a = maths::Matrix4f(maths::Vector4f(1, 1, 1, -1),
		maths::Vector4f(1, 1, -1, 1),
		maths::Vector4f(1, -1, 1, 1),
		maths::Vector4f(-1, 1, 1, 1));

	//Test cofactor
	EXPECT_EQ(a.GetCofactor(0, 0), -4);
	EXPECT_EQ(a.GetCofactor(0, 1), -4);
	EXPECT_EQ(a.GetCofactor(0, 2), -4);
	EXPECT_EQ(a.GetCofactor(0, 3), 4);
	EXPECT_EQ(a.GetCofactor(1, 0), -4);
	EXPECT_EQ(a.GetCofactor(1, 1), -4);
	EXPECT_EQ(a.GetCofactor(1, 2), 4);
	EXPECT_EQ(a.GetCofactor(1, 3), -4);
	EXPECT_EQ(a.GetCofactor(2, 0), -4);
	EXPECT_EQ(a.GetCofactor(2, 1), 4);
	EXPECT_EQ(a.GetCofactor(2, 2), -4);
	EXPECT_EQ(a.GetCofactor(2, 3), -4);
	EXPECT_EQ(a.GetCofactor(3, 0), 4);
	EXPECT_EQ(a.GetCofactor(3, 1), -4);
	EXPECT_EQ(a.GetCofactor(3, 2), -4);
	EXPECT_EQ(a.GetCofactor(3, 3), -4);
}

TEST(Maths, Matrix4f_Determinant)
{
	const maths::Matrix4f a = maths::Matrix4f(maths::Vector4f(1, 1, 1, -1),
											maths::Vector4f(1, 1, -1, 1),
											maths::Vector4f(1, -1, 1, 1),
											maths::Vector4f(-1, 1, 1, 1));

	//Test determinant
	EXPECT_EQ(a.Determinant(), -16);
}

TEST(Maths, Matrix4f_Inverse)
{
	const maths::Matrix4f a = maths::Matrix4f(maths::Vector4f(1, 1, 1, -1),
											maths::Vector4f(1, 1, -1, 1),
											maths::Vector4f(1, -1, 1, 1),
											maths::Vector4f(-1, 1, 1, 1));

	//Test inverse
	maths::Matrix4f tmp_inverse = a.Inverse();
	
	EXPECT_EQ(tmp_inverse.matrix[0][0], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[0][1], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[0][2], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[0][3], -0.25f);
	EXPECT_EQ(tmp_inverse.matrix[1][0], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[1][1], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[1][2], -0.25f);
	EXPECT_EQ(tmp_inverse.matrix[1][3], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[2][0], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[2][1], -0.25f);
	EXPECT_EQ(tmp_inverse.matrix[2][2], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[2][3], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[3][0], -0.25f);
	EXPECT_EQ(tmp_inverse.matrix[3][1], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[3][2], 0.25f);
	EXPECT_EQ(tmp_inverse.matrix[3][3], 0.25f);
}

TEST(Maths, Matrix4f_Transpose)
{
	const maths::Matrix4f a = maths::Matrix4f(maths::Vector4f(0, 1, 2, 3),
											maths::Vector4f(4, 5, 6, 7),
											maths::Vector4f(8, 9, 10, 11),
											maths::Vector4f(12, 13, 14, 15));;

	//Test transpose
	maths::Matrix4f tmp_transpose = a.Transpose();

	EXPECT_EQ(tmp_transpose.matrix[0][0], 0);
	EXPECT_EQ(tmp_transpose.matrix[0][1], 4);
	EXPECT_EQ(tmp_transpose.matrix[0][2], 8);
	EXPECT_EQ(tmp_transpose.matrix[0][3], 12);
	EXPECT_EQ(tmp_transpose.matrix[1][0], 1);
	EXPECT_EQ(tmp_transpose.matrix[1][1], 5);
	EXPECT_EQ(tmp_transpose.matrix[1][2], 9);
	EXPECT_EQ(tmp_transpose.matrix[1][3], 13);
	EXPECT_EQ(tmp_transpose.matrix[2][0], 2);
	EXPECT_EQ(tmp_transpose.matrix[2][1], 6);
	EXPECT_EQ(tmp_transpose.matrix[2][2], 10);
	EXPECT_EQ(tmp_transpose.matrix[2][3], 14);
	EXPECT_EQ(tmp_transpose.matrix[3][0], 3);
	EXPECT_EQ(tmp_transpose.matrix[3][1], 7);
	EXPECT_EQ(tmp_transpose.matrix[3][2], 11);
	EXPECT_EQ(tmp_transpose.matrix[3][3], 15);
}

TEST(Maths, Matrix4f_Adjoint)
{
	const maths::Matrix4f a = maths::Matrix4f(maths::Vector4f(1, 1, 1, -1),
		maths::Vector4f(1, 1, -1, 1),
		maths::Vector4f(1, -1, 1, 1),
		maths::Vector4f(-1, 1, 1, 1));

	//Test adjoint
	maths::Matrix4f tmp_adjoint = a.Adjoint();
	
	EXPECT_EQ(tmp_adjoint.matrix[0][0], -4);
	EXPECT_EQ(tmp_adjoint.matrix[0][1], -4);
	EXPECT_EQ(tmp_adjoint.matrix[0][2], -4);
	EXPECT_EQ(tmp_adjoint.matrix[0][3], 4);
	EXPECT_EQ(tmp_adjoint.matrix[1][0], -4);
	EXPECT_EQ(tmp_adjoint.matrix[1][1], -4);
	EXPECT_EQ(tmp_adjoint.matrix[1][2], 4);
	EXPECT_EQ(tmp_adjoint.matrix[1][3], -4);
	EXPECT_EQ(tmp_adjoint.matrix[2][0], -4);
	EXPECT_EQ(tmp_adjoint.matrix[2][1], 4);
	EXPECT_EQ(tmp_adjoint.matrix[2][2], -4);
	EXPECT_EQ(tmp_adjoint.matrix[2][3], -4);
	EXPECT_EQ(tmp_adjoint.matrix[3][0], 4);
	EXPECT_EQ(tmp_adjoint.matrix[3][1], -4);
	EXPECT_EQ(tmp_adjoint.matrix[3][2], -4);
	EXPECT_EQ(tmp_adjoint.matrix[3][3], -4);
}

TEST(Maths, Matrix4f_IsOrthogonal)
{
	const maths::Matrix4f a = maths::Matrix4f(maths::Vector4f(1, 1, 1, -1),
		maths::Vector4f(1, 1, -1, 1),
		maths::Vector4f(1, -1, 1, 1),
		maths::Vector4f(-1, 1, 1, 1));

	//Test if matrix is orthogonal
	EXPECT_EQ(a.IsOrthogonal(), false);
	EXPECT_EQ(maths::Matrix4f::Identity().IsOrthogonal(), true);
}

TEST(Maths, Matrix4f_Identity)
{
	const maths::Matrix4f i = maths::Matrix4f::Identity();

	//Test identity
	EXPECT_EQ(i.matrix[0][0], 1);
	EXPECT_EQ(i.matrix[0][1], 0);
	EXPECT_EQ(i.matrix[0][2], 0);
	EXPECT_EQ(i.matrix[0][3], 0);
	EXPECT_EQ(i.matrix[1][0], 0);
	EXPECT_EQ(i.matrix[1][1], 1);
	EXPECT_EQ(i.matrix[1][2], 0);
	EXPECT_EQ(i.matrix[1][3], 0);
	EXPECT_EQ(i.matrix[2][0], 0);
	EXPECT_EQ(i.matrix[2][1], 0);
	EXPECT_EQ(i.matrix[2][2], 1);
	EXPECT_EQ(i.matrix[2][3], 0);
	EXPECT_EQ(i.matrix[3][0], 0);
	EXPECT_EQ(i.matrix[3][1], 0);
	EXPECT_EQ(i.matrix[3][2], 0);
	EXPECT_EQ(i.matrix[3][3], 1);
}

TEST(Maths, Matrix4f_RotationMatrix)
{
	maths::radian_t angle{ 0.0f };

	//Test rotation matrix on x axis
	const maths::Matrix4f a_x = maths::Matrix4f::RotationMatrix(angle, 'x');
	
	EXPECT_EQ(a_x.matrix[0][0], 0);
	EXPECT_EQ(a_x.matrix[0][1], 1);
	EXPECT_EQ(a_x.matrix[0][2], 0);
	EXPECT_EQ(a_x.matrix[0][3], 0);
	EXPECT_EQ(a_x.matrix[1][0], 0);
	EXPECT_EQ(a_x.matrix[1][1], 0);
	EXPECT_EQ(a_x.matrix[1][2], 1);
	EXPECT_EQ(a_x.matrix[1][3], 0);
	EXPECT_EQ(a_x.matrix[2][0], 0);
	EXPECT_EQ(a_x.matrix[2][1], 1);
	EXPECT_EQ(a_x.matrix[2][2], 0);
	EXPECT_EQ(a_x.matrix[2][3], 0);
	EXPECT_EQ(a_x.matrix[3][0], 0);
	EXPECT_EQ(a_x.matrix[3][1], 0);
	EXPECT_EQ(a_x.matrix[3][2], 0);
	EXPECT_EQ(a_x.matrix[3][3], 1);

	//Test rotation matrix on y axis
	const maths::Matrix4f a_y = maths::Matrix4f::RotationMatrix(angle, 'y');

	EXPECT_EQ(a_y.matrix[0][0], 0);
	EXPECT_EQ(a_y.matrix[0][1], 0);
	EXPECT_EQ(a_y.matrix[0][2], 1);
	EXPECT_EQ(a_y.matrix[0][3], 0);
	EXPECT_EQ(a_y.matrix[1][0], 1);
	EXPECT_EQ(a_y.matrix[1][1], 0);
	EXPECT_EQ(a_y.matrix[1][2], 0);
	EXPECT_EQ(a_y.matrix[1][3], 0);
	EXPECT_EQ(a_y.matrix[2][0], 0);
	EXPECT_EQ(a_y.matrix[2][1], 1);
	EXPECT_EQ(a_y.matrix[2][2], 0);
	EXPECT_EQ(a_y.matrix[2][3], 0);
	EXPECT_EQ(a_y.matrix[3][0], 0);
	EXPECT_EQ(a_y.matrix[3][1], 0);
	EXPECT_EQ(a_y.matrix[3][2], 0);
	EXPECT_EQ(a_y.matrix[3][3], 1);

	//Test rotation matrix on y axis
	const maths::Matrix4f a_z = maths::Matrix4f::RotationMatrix(angle, 'z');

	EXPECT_EQ(a_z.matrix[0][0], 1);
	EXPECT_EQ(a_z.matrix[0][1], 0);
	EXPECT_EQ(a_z.matrix[0][2], 0);
	EXPECT_EQ(a_z.matrix[0][3], 0);
	EXPECT_EQ(a_z.matrix[1][0], 0);
	EXPECT_EQ(a_z.matrix[1][1], 1);
	EXPECT_EQ(a_z.matrix[1][2], 0);
	EXPECT_EQ(a_z.matrix[1][3], 0);
	EXPECT_EQ(a_z.matrix[2][0], 0);
	EXPECT_EQ(a_z.matrix[2][1], 1);
	EXPECT_EQ(a_z.matrix[2][2], 0);
	EXPECT_EQ(a_z.matrix[2][3], 0);
	EXPECT_EQ(a_z.matrix[3][0], 0);
	EXPECT_EQ(a_z.matrix[3][1], 0);
	EXPECT_EQ(a_z.matrix[3][2], 0);
	EXPECT_EQ(a_z.matrix[3][3], 1);
}

TEST(Maths, Matrix4f_ScalingMatrix)
{
	const maths::Matrix4f a = maths::Matrix4f::ScalingMatrix(maths::Vector3f(1, 1, 1));

	//Test scaling matrix
	EXPECT_EQ(a.matrix[0][0], 1);
	EXPECT_EQ(a.matrix[0][1], 0);
	EXPECT_EQ(a.matrix[0][2], 0);
	EXPECT_EQ(a.matrix[0][3], 0);
	EXPECT_EQ(a.matrix[1][0], 0);
	EXPECT_EQ(a.matrix[1][1], 1);
	EXPECT_EQ(a.matrix[1][2], 0);
	EXPECT_EQ(a.matrix[1][3], 0);
	EXPECT_EQ(a.matrix[2][0], 0);
	EXPECT_EQ(a.matrix[2][1], 0);
	EXPECT_EQ(a.matrix[2][2], 1);
	EXPECT_EQ(a.matrix[2][3], 0);
	EXPECT_EQ(a.matrix[3][0], 0);
	EXPECT_EQ(a.matrix[3][1], 0);
	EXPECT_EQ(a.matrix[3][2], 0);
	EXPECT_EQ(a.matrix[3][3], 1);
}

TEST(Maths, Matrix4f_TranslationMatrix)
{
	const maths::Matrix4f a = maths::Matrix4f::TranslationMatrix(maths::Vector3f(1, 1, 1));

	//Test translation matrix
	EXPECT_EQ(a.matrix[0][0], 1);
	EXPECT_EQ(a.matrix[0][1], 0);
	EXPECT_EQ(a.matrix[0][2], 0);
	EXPECT_EQ(a.matrix[0][3], 1);
	EXPECT_EQ(a.matrix[1][0], 0);
	EXPECT_EQ(a.matrix[1][1], 1);
	EXPECT_EQ(a.matrix[1][2], 0);
	EXPECT_EQ(a.matrix[1][3], 1);
	EXPECT_EQ(a.matrix[2][0], 0);
	EXPECT_EQ(a.matrix[2][1], 0);
	EXPECT_EQ(a.matrix[2][2], 1);
	EXPECT_EQ(a.matrix[2][3], 1);
	EXPECT_EQ(a.matrix[3][0], 0);
	EXPECT_EQ(a.matrix[3][1], 0);
	EXPECT_EQ(a.matrix[3][2], 0);
	EXPECT_EQ(a.matrix[3][3], 1);
}
