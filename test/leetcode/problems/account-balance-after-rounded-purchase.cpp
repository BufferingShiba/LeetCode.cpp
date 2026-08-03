#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/account-balance-after-rounded-purchase.h"

namespace leetcode {
namespace problem_2806 {

using AccountBalanceAfterRoundedPurchaseTest =
    ::testing::TestWithParam<std::string>;

class AccountBalanceAfterRoundedPurchaseTestFixture
    : public AccountBalanceAfterRoundedPurchaseTest {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AccountBalanceAfterRoundedPurchaseSolution solution;
};

TEST_P(AccountBalanceAfterRoundedPurchaseTestFixture, Example1) {
  EXPECT_EQ(solution.accountBalanceAfterPurchase(9), 90);
}

TEST_P(AccountBalanceAfterRoundedPurchaseTestFixture, Example2) {
  EXPECT_EQ(solution.accountBalanceAfterPurchase(15), 80);
}

TEST_P(AccountBalanceAfterRoundedPurchaseTestFixture, Example3) {
  EXPECT_EQ(solution.accountBalanceAfterPurchase(10), 90);
}

TEST_P(AccountBalanceAfterRoundedPurchaseTestFixture, SelfAuthoredEdgeCases) {
  // Smallest purchase amount, rounds to 0.
  EXPECT_EQ(solution.accountBalanceAfterPurchase(0), 100);
  // Boundary: 5 rounds upward to 10.
  EXPECT_EQ(solution.accountBalanceAfterPurchase(5), 90);
  // Largest purchase amount, rounds to 100.
  EXPECT_EQ(solution.accountBalanceAfterPurchase(100), 0);
}

INSTANTIATE_TEST_SUITE_P(
    AccountBalanceAfterRoundedPurchaseTestSuite,
    AccountBalanceAfterRoundedPurchaseTestFixture,
    ::testing::ValuesIn(AccountBalanceAfterRoundedPurchaseSolution().getStrategyNames()));

}  // namespace problem_2806
}  // namespace leetcode
