#include <gtest/gtest.h>

#include "leetcode/problems/find-the-winner-of-the-circular-game.h"

namespace leetcode::problem_1823 {

namespace {

std::vector<std::string> GetStrategyNames() {
  return FindTheWinnerOfTheCircularGameSolution().getStrategyNames();
}

}  // namespace

class FindTheWinnerOfTheCircularGameTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindTheWinnerOfTheCircularGameSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindTheWinnerOfTheCircularGameTest, Example1) {
  EXPECT_EQ(solution.findTheWinner(5, 2), 3);
}

TEST_P(FindTheWinnerOfTheCircularGameTest, Example2) {
  EXPECT_EQ(solution.findTheWinner(6, 5), 1);
}

TEST_P(FindTheWinnerOfTheCircularGameTest, SinglePerson) {
  EXPECT_EQ(solution.findTheWinner(1, 1), 1);
}

TEST_P(FindTheWinnerOfTheCircularGameTest, KEqualsOne) {
  EXPECT_EQ(solution.findTheWinner(7, 1), 7);
}

TEST_P(FindTheWinnerOfTheCircularGameTest, NEqualsK) {
  EXPECT_EQ(solution.findTheWinner(4, 4), 2);
}

TEST_P(FindTheWinnerOfTheCircularGameTest, MediumCase) {
  EXPECT_EQ(solution.findTheWinner(10, 3), 4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FindTheWinnerOfTheCircularGameTest,
    ::testing::ValuesIn(GetStrategyNames()));

}  // namespace leetcode::problem_1823
