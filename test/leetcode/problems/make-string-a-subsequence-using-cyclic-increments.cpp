#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/make-string-a-subsequence-using-cyclic-increments.h"

using namespace leetcode::problem_2825;

class MakeStringASubsequenceUsingCyclicIncrementsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MakeStringASubsequenceUsingCyclicIncrementsSolution solution;
};

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, Example1) {
  EXPECT_TRUE(solution.canMakeSubsequence("abc", "ad"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, Example2) {
  EXPECT_TRUE(solution.canMakeSubsequence("zc", "ad"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, Example3) {
  EXPECT_FALSE(solution.canMakeSubsequence("ab", "d"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, SelfAuthoredAlreadySubsequence) {
  // str2 is already a subsequence without any operation
  EXPECT_TRUE(solution.canMakeSubsequence("abcde", "ace"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, SelfAuthoredAllNeedIncrement) {
  // Each char in str1 needs exactly one increment to match str2
  EXPECT_TRUE(solution.canMakeSubsequence("abc", "bcd"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, SelfAuthoredWrapAroundZtoA) {
  // z wraps to a
  EXPECT_TRUE(solution.canMakeSubsequence("z", "a"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, SelfAuthoredSingleCharMatchNoOp) {
  EXPECT_TRUE(solution.canMakeSubsequence("a", "a"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, SelfAuthoredImpossibleCase) {
  // No way to get 'z' from 'a' (needs +25, only +1 allowed per char)
  EXPECT_FALSE(solution.canMakeSubsequence("a", "z"));
}

TEST_P(MakeStringASubsequenceUsingCyclicIncrementsTest, SelfAuthoredStr2LongerThanStr1) {
  EXPECT_FALSE(solution.canMakeSubsequence("ab", "abc"));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MakeStringASubsequenceUsingCyclicIncrementsTest,
    testing::ValuesIn(
        MakeStringASubsequenceUsingCyclicIncrementsSolution().getStrategyNames()));
