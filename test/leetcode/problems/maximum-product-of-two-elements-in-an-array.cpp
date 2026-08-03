#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/maximum-product-of-two-elements-in-an-array.h"

namespace leetcode {
namespace problem_1464 {
namespace {

class MaximumProductOfTwoElementsInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumProductOfTwoElementsInAnArray solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumProductOfTwoElementsInAnArrayTest, Example1) {
  std::vector<int> nums = {3, 4, 5, 2};
  EXPECT_EQ(12, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoElementsInAnArrayTest, Example2) {
  std::vector<int> nums = {1, 5, 4, 5};
  EXPECT_EQ(16, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoElementsInAnArrayTest, Example3) {
  std::vector<int> nums = {3, 7};
  EXPECT_EQ(12, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoElementsInAnArrayTest, SelfAuthoredAllOnes) {
  std::vector<int> nums = {1, 1};
  EXPECT_EQ(0, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoElementsInAnArrayTest, SelfAuthoredTwoEqualMax) {
  std::vector<int> nums = {10, 10, 2};
  EXPECT_EQ(81, solution.maxProduct(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfTwoElementsInAnArrayTestSuite,
    MaximumProductOfTwoElementsInAnArrayTest,
    ::testing::ValuesIn(
        MaximumProductOfTwoElementsInAnArray().getStrategyNames()));

}  // namespace
}  // namespace problem_1464
}  // namespace leetcode
