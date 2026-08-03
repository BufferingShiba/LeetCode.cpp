#include <gtest/gtest.h>

#include "leetcode/problems/nth-digit.h"

namespace leetcode::problem_400 {

class NthDigitTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NthDigitSolution solution;
};

TEST_P(NthDigitTest, Example1) {
  EXPECT_EQ(solution.findNthDigit(3), 3);
}

TEST_P(NthDigitTest, Example2) {
  EXPECT_EQ(solution.findNthDigit(11), 0);
}

TEST_P(NthDigitTest, SelfAuthoredSingleDigitRange) {
  EXPECT_EQ(solution.findNthDigit(1), 1);
  EXPECT_EQ(solution.findNthDigit(9), 9);
}

TEST_P(NthDigitTest, SelfAuthoredTransitionToTwoDigits) {
  // n=10: first digit of 10 → '1'
  EXPECT_EQ(solution.findNthDigit(10), 1);
  // n=12: first digit of 11 → '1'
  EXPECT_EQ(solution.findNthDigit(12), 1);
  // n=13: second digit of 11 → '1'
  EXPECT_EQ(solution.findNthDigit(13), 1);
  // n=14: first digit of 12 → '1'
  EXPECT_EQ(solution.findNthDigit(14), 1);
  // n=15: second digit of 12 → '2'
  EXPECT_EQ(solution.findNthDigit(15), 2);
}

TEST_P(NthDigitTest, SelfAuthoredTransitionToThreeDigits) {
  // n=189: last digit of 99 → '9'
  EXPECT_EQ(solution.findNthDigit(189), 9);
  // n=190: first digit of 100 → '1'
  EXPECT_EQ(solution.findNthDigit(190), 1);
  // n=191: second digit of 100 → '0'
  EXPECT_EQ(solution.findNthDigit(191), 0);
  // n=192: third digit of 100 → '0'
  EXPECT_EQ(solution.findNthDigit(192), 0);
  // n=193: first digit of 101 → '1'
  EXPECT_EQ(solution.findNthDigit(193), 1);
}

TEST_P(NthDigitTest, SelfAuthoredLargeN) {
  // Some larger values to stress-test
  // n=1000: should be in 3-digit range
  // Let's compute: 9 + 180 = 189, 189 + 2700 = 2889
  // n=1000-189=811 in 3-digit. (811-1)/3=270, num=100+270=370, (811-1)%3=0 → '3'
  EXPECT_EQ(solution.findNthDigit(1000), 3);

  // n=10000: after 9+180+2700=2889, remaining=7111 in 4-digit
  // (7111-1)/4=1777, num=1000+1777=2777, (7111-1)%4=2
  // 2777 digits: 2(0),7(1),7(2),7(3). Index 2 → '7'
  EXPECT_EQ(solution.findNthDigit(10000), 7);
}

INSTANTIATE_TEST_SUITE_P(Strategies, NthDigitTest,
                         ::testing::ValuesIn(NthDigitSolution().getStrategyNames()));

}  // namespace leetcode::problem_400
