#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-cost-to-reach-every-position.h"

namespace leetcode::problem_3502 {

class MinimumCostToReachEveryPositionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumCostToReachEveryPositionSolution solution_;
};

TEST_P(MinimumCostToReachEveryPositionTest, Example1) {
  std::vector<int> cost{5, 3, 4, 1, 3, 2};
  std::vector<int> expected{5, 3, 3, 1, 1, 1};
  EXPECT_EQ(solution_.minCosts(cost), expected);
}

TEST_P(MinimumCostToReachEveryPositionTest, Example2) {
  std::vector<int> cost{1, 2, 4, 6, 7};
  std::vector<int> expected{1, 1, 1, 1, 1};
  EXPECT_EQ(solution_.minCosts(cost), expected);
}

TEST_P(MinimumCostToReachEveryPositionTest, SelfAuthoredSingleElement) {
  std::vector<int> cost{7};
  std::vector<int> expected{7};
  EXPECT_EQ(solution_.minCosts(cost), expected);
}

TEST_P(MinimumCostToReachEveryPositionTest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> cost{10, 8, 6, 4, 2};
  std::vector<int> expected{10, 8, 6, 4, 2};
  EXPECT_EQ(solution_.minCosts(cost), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToReachEveryPositionTestSuite,
    MinimumCostToReachEveryPositionTest,
    ::testing::ValuesIn(
        MinimumCostToReachEveryPositionSolution().getStrategyNames()));

}  // namespace leetcode::problem_3502
