#include "leetcode/problems/shopping-offers.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_638 {

class ShoppingOffersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShoppingOffersSolution solution;
};

TEST_P(ShoppingOffersTest, Example1) {
  std::vector<int> price = {2, 5};
  std::vector<std::vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
  std::vector<int> needs = {3, 2};
  EXPECT_EQ(14, solution.getSolution()(price, special, needs));
}

TEST_P(ShoppingOffersTest, Example2) {
  std::vector<int> price = {2, 3, 4};
  std::vector<std::vector<int>> special = {{1, 1, 0, 4}, {2, 2, 1, 9}};
  std::vector<int> needs = {1, 2, 1};
  EXPECT_EQ(11, solution.getSolution()(price, special, needs));
}

TEST_P(ShoppingOffersTest, NoSpecialOffers) {
  std::vector<int> price = {1, 2, 3};
  std::vector<std::vector<int>> special = {};
  std::vector<int> needs = {2, 3, 4};
  EXPECT_EQ(1 * 2 + 2 * 3 + 3 * 4, solution.getSolution()(price, special, needs));
}

TEST_P(ShoppingOffersTest, OfferMoreExpensiveThanIndividual) {
  std::vector<int> price = {10};
  std::vector<std::vector<int>> special = {{2, 25}};
  std::vector<int> needs = {3};
  EXPECT_EQ(30, solution.getSolution()(price, special, needs));
}

INSTANTIATE_TEST_SUITE_P(ShoppingOffersTestSuite, ShoppingOffersTest,
                         ::testing::ValuesIn(ShoppingOffersSolution().getStrategyNames()));

}  // namespace problem_638
}  // namespace leetcode
