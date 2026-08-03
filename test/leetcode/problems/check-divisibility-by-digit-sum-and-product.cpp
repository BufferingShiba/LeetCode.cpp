#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/check-divisibility-by-digit-sum-and-product.h"

namespace leetcode::problem_3622 {

class CheckDivisibilityByDigitSumAndProductTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckDivisibilityByDigitSumAndProductSolution solution;
};

TEST_P(CheckDivisibilityByDigitSumAndProductTest, Example1) {
  EXPECT_TRUE(solution.checkDivisibility(99));
}

TEST_P(CheckDivisibilityByDigitSumAndProductTest, Example2) {
  EXPECT_FALSE(solution.checkDivisibility(23));
}

TEST_P(CheckDivisibilityByDigitSumAndProductTest, SelfAuthoredSingleDigit) {
  // n = 7: sum = 7, product = 7, total = 14, 7 % 14 != 0 -> false
  EXPECT_FALSE(solution.checkDivisibility(7));
  // n = 1: sum = 1, product = 1, total = 2, 1 % 2 != 0 -> false
  EXPECT_FALSE(solution.checkDivisibility(1));
}

TEST_P(CheckDivisibilityByDigitSumAndProductTest, SelfAuthoredIncludesZeroDigit) {
  // n = 10: sum = 1, product = 0, total = 1, 10 % 1 == 0 -> true
  EXPECT_TRUE(solution.checkDivisibility(10));
  // n = 100: sum = 1, product = 0, total = 1, 100 % 1 == 0 -> true
  EXPECT_TRUE(solution.checkDivisibility(100));
}

TEST_P(CheckDivisibilityByDigitSumAndProductTest, SelfAuthoredCompositeCase) {
  // n = 21: sum = 3, product = 2, total = 5, 21 % 5 != 0 -> false
  EXPECT_FALSE(solution.checkDivisibility(21));
  // n = 36: sum = 9, product = 18, total = 27, 36 % 27 != 0 -> false
  EXPECT_FALSE(solution.checkDivisibility(36));
}

INSTANTIATE_TEST_SUITE_P(
    CheckDivisibilityByDigitSumAndProductTestSuite,
    CheckDivisibilityByDigitSumAndProductTest,
    ::testing::ValuesIn(
        CheckDivisibilityByDigitSumAndProductSolution().getStrategyNames()));

}  // namespace leetcode::problem_3622
