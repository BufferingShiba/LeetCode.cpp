#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/largest-3-same-digit-number-in-string.h"

namespace leetcode::problem_2264 {

class Largest3SameDigitNumberInStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  Largest3SameDigitNumberInStringSolution solution_;
};

TEST_P(Largest3SameDigitNumberInStringTest, Example1) {
  EXPECT_EQ("777", solution_.largestGoodInteger("6777133339"));
}

TEST_P(Largest3SameDigitNumberInStringTest, Example2) {
  EXPECT_EQ("000", solution_.largestGoodInteger("2300019"));
}

TEST_P(Largest3SameDigitNumberInStringTest, Example3) {
  EXPECT_EQ("", solution_.largestGoodInteger("42352338"));
}

TEST_P(Largest3SameDigitNumberInStringTest, SelfAuthoredNoGoodInteger) {
  EXPECT_EQ("", solution_.largestGoodInteger("123"));
}

TEST_P(Largest3SameDigitNumberInStringTest, SelfAuthoredAllSame) {
  EXPECT_EQ("999", solution_.largestGoodInteger("999"));
}

INSTANTIATE_TEST_SUITE_P(
    Largest3SameDigitNumberInStringTestSuite,
    Largest3SameDigitNumberInStringTest,
    ::testing::ValuesIn(
        Largest3SameDigitNumberInStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_2264
