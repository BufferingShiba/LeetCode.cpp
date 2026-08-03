#include <gtest/gtest.h>
#include "leetcode/problems/count-alternating-subarrays.h"

using namespace leetcode::problem_3101;

class CountAlternatingSubarraysTest : public ::testing::TestWithParam<std::string> {
 protected:
    CountAlternatingSubarraysSolution solution;
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(CountAlternatingSubarraysTest, Example1) {
    std::vector<int> nums = {0, 1, 1, 1};
    EXPECT_EQ(solution.countAlternatingSubarrays(nums), 5);
}

TEST_P(CountAlternatingSubarraysTest, Example2) {
    std::vector<int> nums = {1, 0, 1, 0};
    EXPECT_EQ(solution.countAlternatingSubarrays(nums), 10);
}

TEST_P(CountAlternatingSubarraysTest, SelfAuthoredSingleElement) {
    std::vector<int> nums = {0};
    EXPECT_EQ(solution.countAlternatingSubarrays(nums), 1);
}

TEST_P(CountAlternatingSubarraysTest, SelfAuthoredAllSame) {
    std::vector<int> nums = {1, 1, 1, 1};
    // Only single-element subarrays are alternating: [1],[1],[1],[1] = 4
    EXPECT_EQ(solution.countAlternatingSubarrays(nums), 4);
}

TEST_P(CountAlternatingSubarraysTest, SelfAuthoredAlternatingPair) {
    std::vector<int> nums = {0, 1};
    // Subarrays: [0], [1], [0,1] = 3
    EXPECT_EQ(solution.countAlternatingSubarrays(nums), 3);
}

TEST_P(CountAlternatingSubarraysTest, SelfAuthoredNonAlternatingPair) {
    std::vector<int> nums = {0, 0};
    // Subarrays: [0], [0] = 2
    EXPECT_EQ(solution.countAlternatingSubarrays(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountAlternatingSubarraysTest,
    ::testing::ValuesIn(CountAlternatingSubarraysSolution().getStrategyNames())
);
