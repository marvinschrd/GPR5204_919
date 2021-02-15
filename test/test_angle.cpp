#include <gtest/gtest.h>

#include "maths/angle.h"

TEST(Maths, Angle)
{
    const maths::degree_t angle1{ 0.0f };
    const maths::degree_t angle2{ 90.0f };

    const float epsilon = 0.00001f;

    EXPECT_FLOAT_EQ(maths::cos(angle1), 1.0f);
    //due to floating conversion cos(90°) is just not close enough to zero...
    EXPECT_TRUE(maths::cos(angle2) < epsilon);

    EXPECT_FLOAT_EQ(maths::sin(angle1), 0.0f);
    EXPECT_FLOAT_EQ(maths::sin(angle2), 1.0f);

    EXPECT_FLOAT_EQ(maths::tan(angle1), 0.0f);
    
    EXPECT_FLOAT_EQ(maths::atan(maths::tan(angle1)).value(), 0.0f);
}