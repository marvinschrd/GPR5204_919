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
#include "maths/ray2.h"

bool maths::Ray2::intersect_circle(HitInfo &info, Circle &circle, float castDistance)
{
	Vector2f v = circle.center() - origin();
	float d = v.Dot(direction());
	if(d<0)
	{
		return false;
	}

	float squaredDistance = v.Dot(v) - (d * d);
	float radius2 = circle.radius() * circle.radius();
	if(squaredDistance > radius2)
	{
		return false;
	}

	auto q = std::sqrt(radius2 - squaredDistance);

	auto t0 = d + q;
	auto t1 = d - q;

	bool hasHit = false;
	float dis;
	if (t0 >= 0 && t0 < castDistance) {
		dis = t0;
		hasHit = true;
	}

	if (t1 >= 0 && t1 < castDistance) {
		if (!hasHit || t1 < dis) {
			dis = t1;
			hasHit = true;
		}
	}

	if (!hasHit) {
		return false;
	}

	auto pt = origin()+ direction() * dis;
	info.hit = true;
	info.hitPoint = pt;
	info.distance = dis;
	
	return true;
}

bool maths::Ray2::intersect_AABB2(HitInfo &info, maths::AABB2 aabb)
{
	maths::Vector2f lb = aabb.bottom_left();
	maths::Vector2f rt = aabb.top_right();
	maths::Vector2f dirfrac;

	dirfrac.x = 1.0f / unit_direction_.x;
	dirfrac.y = 1.0f / unit_direction_.y;
	
	// lb is the corner of AABB with minimal coordinates - left bottom, rt is maximal corner
	
	float t1 = (lb.x - origin().x) * dirfrac.x;
	float t2 = (rt.x - origin().x) * dirfrac.x;
	float t3 = (lb.y - origin().y) * dirfrac.y;
	float t4 = (rt.y - origin().y) * dirfrac.y;

	float tmin = std::max(std::min(t1, t2), std::min(t3, t4));
	float tmax = std::min(std::max(t1, t2), std::max(t3, t4));

	// if tmax < 0, ray (line) is intersecting AABB, but the whole AABB is behind us
	if (tmax < 0)
	{
		info.distance = tmax;
		return false;
	}

	// if tmin > tmax, ray doesn't intersect AABB
	if (tmin > tmax)
	{
		info.distance = tmax;
		return false;
	}

	info.distance = tmin;
	info.hitPoint = origin() + direction() * info.distance;
	return true;
}



