#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/count-subarrays-of-length-three-with-a-condition.h"

namespace leetcode::problem_3392 {

class CountSubarraysOfLengthThreeWithAConditionTest
    : public ::testing::TestWithParam<std::string> {
protected:
    CountSubarraysOfLengthThreeWithAConditionSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(CountSubarraysOfLengthThreeWithAConditionTest, Example1) {
    std::vector<int> nums{1, 2, 1, 4, 1};
    EXPECT_EQ(solution.countSubarrays(nums), 1);
}

TEST_P(CountSubarraysOfLengthThreeWithAConditionTest, Example2) {
    std::vector<int> nums{1, 1, 1};
    EXPECT_EQ(solution.countSubarrays(nums), 0);
}

TEST_P(CountSubarraysOfLengthThreeWithAConditionTest, SelfAuthoredAllValidSubarray) {
    std::vector<int> nums{2, 6, 2};  // 2+2=4, 4*2=8 != 6 -> not valid
    EXPECT_EQ(solution.countSubarrays(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountSubarraysOfLengthThreeWithAConditionTestSuite,
    CountSubarraysOfLengthThreeWithAConditionTest,
    ::testing::ValuesIn(
        CountSubarraysOfLengthThreeWithAConditionSolution().getStrategyNames()));

}  // namespace leetcode::problem_3392
