#include <gtest/gtest.h>

#include "leetcode/problems/find-x-sum-of-all-k-long-subarrays-i.h"

using namespace leetcode::problem_3318;

class FindXSumOfAllKLongSubarraysITest : public testing::TestWithParam<std::string> {
 protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
    FindXSumOfAllKLongSubarraysISolution solution;
};

TEST_P(FindXSumOfAllKLongSubarraysITest, Example1) {
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6, x = 2;
    std::vector<int> expected = {6, 10, 12};
    EXPECT_EQ(solution.findXSum(nums, k, x), expected);
}

TEST_P(FindXSumOfAllKLongSubarraysITest, Example2) {
    std::vector<int> nums = {3, 8, 7, 8, 7, 5};
    int k = 2, x = 2;
    std::vector<int> expected = {11, 15, 15, 15, 12};
    EXPECT_EQ(solution.findXSum(nums, k, x), expected);
}

TEST_P(FindXSumOfAllKLongSubarraysITest, SelfAuthoredSingleElementSubarray) {
    std::vector<int> nums = {5};
    int k = 1, x = 1;
    std::vector<int> expected = {5};
    EXPECT_EQ(solution.findXSum(nums, k, x), expected);
}

TEST_P(FindXSumOfAllKLongSubarraysITest, SelfAuthoredAllSameElements) {
    std::vector<int> nums = {7, 7, 7, 7};
    int k = 3, x = 1;
    // Subarrays: [7,7,7] -> all 7s, freq=3, x=1, sum=21; [7,7,7] -> same
    std::vector<int> expected = {21, 21};
    EXPECT_EQ(solution.findXSum(nums, k, x), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    FindXSumOfAllKLongSubarraysITest,
    testing::ValuesIn(FindXSumOfAllKLongSubarraysISolution().getStrategyNames()));
