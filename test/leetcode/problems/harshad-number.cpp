#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/harshad-number.h"

namespace leetcode {
namespace problem_3099 {

class HarshadNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  HarshadNumberSolution solution_;
};

TEST_P(HarshadNumberTest, Example1) {
  EXPECT_EQ(solution_.sumOfTheDigitsOfHarshadNumber(18), 9);
}

TEST_P(HarshadNumberTest, Example2) {
  EXPECT_EQ(solution_.sumOfTheDigitsOfHarshadNumber(23), -1);
}

TEST_P(HarshadNumberTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(solution_.sumOfTheDigitsOfHarshadNumber(7), 7);
}

INSTANTIATE_TEST_SUITE_P(
    HarshadNumberTestSuite, HarshadNumberTest,
    ::testing::ValuesIn(HarshadNumberSolution().getStrategyNames()));

}  // namespace problem_3099
}  // namespace leetcode
