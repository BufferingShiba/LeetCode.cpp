#include <gtest/gtest.h>

#include "leetcode/problems/snakes-and-ladders.h"

using namespace leetcode::problem_909;

class SnakesAndLaddersTest : public ::testing::TestWithParam<std::string> {
 protected:
  SnakesAndLaddersSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SnakesAndLaddersTest, Example1) {
  std::vector<std::vector<int>> board = {
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 15, -1, -1, -1, -1}};
  EXPECT_EQ(solution.snakesAndLadders(board), 4);
}

TEST_P(SnakesAndLaddersTest, Example2) {
  std::vector<std::vector<int>> board = {{-1, -1}, {-1, 3}};
  EXPECT_EQ(solution.snakesAndLadders(board), 1);
}

INSTANTIATE_TEST_SUITE_P(Strategies, SnakesAndLaddersTest,
                         ::testing::ValuesIn(SnakesAndLaddersSolution()
                                                 .getStrategyNames()));
