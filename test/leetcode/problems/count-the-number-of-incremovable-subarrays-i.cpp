#include <gtest/gtest.h>

#include "leetcode/problems/count-the-number-of-incremovable-subarrays-i.h"

using namespace leetcode::problem_2970;

class CountTheNumberOfIncremovableSubarraysITest
    : public testing::TestWithParam<std::string> {
 protected:
  CountTheNumberOfIncremovableSubarraysISolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CountTheNumberOfIncremovableSubarraysITest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution.incremovableSubarrayCount(nums), 10);
}

TEST_P(CountTheNumberOfIncremovableSubarraysITest, Example2) {
  std::vector<int> nums = {6, 5, 7, 8};
  EXPECT_EQ(solution.incremovableSubarrayCount(nums), 7);
}

TEST_P(CountTheNumberOfIncremovableSubarraysITest, Example3) {
  std::vector<int> nums = {8, 7, 6, 6};
  EXPECT_EQ(solution.incremovableSubarrayCount(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountTheNumberOfIncremovableSubarraysITest,
    testing::ValuesIn(
        CountTheNumberOfIncremovableSubarraysISolution().getStrategyNames()));
