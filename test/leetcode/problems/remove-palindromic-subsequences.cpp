#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/remove-palindromic-subsequences.h"

namespace leetcode::problem_1332 {

class RemovePalindromicSubsequencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RemovePalindromicSubsequencesSolution solution_;
};

TEST_P(RemovePalindromicSubsequencesTest, Example1) {
  EXPECT_EQ(1, solution_.removePalindromeSub("ababa"));
}

TEST_P(RemovePalindromicSubsequencesTest, Example2) {
  EXPECT_EQ(2, solution_.removePalindromeSub("abb"));
}

TEST_P(RemovePalindromicSubsequencesTest, Example3) {
  EXPECT_EQ(2, solution_.removePalindromeSub("baabb"));
}

TEST_P(RemovePalindromicSubsequencesTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(1, solution_.removePalindromeSub("a"));
}

TEST_P(RemovePalindromicSubsequencesTest, SelfAuthoredMixedNonPalindrome) {
  EXPECT_EQ(2, solution_.removePalindromeSub("ab"));
}

INSTANTIATE_TEST_SUITE_P(
    RemovePalindromicSubsequencesTestSuite, RemovePalindromicSubsequencesTest,
    ::testing::ValuesIn(
        RemovePalindromicSubsequencesSolution().getStrategyNames()));

}  // namespace leetcode::problem_1332
