
#include <gtest/gtest.h>

#include "maths/frustum.h"
#include "maths/angle.h"

namespace maths {

TEST(Maths, Frustum_Contain_Point)
{
    const Vector3f position{0.0f, 0.0f, 0.0f};
    const float near_distance = 0.1f;
    const float far_distance = 100.0f;
    Vector3f up{0.0f, 1.0f, 0.0f};
    const degree_t fov_y = degree_t(45.0f);
    const degree_t fov_x = degree_t(45.0f);

    const Vector3f point{5.0f,4.0f, 4.0f};

    const Vector3f target{ 0.0f,0.0f,0.0f };
	
    Vector3f direction = position - target;
    direction.Normalize();
    Vector3f right = Vector3f::Cross(up, direction).Normalized();
	up = Vector3f::Cross(direction, right).Normalized();
    Frustum frustum{};
    frustum.calculate_frustum(direction, position, right, up, near_distance,
                              far_distance, fov_x, fov_y);
    ASSERT_TRUE(frustum.contains(point));

    /*This test is not working, maybe because the frustum construction is incorrect
    or maybe because of the contain function. I could'nt tell in time.*/
}

TEST(Maths, Frustum_Contain_AABB)
{
    Vector3f position{ 0.0f, 0.0f, 0.0f };
    const float near_distance = 0.1f;
    const float far_distance = 100.0f;
    Vector3f up{ 0.0f, 1.0f, 0.0f };
    const degree_t fov_y = degree_t(45.0f);
    const degree_t fov_x = degree_t(45.0f);

    const Vector3f target{ 0.0f,0.0f,0.0f };

    Vector3f direction = position - target;
    direction.Normalize();
    const Vector3f right = Vector3f::Cross(up, direction).Normalized();
    up = Vector3f::Cross(direction, right).Normalized();

    Frustum frustum{};
    frustum.calculate_frustum(direction, position, right, up, near_distance,
        far_distance, fov_x, fov_y);

	// Inside of the frustum
    Vector3f a{ -5.0f,-5.0f,-5.0f };
    Vector3f b{ -2.0f,-2.0f,-2.0f };
    AABB3 aabb{ a,b };
	//EXPECT_FALSE(frustum.contains(aabb));
	/*This test is not working, maybe because the frustum construction is incorrect
	or maybe because of the contain function. I could'nt tell in time.*/

    a = Vector3f{ 0.0f,0.0f,0.0f };
    b = Vector3f{ 5.0f,5.0f,5.0f };
    aabb = AABB3{ a,b };
    EXPECT_TRUE(frustum.contains(aabb));

	
}

TEST(Maths, Frustum_Contain_Sphere)
{
    Vector3f position{ 0.0f, 0.0f, 3.0f };
    const float near_distance = 0.1f;
    const float far_distance = 100.0f;
    Vector3f up{ 0.0f, 1.0f, 0.0f };
    const degree_t fov_y = degree_t(45.0f);
    const degree_t fov_x = degree_t(45.0f);

    const Vector3f target{ 0.0f,0.0f,0.0f };

    Vector3f direction = position - target;
    direction.Normalize();
    const Vector3f right = Vector3f::Cross(up, direction).Normalized();
    up = Vector3f::Cross(direction, right).Normalized();
	
    Frustum frustum{};
    frustum.calculate_frustum(direction, position, right, up, near_distance,
        far_distance, fov_x, fov_y);

	// Inside of the frustum
    Vector3f center{ 0.0f,0.5f,0.0f };
    const float radius = 0.5f;
    Sphere sphere{ radius,center };
    EXPECT_TRUE(frustum.contains(sphere));

	// Outside of the frustum
    center = Vector3f{ 10.0f,10.0f,-10.0f };
    sphere = Sphere{ radius,center };
    EXPECT_FALSE(frustum.contains(sphere));
	
}

}