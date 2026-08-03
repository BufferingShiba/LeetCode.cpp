#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-cost-to-move-chips-to-the-same-position.h"

namespace leetcode::problem_1217 {

class MinimumCostToMoveChipsToTheSamePositionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToMoveChipsToTheSamePositionSolution solution;
};

TEST_P(MinimumCostToMoveChipsToTheSamePositionTest, Example1) {
  std::vector<int> position = {1, 2, 3};
  ASSERT_EQ(solution.minCostToMoveChips(position), 1);
}

TEST_P(MinimumCostToMoveChipsToTheSamePositionTest, Example2) {
  std::vector<int> position = {2, 2, 2, 3, 3};
  ASSERT_EQ(solution.minCostToMoveChips(position), 2);
}

TEST_P(MinimumCostToMoveChipsToTheSamePositionTest, Example3) {
  std::vector<int> position = {1, 1000000000};
  ASSERT_EQ(solution.minCostToMoveChips(position), 1);
}

TEST_P(MinimumCostToMoveChipsToTheSamePositionTest, SelfAuthoredSingleChip) {
  std::vector<int> position = {5};
  ASSERT_EQ(solution.minCostToMoveChips(position), 0);
}

TEST_P(MinimumCostToMoveChipsToTheSamePositionTest, SelfAuthoredAllEven) {
  std::vector<int> position = {2, 4, 6, 8};
  ASSERT_EQ(solution.minCostToMoveChips(position), 0);
}

TEST_P(MinimumCostToMoveChipsToTheSamePositionTest, SelfAuthoredAllOdd) {
  std::vector<int> position = {1, 3, 5, 7};
  ASSERT_EQ(solution.minCostToMoveChips(position), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToMoveChipsToTheSamePositionTestSuite,
    MinimumCostToMoveChipsToTheSamePositionTest,
    ::testing::ValuesIn(MinimumCostToMoveChipsToTheSamePositionSolution()
                            .getStrategyNames()));

}  // namespace leetcode::problem_1217
