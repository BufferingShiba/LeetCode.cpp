#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-common-words-with-one-occurrence.h"

namespace leetcode {
namespace problem_2085 {
namespace {

class CountCommonWordsWithOneOccurrenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  CountCommonWordsWithOneOccurrenceSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CountCommonWordsWithOneOccurrenceTest, Example1) {
  std::vector<std::string> words1 = {"leetcode", "is", "amazing", "as", "is"};
  std::vector<std::string> words2 = {"amazing", "leetcode", "is"};
  EXPECT_EQ(solution.countWords(words1, words2), 2);
}

TEST_P(CountCommonWordsWithOneOccurrenceTest, Example2) {
  std::vector<std::string> words1 = {"b", "bb", "bbb"};
  std::vector<std::string> words2 = {"a", "aa", "aaa"};
  EXPECT_EQ(solution.countWords(words1, words2), 0);
}

TEST_P(CountCommonWordsWithOneOccurrenceTest, Example3) {
  std::vector<std::string> words1 = {"a", "ab"};
  std::vector<std::string> words2 = {"a", "a", "a", "ab"};
  EXPECT_EQ(solution.countWords(words1, words2), 1);
}

TEST_P(CountCommonWordsWithOneOccurrenceTest, SelfAuthoredSingleSameOnce) {
  std::vector<std::string> words1 = {"hello"};
  std::vector<std::string> words2 = {"hello"};
  EXPECT_EQ(solution.countWords(words1, words2), 1);
}

TEST_P(CountCommonWordsWithOneOccurrenceTest, SelfAuthoredRepeatedBothSides) {
  std::vector<std::string> words1 = {"x", "x", "x"};
  std::vector<std::string> words2 = {"x", "x"};
  EXPECT_EQ(solution.countWords(words1, words2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountCommonWordsWithOneOccurrenceTestSuite,
    CountCommonWordsWithOneOccurrenceTest,
    ::testing::ValuesIn(
        CountCommonWordsWithOneOccurrenceSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2085
}  // namespace leetcode
