#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-valid-strings-to-form-target-ii.h"

using leetcode::problem_3292::MinimumNumberOfValidStringsToFormTargetIiSolution;

class MinimumNumberOfValidStringsToFormTargetIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { strategy_ = GetParam(); }

  int minValidStrings(std::vector<std::string> words, std::string target) {
    MinimumNumberOfValidStringsToFormTargetIiSolution solution;
    solution.setStrategy(strategy_);
    return solution.minValidStrings(words, std::move(target));
  }

  std::string strategy_;
};

TEST_P(MinimumNumberOfValidStringsToFormTargetIiTest, Example1) {
  std::vector<std::string> words = {"abc", "aaaaa", "bcdef"};
  EXPECT_EQ(3, minValidStrings(words, "aabcdabc"));
}

TEST_P(MinimumNumberOfValidStringsToFormTargetIiTest, Example2) {
  std::vector<std::string> words = {"abababab", "ab"};
  EXPECT_EQ(2, minValidStrings(words, "ababaababa"));
}

TEST_P(MinimumNumberOfValidStringsToFormTargetIiTest, Example3) {
  std::vector<std::string> words = {"abcdef"};
  EXPECT_EQ(-1, minValidStrings(words, "xyz"));
}

TEST_P(MinimumNumberOfValidStringsToFormTargetIiTest, SelfAuthoredSingleCharTarget) {
  std::vector<std::string> words = {"abc"};
  EXPECT_EQ(1, minValidStrings(words, "a"));
}

TEST_P(MinimumNumberOfValidStringsToFormTargetIiTest, SelfAuthoredSingleCharImpossible) {
  std::vector<std::string> words = {"abc"};
  EXPECT_EQ(-1, minValidStrings(words, "z"));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfValidStringsToFormTargetIiStrategies,
    MinimumNumberOfValidStringsToFormTargetIiTest,
    ::testing::ValuesIn(
        MinimumNumberOfValidStringsToFormTargetIiSolution().getStrategyNames()));
