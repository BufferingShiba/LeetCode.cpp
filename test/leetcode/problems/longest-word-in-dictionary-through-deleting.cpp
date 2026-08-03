#include "leetcode/problems/longest-word-in-dictionary-through-deleting.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_524 {
namespace {

class LongestWordInDictionaryThroughDeletingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LongestWordInDictionaryThroughDeletingSolution solution_;
};

TEST_P(LongestWordInDictionaryThroughDeletingTest, Example1) {
  std::string s = "abpcplea";
  std::vector<std::string> dictionary = {"ale", "apple", "monkey", "plea"};
  EXPECT_EQ("apple", solution_.findLongestWord(s, dictionary));
}

TEST_P(LongestWordInDictionaryThroughDeletingTest, Example2) {
  std::string s = "abpcplea";
  std::vector<std::string> dictionary = {"a", "b", "c"};
  EXPECT_EQ("a", solution_.findLongestWord(s, dictionary));
}

TEST_P(LongestWordInDictionaryThroughDeletingTest, SelfAuthoredEmptyResult) {
  std::string s = "abc";
  std::vector<std::string> dictionary = {"xyz", "de"};
  EXPECT_EQ("", solution_.findLongestWord(s, dictionary));
}

TEST_P(LongestWordInDictionaryThroughDeletingTest, SelfAuthoredLexicographicallySmallest) {
  std::string s = "abpcplea";
  std::vector<std::string> dictionary = {"apple", "plea"};
  EXPECT_EQ("apple", solution_.findLongestWord(s, dictionary));
}

INSTANTIATE_TEST_SUITE_P(
    LongestWordInDictionaryThroughDeletingTestSuite,
    LongestWordInDictionaryThroughDeletingTest,
    ::testing::ValuesIn(
        LongestWordInDictionaryThroughDeletingSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_524
}  // namespace leetcode
