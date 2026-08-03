#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-only-letters.h"

namespace leetcode::problem_917 {

class ReverseOnlyLettersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  ReverseOnlyLettersSolution solution_;
};

TEST_P(ReverseOnlyLettersTest, Example1) {
  EXPECT_EQ("dc-ba", solution_.reverseOnlyLetters("ab-cd"));
}

TEST_P(ReverseOnlyLettersTest, Example2) {
  EXPECT_EQ("j-Ih-gfE-dCba", solution_.reverseOnlyLetters("a-bC-dEf-ghIj"));
}

TEST_P(ReverseOnlyLettersTest, Example3) {
  EXPECT_EQ("Qedo1ct-eeLg=ntse-T!",
            solution_.reverseOnlyLetters("Test1ng-Leet=code-Q!"));
}

TEST_P(ReverseOnlyLettersTest, SelfAuthoredNoLetters) {
  EXPECT_EQ("123!@#", solution_.reverseOnlyLetters("123!@#"));
}

TEST_P(ReverseOnlyLettersTest, SelfAuthoredSingleLetter) {
  EXPECT_EQ("a", solution_.reverseOnlyLetters("a"));
}

TEST_P(ReverseOnlyLettersTest, SelfAuthoredAllLetters) {
  EXPECT_EQ("zyxwv", solution_.reverseOnlyLetters("vwxyz"));
}

INSTANTIATE_TEST_SUITE_P(
    ReverseOnlyLettersTestSuite, ReverseOnlyLettersTest,
    ::testing::ValuesIn(ReverseOnlyLettersSolution().getStrategyNames()));

}  // namespace leetcode::problem_917
