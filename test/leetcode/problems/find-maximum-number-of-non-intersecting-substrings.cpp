#include <gtest/gtest.h>

#include "leetcode/problems/find-maximum-number-of-non-intersecting-substrings.h"

using namespace leetcode::problem_3557;

class FindMaximumNumberOfNonIntersectingSubstringsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindMaximumNumberOfNonIntersectingSubstringsSolution solution;
};

TEST_P(FindMaximumNumberOfNonIntersectingSubstringsTest, Examples) {
  EXPECT_EQ(solution.maxSubstrings("abcdeafdef"), 2);
  EXPECT_EQ(solution.maxSubstrings("bcdaaaab"), 1);
}

TEST_P(FindMaximumNumberOfNonIntersectingSubstringsTest, SelfAuthored) {
  // 长度不足 4，无法选出任何子串
  EXPECT_EQ(solution.maxSubstrings("abc"), 0);
  EXPECT_EQ(solution.maxSubstrings("aaaa"), 1);
  // 没有以相同字母开头结尾且长度 ≥ 4 的子串
  EXPECT_EQ(solution.maxSubstrings("abcd"), 0);
  // 多个不重叠子串：a...a 与 b...b 不相交
  EXPECT_EQ(solution.maxSubstrings("axxxabxxxb"), 2);
  // 嵌套子串：只能选一个
  EXPECT_EQ(solution.maxSubstrings("axxxa"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindMaximumNumberOfNonIntersectingSubstringsTest,
    testing::ValuesIn(
        FindMaximumNumberOfNonIntersectingSubstringsSolution().getStrategyNames()));
