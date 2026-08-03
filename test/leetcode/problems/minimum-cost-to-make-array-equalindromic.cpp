#include <gtest/gtest.h>

#include "leetcode/problems/minimum-cost-to-make-array-equalindromic.h"

using leetcode::problem_2967::MinimumCostToMakeArrayEqualindromicSolution;

class MinimumCostToMakeArrayEqualindromicTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToMakeArrayEqualindromicSolution solution;
};

TEST_P(MinimumCostToMakeArrayEqualindromicTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(6, solution.minimumCost(nums));
}

TEST_P(MinimumCostToMakeArrayEqualindromicTest, Example2) {
  std::vector<int> nums = {10, 12, 13, 14, 15};
  EXPECT_EQ(11, solution.minimumCost(nums));
}

TEST_P(MinimumCostToMakeArrayEqualindromicTest, Example3) {
  std::vector<int> nums = {22, 33, 22, 33, 22};
  EXPECT_EQ(22, solution.minimumCost(nums));
}

TEST_P(MinimumCostToMakeArrayEqualindromicTest, SelfAuthoredSingleElementIsPalindrome) {
  std::vector<int> nums = {1000000000};
  // median 1e9; nearest palindromes: 999999999 (cost 1) and 1000000001 (>1e9
  // out of range). prev = 999999999 cost 1. out-of-range next clamped to
  // 999999999 too, so result 1.
  EXPECT_EQ(1, solution.minimumCost(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToMakeArrayEqualindromicTest, MinimumCostToMakeArrayEqualindromicTest,
    ::testing::ValuesIn(
        MinimumCostToMakeArrayEqualindromicSolution().getStrategyNames()));
