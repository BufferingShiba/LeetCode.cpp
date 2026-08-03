#include "leetcode/problems/k-diff-pairs-in-an-array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

using leetcode::problem_532::KDiffPairsInAnArraySolution;

class KDiffPairsInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    KDiffPairsInAnArraySolution solution;
};

TEST_P(KDiffPairsInAnArrayTest, Example1) {
    std::vector<int> nums = {3, 1, 4, 1, 5};
    EXPECT_EQ(solution.findPairs(nums, 2), 2);
}

TEST_P(KDiffPairsInAnArrayTest, Example2) {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.findPairs(nums, 1), 4);
}

TEST_P(KDiffPairsInAnArrayTest, Example3) {
    std::vector<int> nums = {1, 3, 1, 5, 4};
    EXPECT_EQ(solution.findPairs(nums, 0), 1);
}

TEST_P(KDiffPairsInAnArrayTest, SelfAuthoredEdgeCases) {
    {
        std::vector<int> nums = {1, 1, 1};
        EXPECT_EQ(solution.findPairs(nums, 0), 1);
    }
    {
        std::vector<int> nums = {1, 2, 3};
        EXPECT_EQ(solution.findPairs(nums, 0), 0);
    }
    {
        std::vector<int> nums = {1, 2, 3, 4};
        EXPECT_EQ(solution.findPairs(nums, 2), 2);
    }
    {
        std::vector<int> nums = {-1, 1, 3};
        EXPECT_EQ(solution.findPairs(nums, 2), 2);
    }
}

INSTANTIATE_TEST_SUITE_P(
    KDiffPairsInAnArrayStrategies, KDiffPairsInAnArrayTest,
    ::testing::ValuesIn(KDiffPairsInAnArraySolution().getStrategyNames()));
