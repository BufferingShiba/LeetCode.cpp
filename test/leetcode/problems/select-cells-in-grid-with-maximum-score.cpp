#include <gtest/gtest.h>

#include "leetcode/problems/select-cells-in-grid-with-maximum-score.h"

namespace leetcode {
namespace problem_3276 {

class SelectCellsInGridWithMaximumScoreTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  SelectCellsInGridWithMaximumScoreSolution solution_;
};

TEST_P(SelectCellsInGridWithMaximumScoreTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 2, 3}, {4, 3, 2}, {1, 1, 1}};
  EXPECT_EQ(solution_.maxScore(grid), 8);
}

TEST_P(SelectCellsInGridWithMaximumScoreTest, Example2) {
  std::vector<std::vector<int>> grid = {{8, 7, 6}, {8, 3, 2}};
  EXPECT_EQ(solution_.maxScore(grid), 15);
}

TEST_P(SelectCellsInGridWithMaximumScoreTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{5}};
  EXPECT_EQ(solution_.maxScore(grid), 5);
}

TEST_P(SelectCellsInGridWithMaximumScoreTest, SelfAuthoredAllSameValue) {
  std::vector<std::vector<int>> grid = {{2, 2}, {2, 2}};
  EXPECT_EQ(solution_.maxScore(grid), 2);
}

TEST_P(SelectCellsInGridWithMaximumScoreTest, SelfAuthoredOneRowOnly) {
  std::vector<std::vector<int>> grid = {{3, 1, 4, 1, 5}};
  // Only one cell can be selected; pick the max value
  EXPECT_EQ(solution_.maxScore(grid), 5);
}

TEST_P(SelectCellsInGridWithMaximumScoreTest, SelfAuthored1) {
  // 3 rows, distinct values in each row, all different
  std::vector<std::vector<int>> grid = {{10, 20}, {30, 40}, {50, 60}};
  // Can pick 20 + 40 + 60 = 120
  EXPECT_EQ(solution_.maxScore(grid), 120);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, SelectCellsInGridWithMaximumScoreTest,
    testing::ValuesIn(
        SelectCellsInGridWithMaximumScoreSolution().getStrategyNames()));

}  // namespace problem_3276
}  // namespace leetcode
