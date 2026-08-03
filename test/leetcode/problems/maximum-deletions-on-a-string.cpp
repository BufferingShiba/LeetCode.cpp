#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/maximum-deletions-on-a-string.h"

namespace leetcode::problem_2430 {

using MaximumDeletionsOnAStringTest = ::testing::TestWithParam<std::string>;

namespace {
int solve(const std::string& strategy, const std::string& s) {
  MaximumDeletionsOnAStringSolution sol;
  sol.setStrategy(strategy);
  return sol.deleteString(s);
}
}  // namespace

TEST_P(MaximumDeletionsOnAStringTest, Example1) {
  const std::string strategy = GetParam();
  EXPECT_EQ(solve(strategy, "abcabcdabc"), 2);
}

TEST_P(MaximumDeletionsOnAStringTest, Example2) {
  const std::string strategy = GetParam();
  EXPECT_EQ(solve(strategy, "aaabaab"), 4);
}

TEST_P(MaximumDeletionsOnAStringTest, Example3) {
  const std::string strategy = GetParam();
  EXPECT_EQ(solve(strategy, "aaaaa"), 5);
}

TEST_P(MaximumDeletionsOnAStringTest, SelfAuthoredEdgeCases) {
  const std::string strategy = GetParam();
  EXPECT_EQ(solve(strategy, "a"), 1);
  EXPECT_EQ(solve(strategy, "aa"), 2);
  EXPECT_EQ(solve(strategy, "ababa"), 2);  // delete "ab" -> "aba", delete all -> 2
  EXPECT_EQ(solve(strategy, "abab"), 2);   // delete "ab" -> "ab", delete all -> 2
}

INSTANTIATE_TEST_SUITE_P(
    MaximumDeletionsOnAStringTestSuite,
    MaximumDeletionsOnAStringTest,
    ::testing::ValuesIn(MaximumDeletionsOnAStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_2430
