#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/sum-of-gcd-of-formed-pairs.h"

using namespace leetcode::problem_3867;

class SumOfGcdOfFormedPairsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  SumOfGcdOfFormedPairsSolution solution;
};

TEST_P(SumOfGcdOfFormedPairsTest, Example1) {
  std::vector<int> nums = {2, 6, 4};
  EXPECT_EQ(solution.gcdSum(nums), 2);
}

TEST_P(SumOfGcdOfFormedPairsTest, Example2) {
  std::vector<int> nums = {3, 6, 2, 8};
  EXPECT_EQ(solution.gcdSum(nums), 5);
}

TEST_P(SumOfGcdOfFormedPairsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(solution.gcdSum(nums), 0);
}

TEST_P(SumOfGcdOfFormedPairsTest, SelfAuthoredAllSame) {
  std::vector<int> nums = {5, 5, 5, 5};
  // prefixGcd = [5,5,5,5], sorted = [5,5,5,5]
  // pairs: gcd(5,5)=5, gcd(5,5)=5 => sum=10
  EXPECT_EQ(solution.gcdSum(nums), 10);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SumOfGcdOfFormedPairsTest,
    testing::ValuesIn(SumOfGcdOfFormedPairsSolution().getStrategyNames()));
