#include <gtest/gtest.h>

#include "leetcode/problems/sum-of-digit-differences-of-all-pairs.h"

class SumOfDigitDifferencesOfAllPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  leetcode::problem_3153::SumOfDigitDifferencesOfAllPairsSolution solution;
};

TEST_P(SumOfDigitDifferencesOfAllPairsTest, Example1) {
  std::vector<int> nums = {13, 23, 12};
  EXPECT_EQ(solution.sumDigitDifferences(nums), 4);
}

TEST_P(SumOfDigitDifferencesOfAllPairsTest, Example2) {
  std::vector<int> nums = {10, 10, 10, 10};
  EXPECT_EQ(solution.sumDigitDifferences(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SumOfDigitDifferencesOfAllPairsTest,
    ::testing::ValuesIn(
        leetcode::problem_3153::SumOfDigitDifferencesOfAllPairsSolution()
            .getStrategyNames()));
