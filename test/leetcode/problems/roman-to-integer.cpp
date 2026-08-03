#include <gtest/gtest.h>

#include "leetcode/problems/roman-to-integer.h"

namespace leetcode {
namespace problem_13 {

class RomanToIntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RomanToIntegerSolution solution_;
};

TEST_P(RomanToIntegerTest, Example1) {
  EXPECT_EQ(solution_.romanToInt("III"), 3);
}

TEST_P(RomanToIntegerTest, Example2) {
  EXPECT_EQ(solution_.romanToInt("LVIII"), 58);
}

TEST_P(RomanToIntegerTest, Example3) {
  EXPECT_EQ(solution_.romanToInt("MCMXCIV"), 1994);
}

TEST_P(RomanToIntegerTest, SelfAuthoredSingleSymbol) {
  EXPECT_EQ(solution_.romanToInt("M"), 1000);
}

TEST_P(RomanToIntegerTest, SelfAuthoredAllSubtractionRule) {
  EXPECT_EQ(solution_.romanToInt("MCMXCIV"), 1994);
}

TEST_P(RomanToIntegerTest, SelfAuthoredMaxValue) {
  EXPECT_EQ(solution_.romanToInt("MMMCMXCIX"), 3999);
}

INSTANTIATE_TEST_SUITE_P(
    RomanToIntegerTestSuite, RomanToIntegerTest,
    ::testing::ValuesIn(RomanToIntegerSolution().getStrategyNames()));

}  // namespace problem_13
}  // namespace leetcode
