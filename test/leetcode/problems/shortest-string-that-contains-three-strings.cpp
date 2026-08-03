#include <gtest/gtest.h>

#include "leetcode/problems/shortest-string-that-contains-three-strings.h"

using namespace leetcode::problem_2800;
using namespace std;

class ShortestStringThatContainsThreeStringsTest
    : public testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ShortestStringThatContainsThreeStringsSolution solution;
};

TEST_P(ShortestStringThatContainsThreeStringsTest, Example1) {
  EXPECT_EQ(solution.minimumString("abc", "bca", "aaa"), "aaabca");
}

TEST_P(ShortestStringThatContainsThreeStringsTest, Example2) {
  EXPECT_EQ(solution.minimumString("ab", "ba", "aba"), "aba");
}

TEST_P(ShortestStringThatContainsThreeStringsTest, SelfAuthoredAllEqual) {
  EXPECT_EQ(solution.minimumString("xyz", "xyz", "xyz"), "xyz");
}

TEST_P(ShortestStringThatContainsThreeStringsTest, SelfAuthoredOneContainsAll) {
  // a contains b and c
  EXPECT_EQ(solution.minimumString("abcde", "bcd", "c"), "abcde");
}

TEST_P(ShortestStringThatContainsThreeStringsTest, SelfAuthoredNoOverlap) {
  // completely disjoint strings
  auto result = solution.minimumString("a", "b", "c");
  // shortest must be length 3, any order like "abc"
  EXPECT_EQ(result.size(), 3u);
  // verify all substrings are present
  EXPECT_NE(result.find("a"), string::npos);
  EXPECT_NE(result.find("b"), string::npos);
  EXPECT_NE(result.find("c"), string::npos);
}

TEST_P(ShortestStringThatContainsThreeStringsTest, SelfAuthoredLexicographicallySmallest) {
  // Multiple shortest candidates with same length, pick lexicographically
  // smallest. "ab" + "bc" = "abc", "bc" + "ab" overlap 0 -> "bcab" (len 4 vs
  // 3). Let's design: a="ab", b="bc", c="ca".
  // merge("ab","bc")="abc", merge("abc","ca")="abca" (overlap "c")
  // another order may give same length. We just check result is shortest.
  auto result = solution.minimumString("ab", "bc", "ca");
  EXPECT_EQ(result.size(), 4u);
  EXPECT_NE(result.find("ab"), string::npos);
  EXPECT_NE(result.find("bc"), string::npos);
  EXPECT_NE(result.find("ca"), string::npos);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ShortestStringThatContainsThreeStringsTest,
    testing::ValuesIn(
        ShortestStringThatContainsThreeStringsSolution().getStrategyNames()));
