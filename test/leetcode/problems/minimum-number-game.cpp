#include <gtest/gtest.h>

#include "leetcode/problems/minimum-number-game.h"

using namespace leetcode::problem_2974;

class MinimumNumberGameTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    MinimumNumberGameSolution solution;
};

TEST_P(MinimumNumberGameTest, Example1) {
    std::vector<int> nums = {5, 4, 2, 3};
    std::vector<int> expected = {3, 2, 5, 4};
    EXPECT_EQ(solution.numberGame(nums), expected);
}

TEST_P(MinimumNumberGameTest, Example2) {
    std::vector<int> nums = {2, 5};
    std::vector<int> expected = {5, 2};
    EXPECT_EQ(solution.numberGame(nums), expected);
}

TEST_P(MinimumNumberGameTest, SelfAuthoredSortedPairs) {
    std::vector<int> nums = {1, 4, 2, 3, 7, 6};
    // sorted: 1,2,3,4,6,7; swap pairs -> 2,1,4,3,7,6
    std::vector<int> expected = {2, 1, 4, 3, 7, 6};
    EXPECT_EQ(solution.numberGame(nums), expected);
}

TEST_P(MinimumNumberGameTest, SelfAuthoredMinimalDistinct) {
    std::vector<int> nums = {10, 5, 8, 3};
    // sorted: 3,5,8,10; swap pairs -> 5,3,10,8
    std::vector<int> expected = {5, 3, 10, 8};
    EXPECT_EQ(solution.numberGame(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberGameStrategies, MinimumNumberGameTest,
    ::testing::ValuesIn(MinimumNumberGameSolution().getStrategyNames()));
