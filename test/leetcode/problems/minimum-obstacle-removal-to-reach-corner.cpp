#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-obstacle-removal-to-reach-corner.h"

namespace leetcode::problem_2290 {

class MinimumObstacleRemovalToReachCornerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumObstacleRemovalToReachCornerSolution solution_;
};

TEST_P(MinimumObstacleRemovalToReachCornerTest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};
  EXPECT_EQ(solution_.minimumObstacles(grid), 2);
}

TEST_P(MinimumObstacleRemovalToReachCornerTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
  EXPECT_EQ(solution_.minimumObstacles(grid), 0);
}

TEST_P(MinimumObstacleRemovalToReachCornerTest, SingleCell) {
  std::vector<std::vector<int>> grid = {{0}};
  EXPECT_EQ(solution_.minimumObstacles(grid), 0);
}

TEST_P(MinimumObstacleRemovalToReachCornerTest, AllOnePath) {
  std::vector<std::vector<int>> grid = {
      {0, 1, 1},
      {1, 1, 1},
      {1, 1, 0}};
  // Best path: (0,0)->(1,0)->(2,0)->(2,1)->(2,2), removing obstacles at
  // (1,0), (2,0), (2,1) = 3 removals.
  EXPECT_EQ(solution_.minimumObstacles(grid), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumObstacleRemovalToReachCornerTestCases,
    MinimumObstacleRemovalToReachCornerTest,
    ::testing::ValuesIn(
        MinimumObstacleRemovalToReachCornerSolution().getStrategyNames()));

}  // namespace leetcode::problem_2290
