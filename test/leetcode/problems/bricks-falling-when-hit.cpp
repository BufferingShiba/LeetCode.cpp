#include <gtest/gtest.h>
#include "leetcode/problems/bricks-falling-when-hit.h"

namespace leetcode::problem_803 {

class BricksFallingWhenHitTest : public ::testing::TestWithParam<std::string> {
 protected:
    BricksFallingWhenHitSolution solution;
    void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(BricksFallingWhenHitTest, Example1) {
    std::vector<std::vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 1, 0}};
    std::vector<std::vector<int>> hits = {{1, 0}};
    std::vector<int> expected = {2};
    EXPECT_EQ(solution.hitBricks(grid, hits), expected);
}

TEST_P(BricksFallingWhenHitTest, Example2) {
    std::vector<std::vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 0, 0}};
    std::vector<std::vector<int>> hits = {{1, 1}, {1, 0}};
    std::vector<int> expected = {0, 0};
    EXPECT_EQ(solution.hitBricks(grid, hits), expected);
}

INSTANTIATE_TEST_SUITE_P(, BricksFallingWhenHitTest,
                         ::testing::ValuesIn(BricksFallingWhenHitSolution().getStrategyNames()));

}  // namespace leetcode::problem_803
