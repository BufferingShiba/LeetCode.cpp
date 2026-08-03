#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/apply-operations-to-an-array.h"

namespace leetcode::problem_2460 {

class ApplyOperationsToAnArrayTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    ApplyOperationsToAnArraySolution solution;
};

TEST_P(ApplyOperationsToAnArrayTest, Example1) {
    std::vector<int> nums{1, 2, 2, 1, 1, 0};
    EXPECT_EQ((std::vector<int>{1, 4, 2, 0, 0, 0}), solution.applyOperations(nums));
}

TEST_P(ApplyOperationsToAnArrayTest, Example2) {
    std::vector<int> nums{0, 1};
    EXPECT_EQ((std::vector<int>{1, 0}), solution.applyOperations(nums));
}

TEST_P(ApplyOperationsToAnArrayTest, SelfAuthoredAllSameValues) {
    std::vector<int> nums{2, 2, 2, 2};
    // i=0: 4,0,2,2 ; i=2: 4,0,4,0 ; shift -> 4,4,0,0
    EXPECT_EQ((std::vector<int>{4, 4, 0, 0}), solution.applyOperations(nums));
}

INSTANTIATE_TEST_SUITE_P(
    ApplyOperationsToAnArrayTestSuite, ApplyOperationsToAnArrayTest,
    ::testing::ValuesIn(ApplyOperationsToAnArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_2460
