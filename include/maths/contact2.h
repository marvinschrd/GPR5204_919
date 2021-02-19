#include "maths/aabb2.h"
namespace maths
{
	bool Overlap(const AABB2D& a, const AABB2D& b)
	{
		maths::Vec2f v1 = b.bottomLeft - a.topRight;
		maths::Vec2f v2 = a.bottomLeft - b.topRight;
		
		return !(v1.x > 0 || v2.x > 0 || v1.y > 0 || v2.y > 0);
	}

	bool Contain(const AABB2D& a, const AABB2D& b)
	{
		maths::Vec2f v1 = b.bottomLeft - a.bottomLeft;
		maths::Vec2f v2 = a.topRight - b.topRight;

		return (v1.x > 0 && v1.y > 0 && v2.x > 0 && v2.y > 0);
	}
}