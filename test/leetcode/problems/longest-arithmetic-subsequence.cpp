#include <gtest/gtest.h>

#include "leetcode/problems/longest-arithmetic-subsequence.h"

using namespace leetcode::problem_1027;

class LongestArithmeticSubsequenceTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  LongestArithmeticSubsequenceSolution solution_;
};

TEST_P(LongestArithmeticSubsequenceTest, Example1) {
  std::vector<int> nums = {3, 6, 9, 12};
  EXPECT_EQ(solution_.longestArithSeqLength(nums), 4);
}

TEST_P(LongestArithmeticSubsequenceTest, Example2) {
  std::vector<int> nums = {9, 4, 7, 2, 10};
  EXPECT_EQ(solution_.longestArithSeqLength(nums), 3);
}

TEST_P(LongestArithmeticSubsequenceTest, Example3) {
  std::vector<int> nums = {20, 1, 15, 3, 10, 5, 8};
  EXPECT_EQ(solution_.longestArithSeqLength(nums), 4);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    LongestArithmeticSubsequenceTest,
    testing::ValuesIn(LongestArithmeticSubsequenceSolution().getStrategyNames()));
