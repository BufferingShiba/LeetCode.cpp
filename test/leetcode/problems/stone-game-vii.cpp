#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/stone-game-vii.h"

namespace leetcode::problem_1690 {

class StoneGameViiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  StoneGameViiSolution solution;
};

TEST_P(StoneGameViiTest, Example1) {
  std::vector<int> stones{5, 3, 1, 4, 2};
  EXPECT_EQ(solution.stoneGameVII(stones), 6);
}

TEST_P(StoneGameViiTest, Example2) {
  std::vector<int> stones{7, 90, 5, 1, 100, 10, 10, 2};
  EXPECT_EQ(solution.stoneGameVII(stones), 122);
}

INSTANTIATE_TEST_SUITE_P(
    StoneGameViiTestCases, StoneGameViiTest,
    ::testing::ValuesIn(StoneGameViiSolution().getStrategyNames()));

}  // namespace leetcode::problem_1690
