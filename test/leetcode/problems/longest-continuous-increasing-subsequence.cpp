#include "leetcode/problems/longest-continuous-increasing-subsequence.h"
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_674 {

class LongestContinuousIncreasingSubsequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestContinuousIncreasingSubsequenceSolution solution;
};

TEST_P(LongestContinuousIncreasingSubsequenceTest, Example1) {
  std::vector<int> nums = {1, 3, 5, 4, 7};
  EXPECT_EQ(3, solution.findLengthOfLCIS(nums));
}

TEST_P(LongestContinuousIncreasingSubsequenceTest, Example2) {
  std::vector<int> nums = {2, 2, 2, 2, 2};
  EXPECT_EQ(1, solution.findLengthOfLCIS(nums));
}

TEST_P(LongestContinuousIncreasingSubsequenceTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(1, solution.findLengthOfLCIS(nums));
}

INSTANTIATE_TEST_SUITE_P(LongestContinuousIncreasingSubsequenceTestSuite,
                         LongestContinuousIncreasingSubsequenceTest,
                         ::testing::ValuesIn(
                             LongestContinuousIncreasingSubsequenceSolution()
                                 .getStrategyNames()));

}  // namespace problem_674
}  // namespace leetcode
