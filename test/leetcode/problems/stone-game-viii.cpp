#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/stone-game-viii.h"

namespace leetcode::problem_1872 {

class StoneGameViiiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  StoneGameViiiSolution solution_;
};

TEST_P(StoneGameViiiTest, Example1) {
  std::vector<int> stones = {-1, 2, -3, 4, -5};
  EXPECT_EQ(solution_.stoneGameVIII(stones), 5);
}

TEST_P(StoneGameViiiTest, Example2) {
  std::vector<int> stones = {7, -6, 5, 10, 5, -2, -6};
  EXPECT_EQ(solution_.stoneGameVIII(stones), 13);
}

TEST_P(StoneGameViiiTest, Example3) {
  std::vector<int> stones = {-10, -12};
  EXPECT_EQ(solution_.stoneGameVIII(stones), -22);
}

INSTANTIATE_TEST_SUITE_P(,
                         StoneGameViiiTest,
                         ::testing::ValuesIn(
                             StoneGameViiiSolution().getStrategyNames()));

}  // namespace leetcode::problem_1872
