#include <gtest/gtest.h>

#include "leetcode/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and.h"

namespace leetcode::problem_3825 {

class LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndSolution solution_;
};

TEST_P(LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndTest, Example1) {
  std::vector<int> nums = {5, 4, 7};
  EXPECT_EQ(solution_.longestSubsequence(nums), 2);
}

TEST_P(LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndTest, Example2) {
  std::vector<int> nums = {2, 3, 6};
  EXPECT_EQ(solution_.longestSubsequence(nums), 3);
}

TEST_P(LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndTest, Example3) {
  std::vector<int> nums = {0, 1};
  EXPECT_EQ(solution_.longestSubsequence(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndTest,
    testing::ValuesIn(
        LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3825
