#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/word-pattern.h"

namespace leetcode::problem_290 {

class WordPatternTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  WordPatternSolution solution;
};

TEST_P(WordPatternTest, Example1) {
  EXPECT_TRUE(solution.wordPattern("abba", "dog cat cat dog"));
}

TEST_P(WordPatternTest, Example2) {
  EXPECT_FALSE(solution.wordPattern("abba", "dog cat cat fish"));
}

TEST_P(WordPatternTest, Example3) {
  EXPECT_FALSE(solution.wordPattern("aaaa", "dog cat cat dog"));
}

TEST_P(WordPatternTest, SelfAuthoredMismatchedCount) {
  EXPECT_FALSE(solution.wordPattern("abba", "dog cat cat"));
}

TEST_P(WordPatternTest, SelfAuthoredSingle) {
  EXPECT_TRUE(solution.wordPattern("a", "dog"));
}

TEST_P(WordPatternTest, SelfAuthoredSameWordTwoLetters) {
  // Word "dog" maps to both 'a' and 'b' -> not a bijection.
  EXPECT_FALSE(solution.wordPattern("ab", "dog dog"));
}

INSTANTIATE_TEST_SUITE_P(
    WordPatternTestSuite, WordPatternTest,
    ::testing::ValuesIn(WordPatternSolution().getStrategyNames()));

}  // namespace leetcode::problem_290
