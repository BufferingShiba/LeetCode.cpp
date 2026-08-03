#include <gtest/gtest.h>

#include "leetcode/problems/k-divisible-elements-subarrays.h"

namespace leetcode {
namespace problem_2261 {

using leetcode::problem_2261::KDivisibleElementsSubarraysSolution;

class KDivisibleElementsSubarraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  KDivisibleElementsSubarraysSolution solution_;
};

TEST_P(KDivisibleElementsSubarraysTest, Example1) {
  std::vector<int> nums = {2, 3, 3, 2, 2};
  EXPECT_EQ(solution_.countDistinct(nums, 2, 2), 11);
}

TEST_P(KDivisibleElementsSubarraysTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution_.countDistinct(nums, 4, 1), 10);
}

INSTANTIATE_TEST_SUITE_P(
    KDivisibleElementsSubarraysTestCases,
    KDivisibleElementsSubarraysTest,
    ::testing::ValuesIn(KDivisibleElementsSubarraysSolution().getStrategyNames()));

}  // namespace problem_2261
}  // namespace leetcode
