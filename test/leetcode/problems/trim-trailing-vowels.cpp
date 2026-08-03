#include "leetcode/problems/trim-trailing-vowels.h"

#include <gtest/gtest.h>

#include <string>

namespace leetcode::problem_3856 {

class TrimTrailingVowelsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TrimTrailingVowelsSolution solution_;
};

TEST_P(TrimTrailingVowelsTest, Example1) {
  EXPECT_EQ("id", solution_.trimTrailingVowels("idea"));
}

TEST_P(TrimTrailingVowelsTest, Example2) {
  EXPECT_EQ("day", solution_.trimTrailingVowels("day"));
}

TEST_P(TrimTrailingVowelsTest, Example3) {
  EXPECT_EQ("", solution_.trimTrailingVowels("aeiou"));
}

TEST_P(TrimTrailingVowelsTest, SelfAuthoredAllConsonants) {
  EXPECT_EQ("xyz", solution_.trimTrailingVowels("xyz"));
}

TEST_P(TrimTrailingVowelsTest, SelfAuthoredSingleVowel) {
  EXPECT_EQ("", solution_.trimTrailingVowels("a"));
}

INSTANTIATE_TEST_SUITE_P(
    TrimTrailingVowelsTestSuite, TrimTrailingVowelsTest,
    ::testing::ValuesIn(TrimTrailingVowelsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3856
