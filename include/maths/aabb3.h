#pragma once

#include "maths/vector3.h"

namespace maths
{
	struct AABB3D
	{
		maths::Vec3f bottomLeft;
		maths::Vec3f topRight;

		AABB3D() : bottomLeft(), topRight() {}

		AABB3D(maths::Vec3f bottomLeft, maths::Vec3f topRight) : bottomLeft(bottomLeft), topRight(topRight) {}

		maths::Vec3f CalculateCenter() const
		{
			return { (bottomLeft + topRight) / 2.0f };
		}

		maths::Vec3f CalculateExtent() const
		{
			maths::Vec3f getCenter = CalculateCenter();
			return { topRight - getCenter };
		}
	};
}