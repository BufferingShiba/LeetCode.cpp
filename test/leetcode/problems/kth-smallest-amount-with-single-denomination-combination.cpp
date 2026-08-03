#include <gtest/gtest.h>
#include "leetcode/problems/kth-smallest-amount-with-single-denomination-combination.h"

using namespace leetcode::problem_3116;

class KthSmallestAmountWithSingleDenominationCombinationTest :
    public ::testing::TestWithParam<std::string> {
 protected:
  KthSmallestAmountWithSingleDenominationCombinationSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(KthSmallestAmountWithSingleDenominationCombinationTest, Example1) {
  std::vector<int> coins = {3, 6, 9};
  int k = 3;
  EXPECT_EQ(solution.findKthSmallest(coins, k), 9);
}

TEST_P(KthSmallestAmountWithSingleDenominationCombinationTest, Example2) {
  std::vector<int> coins = {5, 2};
  int k = 7;
  EXPECT_EQ(solution.findKthSmallest(coins, k), 12);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    KthSmallestAmountWithSingleDenominationCombinationTest,
    ::testing::ValuesIn(
        KthSmallestAmountWithSingleDenominationCombinationSolution().getStrategyNames()));
