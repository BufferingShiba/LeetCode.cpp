#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/final-prices-with-a-special-discount-in-a-shop.h"

namespace leetcode::problem_1475 {

class FinalPricesWithASpecialDiscountInAShopTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FinalPricesWithASpecialDiscountInAShopSolution solution;
};

TEST_P(FinalPricesWithASpecialDiscountInAShopTest, Example1) {
  std::vector<int> prices{8, 4, 6, 2, 3};
  std::vector<int> expected{4, 2, 4, 2, 3};
  EXPECT_EQ(solution.finalPrices(prices), expected);
}

TEST_P(FinalPricesWithASpecialDiscountInAShopTest, Example2) {
  std::vector<int> prices{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  EXPECT_EQ(solution.finalPrices(prices), expected);
}

TEST_P(FinalPricesWithASpecialDiscountInAShopTest, Example3) {
  std::vector<int> prices{10, 1, 1, 6};
  std::vector<int> expected{9, 0, 1, 6};
  EXPECT_EQ(solution.finalPrices(prices), expected);
}

TEST_P(FinalPricesWithASpecialDiscountInAShopTest, SelfAuthoredSingleElement) {
  std::vector<int> prices{7};
  std::vector<int> expected{7};
  EXPECT_EQ(solution.finalPrices(prices), expected);
}

TEST_P(FinalPricesWithASpecialDiscountInAShopTest, SelfAuthoredEqualAfter) {
  std::vector<int> prices{5, 5, 5, 5};
  std::vector<int> expected{0, 0, 0, 5};
  EXPECT_EQ(solution.finalPrices(prices), expected);
}

TEST_P(FinalPricesWithASpecialDiscountInAShopTest, SelfAuthoredDescentThenEqual) {
  std::vector<int> prices{8, 2, 4, 2, 7};
  std::vector<int> expected{6, 0, 2, 2, 7};
  EXPECT_EQ(solution.finalPrices(prices), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FinalPricesWithASpecialDiscountInAShopTestSuite,
    FinalPricesWithASpecialDiscountInAShopTest,
    ::testing::ValuesIn(
        FinalPricesWithASpecialDiscountInAShopSolution().getStrategyNames()));

}  // namespace leetcode::problem_1475
