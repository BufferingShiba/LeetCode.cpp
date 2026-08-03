#include <gtest/gtest.h>

#include "leetcode/problems/best-time-to-buy-and-sell-stock-with-cooldown.h"

namespace leetcode::problem_309 {

class BestTimeToBuyAndSellStockWithCooldownTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BestTimeToBuyAndSellStockWithCooldownSolution solution_;
};

TEST_P(BestTimeToBuyAndSellStockWithCooldownTest, Example1) {
  std::vector<int> prices = {1, 2, 3, 0, 2};
  EXPECT_EQ(solution_.maxProfit(prices), 3);
}

TEST_P(BestTimeToBuyAndSellStockWithCooldownTest, Example2) {
  std::vector<int> prices = {1};
  EXPECT_EQ(solution_.maxProfit(prices), 0);
}

TEST_P(BestTimeToBuyAndSellStockWithCooldownTest, SelfAuthored_AllDecreasing) {
  std::vector<int> prices = {5, 4, 3, 2, 1};
  EXPECT_EQ(solution_.maxProfit(prices), 0);
}

TEST_P(BestTimeToBuyAndSellStockWithCooldownTest, SelfAuthored_AllIncreasing) {
  std::vector<int> prices = {1, 2, 3, 4, 5};
  // 买入第1天，卖出第5天，利润4（不需要冷却因为只交易一次）
  EXPECT_EQ(solution_.maxProfit(prices), 4);
}

TEST_P(BestTimeToBuyAndSellStockWithCooldownTest, SelfAuthored_TwoTransactions) {
  // 买1卖3 (i=0→1, 利润2), 冷却i=2, 买1卖4 (i=3→4, 利润3), 总利润5
  std::vector<int> prices = {1, 3, 2, 1, 4};
  EXPECT_EQ(solution_.maxProfit(prices), 5);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    BestTimeToBuyAndSellStockWithCooldownTest,
    testing::ValuesIn(
        BestTimeToBuyAndSellStockWithCooldownSolution().getStrategyNames()));

}  // namespace leetcode::problem_309
