#include "leetcode/problems/longest-subarray-with-maximum-bitwise-and.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2419 {

class LongestSubarrayWithMaximumBitwiseAndTest
    : public ::testing::TestWithParam<std::string> {
protected:
    LongestSubarrayWithMaximumBitwiseAndSolution solution;
    void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(LongestSubarrayWithMaximumBitwiseAndTest, Example1) {
    std::vector<int> nums = {1, 2, 3, 3, 2, 2};
    EXPECT_EQ(solution.longestSubarray(nums), 2);
}

TEST_P(LongestSubarrayWithMaximumBitwiseAndTest, Example2) {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.longestSubarray(nums), 1);
}

TEST_P(LongestSubarrayWithMaximumBitwiseAndTest, SingleElement) {
    std::vector<int> nums = {7};
    EXPECT_EQ(solution.longestSubarray(nums), 1);
}

TEST_P(LongestSubarrayWithMaximumBitwiseAndTest, AllSame) {
    std::vector<int> nums = {5, 5, 5, 5};
    EXPECT_EQ(solution.longestSubarray(nums), 4);
}

TEST_P(LongestSubarrayWithMaximumBitwiseAndTest, MaxAtEnd) {
    std::vector<int> nums = {1, 1, 9, 9, 9, 1};
    EXPECT_EQ(solution.longestSubarray(nums), 3);
}

namespace {
LongestSubarrayWithMaximumBitwiseAndSolution InitSolution() {
    return LongestSubarrayWithMaximumBitwiseAndSolution();
}
}  // namespace

INSTANTIATE_TEST_SUITE_P(
    LongestSubarrayWithMaximumBitwiseAndTestSuite,
    LongestSubarrayWithMaximumBitwiseAndTest,
    ::testing::ValuesIn(InitSolution().getStrategyNames()));

}  // namespace problem_2419
}  // namespace leetcode
