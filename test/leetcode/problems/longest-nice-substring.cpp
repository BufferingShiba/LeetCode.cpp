#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-nice-substring.h"

namespace leetcode {
namespace problem_1763 {
namespace {

using LongestNiceSubstringTest = ::testing::TestWithParam<std::string>;

TEST_P(LongestNiceSubstringTest, Example1) {
  LongestNiceSubstringSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ("aAa", solution.longestNiceSubstring("YazaAay"));
}

TEST_P(LongestNiceSubstringTest, Example2) {
  LongestNiceSubstringSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ("Bb", solution.longestNiceSubstring("Bb"));
}

TEST_P(LongestNiceSubstringTest, Example3) {
  LongestNiceSubstringSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ("", solution.longestNiceSubstring("c"));
}

TEST_P(LongestNiceSubstringTest, SelfAuthoredSingleLowerCase) {
  LongestNiceSubstringSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ("", solution.longestNiceSubstring("a"));
}

TEST_P(LongestNiceSubstringTest, SelfAuthoredAllPairsWhole) {
  LongestNiceSubstringSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ("abABB", solution.longestNiceSubstring("abABB"));
}

INSTANTIATE_TEST_SUITE_P(
    LongestNiceSubstringStrategies, LongestNiceSubstringTest,
    ::testing::ValuesIn(LongestNiceSubstringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1763
}  // namespace leetcode
