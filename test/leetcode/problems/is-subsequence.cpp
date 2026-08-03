#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/is-subsequence.h"

namespace leetcode {
namespace problem_392 {

class IsSubsequenceTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IsSubsequenceSolution solution;
};

TEST_P(IsSubsequenceTest, Example1) {
  EXPECT_TRUE(solution.isSubsequence("abc", "ahbgdc"));
}

TEST_P(IsSubsequenceTest, Example2) {
  EXPECT_FALSE(solution.isSubsequence("axc", "ahbgdc"));
}

TEST_P(IsSubsequenceTest, SelfAuthoredEmptyString) {
  EXPECT_TRUE(solution.isSubsequence("", "ahbgdc"));
}

TEST_P(IsSubsequenceTest, SelfAuthoredEqualStrings) {
  EXPECT_TRUE(solution.isSubsequence("abc", "abc"));
}

TEST_P(IsSubsequenceTest, SelfAuthoredSLongerThanT) {
  EXPECT_FALSE(solution.isSubsequence("abcd", "abc"));
}

INSTANTIATE_TEST_SUITE_P(
    IsSubsequenceTestSuite, IsSubsequenceTest,
    ::testing::ValuesIn(IsSubsequenceSolution().getStrategyNames()));

}  // namespace problem_392
}  // namespace leetcode
