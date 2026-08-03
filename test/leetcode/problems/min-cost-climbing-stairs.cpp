#include <gtest/gtest.h>

#include "leetcode/problems/min-cost-climbing-stairs.h"

namespace leetcode {
namespace problem_746 {

class MinCostClimbingStairsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinCostClimbingStairsSolution solution;
};

TEST_P(MinCostClimbingStairsTest, Example1) {
  std::vector<int> cost{10, 15, 20};
  EXPECT_EQ(15, solution.minCostClimbingStairs(cost));
}

TEST_P(MinCostClimbingStairsTest, Example2) {
  std::vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  EXPECT_EQ(6, solution.minCostClimbingStairs(cost));
}

TEST_P(MinCostClimbingStairsTest, TwoSteps) {
  std::vector<int> cost{0, 0};
  EXPECT_EQ(0, solution.minCostClimbingStairs(cost));
}

TEST_P(MinCostClimbingStairsTest, FreeStartFromIndexOne) {
  std::vector<int> cost{10, 0, 1};
  // Start at index 1 (free), pay 0, climb two steps to top. Total = 0.
  EXPECT_EQ(0, solution.minCostClimbingStairs(cost));
}

INSTANTIATE_TEST_SUITE_P(
    MinCostClimbingStairsTestSuite, MinCostClimbingStairsTest,
    ::testing::ValuesIn(MinCostClimbingStairsSolution().getStrategyNames()));

}  // namespace problem_746
}  // namespace leetcode
