#include <gtest/gtest.h>
#include "Ant.h"

TEST(AntTest, Initialization) {
    Ant ant(5, 5);
    EXPECT_EQ(ant.getX(), 5);
    EXPECT_EQ(ant.getY(), 5);
}

TEST(AntTest, TurnRight) {
    Ant ant(0, 0);
    int initialX = ant.getX();
    int initialY = ant.getY();
    ant.turnRight();
    ant.moveForward();
    EXPECT_EQ(ant.getX(), initialX + 1);
    EXPECT_EQ(ant.getY(), initialY);
}

TEST(AntTest, TurnLeft) {
    Ant ant(0, 0);
    int initialX = ant.getX();
    int initialY = ant.getY();
    ant.turnLeft();
    ant.moveForward();
    EXPECT_EQ(ant.getX(), initialX - 1);
    EXPECT_EQ(ant.getY(), initialY);
}