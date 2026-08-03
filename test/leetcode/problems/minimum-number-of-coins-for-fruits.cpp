#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/minimum-number-of-coins-for-fruits.h"

namespace leetcode {
namespace problem_2944 {
namespace {

class MinimumNumberOfCoinsForFruitsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfCoinsForFruitsSolution solution;
};

TEST_P(MinimumNumberOfCoinsForFruitsTest, Example1) {
  std::vector<int> prices = {3, 1, 2};
  EXPECT_EQ(4, solution.minimumCoins(prices));
}

TEST_P(MinimumNumberOfCoinsForFruitsTest, Example2) {
  std::vector<int> prices = {1, 10, 1, 1};
  EXPECT_EQ(2, solution.minimumCoins(prices));
}

TEST_P(MinimumNumberOfCoinsForFruitsTest, Example3) {
  std::vector<int> prices = {26, 18, 6, 12, 49, 7, 45, 45};
  EXPECT_EQ(39, solution.minimumCoins(prices));
}

TEST_P(MinimumNumberOfCoinsForFruitsTest, SelfAuthoredSingleFruit) {
  std::vector<int> prices = {5};
  EXPECT_EQ(5, solution.minimumCoins(prices));
}

TEST_P(MinimumNumberOfCoinsForFruitsTest, SelfAuthoredTwoFruitsBuyAll) {
  std::vector<int> prices = {2, 7};
  // 买第0个(2)送第1个, 或分别买 2+7=9. 最优: 2.
  EXPECT_EQ(2, solution.minimumCoins(prices));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfCoinsForFruitsTestGroup,
    MinimumNumberOfCoinsForFruitsTest,
    testing::ValuesIn(MinimumNumberOfCoinsForFruitsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2944
}  // namespace leetcode
