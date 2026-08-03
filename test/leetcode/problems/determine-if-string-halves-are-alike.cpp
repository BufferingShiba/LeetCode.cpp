#include <gtest/gtest.h>

#include "leetcode/problems/determine-if-string-halves-are-alike.h"

using namespace leetcode::problem_1704;

class DetermineIfStringHalvesAreAlikeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  DetermineIfStringHalvesAreAlikeSolution solution;
};

TEST_P(DetermineIfStringHalvesAreAlikeTest, Example1) {
  EXPECT_TRUE(solution.halvesAreAlike("book"));
}

TEST_P(DetermineIfStringHalvesAreAlikeTest, Example2) {
  EXPECT_FALSE(solution.halvesAreAlike("textbook"));
}

TEST_P(DetermineIfStringHalvesAreAlikeTest, SelfAuthoredAllConsonants) {
  EXPECT_TRUE(solution.halvesAreAlike("bcdfghjkl"));
}

TEST_P(DetermineIfStringHalvesAreAlikeTest, SelfAuthoredMixedCase) {
  EXPECT_TRUE(solution.halvesAreAlike("AbCdEfGh"));
}

TEST_P(DetermineIfStringHalvesAreAlikeTest, SelfAuthoredUnequalHalves) {
  EXPECT_FALSE(solution.halvesAreAlike("abcixyzu"));
}

INSTANTIATE_TEST_SUITE_P(DetermineIfStringHalvesAreAlike,
                         DetermineIfStringHalvesAreAlikeTest,
                         testing::ValuesIn(
                             DetermineIfStringHalvesAreAlikeSolution().getStrategyNames()));
