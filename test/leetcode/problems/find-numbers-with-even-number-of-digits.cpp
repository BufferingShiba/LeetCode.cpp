#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-numbers-with-even-number-of-digits.h"

namespace leetcode {
namespace problem_1295 {

class FindNumbersWithEvenNumberOfDigitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindNumbersWithEvenNumberOfDigitsSolution solution_;
};

TEST_P(FindNumbersWithEvenNumberOfDigitsTest, Example1) {
  std::vector<int> nums = {12, 345, 2, 6, 7896};
  EXPECT_EQ(2, solution_.findNumbers(nums));
}

TEST_P(FindNumbersWithEvenNumberOfDigitsTest, Example2) {
  std::vector<int> nums = {555, 901, 482, 1771};
  EXPECT_EQ(1, solution_.findNumbers(nums));
}

TEST_P(FindNumbersWithEvenNumberOfDigitsTest, SelfAuthoredAllEvenDigits) {
  std::vector<int> nums = {11, 22, 3333, 44};
  EXPECT_EQ(4, solution_.findNumbers(nums));
}

INSTANTIATE_TEST_SUITE_P(
    FindNumbersWithEvenNumberOfDigitsTestSuite,
    FindNumbersWithEvenNumberOfDigitsTest,
    ::testing::ValuesIn(
        FindNumbersWithEvenNumberOfDigitsSolution().getStrategyNames()));

}  // namespace problem_1295
}  // namespace leetcode
