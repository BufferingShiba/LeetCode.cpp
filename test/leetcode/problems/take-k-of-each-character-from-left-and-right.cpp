#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/take-k-of-each-character-from-left-and-right.h"

namespace leetcode {
namespace problem_2516 {

class TakeKOfEachCharacterFromLeftAndRightTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TakeKOfEachCharacterFromLeftAndRightSolution solution;
};

TEST_P(TakeKOfEachCharacterFromLeftAndRightTest, Example1) {
  EXPECT_EQ(solution.takeCharacters("aabaaaacaabc", 2), 8);
}

TEST_P(TakeKOfEachCharacterFromLeftAndRightTest, Example2) {
  EXPECT_EQ(solution.takeCharacters("a", 1), -1);
}

TEST_P(TakeKOfEachCharacterFromLeftAndRightTest, SelfAuthoredEdgeCaseKZero) {
  EXPECT_EQ(solution.takeCharacters("abc", 0), 0);
}

TEST_P(TakeKOfEachCharacterFromLeftAndRightTest, SelfAuthoredEdgeCaseExactlyEnough) {
  // Need exactly 2 of each; all 6 chars consumed.
  EXPECT_EQ(solution.takeCharacters("abcabc", 2), 6);
}

TEST_P(TakeKOfEachCharacterFromLeftAndRightTest, SelfAuthoredEdgeCaseAllOnOneSide) {
  // s="aabbcc", k=1: total 2a,2b,2c. Best kept window has each char <=1.
  // Max kept size 2 (e.g. "ab") -> answer 6-2 = 4.
  EXPECT_EQ(solution.takeCharacters("aabbcc", 1), 4);
}

TEST_P(TakeKOfEachCharacterFromLeftAndRightTest, SelfAuthoredEdgeCaseImpossible) {
  // s="aaa", k=2: b and c each have 0 < 2 -> impossible.
  EXPECT_EQ(solution.takeCharacters("aaa", 2), -1);
}

TEST_P(TakeKOfEachCharacterFromLeftAndRightTest, SelfAuthoredEdgeCaseOneCharEach) {
  // s="abc", k=1: need 1 of each -> take all 3.
  EXPECT_EQ(solution.takeCharacters("abc", 1), 3);
}

INSTANTIATE_TEST_SUITE_P(
    TakeKOfEachCharacterFromLeftAndRightTestSuite,
    TakeKOfEachCharacterFromLeftAndRightTest,
    ::testing::ValuesIn(
        TakeKOfEachCharacterFromLeftAndRightSolution().getStrategyNames()));

}  // namespace problem_2516
}  // namespace leetcode
