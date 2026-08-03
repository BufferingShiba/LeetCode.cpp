#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-strings-that-appear-as-substrings-in-word.h"

namespace leetcode {
namespace problem_1967 {
namespace {

class NumberOfStringsThatAppearAsSubstringsInWordTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfStringsThatAppearAsSubstringsInWordSolution solution;
};

TEST_P(NumberOfStringsThatAppearAsSubstringsInWordTest, Example1) {
  std::vector<std::string> patterns = {"a", "abc", "bc", "d"};
  std::string word = "abc";
  EXPECT_EQ(3, solution.numOfStrings(patterns, word));
}

TEST_P(NumberOfStringsThatAppearAsSubstringsInWordTest, Example2) {
  std::vector<std::string> patterns = {"a", "b", "c"};
  std::string word = "aaaaabbbbb";
  EXPECT_EQ(2, solution.numOfStrings(patterns, word));
}

TEST_P(NumberOfStringsThatAppearAsSubstringsInWordTest, Example3) {
  std::vector<std::string> patterns = {"a", "a", "a"};
  std::string word = "ab";
  EXPECT_EQ(3, solution.numOfStrings(patterns, word));
}

TEST_P(NumberOfStringsThatAppearAsSubstringsInWordTest, SelfAuthored_SingleCharNoMatch) {
  std::vector<std::string> patterns = {"z"};
  std::string word = "abc";
  EXPECT_EQ(0, solution.numOfStrings(patterns, word));
}

TEST_P(NumberOfStringsThatAppearAsSubstringsInWordTest, SelfAuthored_WholeWord) {
  std::vector<std::string> patterns = {"abc", "abcd", "ab"};
  std::string word = "abc";
  EXPECT_EQ(2, solution.numOfStrings(patterns, word));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfStringsThatAppearAsSubstringsInWordTests,
    NumberOfStringsThatAppearAsSubstringsInWordTest,
    ::testing::ValuesIn(
        NumberOfStringsThatAppearAsSubstringsInWordSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1967
}  // namespace leetcode
