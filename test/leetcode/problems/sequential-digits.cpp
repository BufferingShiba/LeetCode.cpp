#include "leetcode/problems/sequential-digits.h"

#include <gtest/gtest.h>

namespace leetcode::problem_1291 {

class SequentialDigitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SequentialDigitsSolution solution_;
};

TEST_P(SequentialDigitsTest, Example1) {
  std::vector<int> expected{123, 234};
  EXPECT_EQ(expected, solution_.sequentialDigits(100, 300));
}

TEST_P(SequentialDigitsTest, Example2) {
  std::vector<int> expected{1234, 2345, 3456, 4567, 5678, 6789, 12345};
  EXPECT_EQ(expected, solution_.sequentialDigits(1000, 13000));
}

TEST_P(SequentialDigitsTest, SelfAuthoredSingleSequential) {
  // low == high, exactly one sequential number.
  EXPECT_EQ(std::vector<int>{12}, solution_.sequentialDigits(12, 12));
}

TEST_P(SequentialDigitsTest, SelfAuthoredNoResultInSmallRange) {
  // 10..11 contain no sequential digits.
  EXPECT_TRUE(solution_.sequentialDigits(10, 11).empty());
}

TEST_P(SequentialDigitsTest, SelfAuthoredMaxRange) {
  // Full range covers all sequential digits.
  std::vector<int> expected{12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345,
                            456, 567, 678, 789, 1234, 2345, 3456, 4567,
                            5678, 6789, 12345, 23456, 34567, 45678, 56789,
                            123456, 234567, 345678, 456789, 1234567,
                            2345678, 3456789, 12345678, 23456789, 123456789};
  EXPECT_EQ(expected, solution_.sequentialDigits(10, 1000000000));
}

INSTANTIATE_TEST_SUITE_P(
    SequentialDigitsStrategies, SequentialDigitsTest,
    ::testing::ValuesIn(SequentialDigitsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1291
