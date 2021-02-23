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
float Matrix4f::Determinant()
{
	return 0.0f;
}
Matrix4f Matrix4f::Inverse()
{
	return Matrix4f();
}
Matrix4f Matrix4f::Transpose()
{
	return Matrix4f();
}
Matrix4f Matrix4f::Adjoint()
{
	return Matrix4f();
}
bool Matrix4f::IsOrthogonal()
{
	return false;
}
Matrix4f Matrix4f::Identity()
{
	return Matrix4f();
}
Matrix4f Matrix4f::RotationMatrix(radian_t angle, char axis)
{
	return Matrix4f();
}
Matrix4f Matrix4f::ScalingMatrix(Vector3f axisValues)
{
	return Matrix4f();
}
Matrix4f Matrix4f::TranslationMatrix(Vector3f axisValues)
{
	return Matrix4f();
}
	
}//namespace maths