#include <gtest/gtest.h>
#include "Grid.h"
#include "Ant.h"

TEST(GridTest, Initialization) {
    Grid grid(10);
    EXPECT_EQ(grid.getSize(), 10);
    EXPECT_EQ(grid.getCell(5, 5), 0);
}

TEST(GridTest, Update) {
    Grid grid(10);
    Ant ant(5, 5);
    grid.update(ant);
    EXPECT_EQ(grid.getCell(5, 5), 1);
    EXPECT_EQ(ant.getDirection(), EAST);
}