#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-items-from-sale-i.h"

namespace leetcode::problem_3946 {

class MaximumNumberOfItemsFromSaleITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfItemsFromSaleISolution solution_;
};

TEST_P(MaximumNumberOfItemsFromSaleITest, Example1) {
  std::vector<std::vector<int>> items = {{6, 2}, {2, 6}, {3, 4}};
  EXPECT_EQ(solution_.maximumSaleItems(items, 9), 4);
}

TEST_P(MaximumNumberOfItemsFromSaleITest, Example2) {
  std::vector<std::vector<int>> items = {
      {2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
  EXPECT_EQ(solution_.maximumSaleItems(items, 8), 10);
}

TEST_P(MaximumNumberOfItemsFromSaleITest, SelfAuthoredSingleItem) {
  std::vector<std::vector<int>> items = {{7, 3}};
  EXPECT_EQ(solution_.maximumSaleItems(items, 10), 3);
}

TEST_P(MaximumNumberOfItemsFromSaleITest, SelfAuthoredNoFreeBonus) {
  // No factor divides another distinct factor, all equal prices.
  std::vector<std::vector<int>> items = {{2, 5}, {3, 5}, {5, 5}};
  EXPECT_EQ(solution_.maximumSaleItems(items, 15), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfItemsFromSaleITestSuite, MaximumNumberOfItemsFromSaleITest,
    ::testing::ValuesIn(
        MaximumNumberOfItemsFromSaleISolution().getStrategyNames()));

}  // namespace leetcode::problem_3946
