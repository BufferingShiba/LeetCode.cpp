#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/regular-expression-matching.h"

namespace leetcode {
namespace problem_10 {

class RegularExpressionMatchingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RegularExpressionMatchingSolution solution;
};

TEST_P(RegularExpressionMatchingTest, Example1) {
  EXPECT_FALSE(solution.isMatch("aa", "a"));
}

TEST_P(RegularExpressionMatchingTest, Example2) {
  EXPECT_TRUE(solution.isMatch("aa", "a*"));
}

TEST_P(RegularExpressionMatchingTest, Example3) {
  EXPECT_TRUE(solution.isMatch("ab", ".*"));
}

TEST_P(RegularExpressionMatchingTest, SelfAuthoredExample4) {
  EXPECT_TRUE(solution.isMatch("aab", "c*a*b"));
}

TEST_P(RegularExpressionMatchingTest, SelfAuthoredExample5) {
  EXPECT_FALSE(solution.isMatch("mississippi", "mis*is*p*."));
}

TEST_P(RegularExpressionMatchingTest, SelfAuthoredStarZeroMatch) {
  EXPECT_TRUE(solution.isMatch("a", "b*a"));   // '*' 匹配零次
  EXPECT_TRUE(solution.isMatch("", "a*"));     // 空串也能被 a* 匹配
  EXPECT_TRUE(solution.isMatch("", "c*a*b*")); // 空串匹配多组零次
}

TEST_P(RegularExpressionMatchingTest, SelfAuthoredDotStarMatching) {
  EXPECT_TRUE(solution.isMatch("anything", ".*"));
  EXPECT_TRUE(solution.isMatch("abc", "a.c"));
  EXPECT_FALSE(solution.isMatch("ab", "a.c"));
}

INSTANTIATE_TEST_SUITE_P(
    RegularExpressionMatchingTestSuite, RegularExpressionMatchingTest,
    ::testing::ValuesIn(RegularExpressionMatchingSolution().getStrategyNames()));

}  // namespace problem_10
}  // namespace leetcode
