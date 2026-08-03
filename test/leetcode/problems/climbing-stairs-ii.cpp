#include <gtest/gtest.h>

#include "leetcode/problems/climbing-stairs-ii.h"

namespace leetcode {
namespace problem_3693 {

class ClimbingStairsIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  ClimbingStairsIiSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ClimbingStairsIiTest, Example1) {
  int n = 4;
  std::vector<int> costs = {1, 2, 3, 4};
  EXPECT_EQ(solution.climbStairs(n, costs), 13);
}

TEST_P(ClimbingStairsIiTest, Example2) {
  int n = 4;
  std::vector<int> costs = {5, 1, 6, 2};
  EXPECT_EQ(solution.climbStairs(n, costs), 11);
}

TEST_P(ClimbingStairsIiTest, Example3) {
  int n = 3;
  std::vector<int> costs = {9, 8, 3};
  EXPECT_EQ(solution.climbStairs(n, costs), 12);
}

TEST_P(ClimbingStairsIiTest, SelfAuthoredSingleStep) {
  int n = 1;
  std::vector<int> costs = {5};
  // Only path: 0 -> 1, cost = costs[1] + 1^2 = 5 + 1 = 6
  EXPECT_EQ(solution.climbStairs(n, costs), 6);
}

TEST_P(ClimbingStairsIiTest, SelfAuthoredTwoStepsDirect) {
  int n = 2;
  std::vector<int> costs = {10, 1};
  // Path 0->2: costs[2] + 4 = 1 + 4 = 5
  // Path 0->1->2: (10+1) + (1+1) = 11 + 2 = 13
  // Min = 5
  EXPECT_EQ(solution.climbStairs(n, costs), 5);
}

TEST_P(ClimbingStairsIiTest, SelfAuthoredThreeStepsAllJump) {
  int n = 3;
  std::vector<int> costs = {100, 100, 1};
  // Path 0->3: costs[3] + 9 = 1 + 9 = 10
  // Any path through step 1 or 2 costs at least 100+something
  EXPECT_EQ(solution.climbStairs(n, costs), 10);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    ClimbingStairsIiTest,
    ::testing::ValuesIn(ClimbingStairsIiSolution().getStrategyNames()));

}  // namespace problem_3693
}  // namespace leetcode
