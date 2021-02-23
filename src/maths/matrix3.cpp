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

#include "maths/matrix3.h"
#include "maths/angle.h"
#include "maths/matrix2.h"

namespace maths
{
Matrix3f Matrix3f::operator+(const Matrix3f& rhs) const
{
	return Matrix3f();
}
void Matrix3f::operator+=(const Matrix3f& rhs)
{
}
Matrix3f Matrix3f::operator-(const Matrix3f& rhs) const
{
	return Matrix3f();
}
void Matrix3f::operator-=(const Matrix3f& rhs)
{
}
Matrix3f Matrix3f::operator*(const Matrix3f& rhs) const
{
	return Matrix3f();
}
void Matrix3f::operator*=(const Matrix3f& rhs)
{
}
Vector3f Matrix3f::operator*(const Vector3f& rhs) const
{
	return Vector3f();
}
void Matrix3f::operator*=(const Vector3f& rhs)
{
}
void Matrix3f::operator*=(const float& scalar)
{
	int size = 3;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] *= scalar;
		}
	}
}
float Matrix3f::GetCofactor(const int row, const int column) const
{
	const int size = 3;
	const float sign = (column + row) % 2 == 0 ? 1.0f : -1.0f;
	Matrix2f tmp_mat;
	int k = 0;
	int l = 0;
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(i != column && j != row)
			{
				tmp_mat.matrix[k][l++] = matrix[i][j];

				if(l == size -1)
				{
					l = 0;
					k++;
				}
			}
		}
	}

	const float tmp_det = tmp_mat.Determinant();
	
	return sign * tmp_det;
}
float Matrix3f::Determinant() const
{
	const float det = matrix[0][0] * GetCofactor(0, 0)
					+ matrix[0][1] * GetCofactor(1, 0)
					+ matrix[0][2] * GetCofactor(2, 0);
	
	return det;
}
Matrix3f Matrix3f::Inverse() const
{
	if(IsOrthogonal())
	{
		return Transpose();
	}
	Matrix3f tmp_mat = Adjoint();

	tmp_mat *= (1 / Determinant());
	
	return tmp_mat;
}
Matrix3f Matrix3f::Transpose() const
{
	return Matrix3f(Vector3f(matrix[0][0], matrix[1][0], matrix[2][0]), 
					Vector3f(matrix[0][1], matrix[1][1], matrix[2][1]), 
					Vector3f(matrix[0][2], matrix[1][2], matrix[2][2]));
}
Matrix3f Matrix3f::Adjoint() const
{
	int size = 3;
	Matrix3f tmp_mat;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			tmp_mat.matrix[i][j] = GetCofactor(j, i);
		}
	}
	
	return tmp_mat.Transpose();
}
bool Matrix3f::IsOrthogonal() const
{
	int size = 3;
	int nb_identical_elements = 0;
	Matrix3f mult_mat_tranpose;
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			mult_mat_tranpose.matrix[i][j] = matrix[i][j];
		}
	}

	mult_mat_tranpose *= Transpose();

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(mult_mat_tranpose.matrix[i][j] == Identity().matrix[i][j])
			{
				nb_identical_elements++;
			}
		}
	}
	
	return nb_identical_elements == size * size? true : false;
}
Matrix3f Matrix3f::Identity()
{
	return Matrix3f(Vector3f(1, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1));
}
Matrix3f Matrix3f::RotationMatrix(radian_t angle)
{
	return Matrix3f(Vector3f(cos(angle), -sin(angle), 0),
					Vector3f(sin(angle), cos(angle), 0), 
					Vector3f(0, 0, 1));
}
Matrix3f Matrix3f::ScalingMatrix(Vector2f axisValues)
{
	return Matrix3f(Vector3f(axisValues.x, 0, 0), Vector3f(0, axisValues.y, 0), Vector3f(0, 0, 1));
}
Matrix3f Matrix3f::TranslationMatrix(Vector2f axisValues)
{
	return Matrix3f(Vector3f(1, 0, axisValues.x), Vector3f(0, 1, axisValues.y), Vector3f(0, 0, 1));
}
	
}//namespace maths
