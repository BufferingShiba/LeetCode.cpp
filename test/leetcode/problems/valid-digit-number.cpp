#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/valid-digit-number.h"

namespace leetcode {
namespace problem_3908 {

class ValidDigitNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ValidDigitNumberSolution solution_;
};

TEST_P(ValidDigitNumberTest, Example1) {
  EXPECT_TRUE(solution_.validDigit(101, 0));
}

TEST_P(ValidDigitNumberTest, Example2) {
  EXPECT_FALSE(solution_.validDigit(232, 2));
}

TEST_P(ValidDigitNumberTest, Example3) {
  EXPECT_FALSE(solution_.validDigit(5, 1));
}

TEST_P(ValidDigitNumberTest, SelfAuthoredZeroNumber) {
  // n = 0 -> "0". Starts with 0.
  // For x = 0, starts with x => invalid.
  EXPECT_FALSE(solution_.validDigit(0, 0));
  // For x = 1, does not contain 1 => invalid.
  EXPECT_FALSE(solution_.validDigit(0, 1));
}

TEST_P(ValidDigitNumberTest, SelfAuthoredSingleDigitMatchesXNotAsStart) {
  // n = 7, x = 7 -> starts with 7 => invalid.
  EXPECT_FALSE(solution_.validDigit(7, 7));
  // n = 7, x = 0 -> contains neither => invalid.
  EXPECT_FALSE(solution_.validDigit(7, 0));
}

INSTANTIATE_TEST_SUITE_P(
    ValidDigitNumberTestSuite, ValidDigitNumberTest,
    ::testing::ValuesIn(ValidDigitNumberSolution().getStrategyNames()));

}  // namespace problem_3908
}  // namespace leetcode
