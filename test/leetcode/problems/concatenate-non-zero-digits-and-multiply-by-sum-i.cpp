#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/concatenate-non-zero-digits-and-multiply-by-sum-i.h"

namespace leetcode::problem_3754 {

class ConcatenateNonZeroDigitsAndMultiplyBySumITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ConcatenateNonZeroDigitsAndMultiplyBySumISolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ConcatenateNonZeroDigitsAndMultiplyBySumITest, Example1) {
  EXPECT_EQ(solution.sumAndMultiply(10203004), 12340LL);
}

TEST_P(ConcatenateNonZeroDigitsAndMultiplyBySumITest, Example2) {
  EXPECT_EQ(solution.sumAndMultiply(1000), 1LL);
}

TEST_P(ConcatenateNonZeroDigitsAndMultiplyBySumITest, AllZeroDigits) {
  EXPECT_EQ(solution.sumAndMultiply(0), 0LL);
}

TEST_P(ConcatenateNonZeroDigitsAndMultiplyBySumITest, NoZeroDigits) {
  EXPECT_EQ(solution.sumAndMultiply(12345), 12345LL * 15LL);
}

INSTANTIATE_TEST_SUITE_P(
    ConcatenateNonZeroDigitsAndMultiplyBySumITest,
    ConcatenateNonZeroDigitsAndMultiplyBySumITest,
    ::testing::ValuesIn(
        ConcatenateNonZeroDigitsAndMultiplyBySumISolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3754
