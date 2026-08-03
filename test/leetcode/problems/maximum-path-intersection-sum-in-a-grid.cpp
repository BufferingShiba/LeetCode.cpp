#include <gtest/gtest.h>
#include "leetcode/problems/maximum-path-intersection-sum-in-a-grid.h"

namespace leetcode {
namespace problem_3938 {

class MaximumPathIntersectionSumInAGridTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MaximumPathIntersectionSumInAGridSolution solution;
};

TEST_P(MaximumPathIntersectionSumInAGridTest, OfficialExamples) {
  // Example 1
  std::vector<std::vector<int>> grid1 = {
    {1, 2, 0, -3},
    {1, -2, 1, 0},
    {-4, 2, -1, 3},
    {3, -3, 3, -2},
    {-1, -5, 0, 1}
  };
  EXPECT_EQ(solution.maxScore(grid1), 4);

  // Example 2
  std::vector<std::vector<int>> grid2 = {
    {4, -2, -3},
    {-1, -3, -1},
    {-4, 2, -1}
  };
  EXPECT_EQ(solution.maxScore(grid2), 3);
}

TEST_P(MaximumPathIntersectionSumInAGridTest, SelfAuthored) {
  // Single interior cell is the best
  std::vector<std::vector<int>> grid1 = {
    {-100, -100, -100},
    {-100,  100, -100},
    {-100, -100, -100}
  };
  EXPECT_EQ(solution.maxScore(grid1), 100);

  // Horizontal segment beats interior cell
  std::vector<std::vector<int>> grid2 = {
    {5, 5, -100},
    {-1, -1, -1},
    {-1, -1, -1}
  };
  EXPECT_EQ(solution.maxScore(grid2), 10);  // row 0: 5+5=10

  // Vertical segment on a column
  std::vector<std::vector<int>> grid3 = {
    {10, -100},
    {10, -100},
    {-100, -100}
  };
  EXPECT_EQ(solution.maxScore(grid3), 20);  // col 0: 10+10=20

  // All negative: least negative segment of length >= 2
  std::vector<std::vector<int>> grid4 = {
    {-5, -1, -2},
    {-3, -4, -1}
  };
  // rows: [-5,-1]=-6, [-1,-2]=-3, [-5,-1,-2]=-8; [-3,-4]=-7, [-4,-1]=-5, [-3,-4,-1]=-8
  // cols: [-5,-3]=-8; [-1,-4]=-5; [-2,-1]=-3
  EXPECT_EQ(solution.maxScore(grid4), -3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumPathIntersectionSumInAGridTest,
    testing::ValuesIn(
        MaximumPathIntersectionSumInAGridSolution().getStrategyNames()));

}  // namespace problem_3938
}  // namespace leetcode
