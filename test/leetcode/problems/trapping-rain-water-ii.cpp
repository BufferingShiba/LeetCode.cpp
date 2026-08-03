#include "leetcode/problems/trapping-rain-water-ii.h"

#include <gtest/gtest.h>

namespace leetcode::problem_407 {

class TrappingRainWaterIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TrappingRainWaterIiSolution solution;
};

TEST_P(TrappingRainWaterIiTest, Example1) {
  std::vector<std::vector<int>> heightMap = {
      {1, 4, 3, 1, 3, 2},
      {3, 2, 1, 3, 2, 4},
      {2, 3, 3, 2, 3, 1}};
  EXPECT_EQ(4, solution.getSolution()(heightMap));
}

TEST_P(TrappingRainWaterIiTest, Example2) {
  std::vector<std::vector<int>> heightMap = {
      {3, 3, 3, 3, 3},
      {3, 2, 2, 2, 3},
      {3, 2, 1, 2, 3},
      {3, 2, 2, 2, 3},
      {3, 3, 3, 3, 3}};
  EXPECT_EQ(10, solution.getSolution()(heightMap));
}

TEST_P(TrappingRainWaterIiTest, SelfAuthoredSmallMatrixNoWater) {
  std::vector<std::vector<int>> heightMap = {{1, 1}, {1, 1}};
  EXPECT_EQ(0, solution.getSolution()(heightMap));
}

TEST_P(TrappingRainWaterIiTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> heightMap = {{5}};
  EXPECT_EQ(0, solution.getSolution()(heightMap));
}

TEST_P(TrappingRainWaterIiTest, SelfAuthoredOpenToEdgeNoTrap) {
  std::vector<std::vector<int>> heightMap = {
      {1, 0, 1},
      {0, 0, 0},
      {1, 0, 1}};
  // The center is connected to edges (all 0), water drains out.
  EXPECT_EQ(0, solution.getSolution()(heightMap));
}

INSTANTIATE_TEST_SUITE_P(
    TrappingRainWaterIi, TrappingRainWaterIiTest,
    ::testing::ValuesIn(TrappingRainWaterIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_407
