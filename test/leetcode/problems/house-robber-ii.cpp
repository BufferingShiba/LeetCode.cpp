#include <gtest/gtest.h>
#include "leetcode/problems/house-robber-ii.h"

using namespace leetcode::problem_213;

class HouseRobberIiTest : public HouseRobberIiSolution, public testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        setStrategy(GetParam());
    }
};

TEST_P(HouseRobberIiTest, Example1) {
    std::vector<int> nums = {2, 3, 2};
    EXPECT_EQ(rob(nums), 3);
}

TEST_P(HouseRobberIiTest, Example2) {
    std::vector<int> nums = {1, 2, 3, 1};
    EXPECT_EQ(rob(nums), 4);
}

TEST_P(HouseRobberIiTest, Example3) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(rob(nums), 3);
}

TEST_P(HouseRobberIiTest, SelfAuthoredSingleHouse) {
    std::vector<int> nums = {5};
    EXPECT_EQ(rob(nums), 5);
}

TEST_P(HouseRobberIiTest, SelfAuthoredTwoHouses) {
    std::vector<int> nums = {10, 20};
    EXPECT_EQ(rob(nums), 20);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    HouseRobberIiTest,
    testing::ValuesIn(HouseRobberIiSolution().getStrategyNames())
);
