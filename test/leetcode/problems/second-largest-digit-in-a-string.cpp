#include <gtest/gtest.h>

#include "leetcode/problems/second-largest-digit-in-a-string.h"

namespace leetcode {
namespace problem_1796 {

class SecondLargestDigitInAStringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SecondLargestDigitInAStringSolution solution_;
};

TEST_P(SecondLargestDigitInAStringTest, OfficialExamples) {
  EXPECT_EQ(solution_.secondHighest("dfa12321afd"), 2);
  EXPECT_EQ(solution_.secondHighest("abc1111"), -1);
}

TEST_P(SecondLargestDigitInAStringTest, SelfAuthored) {
  // No digits at all
  EXPECT_EQ(solution_.secondHighest("abc"), -1);
  // Only one distinct digit
  EXPECT_EQ(solution_.secondHighest("5"), -1);
  // All digits 0-9 appear
  EXPECT_EQ(solution_.secondHighest("0123456789"), 8);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SecondLargestDigitInAStringTest,
    testing::ValuesIn(
        SecondLargestDigitInAStringSolution().getStrategyNames()));

}  // namespace problem_1796
}  // namespace leetcode
