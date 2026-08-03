#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/smallest-value-after-replacing-with-sum-of-prime-factors.h"

namespace leetcode::problem_2507 {

class SmallestValueAfterReplacingWithSumOfPrimeFactorsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  SmallestValueAfterReplacingWithSumOfPrimeFactorsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SmallestValueAfterReplacingWithSumOfPrimeFactorsTest, Example1) {
  EXPECT_EQ(solution.smallestValue(15), 5);
}

TEST_P(SmallestValueAfterReplacingWithSumOfPrimeFactorsTest, Example2) {
  EXPECT_EQ(solution.smallestValue(3), 3);
}

TEST_P(SmallestValueAfterReplacingWithSumOfPrimeFactorsTest, SelfAuthoredEdgeCases) {
  EXPECT_EQ(solution.smallestValue(2), 2);   // prime
  EXPECT_EQ(solution.smallestValue(4), 4);   // 2+2=4 stays
  EXPECT_EQ(solution.smallestValue(100), 5); // 100->14->9->6->5
}

INSTANTIATE_TEST_SUITE_P(
    SmallestValueAfterReplacingWithSumOfPrimeFactorsTest, SmallestValueAfterReplacingWithSumOfPrimeFactorsTest,
    ::testing::ValuesIn(SmallestValueAfterReplacingWithSumOfPrimeFactorsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2507
