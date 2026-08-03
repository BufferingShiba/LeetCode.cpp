#include "leetcode/problems/count-valid-word-occurrences.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3926 {
namespace {

class CountValidWordOccurrencesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountValidWordOccurrencesSolution solution;
};

TEST_P(CountValidWordOccurrencesTest, Example1) {
  std::vector<std::string> chunks = {"hello wor", "ld hello"};
  std::vector<std::string> queries = {"hello", "world", "wor"};
  std::vector<int> expected = {2, 1, 0};
  EXPECT_EQ(solution.countWordOccurrences(chunks, queries), expected);
}

TEST_P(CountValidWordOccurrencesTest, Example2) {
  std::vector<std::string> chunks = {"a-b a--b ", "a-", "b"};
  std::vector<std::string> queries = {"a-b", "a", "b"};
  std::vector<int> expected = {2, 1, 1};
  EXPECT_EQ(solution.countWordOccurrences(chunks, queries), expected);
}

TEST_P(CountValidWordOccurrencesTest, Example3) {
  std::vector<std::string> chunks = {"-cat dog- mouse"};
  std::vector<std::string> queries = {"cat", "dog", "mouse", "cat-dog"};
  std::vector<int> expected = {1, 1, 1, 0};
  EXPECT_EQ(solution.countWordOccurrences(chunks, queries), expected);
}

TEST_P(CountValidWordOccurrencesTest, SelfAuthoredSingleWord) {
  std::vector<std::string> chunks = {"abc"};
  std::vector<std::string> queries = {"abc", "ab"};
  std::vector<int> expected = {1, 0};
  EXPECT_EQ(solution.countWordOccurrences(chunks, queries), expected);
}

TEST_P(CountValidWordOccurrencesTest, SelfAuthoredEdgeHyphens) {
  std::vector<std::string> chunks = {"-", "a", "-"};
  std::vector<std::string> queries = {"a", "-a", "a-"};
  std::vector<int> expected = {1, 0, 0};
  EXPECT_EQ(solution.countWordOccurrences(chunks, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CountValidWordOccurrencesTests,
    CountValidWordOccurrencesTest,
    ::testing::ValuesIn(CountValidWordOccurrencesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3926
}  // namespace leetcode
