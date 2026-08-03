#include <gtest/gtest.h>

#include "leetcode/problems/stone-removal-game.h"

namespace leetcode {
namespace problem_3360 {

class StoneRemovalGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  StoneRemovalGameSolution solution_;
};

TEST_P(StoneRemovalGameTest, OfficialExamples) {
  // Example 1: n=12 → Alice removes 10, leaves 2 → Bob cannot remove 9 → Alice wins
  EXPECT_TRUE(solution_.canAliceWin(12));

  // Example 2: n=1 → Alice cannot remove 10 → Alice loses
  EXPECT_FALSE(solution_.canAliceWin(1));
}

TEST_P(StoneRemovalGameTest, SelfAuthored) {
  // n=10: Alice removes 10, leaves 0 → Bob cannot remove 9 → Alice wins
  EXPECT_TRUE(solution_.canAliceWin(10));

  // n=19: Alice(10)→9 left, Bob(9)→0 left, Alice cannot remove 8 → Alice loses
  EXPECT_FALSE(solution_.canAliceWin(19));

  // n=20: Alice(10)→10 left, Bob(9)→1 left, Alice cannot remove 8 → Alice loses
  EXPECT_FALSE(solution_.canAliceWin(20));
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         StoneRemovalGameTest,
                         ::testing::ValuesIn(
                             StoneRemovalGameSolution().getStrategyNames()));

}  // namespace problem_3360
}  // namespace leetcode
