#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/check-if-all-characters-have-equal-number-of-occurrences.h"

using namespace leetcode::problem_1941;

class CheckIfAllCharactersHaveEqualNumberOfOccurrencesTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckIfAllCharactersHaveEqualNumberOfOccurrencesSolution solution;
};

TEST_P(CheckIfAllCharactersHaveEqualNumberOfOccurrencesTest, Examples) {
  // Example 1
  EXPECT_TRUE(solution.areOccurrencesEqual("abacbc"));
  // Example 2
  EXPECT_FALSE(solution.areOccurrencesEqual("aaabb"));
}

TEST_P(CheckIfAllCharactersHaveEqualNumberOfOccurrencesTest, SelfAuthored) {
  // Single character
  EXPECT_TRUE(solution.areOccurrencesEqual("z"));
  // All same character, 5 times
  EXPECT_TRUE(solution.areOccurrencesEqual("aaaaa"));
  // Two characters with different frequencies
  EXPECT_FALSE(solution.areOccurrencesEqual("aab"));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CheckIfAllCharactersHaveEqualNumberOfOccurrencesTest,
    testing::ValuesIn(
        CheckIfAllCharactersHaveEqualNumberOfOccurrencesSolution().getStrategyNames()));
