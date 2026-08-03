#include <gtest/gtest.h>

#include "leetcode/problems/minimum-window-substring.h"

namespace leetcode {
namespace problem_76 {

class MinimumWindowSubstringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumWindowSubstringSolution solution_;
};

TEST_P(MinimumWindowSubstringTest, Example1) {
  EXPECT_EQ(solution_.minWindow("ADOBECODEBANC", "ABC"), "BANC");
}

TEST_P(MinimumWindowSubstringTest, Example2) {
  EXPECT_EQ(solution_.minWindow("a", "a"), "a");
}

TEST_P(MinimumWindowSubstringTest, Example3) {
  EXPECT_EQ(solution_.minWindow("a", "aa"), "");
}

TEST_P(MinimumWindowSubstringTest, NoWindowExists) {
  EXPECT_EQ(solution_.minWindow("abc", "def"), "");
}

TEST_P(MinimumWindowSubstringTest, EntireStringIsWindow) {
  EXPECT_EQ(solution_.minWindow("abc", "cba"), "abc");
}

TEST_P(MinimumWindowSubstringTest, DuplicateCharsInT) {
  // s="abcaacab", t="aabc": need a×2,b×1,c×1.
  // Minimal windows: "abca" (0-3) and "bcaa" (1-4), both length 4.
  EXPECT_EQ(solution_.minWindow("abcaacab", "aabc"), "abca");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumWindowSubstringTest,
    ::testing::ValuesIn(
        MinimumWindowSubstringSolution().getStrategyNames()));

}  // namespace problem_76
}  // namespace leetcode
