#include <gtest/gtest.h>
#include "leetcode/problems/jump-game-iii.h"

using namespace leetcode::problem_1306;

class JumpGameIiiTest : public ::testing::TestWithParam<std::string> {
 protected:
  JumpGameIiiSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(JumpGameIiiTest, Example1) {
  std::vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
  int start = 5;
  EXPECT_TRUE(solution.canReach(arr, start));
}

TEST_P(JumpGameIiiTest, Example2) {
  std::vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
  int start = 0;
  EXPECT_TRUE(solution.canReach(arr, start));
}

TEST_P(JumpGameIiiTest, Example3) {
  std::vector<int> arr = {3, 0, 2, 1, 2};
  int start = 2;
  EXPECT_FALSE(solution.canReach(arr, start));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    JumpGameIiiTest,
    ::testing::ValuesIn(JumpGameIiiSolution().getStrategyNames()));
