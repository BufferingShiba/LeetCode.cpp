#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/buy-two-chocolates.h"

namespace leetcode::problem_2706 {
namespace {

class BuyTwoChocolatesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BuyTwoChocolatesSolution solution;
};

TEST_P(BuyTwoChocolatesTest, Example1) {
  std::vector<int> prices{1, 2, 2};
  EXPECT_EQ(solution.buyChoco(prices, 3), 0);
}

TEST_P(BuyTwoChocolatesTest, Example2) {
  std::vector<int> prices{3, 2, 3};
  EXPECT_EQ(solution.buyChoco(prices, 3), 3);
}

TEST_P(BuyTwoChocolatesTest, SelfAuthored_ExactMoney) {
  std::vector<int> prices{5, 5};
  EXPECT_EQ(solution.buyChoco(prices, 10), 0);
}

TEST_P(BuyTwoChocolatesTest, SelfAuthored_LeftoverPositive) {
  std::vector<int> prices{4, 7, 2, 9};
  EXPECT_EQ(solution.buyChoco(prices, 15), 9);
}

TEST_P(BuyTwoChocolatesTest, SelfAuthored_TooPoor) {
  std::vector<int> prices{2, 3, 4};
  EXPECT_EQ(solution.buyChoco(prices, 3), 3);
}

INSTANTIATE_TEST_SUITE_P(
    BuyTwoChocolatesTestSuite, BuyTwoChocolatesTest,
    ::testing::ValuesIn(BuyTwoChocolatesSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2706
