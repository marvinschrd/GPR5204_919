#pragma once

#include "maths/vector2.h"

namespace maths
{
	struct AABB2D
	{
		maths::Vec2f bottomLeft;
		maths::Vec2f topRight;

		AABB2D() : bottomLeft(), topRight() {}

		AABB2D(maths::Vec2f bottomLeft, maths::Vec2f topRight) : bottomLeft(bottomLeft), topRight(topRight) {}

		// Calculate center of the aabb
		maths::Vec2f CalculateCenter() const
		{
			return { (bottomLeft + topRight) / 2.0f };
		}

		maths::Vec2f CalculateExtent() const
		{
			return { topRight - CalculateCenter() };
		}
	};

	bool Overlap(const AABB2D& a, const AABB2D& b);
	bool Contain(const AABB2D& a, const AABB2D& b);
}
