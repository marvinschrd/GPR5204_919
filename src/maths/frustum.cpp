#include "..\..\include\maths\frustum.h"
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

namespace maths {
	
	bool Contains(Frustum& frustum, const Sphere& sphere)
	{
		return false;
	}
	
	bool Contains(Frustum& frustum, const AABB3& aabb)
	{
		return false;
	}
	
	bool Contains(Frustum& frustum, const Vector3f& point)
	{
		return false;
	}
	
	void Frustum::normalize_plane(Plane& plane)
	{
		float distance = sqrtf(plane.a * plane.a + plane.b * plane.b + plane.c * plane.c);
		plane.a /= distance;
		plane.b /= distance;
		plane.c /= distance;
	}

	void Frustum::calcluate_frustum_planes()
	{
		planes_[0].a = viewProjection_.v1.w + viewProjection_.v1.z;
		planes_[0].b = viewProjection_.v2.w + viewProjection_.v2.z;
		planes_[0].c = viewProjection_.v3.w + viewProjection_.v3.z;
		planes_[0].d = viewProjection_.v4.w + viewProjection_.v4.z;
		normalize_plane(planes_[0]);

		planes_[1].a = viewProjection_.v1.w - viewProjection_.v1.z;
		planes_[1].b = viewProjection_.v2.w - viewProjection_.v2.z;
		planes_[1].c = viewProjection_.v3.w - viewProjection_.v3.z;
		planes_[1].d = viewProjection_.v4.w - viewProjection_.v4.z;
		normalize_plane(planes_[1]);

		planes_[2].a = viewProjection_.v1.w + viewProjection_.v1.x;
		planes_[2].b = viewProjection_.v2.w + viewProjection_.v2.x;
		planes_[2].c = viewProjection_.v3.w + viewProjection_.v3.x;
		planes_[2].d = viewProjection_.v4.w + viewProjection_.v4.x;
		normalize_plane(planes_[2]);

		planes_[3].a = viewProjection_.v1.w - viewProjection_.v1.x;
		planes_[3].b = viewProjection_.v2.w - viewProjection_.v2.x;
		planes_[3].c = viewProjection_.v3.w - viewProjection_.v3.x;
		planes_[3].d = viewProjection_.v4.w - viewProjection_.v4.x;
		normalize_plane(planes_[3]);

		planes_[4].a = viewProjection_.v1.w - viewProjection_.v1.y;
		planes_[4].b = viewProjection_.v2.w - viewProjection_.v2.y;
		planes_[4].c = viewProjection_.v3.w - viewProjection_.v3.y;
		planes_[4].d = viewProjection_.v4.w - viewProjection_.v4.y;
		normalize_plane(planes_[4]);

		planes_[5].a = viewProjection_.v1.w + viewProjection_.v1.y;
		planes_[5].b = viewProjection_.v2.w + viewProjection_.v2.y;
		planes_[5].c = viewProjection_.v3.w + viewProjection_.v3.y;
		planes_[5].d = viewProjection_.v4.w + viewProjection_.v4.y;
		normalize_plane(planes_[5]);
	}

} // namespace maths