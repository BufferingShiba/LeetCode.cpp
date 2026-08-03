#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/best-time-to-buy-and-sell-stock.h"

namespace leetcode::problem_121 {

class BestTimeToBuyAndSellStockTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BestTimeToBuyAndSellStockSolution solution_;
};

TEST_P(BestTimeToBuyAndSellStockTest, Example1) {
  std::vector<int> prices{7, 1, 5, 3, 6, 4};
  EXPECT_EQ(5, solution_.maxProfit(prices));
}

TEST_P(BestTimeToBuyAndSellStockTest, Example2) {
  std::vector<int> prices{7, 6, 4, 3, 1};
  EXPECT_EQ(0, solution_.maxProfit(prices));
}

TEST_P(BestTimeToBuyAndSellStockTest, SelfAuthoredSingleElement) {
  std::vector<int> prices{1};
  EXPECT_EQ(0, solution_.maxProfit(prices));
}

INSTANTIATE_TEST_SUITE_P(
    BestTimeToBuyAndSellStockTests, BestTimeToBuyAndSellStockTest,
    ::testing::ValuesIn(BestTimeToBuyAndSellStockSolution().getStrategyNames()));

}  // namespace leetcode::problem_121
