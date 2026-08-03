#include "leetcode/problems/minimum-sideway-jumps.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1824 {

class MinimumSidewayJumpsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumSidewayJumpsSolution solution;
};

TEST_P(MinimumSidewayJumpsTest, Example1) {
  std::vector<int> obstacles = {0, 1, 2, 3, 0};
  EXPECT_EQ(2, solution.minSideJumps(obstacles));
}

TEST_P(MinimumSidewayJumpsTest, Example2) {
  std::vector<int> obstacles = {0, 1, 1, 3, 3, 0};
  EXPECT_EQ(0, solution.minSideJumps(obstacles));
}

TEST_P(MinimumSidewayJumpsTest, Example3) {
  std::vector<int> obstacles = {0, 2, 1, 0, 3, 0};
  EXPECT_EQ(2, solution.minSideJumps(obstacles));
}

TEST_P(MinimumSidewayJumpsTest, SelfAuthoredNoObstacles) {
  std::vector<int> obstacles = {0, 0, 0, 0};
  EXPECT_EQ(0, solution.minSideJumps(obstacles));
}

TEST_P(MinimumSidewayJumpsTest, SelfAuthoredNeedTwoSwitches) {
  // Need to hop around obstacles.
  std::vector<int> obstacles = {0, 1, 2, 1, 0};
  EXPECT_EQ(1, solution.minSideJumps(obstacles));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumSidewayJumpsTestSuite, MinimumSidewayJumpsTest,
    ::testing::ValuesIn(MinimumSidewayJumpsSolution().getStrategyNames()));

}  // namespace problem_1824
}  // namespace leetcode
