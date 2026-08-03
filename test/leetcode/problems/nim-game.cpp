#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/nim-game.h"

namespace leetcode::problem_292 {

class NimGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NimGameSolution solution;
};

TEST_P(NimGameTest, Example1) {
  EXPECT_FALSE(solution.canWinNim(4));
}

TEST_P(NimGameTest, Example2) {
  EXPECT_TRUE(solution.canWinNim(1));
}

TEST_P(NimGameTest, Example3) {
  EXPECT_TRUE(solution.canWinNim(2));
}

TEST_P(NimGameTest, SelfAuthoredMultipleOfFour) {
  EXPECT_FALSE(solution.canWinNim(8));
}

TEST_P(NimGameTest, SelfAuthoredNonMultipleOfFour) {
  EXPECT_TRUE(solution.canWinNim(3));
}

TEST_P(NimGameTest, SelfAuthoredLargeBoundary) {
  EXPECT_TRUE(solution.canWinNim(2147483647));
}

INSTANTIATE_TEST_SUITE_P(
    NimGameTestSuite, NimGameTest,
    ::testing::ValuesIn(NimGameSolution().getStrategyNames()));

}  // namespace leetcode::problem_292
