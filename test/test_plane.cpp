#include <gtest/gtest.h>

#include "maths/plane.h"
#include "maths/vector3.h"
#include "maths/vector2.h"

namespace maths
{
	TEST(Maths,Plane_Distance)
	{
		// Test Distance
		Vector3f point{ 1.0f,0.0f,0.0f };
		Vector3f plane_point{ 1.0f,1.0f,1.0f };
		Vector3f plane_normal{ 0.0f,1.0f,0.0f };
		Plane plane{ plane_point,plane_normal };

		ASSERT_EQ(plane.Distance(point), -1.0f);
	}

	TEST(Maths,Plane_CalculateNormalFromPoint)
	{
		// Test CalculateNormalFromPoint
		Vector3f a{ 1.0f,1.0f,1.0f };
		Vector3f b{ 2.0f,2.0f,2.0f };
		Vector3f c{ 1.0f,0.0f,1.0f };

		Vector3f v_a = a - b;
		Vector3f v_b = c - b;
		Vector3f t = Vector3f::Cross(v_a, v_b).Normalized();
		Plane plane{};

		Vector3f h = plane.CalculateNormalFromPoints(a, b, c);
		EXPECT_EQ(h.x, t.x);
		EXPECT_EQ(h.y, t.y);
		EXPECT_EQ(h.z, t.z);
	}

} // namespace maths

