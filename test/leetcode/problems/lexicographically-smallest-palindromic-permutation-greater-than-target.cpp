#include <gtest/gtest.h>

#include "leetcode/problems/lexicographically-smallest-palindromic-permutation-greater-than-target.h"

using namespace leetcode::problem_3734;

class LexicographicallySmallestPalindromicPermutationGreaterThanTargetTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LexicographicallySmallestPalindromicPermutationGreaterThanTargetSolution
      solution;
};

TEST_P(LexicographicallySmallestPalindromicPermutationGreaterThanTargetTest,
       Example1) {
  EXPECT_EQ(solution.lexPalindromicPermutation("baba", "abba"), "baab");
}

TEST_P(LexicographicallySmallestPalindromicPermutationGreaterThanTargetTest,
       Example2) {
  EXPECT_EQ(solution.lexPalindromicPermutation("baba", "bbaa"), "");
}

TEST_P(LexicographicallySmallestPalindromicPermutationGreaterThanTargetTest,
       Example3) {
  EXPECT_EQ(solution.lexPalindromicPermutation("abc", "abb"), "");
}

TEST_P(LexicographicallySmallestPalindromicPermutationGreaterThanTargetTest,
       Example4) {
  EXPECT_EQ(solution.lexPalindromicPermutation("aac", "abb"), "aca");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    LexicographicallySmallestPalindromicPermutationGreaterThanTargetTest,
    testing::ValuesIn(
        LexicographicallySmallestPalindromicPermutationGreaterThanTargetSolution()
            .getStrategyNames()));
