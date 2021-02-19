#pragma once
#include "maths/aabb3.h"
namespace maths
{
	bool Overlap(const AABB3D& a, const AABB3D& b)
	{
		maths::Vec3f v1 = b.bottomLeft - a.topRight;
		maths::Vec3f v2 = a.bottomLeft - b.topRight;
		
		return !(v1.x > 0 || v2.x > 0 || v1.y > 0 || v2.y > 0 || v1.z > 0 || v2.z > 0);
	}

	bool Contain(const AABB3D& a, const AABB3D& b)
	{
		maths::Vec3f v1 = b.bottomLeft - a.bottomLeft;
		maths::Vec3f v2 = a.topRight - b.topRight;

		return (v1.x > 0 && v1.y > 0 && v1.z > 0 && v2.x > 0 && v2.y > 0 && v2.z > 0);
	}
}