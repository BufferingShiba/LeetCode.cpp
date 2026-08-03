#include "leetcode/problems/repeated-string-match.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_686 {

class RepeatedStringMatchTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RepeatedStringMatchSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  a = "abcd", b = "cdabcdab"
// Output: 3
TEST_P(RepeatedStringMatchTest, OfficialExample1) {
  EXPECT_EQ(3, solution.repeatedStringMatch("abcd", "cdabcdab"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  a = "a", b = "aa"
// Output: 2
TEST_P(RepeatedStringMatchTest, OfficialExample2) {
  EXPECT_EQ(2, solution.repeatedStringMatch("a", "aa"));
}

// ===== Self-authored edge cases =====
// b cannot be formed
TEST_P(RepeatedStringMatchTest, NotPossibleCase) {
  EXPECT_EQ(-1, solution.repeatedStringMatch("abcd", "z"));
}

// b is already a substring of a
TEST_P(RepeatedStringMatchTest, SubstringInSingle) {
  EXPECT_EQ(1, solution.repeatedStringMatch("abc", "bc"));
}

// b fits exactly one copy of a
TEST_P(RepeatedStringMatchTest, ExactMatch) {
  EXPECT_EQ(1, solution.repeatedStringMatch("abc", "abc"));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, RepeatedStringMatchTest,
    ::testing::ValuesIn(RepeatedStringMatchSolution().getStrategyNames()));

}  // namespace problem_686
}  // namespace leetcode
