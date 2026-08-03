#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/count-vowels-permutation.h"

namespace leetcode::problem_1220 {

class CountVowelsPermutationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountVowelsPermutationSolution solution;
};

TEST_P(CountVowelsPermutationTest, Example1) {
  EXPECT_EQ(solution.getSolution()(1), 5);
}

TEST_P(CountVowelsPermutationTest, Example2) {
  EXPECT_EQ(solution.getSolution()(2), 10);
}

TEST_P(CountVowelsPermutationTest, SelfAuthoredExample3) {
  EXPECT_EQ(solution.getSolution()(5), 68);
}

TEST_P(CountVowelsPermutationTest, SelfAuthoredLargeN) {
  // n = 20000, result modulo 1e9+7. Simply assert it runs and is within range.
  int res = solution.getSolution()(20000);
  EXPECT_GE(res, 0);
  EXPECT_LT(res, 1000000007);
}

INSTANTIATE_TEST_SUITE_P(
    CountVowelsPermutationTestSuite, CountVowelsPermutationTest,
    ::testing::ValuesIn(CountVowelsPermutationSolution().getStrategyNames()));

}  // namespace leetcode::problem_1220
