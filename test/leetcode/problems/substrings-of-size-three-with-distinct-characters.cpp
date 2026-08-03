#include <gtest/gtest.h>

#include "leetcode/problems/substrings-of-size-three-with-distinct-characters.h"

using namespace leetcode::problem_1876;

class SubstringsOfSizeThreeWithDistinctCharactersTest
    : public testing::TestWithParam<std::string> {
 protected:
  SubstringsOfSizeThreeWithDistinctCharactersSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SubstringsOfSizeThreeWithDistinctCharactersTest, LeetCodeExamples) {
  EXPECT_EQ(solution.countGoodSubstrings("xyzzaz"), 1);
  EXPECT_EQ(solution.countGoodSubstrings("aababcabc"), 4);
}

TEST_P(SubstringsOfSizeThreeWithDistinctCharactersTest, SelfAuthoredCases) {
  EXPECT_EQ(solution.countGoodSubstrings("abc"), 1);
  EXPECT_EQ(solution.countGoodSubstrings("aaa"), 0);
  EXPECT_EQ(solution.countGoodSubstrings("a"), 0);
  EXPECT_EQ(solution.countGoodSubstrings("ab"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    , SubstringsOfSizeThreeWithDistinctCharactersTest,
    ::testing::ValuesIn(
        SubstringsOfSizeThreeWithDistinctCharactersSolution()
            .getStrategyNames()));
