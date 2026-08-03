#include "leetcode/problems/closest-subsequence-sum.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1755 {
namespace {

class ClosestSubsequenceSumTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    ClosestSubsequenceSumSolution solution;
};

TEST_P(ClosestSubsequenceSumTest, Example1) {
    std::vector<int> nums = {5, -7, 3, 5};
    int goal = 6;
    EXPECT_EQ(solution.minAbsDifference(nums, goal), 0);
}

TEST_P(ClosestSubsequenceSumTest, Example2) {
    std::vector<int> nums = {7, -9, 15, -2};
    int goal = -5;
    EXPECT_EQ(solution.minAbsDifference(nums, goal), 1);
}

TEST_P(ClosestSubsequenceSumTest, Example3) {
    std::vector<int> nums = {1, 2, 3};
    int goal = -7;
    EXPECT_EQ(solution.minAbsDifference(nums, goal), 7);
}

TEST_P(ClosestSubsequenceSumTest, SelfAuthoredSingleElementEqualsGoal) {
    std::vector<int> nums = {10};
    int goal = 10;
    EXPECT_EQ(solution.minAbsDifference(nums, goal), 0);
}

TEST_P(ClosestSubsequenceSumTest, SelfAuthoredSingleElementSelectEmpty) {
    std::vector<int> nums = {10};
    int goal = 3;
    // subseq sums: 0, 10 -> closest to 3 is 0 -> |0-3|=3
    EXPECT_EQ(solution.minAbsDifference(nums, goal), 3);
}

TEST_P(ClosestSubsequenceSumTest, SelfAuthoredAllNegatives) {
    std::vector<int> nums = {-1, -2, -3};
    int goal = 1;
    // subseq sums: 0,-1,-2,-3,-3,-4,-5,-6; closest to 1 is 0 -> 1
    EXPECT_EQ(solution.minAbsDifference(nums, goal), 1);
}

INSTANTIATE_TEST_SUITE_P(
    ClosestSubsequenceSumTestCases,
    ClosestSubsequenceSumTest,
    ::testing::ValuesIn(ClosestSubsequenceSumSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1755
}  // namespace leetcode
