#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/check-if-bitwise-or-has-trailing-zeros.h"

using leetcode::problem_2980::CheckIfBitwiseOrHasTrailingZerosSolution;

namespace {

class CheckIfBitwiseOrHasTrailingZerosTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckIfBitwiseOrHasTrailingZerosSolution solution;
};

TEST_P(CheckIfBitwiseOrHasTrailingZerosTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_TRUE(solution.hasTrailingZeros(nums));
}

TEST_P(CheckIfBitwiseOrHasTrailingZerosTest, Example2) {
  std::vector<int> nums = {2, 4, 8, 16};
  EXPECT_TRUE(solution.hasTrailingZeros(nums));
}

TEST_P(CheckIfBitwiseOrHasTrailingZerosTest, Example3) {
  std::vector<int> nums = {1, 3, 5, 7, 9};
  EXPECT_FALSE(solution.hasTrailingZeros(nums));
}

TEST_P(CheckIfBitwiseOrHasTrailingZerosTest, SelfAuthoredMinOddBoth) {
  std::vector<int> nums = {1, 3};
  EXPECT_FALSE(solution.hasTrailingZeros(nums));
}

TEST_P(CheckIfBitwiseOrHasTrailingZerosTest, SelfAuthoredSingleEvenOnly) {
  std::vector<int> nums = {2, 3};
  EXPECT_FALSE(solution.hasTrailingZeros(nums));
}

TEST_P(CheckIfBitwiseOrHasTrailingZerosTest, SelfAuthoredMinEvenBoth) {
  std::vector<int> nums = {2, 4};
  EXPECT_TRUE(solution.hasTrailingZeros(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfBitwiseOrHasTrailingZerosTestSuite,
    CheckIfBitwiseOrHasTrailingZerosTest,
    ::testing::ValuesIn(CheckIfBitwiseOrHasTrailingZerosSolution().getStrategyNames()));

}  // namespace
