#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/painting-the-walls.h"

namespace leetcode::problem_2742 {

class PaintingTheWallsTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    PaintingTheWallsSolution solution_;
};

TEST_P(PaintingTheWallsTest, Example1) {
    std::vector<int> cost{1, 2, 3, 2};
    std::vector<int> time{1, 2, 3, 2};
    EXPECT_EQ(3, solution_.paintWalls(cost, time));
}

TEST_P(PaintingTheWallsTest, Example2) {
    std::vector<int> cost{2, 3, 4, 2};
    std::vector<int> time{1, 1, 1, 1};
    EXPECT_EQ(4, solution_.paintWalls(cost, time));
}

TEST_P(PaintingTheWallsTest, SelfAuthoredSingleWall) {
    std::vector<int> cost{5};
    std::vector<int> time{3};
    EXPECT_EQ(5, solution_.paintWalls(cost, time));
}

TEST_P(PaintingTheWallsTest, SelfAuthoredSingleWallMinTime) {
    std::vector<int> cost{7};
    std::vector<int> time{1};
    EXPECT_EQ(7, solution_.paintWalls(cost, time));
}

INSTANTIATE_TEST_SUITE_P(PaintingTheWallsTestSuite, PaintingTheWallsTest,
                         ::testing::ValuesIn(PaintingTheWallsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2742
