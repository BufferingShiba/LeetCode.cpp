#include "leetcode/problems/coin-change-ii.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_518 {

class CoinChangeIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CoinChangeIiSolution solution;
};

TEST_P(CoinChangeIiTest, Example1) {
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(4, solution.change(5, coins));
}

TEST_P(CoinChangeIiTest, Example2) {
  std::vector<int> coins = {2};
  EXPECT_EQ(0, solution.change(3, coins));
}

TEST_P(CoinChangeIiTest, Example3) {
  std::vector<int> coins = {10};
  EXPECT_EQ(1, solution.change(10, coins));
}

TEST_P(CoinChangeIiTest, ZeroAmount) {
  std::vector<int> coins = {2, 5};
  EXPECT_EQ(1, solution.change(0, coins));
}

TEST_P(CoinChangeIiTest, DuplicateOrderDoesNotChangeCombinations) {
  std::vector<int> coins = {2, 3, 7};
  EXPECT_EQ(4, solution.change(12, coins));
}

INSTANTIATE_TEST_SUITE_P(
    CoinChangeIiTestSuite, CoinChangeIiTest,
    ::testing::ValuesIn(CoinChangeIiSolution().getStrategyNames()));

}  // namespace problem_518
}  // namespace leetcode
