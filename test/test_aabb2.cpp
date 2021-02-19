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
#include "maths/aabb2.h"

TEST(Maths, Aabb2_center)
{
	maths::AABB2 aabb_2d(maths::Vector2f{ 0.0f, 1.0f }, maths::Vector2f{ 1.0f, 2.0f });
	EXPECT_FLOAT_EQ(aabb_2d.center().x, 0.5f);
	EXPECT_FLOAT_EQ(aabb_2d.center().y, 1.5f);
}

TEST(Maths, Aabb2_overlap)
{
	// Test aabb2 � l'interieur de aabb1
	maths::AABB2 aabb1(maths::Vector2f{ 0.0f, 0.0f }, maths::Vector2f{ 1.0f, 1.0f });
	maths::AABB2 aabb2(maths::Vector2f{ 0.1f, 0.1f }, maths::Vector2f{ 0.9f, 0.9f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
	EXPECT_TRUE(Overlap(aabb2, aabb1));

	// Test aabb2 � l'exterieur de aabb1 en positif
	aabb2 = maths::AABB2(maths::Vector2f{ 1.1f, 1.1f }, maths::Vector2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Overlap(aabb1, aabb2));
	
	// Test aabb2 � l'exterieur de aabb1 en negatif
	aabb2 = maths::AABB2(maths::Vector2f{ -0.5f, -0.5f }, maths::Vector2f{ -0.1f, -0.1f });
	EXPECT_FALSE(Overlap(aabb1, aabb2));

	// Test angle aabb2 superpos� � aabb1 en positif
	aabb2 = maths::AABB2(maths::Vector2f{ 1.0f, 1.0f }, maths::Vector2f{ 1.5f, 1.5f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Test angle aabb2 superpos� � aabb1 en negatif
	aabb2 = maths::AABB2(maths::Vector2f{ -0.5f, -0.5f }, maths::Vector2f{ -0.0f, -0.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
	
	// Angle bas gauche aabb2 chavauche aabb1
	aabb2 = maths::AABB2 (maths::Vector2f{ 0.5f, 0.5f }, maths::Vector2f{ 1.5f, 1.5f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Angle haut droit chevauche aabb1
	aabb2 = maths::AABB2 (maths::Vector2f{ -0.5f, -0.5f }, maths::Vector2f{ 0.5f, 0.5f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	//Aabb2 traverse aabb1
	aabb2 = maths::AABB2(maths::Vector2f{ -0.1f, 0.1f }, maths::Vector2f{ 1.1f, 0.9f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));

	// Meme aabb -> true ou false?
	aabb2 = maths::AABB2(maths::Vector2f{ 0.0f, 0.0f }, maths::Vector2f{ 1.0f, 1.0f });
	EXPECT_TRUE(Overlap(aabb1, aabb2));
}

TEST(Maths, Aabb2_contain)
{
	// Test aabb2 � l'interieur de aabb1
	maths::AABB2 aabb1(maths::Vector2f{ 0.0f, 0.0f }, maths::Vector2f{ 1.0f, 1.0f });
	maths::AABB2 aabb2(maths::Vector2f{ 0.1f, 0.1f }, maths::Vector2f{ 0.9f, 0.9f });
	EXPECT_TRUE(Contain(aabb1, aabb2));
	EXPECT_FALSE(Contain(aabb2, aabb1));

	// Test aabb2 � l'exterieur de aabb1 en positif
	aabb2 = maths::AABB2(maths::Vector2f{ 1.1f, 1.1f }, maths::Vector2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Test aabb2 � l'exterieur de aabb1 en negatif
	aabb2 = maths::AABB2(maths::Vector2f{ -0.5f, -0.5f }, maths::Vector2f{ -0.1f, -0.1f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Test angle aabb2 superpos� � aabb1 en positif
	aabb2 = maths::AABB2(maths::Vector2f{ 1.0f, 1.0f }, maths::Vector2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));
	
	// Test angle aabb2 superpos� � aabb1 en negatif
	aabb2 = maths::AABB2(maths::Vector2f{ -0.5f, -0.5f }, maths::Vector2f{ -0.0f, -0.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Angle bas gauche aabb2 chavauche aabb1
	aabb2 = maths::AABB2(maths::Vector2f{ 0.5f, 0.5f }, maths::Vector2f{ 1.5f, 1.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Angle haut droit chevauche aabb1
	aabb2 = maths::AABB2(maths::Vector2f{ -0.5f, -0.5f }, maths::Vector2f{ 0.5f, 0.5f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	//Aabb2 traverse aabb1
	aabb2 = maths::AABB2(maths::Vector2f{ -0.1f, 0.1f }, maths::Vector2f{ 1.1f, 0.9f });
	EXPECT_FALSE(Contain(aabb1, aabb2));

	// Meme aabb -> true ou false?
	aabb2 = maths::AABB2(maths::Vector2f{ 0.0f, 0.0f }, maths::Vector2f{ 1.0f, 1.0f });
	EXPECT_FALSE(Contain(aabb1, aabb2));
}
