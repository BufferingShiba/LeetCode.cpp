#include "leetcode/problems/the-number-of-weak-characters-in-the-game.h"
#include <gtest/gtest.h>

namespace leetcode::problem_1996 {

class TheNumberOfWeakCharactersInTheGameTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TheNumberOfWeakCharactersInTheGameSolution solution;
};

TEST_P(TheNumberOfWeakCharactersInTheGameTest, Example1) {
  std::vector<std::vector<int>> properties = {{5, 5}, {6, 3}, {3, 6}};
  EXPECT_EQ(0, solution.getSolution()(properties));
}

TEST_P(TheNumberOfWeakCharactersInTheGameTest, Example2) {
  std::vector<std::vector<int>> properties = {{2, 2}, {3, 3}};
  EXPECT_EQ(1, solution.getSolution()(properties));
}

TEST_P(TheNumberOfWeakCharactersInTheGameTest, Example3) {
  std::vector<std::vector<int>> properties = {{1, 5}, {10, 4}, {4, 3}};
  EXPECT_EQ(1, solution.getSolution()(properties));
}

TEST_P(TheNumberOfWeakCharactersInTheGameTest, SelfAuthoredSameAttackGroup) {
  // Same attack, character can only be weak towards one with same attack and higher defense? No,
  // needs strictly greater attack too, so same attack never causes weakness.
  std::vector<std::vector<int>> properties = {{5, 1}, {5, 2}, {5, 3}};
  EXPECT_EQ(0, solution.getSolution()(properties));
}

INSTANTIATE_TEST_SUITE_P(
    TheNumberOfWeakCharactersInTheGameStrategies,
    TheNumberOfWeakCharactersInTheGameTest,
    ::testing::ValuesIn(TheNumberOfWeakCharactersInTheGameSolution().getStrategyNames()));

}  // namespace leetcode::problem_1996
