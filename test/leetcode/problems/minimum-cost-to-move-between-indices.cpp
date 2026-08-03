#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-cost-to-move-between-indices.h"

namespace leetcode::problem_3919 {

class MinimumCostToMoveBetweenIndicesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  MinimumCostToMoveBetweenIndicesSolution solution;
};

TEST_P(MinimumCostToMoveBetweenIndicesTest, Example1) {
  std::vector<int> nums{-5, -2, 3};
  std::vector<std::vector<int>> queries{{0, 2}, {2, 0}, {1, 2}};
  std::vector<int> expected{6, 2, 5};
  EXPECT_EQ(solution.minCost(nums, queries), expected);
}

TEST_P(MinimumCostToMoveBetweenIndicesTest, Example2) {
  std::vector<int> nums{0, 2, 3, 9};
  std::vector<std::vector<int>> queries{{3, 0}, {1, 2}, {2, 0}};
  std::vector<int> expected{4, 1, 3};
  EXPECT_EQ(solution.minCost(nums, queries), expected);
}

TEST_P(MinimumCostToMoveBetweenIndicesTest, SelfAuthoredTwoElements) {
  std::vector<int> nums{1, 5};
  std::vector<std::vector<int>> queries{{0, 1}, {1, 0}};
  // Only one edge (d_0 = 4). Move up from 0->1: closest(0)=1 cost 1.
  // Move down from 1->0: closest(1)=0 cost 1.
  std::vector<int> expected{1, 1};
  EXPECT_EQ(solution.minCost(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToMoveBetweenIndices,
    MinimumCostToMoveBetweenIndicesTest,
    ::testing::ValuesIn(MinimumCostToMoveBetweenIndicesSolution().getStrategyNames()));

}  // namespace leetcode::problem_3919
