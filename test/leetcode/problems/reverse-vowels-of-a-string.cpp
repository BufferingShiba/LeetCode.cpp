#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-vowels-of-a-string.h"

namespace leetcode::problem_345 {

class ReverseVowelsOfAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReverseVowelsOfAStringSolution solution_;
};

TEST_P(ReverseVowelsOfAStringTest, Example1) {
  EXPECT_EQ(solution_.reverseVowels("IceCreAm"), "AceCreIm");
}

TEST_P(ReverseVowelsOfAStringTest, Example2) {
  EXPECT_EQ(solution_.reverseVowels("leetcode"), "leotcede");
}

TEST_P(ReverseVowelsOfAStringTest, SelfAuthoredNoVowels) {
  EXPECT_EQ(solution_.reverseVowels("xyz"), "xyz");
}

TEST_P(ReverseVowelsOfAStringTest, SelfAuthoredSingleVowel) {
  EXPECT_EQ(solution_.reverseVowels("a"), "a");
}

TEST_P(ReverseVowelsOfAStringTest, SelfAuthoredAllVowels) {
  EXPECT_EQ(solution_.reverseVowels("aeiou"), "uoiea");
}

INSTANTIATE_TEST_SUITE_P(
    ReverseVowelsOfAStringTestParam, ReverseVowelsOfAStringTest,
    ::testing::ValuesIn(ReverseVowelsOfAStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_345
