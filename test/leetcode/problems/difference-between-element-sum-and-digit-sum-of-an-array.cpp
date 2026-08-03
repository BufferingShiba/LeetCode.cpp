#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/difference-between-element-sum-and-digit-sum-of-an-array.h"

namespace leetcode {
namespace problem_2535 {

class DifferenceBetweenElementSumAndDigitSumOfAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DifferenceBetweenElementSumAndDigitSumOfAnArraySolution solution;
};

TEST_P(DifferenceBetweenElementSumAndDigitSumOfAnArrayTest, Example1) {
  std::vector<int> nums{1, 15, 6, 3};
  EXPECT_EQ(9, solution.differenceOfSum(nums));
}

TEST_P(DifferenceBetweenElementSumAndDigitSumOfAnArrayTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4};
  EXPECT_EQ(0, solution.differenceOfSum(nums));
}

TEST_P(DifferenceBetweenElementSumAndDigitSumOfAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{2000};
  // element sum = 2000, digit sum = 2, difference = 1998
  EXPECT_EQ(1998, solution.differenceOfSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    DifferenceBetweenElementSumAndDigitSumOfAnArrayTestSuite,
    DifferenceBetweenElementSumAndDigitSumOfAnArrayTest,
    ::testing::ValuesIn(
        DifferenceBetweenElementSumAndDigitSumOfAnArraySolution()
            .getStrategyNames()));

}  // namespace problem_2535
}  // namespace leetcode
