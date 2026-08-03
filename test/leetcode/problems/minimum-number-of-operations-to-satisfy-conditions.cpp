#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-operations-to-satisfy-conditions.h"

namespace leetcode::problem_3122 {

class MinimumNumberOfOperationsToSatisfyConditionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumNumberOfOperationsToSatisfyConditionsSolution solution_;
};

TEST_P(MinimumNumberOfOperationsToSatisfyConditionsTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 0, 2}, {1, 0, 2}};
  EXPECT_EQ(0, solution_.minimumOperations(grid));
}

TEST_P(MinimumNumberOfOperationsToSatisfyConditionsTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 1, 1}, {0, 0, 0}};
  EXPECT_EQ(3, solution_.minimumOperations(grid));
}

TEST_P(MinimumNumberOfOperationsToSatisfyConditionsTest, Example3) {
  std::vector<std::vector<int>> grid = {{1}, {2}, {3}};
  EXPECT_EQ(2, solution_.minimumOperations(grid));
}

TEST_P(MinimumNumberOfOperationsToSatisfyConditionsTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{5}};
  EXPECT_EQ(0, solution_.minimumOperations(grid));
}

TEST_P(MinimumNumberOfOperationsToSatisfyConditionsTest, SelfAuthoredAllSameColumnAlready) {
  std::vector<std::vector<int>> grid = {{2, 1}, {2, 3}, {2, 4}};
  // Column0 all 2 (cost 0 for value 2), column1 needs != 2
  // best: col1->1 (cost 2), col0->2 (cost 0), total 2
  EXPECT_EQ(2, solution_.minimumOperations(grid));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfOperationsToSatisfyConditionsTests,
    MinimumNumberOfOperationsToSatisfyConditionsTest,
    ::testing::ValuesIn(
        MinimumNumberOfOperationsToSatisfyConditionsSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3122
