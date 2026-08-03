#include <gtest/gtest.h>

#include "leetcode/problems/constrained-subsequence-sum.h"

namespace leetcode::problem_1425 {

class ConstrainedSubsequenceSumTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ConstrainedSubsequenceSumSolution solution;
};

TEST_P(ConstrainedSubsequenceSumTest, Example1) {
  std::vector<int> nums = {10, 2, -10, 5, 20};
  int k = 2;
  EXPECT_EQ(solution.constrainedSubsetSum(nums, k), 37);
}

TEST_P(ConstrainedSubsequenceSumTest, Example2) {
  std::vector<int> nums = {-1, -2, -3};
  int k = 1;
  EXPECT_EQ(solution.constrainedSubsetSum(nums, k), -1);
}

TEST_P(ConstrainedSubsequenceSumTest, Example3) {
  std::vector<int> nums = {10, -2, -10, -5, 20};
  int k = 2;
  EXPECT_EQ(solution.constrainedSubsetSum(nums, k), 23);
}

TEST_P(ConstrainedSubsequenceSumTest, SelfAuthoredAllNegativePickLargest) {
  std::vector<int> nums = {-5, -1, -9, -3};
  int k = 2;
  EXPECT_EQ(solution.constrainedSubsetSum(nums, k), -1);
}

TEST_P(ConstrainedSubsequenceSumTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  int k = 1;
  EXPECT_EQ(solution.constrainedSubsetSum(nums, k), 42);
}

TEST_P(ConstrainedSubsequenceSumTest, SelfAuthoredKEqualsLength) {
  std::vector<int> nums = {3, -2, 5, -1, 7};
  int k = 5;
  // Can pick all positive: 3 + 5 + 7 = 15, or with -2, -1: 3-2+5-1+7=12, best is 3+5+7=15
  EXPECT_EQ(solution.constrainedSubsetSum(nums, k), 15);
}

INSTANTIATE_TEST_SUITE_P(Strategies, ConstrainedSubsequenceSumTest,
                         testing::ValuesIn(ConstrainedSubsequenceSumSolution().getStrategyNames()));

}  // namespace leetcode::problem_1425
