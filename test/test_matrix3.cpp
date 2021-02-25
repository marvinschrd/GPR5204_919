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

namespace maths
{
TEST(Maths, Matrix3f_GetCofactor) {
	
	const Matrix3f a = Matrix3f(Vector3f(3, 2, 1),
								Vector3f(1, -2, 2),
								Vector3f(-1, 0, -1));

	//Test cofactor
	EXPECT_EQ(a.GetCofactor(0, 0), 2);
	EXPECT_EQ(a.GetCofactor(0, 1), 2);
	EXPECT_EQ(a.GetCofactor(0, 2), 6);
	EXPECT_EQ(a.GetCofactor(1, 0), -1);
	EXPECT_EQ(a.GetCofactor(1, 1), -2);
	EXPECT_EQ(a.GetCofactor(1, 2), -5);
	EXPECT_EQ(a.GetCofactor(2, 0), -2);
	EXPECT_EQ(a.GetCofactor(2, 1), -2);
	EXPECT_EQ(a.GetCofactor(2, 2), -8);
}

TEST(Maths, Matrix3f_Determinant) {
	
	const Matrix3f a = Matrix3f(Vector3f(1, 2, 1), 
								Vector3f(2, 1, 1),
								Vector3f(1, 1, 2));

	//Test determinant
	EXPECT_EQ(a.Determinant(), -4);
}

TEST(Maths, Matrix3f_Inverse) {
	
	const Matrix3f a = Matrix3f(Vector3f(0, 1, -3),
								Vector3f(-3, -4, 4), 
								Vector3f(-2, -2, 1));

	//Test inverse
	maths::Matrix3f tmp_inverse = a.Inverse();
	
	EXPECT_EQ(tmp_inverse[0][0], 4);
	EXPECT_EQ(tmp_inverse[0][1], 5);
	EXPECT_EQ(tmp_inverse[0][2], -8);
	EXPECT_EQ(tmp_inverse[1][0], -5);
	EXPECT_EQ(tmp_inverse[1][1], -6);
	EXPECT_EQ(tmp_inverse[1][2], 9);
	EXPECT_EQ(tmp_inverse[2][0], -2);
	EXPECT_EQ(tmp_inverse[2][1], -2);
	EXPECT_EQ(tmp_inverse[2][2], 3);
}

TEST(Maths, Matrix3f_Transpose) {
	
	const Matrix3f a = Matrix3f(Vector3f(0, 1, 2),
								Vector3f(3, 4, 5),
								Vector3f(6, 7, 8));;

	//Test transpose
	Matrix3f tmp_transpose = a.Transpose();
	
	EXPECT_EQ(tmp_transpose[0][0], 0);
	EXPECT_EQ(tmp_transpose[0][1], 3);
	EXPECT_EQ(tmp_transpose[0][2], 6);
	EXPECT_EQ(tmp_transpose[1][0], 1);
	EXPECT_EQ(tmp_transpose[1][1], 4);
	EXPECT_EQ(tmp_transpose[1][2], 7);
	EXPECT_EQ(tmp_transpose[2][0], 2);
	EXPECT_EQ(tmp_transpose[2][1], 5);
	EXPECT_EQ(tmp_transpose[2][2], 8);
}

TEST(Maths, Matrix3f_Adjoint) {
	
	const Matrix3f a = Matrix3f(Vector3f(3, 2, 1),
								Vector3f(1, -2, 2),
								Vector3f(-1, 0, -1));

	//Test adjoint
	Matrix3f tmp_adjoint = a.Adjoint();
	
	EXPECT_EQ(tmp_adjoint[0][0], 2);
	EXPECT_EQ(tmp_adjoint[0][1], 2);
	EXPECT_EQ(tmp_adjoint[0][2], 6);
	EXPECT_EQ(tmp_adjoint[1][0], -1);
	EXPECT_EQ(tmp_adjoint[1][1], -2);
	EXPECT_EQ(tmp_adjoint[1][2], -5);
	EXPECT_EQ(tmp_adjoint[2][0], -2);
	EXPECT_EQ(tmp_adjoint[2][1], -2);
	EXPECT_EQ(tmp_adjoint[2][2], -8);
}

TEST(Maths, Matrix3f_IsOrthogonal) {
	
	const Matrix3f a = Matrix3f(Vector3f(0, 1, -3), 
								Vector3f(-3, -4, 4), 
								Vector3f(-2, -2, 1));

	//Test if matrix is orthogonal
	EXPECT_EQ(a.IsOrthogonal(), false);
	EXPECT_EQ(Matrix3f::Identity().IsOrthogonal(), true);
}

TEST(Maths, Matrix3f_Identity) {
	
	const Matrix3f i = Matrix3f::Identity();

	//Test identity
	EXPECT_EQ(i[0][0], 1);
	EXPECT_EQ(i[0][1], 0);
	EXPECT_EQ(i[0][2], 0);
	EXPECT_EQ(i[1][0], 0);
	EXPECT_EQ(i[1][1], 1);
	EXPECT_EQ(i[1][2], 0);
	EXPECT_EQ(i[2][0], 0);
	EXPECT_EQ(i[2][1], 0);
	EXPECT_EQ(i[2][2], 1);
}

TEST(Maths, Matrix3f_RotationMatrix) {
	
	radian_t angle { 0.0f };
	const Matrix3f a = Matrix3f::RotationMatrix(angle);

	//Test rotation matrix
	EXPECT_EQ(a[0][0], 1);
	EXPECT_EQ(a[0][1], 0);
	EXPECT_EQ(a[0][2], 0);
	EXPECT_EQ(a[1][0], 0);
	EXPECT_EQ(a[1][1], 1);
	EXPECT_EQ(a[1][2], 0);
	EXPECT_EQ(a[2][0], 0);
	EXPECT_EQ(a[2][1], 0);
	EXPECT_EQ(a[2][2], 1);
}

TEST(Maths, Matrix3f_ScalingMatrix) {
	
	const Matrix3f a = Matrix3f::ScalingMatrix(Vector2f(1, 1));

	//Test scaling matrix
	EXPECT_EQ(a[0][0], 1);
	EXPECT_EQ(a[0][1], 0);
	EXPECT_EQ(a[0][2], 0);
	EXPECT_EQ(a[1][0], 0);
	EXPECT_EQ(a[1][1], 1);
	EXPECT_EQ(a[1][2], 0);
	EXPECT_EQ(a[2][0], 0);
	EXPECT_EQ(a[2][1], 0);
	EXPECT_EQ(a[2][2], 1);
}

TEST(Maths, Matrix3f_TranslationMatrix) {
	
	const Matrix3f a = Matrix3f::TranslationMatrix(Vector2f(1, 1));

	//Test translation matrix
	EXPECT_EQ(a[0][0], 1);
	EXPECT_EQ(a[0][1], 0);
	EXPECT_EQ(a[0][2], 1);
	EXPECT_EQ(a[1][0], 0);
	EXPECT_EQ(a[1][1], 1);
	EXPECT_EQ(a[1][2], 1);
	EXPECT_EQ(a[2][0], 0);
	EXPECT_EQ(a[2][1], 0);
	EXPECT_EQ(a[2][2], 1);
}

}//naemspace maths