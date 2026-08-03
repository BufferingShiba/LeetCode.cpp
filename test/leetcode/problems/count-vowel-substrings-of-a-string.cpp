#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/count-vowel-substrings-of-a-string.h"

namespace leetcode {
namespace problem_2062 {

class CountVowelSubstringsOfAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountVowelSubstringsOfAStringSolution solution_;
};

TEST_P(CountVowelSubstringsOfAStringTest, Example1) {
  EXPECT_EQ(solution_.countVowelSubstrings("aeiouu"), 2);
}

TEST_P(CountVowelSubstringsOfAStringTest, Example2) {
  EXPECT_EQ(solution_.countVowelSubstrings("unicornarihan"), 0);
}

TEST_P(CountVowelSubstringsOfAStringTest, Example3) {
  EXPECT_EQ(solution_.countVowelSubstrings("cuaieuouac"), 7);
}

TEST_P(CountVowelSubstringsOfAStringTest, SelfAuthoredSingleVowel) {
  EXPECT_EQ(solution_.countVowelSubstrings("a"), 0);
}

TEST_P(CountVowelSubstringsOfAStringTest, SelfAuthoredNonVowelOnly) {
  EXPECT_EQ(solution_.countVowelSubstrings("bcdfg"), 0);
}

TEST_P(CountVowelSubstringsOfAStringTest, SelfAuthoredExactlyOne) {
  EXPECT_EQ(solution_.countVowelSubstrings("aeiou"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountVowelSubstringsOfAStringTestSuite,
    CountVowelSubstringsOfAStringTest,
    ::testing::ValuesIn(
        CountVowelSubstringsOfAStringSolution().getStrategyNames()));

}  // namespace problem_2062
}  // namespace leetcode
