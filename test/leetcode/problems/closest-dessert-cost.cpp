#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/closest-dessert-cost.h"

namespace leetcode {
namespace problem_1774 {

class ClosestDessertCostTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ClosestDessertCostSolution solution;
};

TEST_P(ClosestDessertCostTest, Example1) {
  std::vector<int> baseCosts = {1, 7};
  std::vector<int> toppingCosts = {3, 4};
  int target = 10;
  EXPECT_EQ(solution.closestCost(baseCosts, toppingCosts, target), 10);
}

TEST_P(ClosestDessertCostTest, Example2) {
  std::vector<int> baseCosts = {2, 3};
  std::vector<int> toppingCosts = {4, 5, 100};
  int target = 18;
  EXPECT_EQ(solution.closestCost(baseCosts, toppingCosts, target), 17);
}

TEST_P(ClosestDessertCostTest, Example3) {
  std::vector<int> baseCosts = {3, 10};
  std::vector<int> toppingCosts = {2, 5};
  int target = 9;
  EXPECT_EQ(solution.closestCost(baseCosts, toppingCosts, target), 8);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ClosestDessertCostTest,
    ::testing::ValuesIn(ClosestDessertCostSolution().getStrategyNames()));

}  // namespace problem_1774
}  // namespace leetcode
