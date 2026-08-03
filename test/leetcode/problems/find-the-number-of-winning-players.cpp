#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-number-of-winning-players.h"

namespace leetcode {
namespace problem_3238 {

namespace {

using TestData = std::pair<int, std::vector<std::vector<int>>>;

}  // namespace

class FindTheNumberOfWinningPlayersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheNumberOfWinningPlayersSolution solution;
};

TEST_P(FindTheNumberOfWinningPlayersTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> pick = {{0, 0}, {1, 0}, {1, 0},
                                        {2, 1}, {2, 1}, {2, 0}};
  EXPECT_EQ(2, solution.winningPlayerCount(n, pick));
}

TEST_P(FindTheNumberOfWinningPlayersTest, Example2) {
  int n = 5;
  std::vector<std::vector<int>> pick = {{1, 1}, {1, 2}, {1, 3}, {1, 4}};
  EXPECT_EQ(0, solution.winningPlayerCount(n, pick));
}

TEST_P(FindTheNumberOfWinningPlayersTest, Example3) {
  int n = 5;
  std::vector<std::vector<int>> pick = {{1, 1}, {2, 4}, {2, 4}, {2, 4}};
  EXPECT_EQ(1, solution.winningPlayerCount(n, pick));
}

TEST_P(FindTheNumberOfWinningPlayersTest, SelfAuthoredPlayerZeroAlwaysWins) {
  // Player 0 picks any ball => wins (strictly more than 0).
  int n = 3;
  std::vector<std::vector<int>> pick = {{0, 5}};
  EXPECT_EQ(1, solution.winningPlayerCount(n, pick));
}

TEST_P(FindTheNumberOfWinningPlayersTest, SelfAuthoredPlayerZeroWinsOnly) {
  int n = 2;
  std::vector<std::vector<int>> pick = {{0, 5}, {0, 6}};
  // Player 1 has 0 balls => not winning. Only player 0 wins.
  EXPECT_EQ(1, solution.winningPlayerCount(n, pick));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheNumberOfWinningPlayersTestSuite,
    FindTheNumberOfWinningPlayersTest,
    ::testing::ValuesIn(FindTheNumberOfWinningPlayersSolution().getStrategyNames()));

}  // namespace problem_3238
}  // namespace leetcode
