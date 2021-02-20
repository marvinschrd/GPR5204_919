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

#include <gtest/gtest.h>

#include "maths/ray2.h"
#include "maths/ray3.h"
#include "maths/aabb2.h"
#include "maths/aabb3.h"

TEST(Maths, Ray_PointInRay)
{
	maths::Vector2f a{ 1.0f,2.0f };
	maths::Vector2f b{ 2.0f,3.0f };

	maths::Ray2 r{ a,b };
	
	float v = 2.0f;
	
	maths::Vector2f c = r.point_in_ray(v);
	maths::Vector2f d = a + (b * v);
	ASSERT_EQ(r.point_in_ray(v), d);
	
}

TEST(Maths, Ray_Intersect_AABB2)
{
	maths::Vector2f a{ -0.5f,-0.5f };
	maths::Vector2f b{ 0.5f,0.5f };

	maths::AABB2 aabb{ a,b };

	maths::Vector2f origin{ -0.1f,-0.1f };
	maths::Vector2f direction{ 1.0f,1.0f };

	maths::Ray2 ray{ origin,direction };

	// inside intersection
	ASSERT_TRUE(ray.intersect_AABB2(ray.info, aabb));

	// basic intersection
	origin = maths::Vector2f(-1.0f, -1.0f);
	direction = maths::Vector2f(1.0f, 1.0f);
	maths::Ray2 ray2{ origin,direction };
	ASSERT_TRUE(ray2.intersect_AABB2(ray2.info,aabb));
	
	// limit intersection
	origin = maths::Vector2f(-0.5f, -1.5f);
	maths::Ray2 ray3{ origin,direction };
	ASSERT_TRUE(ray3.intersect_AABB2(ray3.info,aabb));

	// no intersection
	origin = maths::Vector2f(-0.5f, -2.0f);
	maths::Ray2 ray4{ origin,direction };
	ASSERT_FALSE(ray4.intersect_AABB2(ray4.info,aabb));

	
}

TEST(Maths, Ray_intercept_ABB3)
{
	maths::Vector3f a{ -0.5f,-0.5f,-0.5f };
	maths::Vector3f b{ 0.5f,0.5f,0.5f };

	maths::AABB3 aabb{ a,b };

	maths::Vector3f origin { -0.1f,-0.1f,-0.1f };
	maths::Vector3f direction{ 1.0f,1.0f,1.0f };
	
	maths::Ray3 ray{ origin,direction};
	// inside intersection
	ASSERT_TRUE(ray.intersect_AABB3(ray.info, aabb));
	
	origin = maths::Vector3f{ -1.0f,-1.0f,-1.0f };
	ray = maths::Ray3{ origin, direction };
	// basic intersection
	ASSERT_TRUE(ray.intersect_AABB3(ray.info, aabb));

	origin = maths::Vector3f{ -0.5f,-1.5f,-1.5f };
	ray = maths::Ray3{ origin, direction };
	// limit intersection
	ASSERT_TRUE(ray.intersect_AABB3(ray.info,aabb));

	origin = maths::Vector3f{ -0.5f, -2.0f, -2.0f };
	ray = maths::Ray3{ origin, direction };
	// no intersection
	ASSERT_FALSE(ray.intersect_AABB3(ray.info, aabb));
}

TEST(Maths, Ray_intersect_Circle)
{
	maths::Vector2f center{ 0.0f,0.0f };
	float radius = 1.0f;

	maths::Circle circle{ radius,center };

	maths::Vector2f origin{ 0.0f,0.0f };
	maths::Vector2f direction{ 1.0f,1.0f };

	maths::Ray2 ray{ origin,direction };
	// inside intersection
	ASSERT_TRUE(ray.intersect_circle(ray.info, circle));
	
	origin = maths::Vector2f{ -1.0f,-1.0f };
	ray = maths::Ray2{ origin,direction };
	// basic intersection
	ASSERT_TRUE(ray.intersect_circle(ray.info, circle));

	origin = maths::Vector2f{ -1.0f,-2.0f };
	ray = maths::Ray2{ origin,direction };
	// limit intersection
	ASSERT_TRUE(ray.intersect_circle(ray.info, circle));

	origin = maths::Vector2f{ -1.0f,-2.5f };
	ray = maths::Ray2{ origin,direction };
	// no intersection
	ASSERT_FALSE(ray.intersect_circle(ray.info, circle));
}

TEST(Maths, Ray_intersect_Sphere)
{
	maths::Vector3f center{ 0.0f,0.0f,0.0f };
	float radius = 1.0f;

	maths::Sphere sphere{ radius,center };

	maths::Vector3f origin{ 0.0f,0.0f,0.0f };
	maths::Vector3f direction{ 1.0f,1.0f,1.0f };

	maths::Ray3 ray{ origin,direction };
	// inside intersection
	ASSERT_TRUE(ray.intersect_sphere(ray.info, sphere));

	origin = maths::Vector3f{ -1.0f,-1.0f,-1.0f };
	ray = maths::Ray3{ origin,direction };
	// basic intersection
	ASSERT_TRUE(ray.intersect_sphere(ray.info, sphere));

	origin = maths::Vector3f{ -1.0f,-1.0f,-2.0f };
	ray = maths::Ray3{ origin,direction };
	// limit intersection
	ASSERT_TRUE(ray.intersect_sphere(ray.info, sphere));

	origin = maths::Vector3f{ -1.0f,-3.0f,-2.0f };
	ray = maths::Ray3{ origin,direction };
	// no intersection
	ASSERT_FALSE(ray.intersect_sphere(ray.info, sphere));
	
}


