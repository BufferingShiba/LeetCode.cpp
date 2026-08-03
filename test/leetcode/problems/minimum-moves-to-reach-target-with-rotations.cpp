#include <gtest/gtest.h>

#include "leetcode/problems/minimum-moves-to-reach-target-with-rotations.h"

namespace leetcode::problem_1210 {

class MinimumMovesToReachTargetWithRotationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumMovesToReachTargetWithRotationsSolution solution_;
};

TEST_P(MinimumMovesToReachTargetWithRotationsTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {0, 0, 0, 0, 0, 1},
      {1, 1, 0, 0, 1, 0},
      {0, 0, 0, 0, 1, 1},
      {0, 0, 1, 0, 1, 0},
      {0, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 0, 0}};
  EXPECT_EQ(solution_.minimumMoves(grid), 11);
}

TEST_P(MinimumMovesToReachTargetWithRotationsTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {0, 0, 1, 1, 1, 1},
      {0, 0, 0, 0, 1, 1},
      {1, 1, 0, 0, 0, 1},
      {1, 1, 1, 0, 0, 1},
      {1, 1, 1, 0, 0, 1},
      {1, 1, 1, 0, 0, 0}};
  EXPECT_EQ(solution_.minimumMoves(grid), 9);
}

TEST_P(MinimumMovesToReachTargetWithRotationsTest, SmallGrid) {
  std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
  EXPECT_EQ(solution_.minimumMoves(grid), 1);
}

TEST_P(MinimumMovesToReachTargetWithRotationsTest, TargetBlocked) {
  std::vector<std::vector<int>> grid = {{0, 0}, {0, 1}};
  EXPECT_EQ(solution_.minimumMoves(grid), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumMovesToReachTargetWithRotationsTest,
    ::testing::ValuesIn(
        MinimumMovesToReachTargetWithRotationsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1210
