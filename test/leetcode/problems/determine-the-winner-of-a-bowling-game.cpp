#include "leetcode/problems/determine-the-winner-of-a-bowling-game.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using leetcode::problem_2660::DetermineTheWinnerOfABowlingGameSolution;

class DetermineTheWinnerOfABowlingGameTest
    : public ::testing::TestWithParam<std::string> {
protected:
    DetermineTheWinnerOfABowlingGameSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(DetermineTheWinnerOfABowlingGameTest, Example1) {
    std::vector<int> player1 = {5, 10, 3, 2};
    std::vector<int> player2 = {6, 5, 7, 3};
    EXPECT_EQ(solution.isWinner(player1, player2), 1);
}

TEST_P(DetermineTheWinnerOfABowlingGameTest, Example2) {
    std::vector<int> player1 = {3, 5, 7, 6};
    std::vector<int> player2 = {8, 10, 10, 2};
    EXPECT_EQ(solution.isWinner(player1, player2), 2);
}

TEST_P(DetermineTheWinnerOfABowlingGameTest, Example3) {
    std::vector<int> player1 = {2, 3};
    std::vector<int> player2 = {4, 1};
    EXPECT_EQ(solution.isWinner(player1, player2), 0);
}

TEST_P(DetermineTheWinnerOfABowlingGameTest, Example4) {
    std::vector<int> player1 = {1, 1, 1, 10, 10, 10, 10};
    std::vector<int> player2 = {10, 10, 10, 10, 1, 1, 1};
    EXPECT_EQ(solution.isWinner(player1, player2), 2);
}

TEST_P(DetermineTheWinnerOfABowlingGameTest, SelfAuthoredSingleTurn) {
    std::vector<int> player1 = {5};
    std::vector<int> player2 = {7};
    EXPECT_EQ(solution.isWinner(player1, player2), 2);
}

TEST_P(DetermineTheWinnerOfABowlingGameTest, SelfAuthoredDoubleAfterStrike) {
    std::vector<int> player1 = {10, 5};
    std::vector<int> player2 = {0, 10};
    // player1: 10 + 2*5 = 20; player2: 0 + 10 = 10
    EXPECT_EQ(solution.isWinner(player1, player2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    DetermineTheWinnerOfABowlingGameTestSuite,
    DetermineTheWinnerOfABowlingGameTest,
    ::testing::ValuesIn(DetermineTheWinnerOfABowlingGameSolution().getStrategyNames()));
