#include <gtest/gtest.h>

#include "leetcode/problems/maximum-alternating-subsequence-sum.h"

using namespace leetcode::problem_1911;

class MaximumAlternatingSubsequenceSumTest : public ::testing::TestWithParam<std::string> {
 protected:
    MaximumAlternatingSubsequenceSumSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(MaximumAlternatingSubsequenceSumTest, Example1) {
    std::vector<int> nums = {4, 2, 5, 3};
    EXPECT_EQ(solution.maxAlternatingSum(nums), 7);
}

TEST_P(MaximumAlternatingSubsequenceSumTest, Example2) {
    std::vector<int> nums = {5, 6, 7, 8};
    EXPECT_EQ(solution.maxAlternatingSum(nums), 8);
}

TEST_P(MaximumAlternatingSubsequenceSumTest, Example3) {
    std::vector<int> nums = {6, 2, 1, 2, 4, 5};
    EXPECT_EQ(solution.maxAlternatingSum(nums), 10);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumAlternatingSubsequenceSumTest,
    ::testing::ValuesIn(MaximumAlternatingSubsequenceSumSolution().getStrategyNames())
);
