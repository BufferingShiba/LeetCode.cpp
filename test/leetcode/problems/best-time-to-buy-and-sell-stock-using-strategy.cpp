#include "leetcode/problems/best-time-to-buy-and-sell-stock-using-strategy.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3652 {

class BestTimeToBuyAndSellStockUsingStrategyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BestTimeToBuyAndSellStockUsingStrategySolution solution;
};

TEST_P(BestTimeToBuyAndSellStockUsingStrategyTest, Example1) {
  std::vector<int> prices = {4, 2, 8};
  std::vector<int> strategy = {-1, 0, 1};
  EXPECT_EQ(10, solution.maxProfit(prices, strategy, 2));
}

TEST_P(BestTimeToBuyAndSellStockUsingStrategyTest, Example2) {
  std::vector<int> prices = {5, 4, 3};
  std::vector<int> strategy = {1, 1, 0};
  EXPECT_EQ(9, solution.maxProfit(prices, strategy, 2));
}

TEST_P(BestTimeToBuyAndSellStockUsingStrategyTest, AllHolds) {
  std::vector<int> prices = {3, 7, 2, 9};
  std::vector<int> strategy = {0, 0, 0, 0};
  EXPECT_EQ(9, solution.maxProfit(prices, strategy, 2));
}

TEST_P(BestTimeToBuyAndSellStockUsingStrategyTest, ModificationCanBeSkipped) {
  std::vector<int> prices = {10, 1, 10, 1};
  std::vector<int> strategy = {1, 0, 1, 0};
  EXPECT_EQ(20, solution.maxProfit(prices, strategy, 2));
}

INSTANTIATE_TEST_SUITE_P(
    BestTimeToBuyAndSellStockUsingStrategyTestSuite,
    BestTimeToBuyAndSellStockUsingStrategyTest,
    ::testing::ValuesIn(
        BestTimeToBuyAndSellStockUsingStrategySolution().getStrategyNames()));

}  // namespace problem_3652
}  // namespace leetcode
