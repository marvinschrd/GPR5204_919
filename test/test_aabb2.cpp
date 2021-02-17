#include <gtest/gtest.h>

#include "aabb2.h"

TEST(Maths, Aabb2_center)
{
	maths::AABB2D aabb_2d(maths::Vec2f{ 0.0f, 1.0f }, maths::Vec2f{ 1.0f, 2.0f });
	EXPECT_FLOAT_EQ(aabb_2d.CalculateCenter().x, 0.5f);
	EXPECT_FLOAT_EQ(aabb_2d.CalculateCenter().y, 1.5f);
}

TEST(Maths, Aabb2_overlap)
{
	// Test aabb2 à l'interieur de aabb1
	maths::AABB2D aabb1(maths::Vec2f{ 0.0f, 0.0f }, maths::Vec2f{ 1.0f, 1.0f });
	maths::AABB2D aabb2(maths::Vec2f{ 0.1f, 0.1f }, maths::Vec2f{ 0.9f, 0.9f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
	EXPECT_TRUE(Overlap(aabb2, aabb1));

	// Test aabb2 à l'exterieur de aabb1 en positif
	aabb2 = maths::AABB2D(maths::Vec2f{ 1.1f, 1.1f }, maths::Vec2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Overlap(aabb1, aabb2));
	
	// Test aabb2 à l'exterieur de aabb1 en negatif
	aabb2 = maths::AABB2D(maths::Vec2f{ -0.5f, -0.5f }, maths::Vec2f{ -0.1f, -0.1f });
	EXPECT_FALSE(Overlap(aabb1, aabb2));

	// Test angle aabb2 superposé à aabb1 en positif
	aabb2 = maths::AABB2D(maths::Vec2f{ 1.0f, 1.0f }, maths::Vec2f{ 1.5f, 1.5f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Test angle aabb2 superposé à aabb1 en negatif
	aabb2 = maths::AABB2D(maths::Vec2f{ -0.5f, -0.5f }, maths::Vec2f{ -0.0f, -0.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
	
	// Angle bas gauche aabb2 chavauche aabb1
	aabb2 = maths::AABB2D (maths::Vec2f{ 0.5f, 0.5f }, maths::Vec2f{ 1.5f, 1.5f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Angle haut droit chevauche aabb1
	aabb2 = maths::AABB2D (maths::Vec2f{ -0.5f, -0.5f }, maths::Vec2f{ 0.5f, 0.5f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	//Aabb2 traverse aabb1
	aabb2 = maths::AABB2D(maths::Vec2f{ -0.1f, 0.1f }, maths::Vec2f{ 1.1f, 0.9f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Meme aabb -> true ou false?
	aabb2 = maths::AABB2D(maths::Vec2f{ 0.0f, 0.0f }, maths::Vec2f{ 1.0f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
}

TEST(Maths, Aabb2_contain)
{
	// Test aabb2 à l'interieur de aabb1
	maths::AABB2D aabb1(maths::Vec2f{ 0.0f, 0.0f }, maths::Vec2f{ 1.0f, 1.0f });
	maths::AABB2D aabb2(maths::Vec2f{ 0.1f, 0.1f }, maths::Vec2f{ 0.9f, 0.9f });
	EXPECT_TRUE(Contain(aabb1, aabb2));
	EXPECT_FALSE(Contain(aabb2, aabb1));

	// Test aabb2 à l'exterieur de aabb1 en positif
	aabb2 = maths::AABB2D(maths::Vec2f{ 1.1f, 1.1f }, maths::Vec2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Test aabb2 à l'exterieur de aabb1 en negatif
	aabb2 = maths::AABB2D(maths::Vec2f{ -0.5f, -0.5f }, maths::Vec2f{ -0.1f, -0.1f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Test angle aabb2 superposé à aabb1 en positif
	aabb2 = maths::AABB2D(maths::Vec2f{ 1.0f, 1.0f }, maths::Vec2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));
	
	// Test angle aabb2 superposé à aabb1 en negatif
	aabb2 = maths::AABB2D(maths::Vec2f{ -0.5f, -0.5f }, maths::Vec2f{ -0.0f, -0.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Angle bas gauche aabb2 chavauche aabb1
	aabb2 = maths::AABB2D(maths::Vec2f{ 0.5f, 0.5f }, maths::Vec2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Angle haut droit chevauche aabb1
	aabb2 = maths::AABB2D(maths::Vec2f{ -0.5f, -0.5f }, maths::Vec2f{ 0.5f, 0.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	//Aabb2 traverse aabb1
	aabb2 = maths::AABB2D(maths::Vec2f{ -0.1f, 0.1f }, maths::Vec2f{ 1.1f, 0.9f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Meme aabb -> true ou false?
	aabb2 = maths::AABB2D(maths::Vec2f{ 0.0f, 0.0f }, maths::Vec2f{ 1.0f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));
}
