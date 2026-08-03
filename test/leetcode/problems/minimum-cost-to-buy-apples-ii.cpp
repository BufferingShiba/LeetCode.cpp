#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-cost-to-buy-apples-ii.h"

namespace leetcode {
namespace problem_3928 {
namespace {

class MinimumCostToBuyApplesIITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToBuyApplesIISolution solution;
};

TEST_P(MinimumCostToBuyApplesIITest, Example1) {
  std::vector<int> prices = {8, 3};
  std::vector<std::vector<int>> roads = {{0, 1, 1, 2}};
  EXPECT_EQ(solution.getSolution()(2, prices, roads), (std::vector<int>{6, 3}));
}

TEST_P(MinimumCostToBuyApplesIITest, Example2) {
  std::vector<int> prices = {9, 4, 6};
  std::vector<std::vector<int>> roads = {{0, 1, 1, 3}, {1, 2, 4, 2}};
  EXPECT_EQ(solution.getSolution()(3, prices, roads),
            (std::vector<int>{8, 4, 6}));
}

TEST_P(MinimumCostToBuyApplesIITest, Example3) {
  std::vector<int> prices = {10, 11, 1};
  std::vector<std::vector<int>> roads = {
      {0, 2, 1, 3}, {1, 2, 3, 4}, {0, 1, 5, 2}};
  EXPECT_EQ(solution.getSolution()(3, prices, roads),
            (std::vector<int>{5, 11, 1}));
}

TEST_P(MinimumCostToBuyApplesIITest, SelfAuthoredDifferentForwardAndReturnPaths) {
  std::vector<int> prices = {100, 100, 1};
  std::vector<std::vector<int>> roads = {
      {0, 1, 1, 10}, {1, 2, 1, 1}, {0, 2, 100, 1}};
  EXPECT_EQ(solution.getSolution()(3, prices, roads),
            (std::vector<int>{14, 3, 1}));
}

TEST_P(MinimumCostToBuyApplesIITest, SelfAuthoredDisconnectedShops) {
  std::vector<int> prices = {7, 2, 9};
  std::vector<std::vector<int>> roads = {{0, 1, 3, 4}};
  EXPECT_EQ(solution.getSolution()(3, prices, roads),
            (std::vector<int>{7, 2, 9}));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToBuyApplesIITestSuite, MinimumCostToBuyApplesIITest,
    ::testing::ValuesIn(MinimumCostToBuyApplesIISolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3928
}  // namespace leetcode
