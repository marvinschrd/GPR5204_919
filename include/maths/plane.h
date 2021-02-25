#pragma once
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

#include "maths/vector3.h"
namespace maths
{
	
class Plane {

public:
	Plane() = default;
	Plane(Vector3f& point,Vector3f& normal) : point_(point), normal_(normal) {}
	Plane(Vector3f a, Vector3f b, Vector3f c) : point_(a), normal_(calculate_normal_from_points(a,b,c)) {}

	float distance( const Vector3f& point) const {
		return {Vector3f::Dot(point - point_, normal_) };
	}
	Vector3f calculate_normal_from_points(Vector3f a, Vector3f b, Vector3f c) {
		Vector3f v_a = a - b;
		Vector3f v_b = c - b;
		return { Vector3f::Cross(v_a,v_b).Normalized() };
		
	}
	
	Vector3f point() const { return { point_ }; }
	Vector3f normal() const { return { normal_ }; }
private:
	Vector3f point_;
	Vector3f normal_;
	};

} // namespace maths