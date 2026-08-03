#include "leetcode/problems/sum-of-numbers-with-units-digit-k.h"

#include <gtest/gtest.h>

namespace leetcode::problem_2310 {

class SumOfNumbersWithUnitsDigitKTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfNumbersWithUnitsDigitKSolution solution;
};

TEST_P(SumOfNumbersWithUnitsDigitKTest, Example1) {
  EXPECT_EQ(solution.minimumNumbers(58, 9), 2);
}

TEST_P(SumOfNumbersWithUnitsDigitKTest, Example2) {
  EXPECT_EQ(solution.minimumNumbers(37, 2), -1);
}

TEST_P(SumOfNumbersWithUnitsDigitKTest, Example3) {
  EXPECT_EQ(solution.minimumNumbers(0, 7), 0);
}

TEST_P(SumOfNumbersWithUnitsDigitKTest, SelfAuthoredKIsZero) {
  // 个位为 0，只能使用 10 的倍数。
  EXPECT_EQ(solution.minimumNumbers(10, 0), 1);
  EXPECT_EQ(solution.minimumNumbers(20, 0), 1);
}

TEST_P(SumOfNumbersWithUnitsDigitKTest, SelfAuthoredSingleNumber) {
  EXPECT_EQ(solution.minimumNumbers(7, 7), 1);
  EXPECT_EQ(solution.minimumNumbers(9, 9), 1);
}

TEST_P(SumOfNumbersWithUnitsDigitKTest, SelfAuthoredImpossibleOddSum) {
  // num = 5, k = 2: 只能使用 12,22,...，最小 12 > 5。
  EXPECT_EQ(solution.minimumNumbers(5, 2), -1);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfNumbersWithUnitsDigitKTestCases,
    SumOfNumbersWithUnitsDigitKTest,
    testing::ValuesIn(SumOfNumbersWithUnitsDigitKSolution().getStrategyNames()));

}  // namespace leetcode::problem_2310
