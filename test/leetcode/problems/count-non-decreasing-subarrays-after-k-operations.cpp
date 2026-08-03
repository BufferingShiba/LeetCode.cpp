#include "leetcode/problems/count-non-decreasing-subarrays-after-k-operations.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3420 {

class CountNonDecreasingSubarraysAfterKOperationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountNonDecreasingSubarraysAfterKOperationsSolution solution;
};

TEST_P(CountNonDecreasingSubarraysAfterKOperationsTest, Example1) {
  std::vector<int> nums = {6, 3, 1, 2, 4, 4};
  EXPECT_EQ(17, solution.countNonDecreasingSubarrays(nums, 7));
}

TEST_P(CountNonDecreasingSubarraysAfterKOperationsTest, Example2) {
  std::vector<int> nums = {6, 3, 1, 3, 6};
  EXPECT_EQ(12, solution.countNonDecreasingSubarrays(nums, 4));
}

TEST_P(CountNonDecreasingSubarraysAfterKOperationsTest,
       SelfAuthoredAlreadySorted) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(6, solution.countNonDecreasingSubarrays(nums, 1));
}

INSTANTIATE_TEST_SUITE_P(
    CountNonDecreasingSubarraysAfterKOperationsTestSuite,
    CountNonDecreasingSubarraysAfterKOperationsTest,
    ::testing::ValuesIn(CountNonDecreasingSubarraysAfterKOperationsSolution()
                             .getStrategyNames()));

}  // namespace problem_3420
}  // namespace leetcode
