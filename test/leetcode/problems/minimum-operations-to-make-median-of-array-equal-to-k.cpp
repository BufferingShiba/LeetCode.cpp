#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-make-median-of-array-equal-to-k.h"

namespace leetcode {
namespace problem_3107 {

class MinimumOperationsToMakeMedianOfArrayEqualToKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumOperationsToMakeMedianOfArrayEqualToKSolution solution;
};

TEST_P(MinimumOperationsToMakeMedianOfArrayEqualToKTest, Example1) {
  std::vector<int> nums = {2, 5, 6, 8, 5};
  int k = 4;
  EXPECT_EQ(solution.minOperationsToMakeMedianK(nums, k), 2);
}

TEST_P(MinimumOperationsToMakeMedianOfArrayEqualToKTest, Example2) {
  std::vector<int> nums = {2, 5, 6, 8, 5};
  int k = 7;
  EXPECT_EQ(solution.minOperationsToMakeMedianK(nums, k), 3);
}

TEST_P(MinimumOperationsToMakeMedianOfArrayEqualToKTest, Example3) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  int k = 4;
  EXPECT_EQ(solution.minOperationsToMakeMedianK(nums, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumOperationsToMakeMedianOfArrayEqualToKTest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeMedianOfArrayEqualToKSolution().getStrategyNames()));

}  // namespace problem_3107
}  // namespace leetcode
