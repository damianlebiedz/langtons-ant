#include <gtest/gtest.h>
#include "Grid.h"
#include "Ant.h"

TEST(GridTest, Initialization) {
    Grid grid(10);

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            EXPECT_EQ(grid.getCell(x, y), 0);
        }
    }
}

TEST(GridTest, Update) {
    Grid grid(10);
    Ant ant(5, 5);

    EXPECT_EQ(grid.getCell(5, 5), 0);

    grid.update(ant);
    EXPECT_EQ(grid.getCell(5, 5), 1);

    EXPECT_EQ(ant.getX(), 6);
    EXPECT_EQ(ant.getY(), 5);
}

TEST(GridTest, OutOfBoundsAccess) {
    Grid grid(10);

    EXPECT_THROW(grid.getCell(-1, -1), std::out_of_range);
    EXPECT_THROW(grid.getCell(10, 10), std::out_of_range);
}
