#include <gtest/gtest.h>

#include "leetcode/problems/concatenated-words.h"

#include <vector>
#include <string>
#include <algorithm>

namespace leetcode {
namespace problem_472 {
namespace {

std::vector<std::string> sortedSet(std::vector<std::string> v) {
  std::sort(v.begin(), v.end());
  return v;
}

}  // namespace

class ConcatenatedWordsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConcatenatedWordsSolution solution;
};

TEST_P(ConcatenatedWordsTest, Example1) {
  std::vector<std::string> words = {
      "cat", "cats", "catsdogcats", "dog", "dogcatsdog",
      "hippopotamuses", "rat", "ratcatdogcat"};
  std::vector<std::string> expected = {"catsdogcats", "dogcatsdog", "ratcatdogcat"};
  EXPECT_EQ(sortedSet(solution.findAllConcatenatedWordsInADict(words)), sortedSet(expected));
}

TEST_P(ConcatenatedWordsTest, Example2) {
  std::vector<std::string> words = {"cat", "dog", "catdog"};
  std::vector<std::string> expected = {"catdog"};
  EXPECT_EQ(sortedSet(solution.findAllConcatenatedWordsInADict(words)), sortedSet(expected));
}

TEST_P(ConcatenatedWordsTest, NoConcatenatedWord) {
  std::vector<std::string> words = {"a", "b", "abx"};
  std::vector<std::string> expected = {};
  EXPECT_EQ(solution.findAllConcatenatedWordsInADict(words), expected);
}

TEST_P(ConcatenatedWordsTest, SingleWordNotConcatenated) {
  std::vector<std::string> words = {"abc"};
  std::vector<std::string> expected = {};
  EXPECT_EQ(solution.findAllConcatenatedWordsInADict(words), expected);
}

TEST_P(ConcatenatedWordsTest, RepeatedShorterWord) {
  // "aaa" = "a" + "a" + "a", each "a" is a shorter dictionary word.
  std::vector<std::string> words = {"a", "aa", "aaa"};
  std::vector<std::string> expected = {"aa", "aaa"};
  EXPECT_EQ(sortedSet(solution.findAllConcatenatedWordsInADict(words)), sortedSet(expected));
}

INSTANTIATE_TEST_SUITE_P(
    ConcatenatedWordsTestSuite, ConcatenatedWordsTest,
    ::testing::ValuesIn(ConcatenatedWordsSolution().getStrategyNames()));

}  // namespace problem_472
}  // namespace leetcode
