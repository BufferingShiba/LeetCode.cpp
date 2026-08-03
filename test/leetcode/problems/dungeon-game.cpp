#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/dungeon-game.h"

namespace leetcode::problem_174 {

class DungeonGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DungeonGameSolution solution_;
};

TEST_P(DungeonGameTest, Example1) {
  std::vector<std::vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
  EXPECT_EQ(solution_.calculateMinimumHP(dungeon), 7);
}

TEST_P(DungeonGameTest, Example2) {
  std::vector<std::vector<int>> dungeon = {{0}};
  EXPECT_EQ(solution_.calculateMinimumHP(dungeon), 1);
}

TEST_P(DungeonGameTest, SelfAuthoredAllPositive) {
  std::vector<std::vector<int>> dungeon = {{1, 2}, {3, 4}};
  EXPECT_EQ(solution_.calculateMinimumHP(dungeon), 1);
}

TEST_P(DungeonGameTest, SelfAuthoredSingleNegative) {
  std::vector<std::vector<int>> dungeon = {{-3}};
  EXPECT_EQ(solution_.calculateMinimumHP(dungeon), 4);
}

INSTANTIATE_TEST_SUITE_P(
    DungeonGameTestSuite, DungeonGameTest,
    ::testing::ValuesIn(DungeonGameSolution().getStrategyNames()));

}  // namespace leetcode::problem_174
