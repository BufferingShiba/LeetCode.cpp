#include <gtest/gtest.h>

#include "leetcode/problems/split-array-into-maximum-number-of-subarrays.h"

namespace leetcode {
namespace problem_2871 {

class SplitArrayIntoMaximumNumberOfSubarraysTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SplitArrayIntoMaximumNumberOfSubarraysSolution solution;
};

TEST_P(SplitArrayIntoMaximumNumberOfSubarraysTest, Example1) {
  std::vector<int> nums = {1, 0, 2, 0, 1, 2};
  EXPECT_EQ(solution.maxSubarrays(nums), 3);
}

TEST_P(SplitArrayIntoMaximumNumberOfSubarraysTest, Example2) {
  std::vector<int> nums = {5, 7, 1, 3};
  EXPECT_EQ(solution.maxSubarrays(nums), 1);
}

TEST_P(SplitArrayIntoMaximumNumberOfSubarraysTest, SelfAuthoredSingleElementZero) {
  std::vector<int> nums = {0};
  EXPECT_EQ(solution.maxSubarrays(nums), 1);
}

TEST_P(SplitArrayIntoMaximumNumberOfSubarraysTest, SelfAuthoredSingleElementNonZero) {
  std::vector<int> nums = {7};
  EXPECT_EQ(solution.maxSubarrays(nums), 1);
}

TEST_P(SplitArrayIntoMaximumNumberOfSubarraysTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0, 0, 0};
  // Each zero alone gives AND = 0, so we can split into 4.
  EXPECT_EQ(solution.maxSubarrays(nums), 4);
}

TEST_P(SplitArrayIntoMaximumNumberOfSubarraysTest, SelfAuthoredNoZeroTotalAndZero) {
  std::vector<int> nums = {1, 2, 3};
  // 1 & 2 & 3 = 0, total_and = 0.
  // Scan: 1 & 2 = 0? 1&2=0, yes -> count=1, reset. Then 3 alone: cur=3, end.
  // So count=1.
  EXPECT_EQ(solution.maxSubarrays(nums), 1);
}

TEST_P(SplitArrayIntoMaximumNumberOfSubarraysTest, SelfAuthoredTotalAndNonZero) {
  std::vector<int> nums = {6, 6, 6};
  // 6 & 6 & 6 = 6 > 0, must keep whole.
  EXPECT_EQ(solution.maxSubarrays(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SplitArrayIntoMaximumNumberOfSubarraysTest,
    testing::ValuesIn(
        SplitArrayIntoMaximumNumberOfSubarraysSolution().getStrategyNames()));

}  // namespace problem_2871
}  // namespace leetcode
