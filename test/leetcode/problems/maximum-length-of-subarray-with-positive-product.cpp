#include "leetcode/problems/maximum-length-of-subarray-with-positive-product.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_1567 {

class MaximumLengthOfSubarrayWithPositiveProductTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumLengthOfSubarrayWithPositiveProductSolution solution;
};

TEST_P(MaximumLengthOfSubarrayWithPositiveProductTest, Example1) {
  std::vector<int> nums = {1, -2, -3, 4};
  EXPECT_EQ(solution.getMaxLen(nums), 4);
}

TEST_P(MaximumLengthOfSubarrayWithPositiveProductTest, Example2) {
  std::vector<int> nums = {0, 1, -2, -3, -4};
  EXPECT_EQ(solution.getMaxLen(nums), 3);
}

TEST_P(MaximumLengthOfSubarrayWithPositiveProductTest, Example3) {
  std::vector<int> nums = {-1, -2, -3, 0, 1};
  EXPECT_EQ(solution.getMaxLen(nums), 2);
}

TEST_P(MaximumLengthOfSubarrayWithPositiveProductTest, AllPositive) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution.getMaxLen(nums), 4);
}

TEST_P(MaximumLengthOfSubarrayWithPositiveProductTest, SingleNegative) {
  std::vector<int> nums = {-1};
  EXPECT_EQ(solution.getMaxLen(nums), 0);
}

TEST_P(MaximumLengthOfSubarrayWithPositiveProductTest, SingleZero) {
  std::vector<int> nums = {0};
  EXPECT_EQ(solution.getMaxLen(nums), 0);
}

TEST_P(MaximumLengthOfSubarrayWithPositiveProductTest, NegativesWrappedByZero) {
  std::vector<int> nums = {-1, -2, 0, -3, -4, -5};
  // Segment1 [-1,-2] (even negatives) -> 2; Segment2 [-3,-4,-5] (odd)
  // -> max subarray is 2. Overall answer 2.
  EXPECT_EQ(solution.getMaxLen(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumLengthOfSubarrayWithPositiveProductTestInstance,
    MaximumLengthOfSubarrayWithPositiveProductTest,
    ::testing::ValuesIn(
        MaximumLengthOfSubarrayWithPositiveProductSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1567
