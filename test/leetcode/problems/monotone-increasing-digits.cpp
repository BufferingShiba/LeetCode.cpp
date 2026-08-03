#include "leetcode/problems/monotone-increasing-digits.h"
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_738 {

class MonotoneIncreasingDigitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MonotoneIncreasingDigitsSolution solution;
};

TEST_P(MonotoneIncreasingDigitsTest, Example1) {
  EXPECT_EQ(solution.monotoneIncreasingDigits(10), 9);
}

TEST_P(MonotoneIncreasingDigitsTest, Example2) {
  EXPECT_EQ(solution.monotoneIncreasingDigits(1234), 1234);
}

TEST_P(MonotoneIncreasingDigitsTest, Example3) {
  EXPECT_EQ(solution.monotoneIncreasingDigits(332), 299);
}

TEST_P(MonotoneIncreasingDigitsTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(solution.monotoneIncreasingDigits(0), 0);
  EXPECT_EQ(solution.monotoneIncreasingDigits(9), 9);
}

TEST_P(MonotoneIncreasingDigitsTest, SelfAuthoredAlreadyMonotone) {
  EXPECT_EQ(solution.monotoneIncreasingDigits(111), 111);
  EXPECT_EQ(solution.monotoneIncreasingDigits(199), 199);
  EXPECT_EQ(solution.monotoneIncreasingDigits(123456789), 123456789);
}

TEST_P(MonotoneIncreasingDigitsTest, SelfAuthoredBorrowAcrossDigits) {
  EXPECT_EQ(solution.monotoneIncreasingDigits(1000), 999);
  EXPECT_EQ(solution.monotoneIncreasingDigits(210), 199);
  EXPECT_EQ(solution.monotoneIncreasingDigits(120), 119);
}

INSTANTIATE_TEST_SUITE_P(
    MonotoneIncreasingDigitsTestSuite, MonotoneIncreasingDigitsTest,
    ::testing::ValuesIn(MonotoneIncreasingDigitsSolution().getStrategyNames()));

}  // namespace problem_738
}  // namespace leetcode
