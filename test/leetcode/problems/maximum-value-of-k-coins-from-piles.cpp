#include <gtest/gtest.h>

#include "leetcode/problems/maximum-value-of-k-coins-from-piles.h"

using namespace leetcode::problem_2218;

class MaximumValueOfKCoinsFromPilesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MaximumValueOfKCoinsFromPilesSolution solution;
};

TEST_P(MaximumValueOfKCoinsFromPilesTest, Example1) {
  std::vector<std::vector<int>> piles = {{1, 100, 3}, {7, 8, 9}};
  int k = 2;
  EXPECT_EQ(101, solution.maxValueOfCoins(piles, k));
}

TEST_P(MaximumValueOfKCoinsFromPilesTest, Example2) {
  std::vector<std::vector<int>> piles = {
      {100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}};
  int k = 7;
  EXPECT_EQ(706, solution.maxValueOfCoins(piles, k));
}

TEST_P(MaximumValueOfKCoinsFromPilesTest, SelfAuthoredSinglePile) {
  std::vector<std::vector<int>> piles = {{5, 4, 3, 2, 1}};
  int k = 3;
  // Take top 3: 5+4+3 = 12
  EXPECT_EQ(12, solution.maxValueOfCoins(piles, k));
}

TEST_P(MaximumValueOfKCoinsFromPilesTest, SelfAuthoredTakeAll) {
  std::vector<std::vector<int>> piles = {{10, 20}, {30}};
  int k = 3;
  EXPECT_EQ(60, solution.maxValueOfCoins(piles, k));
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, MaximumValueOfKCoinsFromPilesTest,
    ::testing::ValuesIn(
        MaximumValueOfKCoinsFromPilesSolution().getStrategyNames()));
