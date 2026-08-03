#include <gtest/gtest.h>

#include "leetcode/problems/permutation-in-string.h"

namespace leetcode {
namespace problem_567 {

class PermutationInStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PermutationInStringSolution solution;
};

TEST_P(PermutationInStringTest, Example1) {
  EXPECT_TRUE(solution.checkInclusion("ab", "eidbaooo"));
}

TEST_P(PermutationInStringTest, Example2) {
  EXPECT_FALSE(solution.checkInclusion("ab", "eidboaoo"));
}

TEST_P(PermutationInStringTest, SelfAuthoredSingleCharMatch) {
  EXPECT_TRUE(solution.checkInclusion("a", "a"));
}

TEST_P(PermutationInStringTest, SelfAuthoredSingleCharNoMatch) {
  EXPECT_FALSE(solution.checkInclusion("a", "b"));
}

TEST_P(PermutationInStringTest, SelfAuthoredS1LongerThanS2) {
  EXPECT_FALSE(solution.checkInclusion("abc", "a"));
}

TEST_P(PermutationInStringTest, SelfAuthoredExactMatch) {
  EXPECT_TRUE(solution.checkInclusion("abc", "abc"));
}

TEST_P(PermutationInStringTest, SelfAuthoredAtEnd) {
  EXPECT_TRUE(solution.checkInclusion("abc", "xyabc"));
}

TEST_P(PermutationInStringTest, SelfAuthoredRepeatingChars) {
  EXPECT_TRUE(solution.checkInclusion("aab", "baababa"));
}

INSTANTIATE_TEST_SUITE_P(Strategies, PermutationInStringTest,
                         ::testing::ValuesIn(
                             PermutationInStringSolution().getStrategyNames()));

}  // namespace problem_567
}  // namespace leetcode
