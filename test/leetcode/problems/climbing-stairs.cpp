#include "leetcode/problems/climbing-stairs.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_70 {

class ClimbingStairsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ClimbingStairsSolution solution;
};

TEST_P(ClimbingStairsTest, Example1) {
  int result = solution.climbStairs(2);
  EXPECT_EQ(2, result);
}

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 2
// Output: 2
TEST_P(ClimbingStairsTest, OfficialExample1) {
  int result = solution.climbStairs(2);
  EXPECT_EQ(2, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 3
// Output: 3
TEST_P(ClimbingStairsTest, OfficialExample2) {
  int result = solution.climbStairs(3);
  EXPECT_EQ(3, result);
}

// n = 1, only one way (1 step)
TEST_P(ClimbingStairsTest, SingleStep) {
  int result = solution.climbStairs(1);
  EXPECT_EQ(1, result);
}

// n = 45, max constraint, Fibonacci(46) overflow-checked
TEST_P(ClimbingStairsTest, MaxConstraint) {
  int result = solution.climbStairs(45);
  EXPECT_EQ(1836311903, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ClimbingStairsTest,
    ::testing::ValuesIn(ClimbingStairsSolution().getStrategyNames()));

}  // namespace problem_70
}  // namespace leetcode
