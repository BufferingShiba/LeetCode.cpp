#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-word-in-dictionary.h"

namespace leetcode::problem_720 {

class LongestWordInDictionaryTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestWordInDictionarySolution solution;
};

TEST_P(LongestWordInDictionaryTest, Example1) {
  std::vector<std::string> words = {"w", "wo", "wor", "worl", "world"};
  EXPECT_EQ("world", solution.longestWord(words));
}

TEST_P(LongestWordInDictionaryTest, Example2) {
  std::vector<std::string> words = {"a", "banana", "app", "appl", "ap",
                                    "apply", "apple"};
  EXPECT_EQ("apple", solution.longestWord(words));
}

TEST_P(LongestWordInDictionaryTest, NoAnswer) {
  std::vector<std::string> words = {"ab", "bc"};
  EXPECT_EQ("", solution.longestWord(words));
}

TEST_P(LongestWordInDictionaryTest, SingleChar) {
  std::vector<std::string> words = {"a"};
  EXPECT_EQ("a", solution.longestWord(words));
}

TEST_P(LongestWordInDictionaryTest, LexicographicTieBreak) {
  std::vector<std::string> words = {"a", "b", "ab", "ac"};
  EXPECT_EQ("ab", solution.longestWord(words));
}

INSTANTIATE_TEST_SUITE_P(
    LongestWordInDictionaryTestSuite, LongestWordInDictionaryTest,
    ::testing::ValuesIn(
        LongestWordInDictionarySolution().getStrategyNames()));

}  // namespace leetcode::problem_720
