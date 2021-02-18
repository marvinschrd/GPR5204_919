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

#include <maths/vector3.h>
#include <maths/circle.h>
#include <maths/sphere.h>
#include <maths/aabb2.h>
#include <maths/aabb3.h>

namespace physics
{
	class Ray2
	{
	public:
		Ray2() {};
		Ray2(maths::Vec2f& a,maths::Vec2f& b) : origin(a), direction(b)
		{
			origin = a;
			direction = b;
			unitDirection = maths::Vec2f{ b.x / b.Magnitude(), b.y / b.Magnitude() };
			//invertedDirectionVec3 = 1 / destinationVec3;
			
		}
		maths::Vec2f Origin() { return origin; }
		maths::Vec2f Direction() { return direction; }
		maths::Vec2f PointInRay(const float value) { return origin + (direction.operator*(value)); }

		 struct HitInfo
		{
			HitInfo()
			{
				reset();
			}

			void reset()
			{
				distance = std::numeric_limits<float>::infinity();
				hit = false;
			}

			maths::Vec2f hitPoint;
			maths::Vec2f hitNormal;
			float distance;
			bool hit;
			
		};

		bool IntersectCircle(HitInfo &info, Circle &circle, float castDistance);
		bool IntersectAABB(HitInfo &info, maths::AABB2D aabb);
	private:
		maths::Vec2f origin;
		maths::Vec2f direction;
		maths::Vec2f unitDirection;
		maths::Vec2f invertedDirectionVec3;
	};

	class Ray3
	{
	public:
		Ray3() {};
		Ray3(maths::Vec3f& a, maths::Vec3f& b) : origin(a), direction(b)
		{
			origin = a;
			direction = b;
			unitDirection = maths::Vec3f{ b.x / b.Magnitude(), b.y / b.Magnitude(), b.z / b.Magnitude() };
			//invertedDirectionVec3 = 1 / destinationVec3;

		}
		maths::Vec3f Origin() { return origin; }
		maths::Vec3f Direction() { return direction; }
		maths::Vec3f PointInRay(const float value) { return origin + (direction.operator*(value)); }

		struct HitInfo
		{
			HitInfo()
			{
				reset();
			}

			void reset()
			{
				distance = std::numeric_limits<float>::infinity();
				hit = false;
			}

			maths::Vec3f hitPoint;
			maths::Vec3f hitNormal;
			float distance;
			bool hit;

		};

		bool IntersectSphere(HitInfo& info, Sphere& sphere, float castDistance);
		bool IntersectAABB3(HitInfo& info, maths::AABB3D aabb);
	private:
		maths::Vec3f unitDirection;
		maths::Vec3f origin;
		maths::Vec3f direction;
		maths::Vec3f invertedDirectionVec3;
		//vec3 unitDirection;
	};
	
}
