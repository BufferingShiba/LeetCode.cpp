#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/short-encoding-of-words.h"

namespace leetcode {
namespace problem_820 {

class ShortEncodingOfWordsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShortEncodingOfWordsSolution solution;
};

TEST_P(ShortEncodingOfWordsTest, Example1) {
  std::vector<std::string> words = {"time", "me", "bell"};
  EXPECT_EQ(solution.minimumLengthEncoding(words), 10);
}

TEST_P(ShortEncodingOfWordsTest, Example2) {
  std::vector<std::string> words = {"t"};
  EXPECT_EQ(solution.minimumLengthEncoding(words), 2);
}

TEST_P(ShortEncodingOfWordsTest, SelfAuthored_AllSuffixes) {
  // "abcde", "bcde", "cde", "de", "e" → 只有 "abcde" 保留
  std::vector<std::string> words = {"abcde", "bcde", "cde", "de", "e"};
  EXPECT_EQ(solution.minimumLengthEncoding(words), 6);  // "abcde#" → 5+1=6
}

TEST_P(ShortEncodingOfWordsTest, SelfAuthored_NoOverlap) {
  // 没有后缀关系
  std::vector<std::string> words = {"abc", "def", "ghi"};
  EXPECT_EQ(solution.minimumLengthEncoding(words), 12);  // "abc#def#ghi#" → 3*(3+1)=12
}

TEST_P(ShortEncodingOfWordsTest, SelfAuthored_IdenticalWords) {
  // 相同单词去重后只保留一个
  std::vector<std::string> words = {"abc", "abc", "abc"};
  EXPECT_EQ(solution.minimumLengthEncoding(words), 4);  // "abc#" → 3+1=4
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ShortEncodingOfWordsTest,
    ::testing::ValuesIn(ShortEncodingOfWordsSolution().getStrategyNames()));

}  // namespace problem_820
}  // namespace leetcode
