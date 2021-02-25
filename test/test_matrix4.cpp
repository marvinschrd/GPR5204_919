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

namespace maths {

TEST(Maths, Matrix4f_Addition)
{
	Matrix4f a = Matrix4f(Vector4f(1, 2, 1, 3), 
						Vector4f(3, 1, 1, 2), 
						Vector4f(1, 1, 1, 2), 
						Vector4f(1, 1, 1, 1));
	Matrix4f b = Matrix4f(Vector4f(3, 2, 1, 2), 
						Vector4f(1, 1, 2, 1), 
						Vector4f(1, 2, 1, 4), 
						Vector4f(1, 1, 1, 1));

	//Test addition (+)
	Matrix4f x = a + b;

	EXPECT_EQ(x[0][0], 4);
	EXPECT_EQ(x[0][1], 4);
	EXPECT_EQ(x[0][2], 2);
	EXPECT_EQ(x[0][3], 5);
	EXPECT_EQ(x[1][0], 4);
	EXPECT_EQ(x[1][1], 2);
	EXPECT_EQ(x[1][2], 3);
	EXPECT_EQ(x[1][3], 3);
	EXPECT_EQ(x[2][0], 2);
	EXPECT_EQ(x[2][1], 3);
	EXPECT_EQ(x[2][2], 2);
	EXPECT_EQ(x[2][3], 6);
	EXPECT_EQ(x[3][0], 2);
	EXPECT_EQ(x[3][1], 2);
	EXPECT_EQ(x[3][2], 2);
	EXPECT_EQ(x[3][3], 2);

	//Test addition (+=)
	a += b;

	EXPECT_EQ(a[0][0], 4);
	EXPECT_EQ(a[0][1], 4);
	EXPECT_EQ(a[0][2], 2);
	EXPECT_EQ(a[0][3], 5);
	EXPECT_EQ(a[1][0], 4);
	EXPECT_EQ(a[1][1], 2);
	EXPECT_EQ(a[1][2], 3);
	EXPECT_EQ(a[1][3], 3);
	EXPECT_EQ(a[2][0], 2);
	EXPECT_EQ(a[2][1], 3);
	EXPECT_EQ(a[2][2], 2);
	EXPECT_EQ(a[2][3], 6);
	EXPECT_EQ(a[3][0], 2);
	EXPECT_EQ(a[3][1], 2);
	EXPECT_EQ(a[3][2], 2);
	EXPECT_EQ(a[3][3], 2);
}

TEST(Maths, Matrix4f_Substraction)
{
	Matrix4f a = Matrix4f(Vector4f(1, 2, 1, 3),
						Vector4f(3, 1, 1, 2),
						Vector4f(1, 1, 1, 2),
						Vector4f(1, 1, 1, 1));
	Matrix4f b = Matrix4f(Vector4f(3, 2, 1, 2),
						Vector4f(1, 1, 2, 1),
						Vector4f(1, 2, 1, 4),
						Vector4f(1, 1, 1, 1));

	//Test substraction (-)
	Matrix4f x = a - b;

	EXPECT_EQ(x[0][0], -2);
	EXPECT_EQ(x[0][1], 0);
	EXPECT_EQ(x[0][2], 0);
	EXPECT_EQ(x[0][3], 1);
	EXPECT_EQ(x[1][0], 2);
	EXPECT_EQ(x[1][1], 0);
	EXPECT_EQ(x[1][2], -1);
	EXPECT_EQ(x[1][3], 1);
	EXPECT_EQ(x[2][0], 0);
	EXPECT_EQ(x[2][1], -1);
	EXPECT_EQ(x[2][2], 0);
	EXPECT_EQ(x[2][3], -2);
	EXPECT_EQ(x[3][0], 0);
	EXPECT_EQ(x[3][1], 0);
	EXPECT_EQ(x[3][2], 0);
	EXPECT_EQ(x[3][3], 0);

	//Test substraction (-=)
	a -= b;

	EXPECT_EQ(a[0][0], -2);
	EXPECT_EQ(a[0][1], 0);
	EXPECT_EQ(a[0][2], 0);
	EXPECT_EQ(a[0][3], 1);
	EXPECT_EQ(a[1][0], 2);
	EXPECT_EQ(a[1][1], 0);
	EXPECT_EQ(a[1][2], -1);
	EXPECT_EQ(a[1][3], 1);
	EXPECT_EQ(a[2][0], 0);
	EXPECT_EQ(a[2][1], -1);
	EXPECT_EQ(a[2][2], 0);
	EXPECT_EQ(a[2][3], -2);
	EXPECT_EQ(a[3][0], 0);
	EXPECT_EQ(a[3][1], 0);
	EXPECT_EQ(a[3][2], 0);
	EXPECT_EQ(a[3][3], 0);
}

TEST(Maths, Matrix4f_Multiplication)
{
	Matrix4f a = Matrix4f(Vector4f(2, 2, 1, 3),
						Vector4f(3, 1, 1, 2),
						Vector4f(1, 1, 1, 2),
						Vector4f(1, 1, 1, 1));
	
	Matrix4f b = Matrix4f(Vector4f(3, 2, 1, 2),
						Vector4f(1, 1, 2, 1),
						Vector4f(1, 2, 1, 4),
						Vector4f(1, 1, 1, 1));

	//Test multiplication (*)
	Matrix4f x = a * b;

	EXPECT_EQ(x[0][0], 15);
	EXPECT_EQ(x[0][1], 11);
	EXPECT_EQ(x[0][2], 8);
	EXPECT_EQ(x[0][3], 18);
	EXPECT_EQ(x[1][0], 8);
	EXPECT_EQ(x[1][1], 6);
	EXPECT_EQ(x[1][2], 5);
	EXPECT_EQ(x[1][3], 11);
	EXPECT_EQ(x[2][0], 13);
	EXPECT_EQ(x[2][1], 9);
	EXPECT_EQ(x[2][2], 8);
	EXPECT_EQ(x[2][3], 14);
	EXPECT_EQ(x[3][0], 7);
	EXPECT_EQ(x[3][1], 5);
	EXPECT_EQ(x[3][2], 4);
	EXPECT_EQ(x[3][3], 9);

	//Test multiplication (*=)
	a *= b;

	EXPECT_EQ(a[0][0], 15);
	EXPECT_EQ(a[0][1], 11);
	EXPECT_EQ(a[0][2], 8);
	EXPECT_EQ(a[0][3], 18);
	EXPECT_EQ(a[1][0], 8);
	EXPECT_EQ(a[1][1], 6);
	EXPECT_EQ(a[1][2], 5);
	EXPECT_EQ(a[1][3], 11);
	EXPECT_EQ(a[2][0], 13);
	EXPECT_EQ(a[2][1], 9);
	EXPECT_EQ(a[2][2], 8);
	EXPECT_EQ(a[2][3], 14);
	EXPECT_EQ(a[3][0], 7);
	EXPECT_EQ(a[3][1], 5);
	EXPECT_EQ(a[3][2], 4);
	EXPECT_EQ(a[3][3], 9);

	//Test multiplication by vector (Matrix2f * Vector2f)
	Vector4f v = Vector4f(1, 2, 1, 2);
	Vector4f c = b * v;

	EXPECT_EQ(c.x, 8);
	EXPECT_EQ(c.y, 8);
	EXPECT_EQ(c.z, 8);
	EXPECT_EQ(c.w, 10);

	//Test multiplication by scalar (Matrix2f *= float)
	b *= 2;

	EXPECT_EQ(b[0][0], 6);
	EXPECT_EQ(b[0][1], 4);
	EXPECT_EQ(b[0][2], 2);
	EXPECT_EQ(b[0][3], 4);
	EXPECT_EQ(b[1][0], 2);
	EXPECT_EQ(b[1][1], 2);
	EXPECT_EQ(b[1][2], 4);
	EXPECT_EQ(b[1][3], 2);
	EXPECT_EQ(b[2][0], 2);
	EXPECT_EQ(b[2][1], 4);
	EXPECT_EQ(b[2][2], 2);
	EXPECT_EQ(b[2][3], 8);
	EXPECT_EQ(b[3][0], 2);
	EXPECT_EQ(b[3][1], 2);
	EXPECT_EQ(b[3][2], 2);
	EXPECT_EQ(b[3][3], 2);
}
TEST(Maths, Matrix4f_GetCofactor) {
	
	const Matrix4f a = Matrix4f(Vector4f(1, 1, 1, -1),
								Vector4f(1, 1, -1, 1),
								Vector4f(1, -1, 1, 1),
								Vector4f(-1, 1, 1, 1));

	//Test cofactor
	EXPECT_EQ(a.cofactor(0, 0), -4);
	EXPECT_EQ(a.cofactor(0, 1), -4);
	EXPECT_EQ(a.cofactor(0, 2), -4);
	EXPECT_EQ(a.cofactor(0, 3), 4);
	EXPECT_EQ(a.cofactor(1, 0), -4);
	EXPECT_EQ(a.cofactor(1, 1), -4);
	EXPECT_EQ(a.cofactor(1, 2), 4);
	EXPECT_EQ(a.cofactor(1, 3), -4);
	EXPECT_EQ(a.cofactor(2, 0), -4);
	EXPECT_EQ(a.cofactor(2, 1), 4);
	EXPECT_EQ(a.cofactor(2, 2), -4);
	EXPECT_EQ(a.cofactor(2, 3), -4);
	EXPECT_EQ(a.cofactor(3, 0), 4);
	EXPECT_EQ(a.cofactor(3, 1), -4);
	EXPECT_EQ(a.cofactor(3, 2), -4);
	EXPECT_EQ(a.cofactor(3, 3), -4);
}
TEST(Maths, Matrix4f_Determinant) {
	
	const Matrix4f a = Matrix4f(Vector4f(1, 1, 1, -1),
								Vector4f(1, 1, -1, 1),
								Vector4f(1, -1, 1, 1),
								Vector4f(-1, 1, 1, 1));

	//Test determinant
	EXPECT_EQ(a.determinant(), -16);
}
TEST(Maths, Matrix4f_Inverse) {
	
	const Matrix4f a = Matrix4f(Vector4f(1, 1, 1, -1),
								Vector4f(1, 1, -1, 1),
								Vector4f(1, -1, 1, 1),
								Vector4f(-1, 1, 1, 1));

	//Test inverse
	Matrix4f tmp_inverse = a.Inverse();
	
	EXPECT_EQ(tmp_inverse[0][0], 0.25f);
	EXPECT_EQ(tmp_inverse[0][1], 0.25f);
	EXPECT_EQ(tmp_inverse[0][2], 0.25f);
	EXPECT_EQ(tmp_inverse[0][3], -0.25f);
	EXPECT_EQ(tmp_inverse[1][0], 0.25f);
	EXPECT_EQ(tmp_inverse[1][1], 0.25f);
	EXPECT_EQ(tmp_inverse[1][2], -0.25f);
	EXPECT_EQ(tmp_inverse[1][3], 0.25f);
	EXPECT_EQ(tmp_inverse[2][0], 0.25f);
	EXPECT_EQ(tmp_inverse[2][1], -0.25f);
	EXPECT_EQ(tmp_inverse[2][2], 0.25f);
	EXPECT_EQ(tmp_inverse[2][3], 0.25f);
	EXPECT_EQ(tmp_inverse[3][0], -0.25f);
	EXPECT_EQ(tmp_inverse[3][1], 0.25f);
	EXPECT_EQ(tmp_inverse[3][2], 0.25f);
	EXPECT_EQ(tmp_inverse[3][3], 0.25f);
}
TEST(Maths, Matrix4f_Transpose) {
	
	const Matrix4f a = Matrix4f(Vector4f(0, 1, 2, 3),
								Vector4f(4, 5, 6, 7),
								Vector4f(8, 9, 10, 11),
								Vector4f(12, 13, 14, 15));

	//Test transpose
	Matrix4f tmp_transpose = a.Transpose();

	EXPECT_EQ(tmp_transpose[0][0], 0);
	EXPECT_EQ(tmp_transpose[0][1], 4);
	EXPECT_EQ(tmp_transpose[0][2], 8);
	EXPECT_EQ(tmp_transpose[0][3], 12);
	EXPECT_EQ(tmp_transpose[1][0], 1);
	EXPECT_EQ(tmp_transpose[1][1], 5);
	EXPECT_EQ(tmp_transpose[1][2], 9);
	EXPECT_EQ(tmp_transpose[1][3], 13);
	EXPECT_EQ(tmp_transpose[2][0], 2);
	EXPECT_EQ(tmp_transpose[2][1], 6);
	EXPECT_EQ(tmp_transpose[2][2], 10);
	EXPECT_EQ(tmp_transpose[2][3], 14);
	EXPECT_EQ(tmp_transpose[3][0], 3);
	EXPECT_EQ(tmp_transpose[3][1], 7);
	EXPECT_EQ(tmp_transpose[3][2], 11);
	EXPECT_EQ(tmp_transpose[3][3], 15);
}
TEST(Maths, Matrix4f_Adjoint)
{
	const Matrix4f a = Matrix4f(Vector4f(1, 1, 1, -1),
								Vector4f(1, 1, -1, 1),
								Vector4f(1, -1, 1, 1),
								Vector4f(-1, 1, 1, 1));

	//Test adjoint
	Matrix4f tmp_adjoint = a.adjoint();
	
	EXPECT_EQ(tmp_adjoint[0][0], -4);
	EXPECT_EQ(tmp_adjoint[0][1], -4);
	EXPECT_EQ(tmp_adjoint[0][2], -4);
	EXPECT_EQ(tmp_adjoint[0][3], 4);
	EXPECT_EQ(tmp_adjoint[1][0], -4);
	EXPECT_EQ(tmp_adjoint[1][1], -4);
	EXPECT_EQ(tmp_adjoint[1][2], 4);
	EXPECT_EQ(tmp_adjoint[1][3], -4);
	EXPECT_EQ(tmp_adjoint[2][0], -4);
	EXPECT_EQ(tmp_adjoint[2][1], 4);
	EXPECT_EQ(tmp_adjoint[2][2], -4);
	EXPECT_EQ(tmp_adjoint[2][3], -4);
	EXPECT_EQ(tmp_adjoint[3][0], 4);
	EXPECT_EQ(tmp_adjoint[3][1], -4);
	EXPECT_EQ(tmp_adjoint[3][2], -4);
	EXPECT_EQ(tmp_adjoint[3][3], -4);
}
TEST(Maths, Matrix4f_IsOrthogonal) {
	
	const Matrix4f a = Matrix4f(Vector4f(0, 1, 2, 3),
								Vector4f(4, 5, 6, 7),
								Vector4f(8, 9, 10, 11),
								Vector4f(12, 13, 14, 15));

	//Test if matrix is orthogonal
	EXPECT_EQ(a.IsOrthogonal(), false);
	EXPECT_EQ(Matrix4f::identity().IsOrthogonal(), true);
}
TEST(Maths, Matrix4f_Identity) {
	
	const Matrix4f i = Matrix4f::identity();

	//Test identity
	EXPECT_EQ(i[0][0], 1);
	EXPECT_EQ(i[0][1], 0);
	EXPECT_EQ(i[0][2], 0);
	EXPECT_EQ(i[0][3], 0);
	EXPECT_EQ(i[1][0], 0);
	EXPECT_EQ(i[1][1], 1);
	EXPECT_EQ(i[1][2], 0);
	EXPECT_EQ(i[1][3], 0);
	EXPECT_EQ(i[2][0], 0);
	EXPECT_EQ(i[2][1], 0);
	EXPECT_EQ(i[2][2], 1);
	EXPECT_EQ(i[2][3], 0);
	EXPECT_EQ(i[3][0], 0);
	EXPECT_EQ(i[3][1], 0);
	EXPECT_EQ(i[3][2], 0);
	EXPECT_EQ(i[3][3], 1);
}
TEST(Maths, Matrix4f_RotationMatrix) {
	
	radian_t angle{ 0.0f };

	//Test rotation matrix on x axis
	const Matrix4f a_x = Matrix4f::rotationMatrix(angle, 'x');
	
	EXPECT_EQ(a_x[0][0], 0);
	EXPECT_EQ(a_x[0][1], 1);
	EXPECT_EQ(a_x[0][2], 0);
	EXPECT_EQ(a_x[0][3], 0);
	EXPECT_EQ(a_x[1][0], 0);
	EXPECT_EQ(a_x[1][1], 0);
	EXPECT_EQ(a_x[1][2], 1);
	EXPECT_EQ(a_x[1][3], 0);
	EXPECT_EQ(a_x[2][0], 0);
	EXPECT_EQ(a_x[2][1], 1);
	EXPECT_EQ(a_x[2][2], 0);
	EXPECT_EQ(a_x[2][3], 0);
	EXPECT_EQ(a_x[3][0], 0);
	EXPECT_EQ(a_x[3][1], 0);
	EXPECT_EQ(a_x[3][2], 0);
	EXPECT_EQ(a_x[3][3], 1);

	//Test rotation matrix on y axis
	const Matrix4f a_y = Matrix4f::rotationMatrix(angle, 'y');

	EXPECT_EQ(a_y[0][0], 0);
	EXPECT_EQ(a_y[0][1], 0);
	EXPECT_EQ(a_y[0][2], 1);
	EXPECT_EQ(a_y[0][3], 0);
	EXPECT_EQ(a_y[1][0], 1);
	EXPECT_EQ(a_y[1][1], 0);
	EXPECT_EQ(a_y[1][2], 0);
	EXPECT_EQ(a_y[1][3], 0);
	EXPECT_EQ(a_y[2][0], 0);
	EXPECT_EQ(a_y[2][1], 1);
	EXPECT_EQ(a_y[2][2], 0);
	EXPECT_EQ(a_y[2][3], 0);
	EXPECT_EQ(a_y[3][0], 0);
	EXPECT_EQ(a_y[3][1], 0);
	EXPECT_EQ(a_y[3][2], 0);
	EXPECT_EQ(a_y[3][3], 1);

	//Test rotation matrix on z axis
	const Matrix4f a_z = Matrix4f::rotationMatrix(angle, 'z');

	EXPECT_EQ(a_z[0][0], 1);
	EXPECT_EQ(a_z[0][1], 0);
	EXPECT_EQ(a_z[0][2], 0);
	EXPECT_EQ(a_z[0][3], 0);
	EXPECT_EQ(a_z[1][0], 0);
	EXPECT_EQ(a_z[1][1], 1);
	EXPECT_EQ(a_z[1][2], 0);
	EXPECT_EQ(a_z[1][3], 0);
	EXPECT_EQ(a_z[2][0], 0);
	EXPECT_EQ(a_z[2][1], 1);
	EXPECT_EQ(a_z[2][2], 0);
	EXPECT_EQ(a_z[2][3], 0);
	EXPECT_EQ(a_z[3][0], 0);
	EXPECT_EQ(a_z[3][1], 0);
	EXPECT_EQ(a_z[3][2], 0);
	EXPECT_EQ(a_z[3][3], 1);
}
TEST(Maths, Matrix4f_ScalingMatrix) {
	
	const Matrix4f a = Matrix4f::scalingMatrix(Vector3f(1, 1, 1));

	//Test scaling matrix
	EXPECT_EQ(a[0][0], 1);
	EXPECT_EQ(a[0][1], 0);
	EXPECT_EQ(a[0][2], 0);
	EXPECT_EQ(a[0][3], 0);
	EXPECT_EQ(a[1][0], 0);
	EXPECT_EQ(a[1][1], 1);
	EXPECT_EQ(a[1][2], 0);
	EXPECT_EQ(a[1][3], 0);
	EXPECT_EQ(a[2][0], 0);
	EXPECT_EQ(a[2][1], 0);
	EXPECT_EQ(a[2][2], 1);
	EXPECT_EQ(a[2][3], 0);
	EXPECT_EQ(a[3][0], 0);
	EXPECT_EQ(a[3][1], 0);
	EXPECT_EQ(a[3][2], 0);
	EXPECT_EQ(a[3][3], 1);
}
TEST(Maths, Matrix4f_TranslationMatrix) {
	
	const Matrix4f a = Matrix4f::translationMatrix(Vector3f(1, 1, 1));

	//Test translation matrix
	EXPECT_EQ(a[0][0], 1);
	EXPECT_EQ(a[0][1], 0);
	EXPECT_EQ(a[0][2], 0);
	EXPECT_EQ(a[0][3], 1);
	EXPECT_EQ(a[1][0], 0);
	EXPECT_EQ(a[1][1], 1);
	EXPECT_EQ(a[1][2], 0);
	EXPECT_EQ(a[1][3], 1);
	EXPECT_EQ(a[2][0], 0);
	EXPECT_EQ(a[2][1], 0);
	EXPECT_EQ(a[2][2], 1);
	EXPECT_EQ(a[2][3], 1);
	EXPECT_EQ(a[3][0], 0);
	EXPECT_EQ(a[3][1], 0);
	EXPECT_EQ(a[3][2], 0);
	EXPECT_EQ(a[3][3], 1);
}

}//namespace maths