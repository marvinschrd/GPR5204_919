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

#include "maths/matrix4.h"
#include "maths/sphere.h"
#include "maths/aabb3.h"

namespace maths {
	
struct Plane {
	float a;
	float b;
	float c;
	float d;
};
	
class Frustum {
public:
	Frustum() = default;
	Frustum(Matrix4f& viewProjection) : viewProjection_(viewProjection) {}

	void normalize_plane(Plane& plane);
	void calcluate_frustum_planes();

private:
	Matrix4f viewProjection_;
	Plane planes_[6];
};

bool Contains(Frustum &frustum, const Sphere &sphere);
bool Contains(Frustum &frustum, const AABB3 &aabb);
bool Contains(Frustum &frustum, const Vector3f &point);
	
} // namespace maths