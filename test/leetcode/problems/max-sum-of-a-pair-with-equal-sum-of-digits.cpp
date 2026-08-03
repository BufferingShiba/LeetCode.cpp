#include <gtest/gtest.h>

#include "leetcode/problems/max-sum-of-a-pair-with-equal-sum-of-digits.h"

namespace leetcode {
namespace problem_2342 {
namespace {

using namespace ::leetcode::problem_2342;

class MaxSumOfAPairWithEqualSumOfDigitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaxSumOfAPairWithEqualSumOfDigitsSolution solution_;
};

TEST_P(MaxSumOfAPairWithEqualSumOfDigitsTest, Example1) {
  std::vector<int> nums = {18, 43, 36, 13, 7};
  EXPECT_EQ(solution_.maximumSum(nums), 54);
}

TEST_P(MaxSumOfAPairWithEqualSumOfDigitsTest, Example2) {
  std::vector<int> nums = {10, 12, 19, 14};
  EXPECT_EQ(solution_.maximumSum(nums), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaxSumOfAPairWithEqualSumOfDigitsTest,
    ::testing::ValuesIn(
        MaxSumOfAPairWithEqualSumOfDigitsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2342
}  // namespace leetcode
