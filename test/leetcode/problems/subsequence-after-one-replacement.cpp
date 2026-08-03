#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/subsequence-after-one-replacement.h"

namespace leetcode {
namespace problem_3983 {
namespace {

class SubsequenceAfterOneReplacementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SubsequenceAfterOneReplacementSolution solution;
};

TEST_P(SubsequenceAfterOneReplacementTest, Example1) {
  EXPECT_TRUE(solution.canMakeSubsequence("cat", "chat"));
}

TEST_P(SubsequenceAfterOneReplacementTest, Example2) {
  EXPECT_FALSE(solution.canMakeSubsequence("plane", "apple"));
}

TEST_P(SubsequenceAfterOneReplacementTest, SelfAuthoredAlreadySubsequence) {
  EXPECT_TRUE(solution.canMakeSubsequence("abc", "aabcc"));
}

TEST_P(SubsequenceAfterOneReplacementTest, SelfAuthoredSingleCharReplace) {
  // s = "abc", replace 'a' with 'z' -> "zbc". t = "zbcc"
  EXPECT_TRUE(solution.canMakeSubsequence("abc", "zbcc"));
}

TEST_P(SubsequenceAfterOneReplacementTest, SelfAuthoredNeedTwoReplacements) {
  // Match 'a'->'a'(skip b), need c and d too -> "ac" vs "abd"
  // s="ac", t="abd": replace 'a'->'a'? already matches. Actually "ac":
  // a matches a, c: need to match c in "bd" - c not present, but can we
  // replace one char? "ac" replace c->? must be subsequence of "abd".
  // 'a' matches, then 'c' must match 'b' or 'd'. Replace c->b gives "ab"
  // which is a subsequence of "abd". So it should be TRUE.
  EXPECT_TRUE(solution.canMakeSubsequence("ac", "abd"));
}

TEST_P(SubsequenceAfterOneReplacementTest, SelfAuthoredImpossibleCase) {
  // s = "abc", t = "xy". Not enough chars in t even with one replacement.
  EXPECT_FALSE(solution.canMakeSubsequence("abc", "xy"));
}

TEST_P(SubsequenceAfterOneReplacementTest, SelfAuthoredEmptySuffixAfterReplace) {
  // Replace last char only; prefix must fully match.
  // s="abc", t="abz" -> replace c->z gives "abz", subsequence of "abz".
  EXPECT_TRUE(solution.canMakeSubsequence("abc", "abz"));
}

TEST_P(SubsequenceAfterOneReplacementTest, SelfAuthoredReplaceOnlyCharMatches) {
  // s single char always workable if t non-empty (replace to fit).
  EXPECT_TRUE(solution.canMakeSubsequence("x", "abc"));
}

TEST_P(SubsequenceAfterOneReplacementTest, SelfAuthoredBiggerThanT) {
  // s longer than t always impossible.
  EXPECT_FALSE(solution.canMakeSubsequence("abcd", "ab"));
}

INSTANTIATE_TEST_SUITE_P(
    SubsequenceAfterOneReplacementTestCases,
    SubsequenceAfterOneReplacementTest,
    ::testing::ValuesIn(SubsequenceAfterOneReplacementSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3983
}  // namespace leetcode
