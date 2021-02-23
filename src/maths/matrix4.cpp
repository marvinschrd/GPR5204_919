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

#include "maths/matrix4.h"

#include <cassert>


#include "maths/matrix3.h"

namespace maths
{
Matrix4f Matrix4f::operator+(const Matrix4f& rhs) const
{
	return Matrix4f();
}
void Matrix4f::operator+=(const Matrix4f& rhs)
{
}
Matrix4f Matrix4f::operator-(const Matrix4f& rhs) const
{
	return Matrix4f();
}
void Matrix4f::operator-=(const Matrix4f& rhs)
{
}
Matrix4f Matrix4f::operator*(const Matrix4f& rhs) const
{
	return Matrix4f();
}
void Matrix4f::operator*=(const Matrix4f& rhs)
{
}
Vector4f Matrix4f::operator*(const Vector4f& rhs) const
{
	return Vector4f();
}
void Matrix4f::operator*=(const Vector4f& rhs)
{
}
void Matrix4f::operator*=(const float& scalar)
{
	int size = 4;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] *= scalar;
		}
	}
}
float Matrix4f::GetCofactor(int row, int column) const
{
	const int size = 4;
	const float sign = (column + row) % 2 == 0 ? 1.0f : -1.0f;
	Matrix3f tmp_mat;
	int k = 0;
	int l = 0;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (i != column && j != row)
			{
				tmp_mat.matrix[k][l++] = matrix[i][j];

				if (l == size - 1)
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
float Matrix4f::Determinant() const
{
	const float det = matrix[0][0] * GetCofactor(0, 0)
		+ matrix[0][1] * GetCofactor(1, 0)
		+ matrix[0][2] * GetCofactor(2, 0)
		+ matrix[0][3] * GetCofactor(3, 0);

	return det;
}
Matrix4f Matrix4f::Inverse() const
{
	assert(Determinant() != 0.0f);
	
	if (IsOrthogonal())
	{
		return Transpose();
	}
	Matrix4f tmp_mat = Adjoint();

	tmp_mat *= (1 / Determinant());

	return tmp_mat;
}
Matrix4f Matrix4f::Transpose() const
{
	return Matrix4f(Vector4f(matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0]),
					Vector4f(matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1]),
					Vector4f(matrix[0][2], matrix[1][2], matrix[2][2], matrix[3][2]),
					Vector4f(matrix[0][3], matrix[1][3], matrix[2][3], matrix[3][3]));
}
Matrix4f Matrix4f::Adjoint() const
{
	int size = 4;
	Matrix4f tmp_mat;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			tmp_mat.matrix[i][j] = GetCofactor(j, i);
		}
	}

	return tmp_mat.Transpose();
}
bool Matrix4f::IsOrthogonal() const
{
	int size = 4;
	int nb_identical_elements = 0;
	Matrix4f mult_mat_tranpose;

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
			if (mult_mat_tranpose.matrix[i][j] == Identity().matrix[i][j])
			{
				nb_identical_elements++;
			}
		}
	}

	return nb_identical_elements == size * size ? true : false;
}
Matrix4f Matrix4f::Identity()
{
	return Matrix4f(Vector4f(1, 0, 0, 0), 
					Vector4f(0, 1, 0, 0), 
					Vector4f(0, 0, 1, 0), 
					Vector4f(0, 0, 0, 1));
}
Matrix4f Matrix4f::RotationMatrix(radian_t angle, char axis)
{
	assert(axis == 'x' || axis == 'y' || axis == 'z');
	
	switch(axis)
	{
	case 'x':
		{
			return Matrix4f(Vector4f(0, cos(angle), -sin(angle), 0),
							Vector4f(0, sin(angle), cos(angle), 0),
							Vector4f(0, 1, 0, 0),
							Vector4f(0, 0, 0, 1));
			break;
		}
		
	case 'y':
		{
			return Matrix4f(Vector4f(-sin(angle), 0, cos(angle), 0),
							Vector4f(cos(angle), 0, sin(angle), 0),
							Vector4f(0, 1, 0, 0),
							Vector4f(0, 0, 0, 1));
			break;
		}
		
	case 'z':
		{
			return Matrix4f(Vector4f(cos(angle), -sin(angle), 0, 0),
							Vector4f(sin(angle), cos(angle), 0, 0),
							Vector4f(0, 1, 0, 0),
							Vector4f(0, 0, 0, 1));
			break;
		}
	}
}
Matrix4f Matrix4f::ScalingMatrix(Vector3f axisValues)
{
	return Matrix4f(Vector4f(axisValues.x, 0, 0, 0),
					Vector4f(0, axisValues.y, 0, 0),
					Vector4f(0, 0, axisValues.z, 0),
					Vector4f(0, 0, 0, 1));
}
Matrix4f Matrix4f::TranslationMatrix(Vector3f axisValues)
{
	return Matrix4f(Vector4f(1, 0, 0, axisValues.x),
					Vector4f(0, 1, 0, axisValues.y),
					Vector4f(0, 0, 1, axisValues.z),
					Vector4f(0, 0, 0, 1));
}
	
}//namespace maths