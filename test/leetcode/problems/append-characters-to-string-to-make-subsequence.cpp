#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/append-characters-to-string-to-make-subsequence.h"

namespace leetcode::problem_2486 {

class AppendCharactersToStringToMakeSubsequenceTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  AppendCharactersToStringToMakeSubsequenceSolution solution_;
};

TEST_P(AppendCharactersToStringToMakeSubsequenceTest, Example1) {
  EXPECT_EQ(solution_.appendCharacters("coaching", "coding"), 4);
}

TEST_P(AppendCharactersToStringToMakeSubsequenceTest, Example2) {
  EXPECT_EQ(solution_.appendCharacters("abcde", "a"), 0);
}

TEST_P(AppendCharactersToStringToMakeSubsequenceTest, Example3) {
  EXPECT_EQ(solution_.appendCharacters("z", "abcde"), 5);
}

TEST_P(AppendCharactersToStringToMakeSubsequenceTest, SelfAuthored) {
  // t already fully matched at start
  EXPECT_EQ(solution_.appendCharacters("hello", "he"), 0);
  // t fully matched scattered
  EXPECT_EQ(solution_.appendCharacters("abxcydze", "abcde"), 0);
  // need to append all
  EXPECT_EQ(solution_.appendCharacters("xyz", "abc"), 3);
  // single character each, match
  EXPECT_EQ(solution_.appendCharacters("a", "a"), 0);
  // single character each, no match
  EXPECT_EQ(solution_.appendCharacters("a", "b"), 1);
  // partial match
  EXPECT_EQ(solution_.appendCharacters("abcdef", "afz"), 1);
  // t longer than s, partial match
  EXPECT_EQ(solution_.appendCharacters("abc", "abcde"), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    AppendCharactersToStringToMakeSubsequenceTest,
    testing::ValuesIn(
        AppendCharactersToStringToMakeSubsequenceSolution().getStrategyNames()));

}  // namespace leetcode::problem_2486
