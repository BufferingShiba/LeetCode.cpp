#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/find-the-winning-player-in-coin-game.h"

namespace leetcode {
namespace problem_3222 {

class FindTheWinningPlayerInCoinGameTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindTheWinningPlayerInCoinGameSolution solution_;
};

TEST_P(FindTheWinningPlayerInCoinGameTest, Example1) {
  EXPECT_EQ("Alice", solution_.winningPlayer(2, 7));
}

TEST_P(FindTheWinningPlayerInCoinGameTest, Example2) {
  EXPECT_EQ("Bob", solution_.winningPlayer(4, 11));
}

TEST_P(FindTheWinningPlayerInCoinGameTest, SelfAuthoredNoTurnForAlice) {
  // x = 1, y = 3：不足 4 个 10 硬币，Alice 第一回合就无法行动，直接输。
  EXPECT_EQ("Bob", solution_.winningPlayer(1, 3));
}

TEST_P(FindTheWinningPlayerInCoinGameTest, SelfAuthoredOnlyOneTurn) {
  // x = 1, y = 4：恰好一回合，Alice 拿完后 Bob 无法行动，Alice 赢。
  EXPECT_EQ("Alice", solution_.winningPlayer(1, 4));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheWinningPlayerInCoinGameTestSuite,
    FindTheWinningPlayerInCoinGameTest,
    ::testing::ValuesIn(FindTheWinningPlayerInCoinGameSolution().getStrategyNames()));

}  // namespace problem_3222
}  // namespace leetcode
