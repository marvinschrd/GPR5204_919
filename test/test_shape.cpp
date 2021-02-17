
#include <gtest/gtest.h>

#include <maths/circle.h>
#include <maths/sphere.h>


TEST(Maths, Circle_CalculateArea)
{
	physics::Circle c{ 1.0f,maths::Vec2f{1.0f,2.0f} };
	ASSERT_FLOAT_EQ(c.CalculateArea(), M_PI * (c.radius_ * c.radius_));
}

TEST(Maths, Sphere_CalculateArea)
{
	physics::Sphere s{ 1.0f,maths::Vec3f{1.0f,2.0f,1.0f} };
	ASSERT_FLOAT_EQ(s.CalculateArea(), 4 * M_PI * (s.radius_ * s.radius_));
}

TEST(Maths, Sphere_CalculateVolume)
{
	physics::Sphere s{ 1.0f,maths::Vec3f{1.0f,2.0f,1.0f} };
	ASSERT_FLOAT_EQ(s.CalculateVolume(), 4 / 3 * M_PI * (s.radius_ * s.radius_ * s.radius_));
}