#include <gtest/gtest.h>

#include "leetcode/problems/words-within-two-edits-of-dictionary.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2452 {

class WordsWithinTwoEditsOfDictionaryTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  WordsWithinTwoEditsOfDictionarySolution solution;
};

TEST_P(WordsWithinTwoEditsOfDictionaryTest, Example1) {
  std::vector<std::string> queries = {"word", "note", "ants", "wood"};
  std::vector<std::string> dictionary = {"wood", "joke", "moat"};
  std::vector<std::string> expected = {"word", "note", "wood"};
  EXPECT_EQ(solution.twoEditWords(queries, dictionary), expected);
}

TEST_P(WordsWithinTwoEditsOfDictionaryTest, Example2) {
  std::vector<std::string> queries = {"yes"};
  std::vector<std::string> dictionary = {"not"};
  std::vector<std::string> expected = {};
  EXPECT_EQ(solution.twoEditWords(queries, dictionary), expected);
}

TEST_P(WordsWithinTwoEditsOfDictionaryTest, SelfAuthoredExactMatch) {
  std::vector<std::string> queries = {"abc", "def"};
  std::vector<std::string> dictionary = {"abc", "xyz"};
  std::vector<std::string> expected = {"abc"};
  EXPECT_EQ(solution.twoEditWords(queries, dictionary), expected);
}

TEST_P(WordsWithinTwoEditsOfDictionaryTest, SelfAuthoredTwoEditsExactBoundary) {
  std::vector<std::string> queries = {"aaaa", "aaab", "aabb"};
  std::vector<std::string> dictionary = {"bbbb"};
  // "aaaa"->"bbbb" 需 4 次；"aaab"->"bbbb" 需 3 次；"aabb"->"bbbb" 需 2 次。
  std::vector<std::string> expected = {"aabb"};
  EXPECT_EQ(solution.twoEditWords(queries, dictionary), expected);
}

INSTANTIATE_TEST_SUITE_P(
    WordsWithinTwoEditsOfDictionaryTestSuite,
    WordsWithinTwoEditsOfDictionaryTest,
    ::testing::ValuesIn(
        WordsWithinTwoEditsOfDictionarySolution().getStrategyNames()));

}  // namespace problem_2452
}  // namespace leetcode
