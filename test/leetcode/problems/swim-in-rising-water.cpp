#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/swim-in-rising-water.h"

namespace leetcode {
namespace problem_778 {
namespace {

class SwimInRisingWaterTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SwimInRisingWaterSolution solution;
};

TEST_P(SwimInRisingWaterTest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 2}, {1, 3}};
  EXPECT_EQ(solution.swimInWater(grid), 3);
}

TEST_P(SwimInRisingWaterTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {0, 1, 2, 3, 4},
      {24, 23, 22, 21, 5},
      {12, 13, 14, 15, 16},
      {11, 17, 18, 19, 20},
      {10, 9, 8, 7, 6}};
  EXPECT_EQ(solution.swimInWater(grid), 16);
}

TEST_P(SwimInRisingWaterTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{0}};
  EXPECT_EQ(solution.swimInWater(grid), 0);
}

TEST_P(SwimInRisingWaterTest, SelfAuthoredTwoByTwoMaxEnd) {
  std::vector<std::vector<int>> grid = {{0, 1}, {2, 3}};
  EXPECT_EQ(solution.swimInWater(grid), 3);
}

INSTANTIATE_TEST_SUITE_P(
    SwimInRisingWaterTestSuite, SwimInRisingWaterTest,
    ::testing::ValuesIn(
        SwimInRisingWaterSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_778
}  // namespace leetcode
