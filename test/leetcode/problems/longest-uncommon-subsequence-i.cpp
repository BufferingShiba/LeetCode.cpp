#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/longest-uncommon-subsequence-i.h"

namespace leetcode::problem_521 {

using LongestUncommonSubsequenceITest = LongestUncommonSubsequenceISolution;

class LongestUncommonSubsequenceITestP : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  LongestUncommonSubsequenceISolution solution_;
};

TEST_P(LongestUncommonSubsequenceITestP, Example1) {
  EXPECT_EQ(solution_.findLUSlength("aba", "cdc"), 3);
}

TEST_P(LongestUncommonSubsequenceITestP, Example2) {
  EXPECT_EQ(solution_.findLUSlength("aaa", "bbb"), 3);
}

TEST_P(LongestUncommonSubsequenceITestP, Example3) {
  EXPECT_EQ(solution_.findLUSlength("aaa", "aaa"), -1);
}

TEST_P(LongestUncommonSubsequenceITestP, SelfAuthoredSameStringLength) {
  EXPECT_EQ(solution_.findLUSlength("abc", "abd"), 3);
}

TEST_P(LongestUncommonSubsequenceITestP, SelfAuthoredDifferentLengths) {
  EXPECT_EQ(solution_.findLUSlength("ab", "abcde"), 5);
}

INSTANTIATE_TEST_SUITE_P(
    LongestUncommonSubsequenceI,
    LongestUncommonSubsequenceITestP,
    ::testing::ValuesIn(LongestUncommonSubsequenceISolution().getStrategyNames()));

}  // namespace leetcode::problem_521
