#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-substring-between-two-equal-characters.h"

namespace leetcode::problem_1624 {

class LargestSubstringBetweenTwoEqualCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LargestSubstringBetweenTwoEqualCharactersSolution solution_;
};

TEST_P(LargestSubstringBetweenTwoEqualCharactersTest, Example1) {
  EXPECT_EQ(solution_.maxLengthBetweenEqualCharacters("aa"), 0);
}

TEST_P(LargestSubstringBetweenTwoEqualCharactersTest, Example2) {
  EXPECT_EQ(solution_.maxLengthBetweenEqualCharacters("abca"), 2);
}

TEST_P(LargestSubstringBetweenTwoEqualCharactersTest, Example3) {
  EXPECT_EQ(solution_.maxLengthBetweenEqualCharacters("cbzxy"), -1);
}

TEST_P(LargestSubstringBetweenTwoEqualCharactersTest, SelfAuthoredCase1) {
  EXPECT_EQ(solution_.maxLengthBetweenEqualCharacters("abcabc"), 2);
}

TEST_P(LargestSubstringBetweenTwoEqualCharactersTest, SelfAuthoredCase2) {
  EXPECT_EQ(solution_.maxLengthBetweenEqualCharacters("a"), -1);
}

TEST_P(LargestSubstringBetweenTwoEqualCharactersTest, SelfAuthoredCase3) {
  EXPECT_EQ(solution_.maxLengthBetweenEqualCharacters("abcd"), -1);
}

INSTANTIATE_TEST_SUITE_P(
    LargestSubstringBetweenTwoEqualCharactersTestSuite,
    LargestSubstringBetweenTwoEqualCharactersTest,
    ::testing::ValuesIn(
        LargestSubstringBetweenTwoEqualCharactersSolution().getStrategyNames()));

}  // namespace leetcode::problem_1624
