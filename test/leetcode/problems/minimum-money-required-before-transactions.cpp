#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/minimum-money-required-before-transactions.h"

namespace leetcode {
namespace problem_2412 {

class MinimumMoneyRequiredBeforeTransactionsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumMoneyRequiredBeforeTransactionsSolution solution_;
};

TEST_P(MinimumMoneyRequiredBeforeTransactionsTest, Example1) {
  std::vector<std::vector<int>> transactions = {{2, 1}, {5, 0}, {4, 2}};
  EXPECT_EQ(solution_.minimumMoney(transactions), 10);
}

TEST_P(MinimumMoneyRequiredBeforeTransactionsTest, Example2) {
  std::vector<std::vector<int>> transactions = {{3, 0}, {0, 3}};
  EXPECT_EQ(solution_.minimumMoney(transactions), 3);
}

TEST_P(MinimumMoneyRequiredBeforeTransactionsTest, SelfAuthoredAllGain) {
  std::vector<std::vector<int>> transactions = {{1, 2}, {3, 4}};
  EXPECT_EQ(solution_.minimumMoney(transactions), 3);
}

TEST_P(MinimumMoneyRequiredBeforeTransactionsTest, SelfAuthoredAllLoss) {
  std::vector<std::vector<int>> transactions = {{10, 0}, {8, 2}};
  // total_net_loss = (10-0)+(8-2)=16, max_cashback_loss=2, max_cost_gain=0
  // ans = 16 + 2 = 18
  EXPECT_EQ(solution_.minimumMoney(transactions), 18);
}

TEST_P(MinimumMoneyRequiredBeforeTransactionsTest, SelfAuthoredSingleTransaction) {
  std::vector<std::vector<int>> transactions = {{7, 3}};
  // net=4>0, total_net_loss=4, max_cashback_loss=3, ans=7
  EXPECT_EQ(solution_.minimumMoney(transactions), 7);
}

TEST_P(MinimumMoneyRequiredBeforeTransactionsTest, SelfAuthoredSingleGainTransaction) {
  std::vector<std::vector<int>> transactions = {{5, 10}};
  // net=-5<=0, total_net_loss=0, max_cost_gain=5, ans=5
  EXPECT_EQ(solution_.minimumMoney(transactions), 5);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumMoneyRequiredBeforeTransactionsTest,
    testing::ValuesIn(
        MinimumMoneyRequiredBeforeTransactionsSolution().getStrategyNames()));

}  // namespace problem_2412
}  // namespace leetcode