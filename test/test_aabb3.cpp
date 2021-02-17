#include <gtest/gtest.h>

#include "aabb3.h"
#include "contact3.h"

TEST(Maths, Aabb3_center)
{
	maths::AABB3D aabb_3d(maths::Vec3f{ 0.0f, 1.0f, 0.0f }, maths::Vec3f{ 1.0f, 2.0f, 1.0f });
	EXPECT_FLOAT_EQ(aabb_3d.CalculateCenter().x, 0.5f);
	EXPECT_FLOAT_EQ(aabb_3d.CalculateCenter().y, 1.5f);
}

TEST(Maths, Aabb3_overlap)
{
	// Test aabb2 à l'interieur de aabb1
	maths::AABB3D aabb1(maths::Vec3f{ 0.0f, 0.0f, 0.0f }, maths::Vec3f{ 1.0f, 1.0f, 1.0f });
	maths::AABB3D aabb2(maths::Vec3f{ 0.1f, 0.1f, 0.0f }, maths::Vec3f{ 0.9f, 0.9f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
	EXPECT_TRUE(Overlap(aabb2, aabb1));

	// Test aabb2 à l'exterieur de aabb1 en positif
	aabb2 = maths::AABB3D(maths::Vec3f{ 1.1f, 1.1f, 0.0f }, maths::Vec3f{ 1.5f, 1.5f, 1.0f });
	EXPECT_FALSE(Overlap(aabb1, aabb2));

	// Test aabb2 à l'exterieur de aabb1 en negatif
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.5f, -0.5f, 0.0f }, maths::Vec3f{ -0.1f, -0.1f, 1.0f });
	EXPECT_FALSE(Overlap(aabb1, aabb2));

	// Test angle aabb2 superposé à aabb1 en positif
	aabb2 = maths::AABB3D(maths::Vec3f{ 1.0f, 1.0f, 0.0f }, maths::Vec3f{ 1.5f, 1.5f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Test angle aabb2 superposé à aabb1 en negatif
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.5f, -0.5f, 0.0f }, maths::Vec3f{ -0.0f, -0.0f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Angle bas gauche aabb2 chavauche aabb1
	aabb2 = maths::AABB3D(maths::Vec3f{ 0.5f, 0.5f, 0.0f }, maths::Vec3f{ 1.5f, 1.5f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Angle haut droit chevauche aabb1
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.5f, -0.5f, 0.0f }, maths::Vec3f{ 0.5f, 0.5f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	//Aabb2 traverse aabb1
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.1f, 0.1f, 0.0f }, maths::Vec3f{ 1.1f, 0.9f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Meme aabb -> true ou false?
	aabb2 = maths::AABB3D(maths::Vec3f{ 0.0f, 0.0f, 0.0f }, maths::Vec3f{ 1.0f, 1.0f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
}

TEST(Maths, Aabb3_contain)
{
	// Test aabb2 à l'interieur de aabb1
	maths::AABB3D aabb1(maths::Vec3f{ 0.0f, 0.0f, 0.0f }, maths::Vec3f{ 1.0f, 1.0f, 1.0f });
	maths::AABB3D aabb2(maths::Vec3f{ 0.1f, 0.1f, 0.1f }, maths::Vec3f{ 0.9f, 0.9f, 0.9f });
	EXPECT_TRUE(Contain(aabb1, aabb2));
	EXPECT_FALSE(Contain(aabb2, aabb1));

	// Test aabb2 à l'exterieur de aabb1 en positif
	aabb2 = maths::AABB3D(maths::Vec3f{ 1.1f, 1.1f, 0.0f }, maths::Vec3f{ 1.5f, 1.5f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Test aabb2 à l'exterieur de aabb1 en negatif
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.5f, -0.5f, 0.0f }, maths::Vec3f{ -0.1f, -0.1f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Test angle aabb2 superposé à aabb1 en positif
	aabb2 = maths::AABB3D(maths::Vec3f{ 1.0f, 1.0f, 0.0f }, maths::Vec3f{ 1.5f, 1.5f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Test angle aabb2 superposé à aabb1 en negatif
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.5f, -0.5f, 0.0f }, maths::Vec3f{ -0.0f, -0.0f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Angle bas gauche aabb2 chavauche aabb1
	aabb2 = maths::AABB3D(maths::Vec3f{ 0.5f, 0.5f, 0.0f }, maths::Vec3f{ 1.5f, 1.5f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Angle haut droit chevauche aabb1
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.5f, -0.5f, 0.0f }, maths::Vec3f{ 0.5f, 0.5f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	//Aabb2 traverse aabb1
	aabb2 = maths::AABB3D(maths::Vec3f{ -0.1f, 0.1f, 0.0f }, maths::Vec3f{ 1.1f, 0.9f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Meme aabb -> true ou false?
	aabb2 = maths::AABB3D(maths::Vec3f{ 0.0f, 0.0f, 0.0f }, maths::Vec3f{ 1.0f, 1.0f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));
}
