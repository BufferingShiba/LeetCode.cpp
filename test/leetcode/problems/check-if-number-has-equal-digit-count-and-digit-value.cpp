#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/check-if-number-has-equal-digit-count-and-digit-value.h"

namespace leetcode {
namespace problem_2283 {

class CheckIfNumberHasEqualDigitCountAndDigitValueTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfNumberHasEqualDigitCountAndDigitValueSolution solution_;
};

TEST_P(CheckIfNumberHasEqualDigitCountAndDigitValueTest, Example1) {
  EXPECT_TRUE(solution_.digitCount("1210"));
}

TEST_P(CheckIfNumberHasEqualDigitCountAndDigitValueTest, Example2) {
  EXPECT_FALSE(solution_.digitCount("030"));
}

TEST_P(CheckIfNumberHasEqualDigitCountAndDigitValueTest, SingleDigitOne) {
  EXPECT_FALSE(solution_.digitCount("1"));
}

TEST_P(CheckIfNumberHasEqualDigitCountAndDigitValueTest, SelfAuthoredFalse) {
  EXPECT_FALSE(solution_.digitCount("10"));
}

TEST_P(CheckIfNumberHasEqualDigitCountAndDigitValueTest, SelfAuthoredTrue) {
  EXPECT_TRUE(solution_.digitCount("2020"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfNumberHasEqualDigitCountAndDigitValueTestSuite,
    CheckIfNumberHasEqualDigitCountAndDigitValueTest,
    ::testing::ValuesIn(
        CheckIfNumberHasEqualDigitCountAndDigitValueSolution().getStrategyNames()));

}  // namespace problem_2283
}  // namespace leetcode
