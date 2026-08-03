
#include "leetcode/problems/minimum-number-of-coins-to-be-added.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2952 {

class MinimumNumberOfCoinsToBeAddedTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfCoinsToBeAddedSolution solution;
};

TEST_P(MinimumNumberOfCoinsToBeAddedTest, Example1) {
  std::vector<int> coins = {1, 4, 10};
  int target = 19;
  EXPECT_EQ(2, solution.minimumAddedCoins(coins, target));
}

TEST_P(MinimumNumberOfCoinsToBeAddedTest, Example2) {
  std::vector<int> coins = {1, 4, 10, 5, 7, 19};
  int target = 19;
  EXPECT_EQ(1, solution.minimumAddedCoins(coins, target));
}

TEST_P(MinimumNumberOfCoinsToBeAddedTest, Example3) {
  std::vector<int> coins = {1, 1, 1};
  int target = 20;
  EXPECT_EQ(3, solution.minimumAddedCoins(coins, target));
}

TEST_P(MinimumNumberOfCoinsToBeAddedTest, SelfAuthoredSingleCoinPartialCover) {
  std::vector<int> coins = {1};
  int target = 3;
  EXPECT_EQ(1, solution.minimumAddedCoins(coins, target));
}

TEST_P(MinimumNumberOfCoinsToBeAddedTest, SelfAuthoredMissingSmallestValues) {
  std::vector<int> coins = {5, 10};
  int target = 15;
  EXPECT_EQ(3, solution.minimumAddedCoins(coins, target));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumNumberOfCoinsToBeAddedTest,
    ::testing::ValuesIn(MinimumNumberOfCoinsToBeAddedSolution().getStrategyNames()));

}  // namespace problem_2952
}  // namespace leetcode
