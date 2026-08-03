#include "leetcode/problems/palindromic-substrings.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_647 {
namespace {

class PalindromicSubstringsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PalindromicSubstringsSolution solution_;
};

TEST_P(PalindromicSubstringsTest, Example1) {
  EXPECT_EQ(solution_.countSubstrings("abc"), 3);
}

TEST_P(PalindromicSubstringsTest, Example2) {
  EXPECT_EQ(solution_.countSubstrings("aaa"), 6);
}

TEST_P(PalindromicSubstringsTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution_.countSubstrings("a"), 1);
}

TEST_P(PalindromicSubstringsTest, SelfAuthoredTwoSameCharacters) {
  EXPECT_EQ(solution_.countSubstrings("aa"), 3);
}

TEST_P(PalindromicSubstringsTest, SelfAuthoredAllDistinct) {
  EXPECT_EQ(solution_.countSubstrings("abcd"), 4);
}

TEST_P(PalindromicSubstringsTest, SelfAuthoredAlternatingPalindrome) {
  EXPECT_EQ(solution_.countSubstrings("aba"), 4);
}

INSTANTIATE_TEST_SUITE_P(
    PalindromicSubstringsStrategies, PalindromicSubstringsTest,
    ::testing::ValuesIn(PalindromicSubstringsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_647
}  // namespace leetcode
