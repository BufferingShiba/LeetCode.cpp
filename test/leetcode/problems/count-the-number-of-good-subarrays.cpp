#include <gtest/gtest.h>

#include "leetcode/problems/count-the-number-of-good-subarrays.h"

namespace leetcode::problem_2537 {

class CountTheNumberOfGoodSubarraysTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTheNumberOfGoodSubarraysSolution solution;
};

TEST_P(CountTheNumberOfGoodSubarraysTest, Example1) {
  std::vector<int> nums = {1, 1, 1, 1, 1};
  int k = 10;
  EXPECT_EQ(solution.countGood(nums, k), 1);
}

TEST_P(CountTheNumberOfGoodSubarraysTest, Example2) {
  std::vector<int> nums = {3, 1, 4, 3, 2, 2, 4};
  int k = 2;
  EXPECT_EQ(solution.countGood(nums, k), 4);
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfGoodSubarrays,
    CountTheNumberOfGoodSubarraysTest,
    testing::ValuesIn(CountTheNumberOfGoodSubarraysSolution().getStrategyNames()));

}  // namespace leetcode::problem_2537
