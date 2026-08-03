#include <gtest/gtest.h>
#include "leetcode/problems/sum-of-integers-with-maximum-digit-range.h"

#include <string>
#include <vector>

namespace leetcode::problem_3982 {

class SumOfIntegersWithMaximumDigitRangeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  SumOfIntegersWithMaximumDigitRangeSolution solution;
};

TEST_P(SumOfIntegersWithMaximumDigitRangeTest, Example1) {
  std::vector<int> nums = {5724, 111, 350};
  EXPECT_EQ(solution.maxDigitRange(nums), 6074);
}

TEST_P(SumOfIntegersWithMaximumDigitRangeTest, Example2) {
  std::vector<int> nums = {90, 900};
  EXPECT_EQ(solution.maxDigitRange(nums), 990);
}

TEST_P(SumOfIntegersWithMaximumDigitRangeTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {10};
  EXPECT_EQ(solution.maxDigitRange(nums), 10);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfIntegersWithMaximumDigitRangeTestSuite,
    SumOfIntegersWithMaximumDigitRangeTest,
    ::testing::ValuesIn(
        SumOfIntegersWithMaximumDigitRangeSolution().getStrategyNames()));

}  // namespace leetcode::problem_3982
