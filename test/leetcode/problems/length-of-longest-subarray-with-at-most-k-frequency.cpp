#include "leetcode/problems/length-of-longest-subarray-with-at-most-k-frequency.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2958 {

class LengthOfLongestSubarrayWithAtMostKFrequencyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LengthOfLongestSubarrayWithAtMostKFrequencySolution solution_;
};

TEST_P(LengthOfLongestSubarrayWithAtMostKFrequencyTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
  EXPECT_EQ(solution_.maxSubarrayLength(nums, 2), 6);
}

TEST_P(LengthOfLongestSubarrayWithAtMostKFrequencyTest, Example2) {
  std::vector<int> nums = {1, 2, 1, 2, 1, 2, 1, 2};
  EXPECT_EQ(solution_.maxSubarrayLength(nums, 1), 2);
}

TEST_P(LengthOfLongestSubarrayWithAtMostKFrequencyTest, Example3) {
  std::vector<int> nums = {5, 5, 5, 5, 5, 5, 5};
  EXPECT_EQ(solution_.maxSubarrayLength(nums, 4), 4);
}

INSTANTIATE_TEST_SUITE_P(
    LengthOfLongestSubarrayWithAtMostKFrequencyTestCases,
    LengthOfLongestSubarrayWithAtMostKFrequencyTest,
    ::testing::ValuesIn(
        LengthOfLongestSubarrayWithAtMostKFrequencySolution().getStrategyNames()));

}  // namespace problem_2958
}  // namespace leetcode
