#include <gtest/gtest.h>
#include "Ant.h"

TEST(AntTest, Initialization) {
    Ant ant(5, 5);
    EXPECT_EQ(ant.getX(), 5);
    EXPECT_EQ(ant.getY(), 5);
    EXPECT_EQ(ant.getDirection(), NORTH);
}

TEST(AntTest, TurnRight) {
    Ant ant(0, 0);
    ant.turnRight();
    EXPECT_EQ(ant.getDirection(), EAST);
}