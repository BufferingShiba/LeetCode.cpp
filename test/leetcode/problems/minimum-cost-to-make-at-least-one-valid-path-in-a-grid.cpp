#include <gtest/gtest.h>

#include "leetcode/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid.h"

namespace leetcode {
namespace problem_1368 {
namespace {

class MinimumCostToMakeAtLeastOneValidPathInAGridTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumCostToMakeAtLeastOneValidPathInAGridSolution solution_;
};

TEST_P(MinimumCostToMakeAtLeastOneValidPathInAGridTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
  EXPECT_EQ(3, solution_.minCost(grid));
}

TEST_P(MinimumCostToMakeAtLeastOneValidPathInAGridTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
  EXPECT_EQ(0, solution_.minCost(grid));
}

TEST_P(MinimumCostToMakeAtLeastOneValidPathInAGridTest, Example3) {
  std::vector<std::vector<int>> grid = {{1, 2}, {4, 3}};
  EXPECT_EQ(1, solution_.minCost(grid));
}

TEST_P(MinimumCostToMakeAtLeastOneValidPathInAGridTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{1}};
  EXPECT_EQ(0, solution_.minCost(grid));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToMakeAtLeastOneValidPathInAGridTestInstance,
    MinimumCostToMakeAtLeastOneValidPathInAGridTest,
    ::testing::ValuesIn(
        MinimumCostToMakeAtLeastOneValidPathInAGridSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_1368
}  // namespace leetcode
