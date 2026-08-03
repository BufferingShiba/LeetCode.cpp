#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-erasure-value.h"

namespace leetcode::problem_1695 {

class MaximumErasureValueTest : public ::testing::TestWithParam<std::string> {
 protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    MaximumErasureValueSolution solution;
};

TEST_P(MaximumErasureValueTest, Example1) {
    std::vector<int> nums{4, 2, 4, 5, 6};
    EXPECT_EQ(solution.maximumUniqueSubarray(nums), 17);
}

TEST_P(MaximumErasureValueTest, Example2) {
    std::vector<int> nums{5, 2, 1, 2, 5, 2, 1, 2, 5};
    EXPECT_EQ(solution.maximumUniqueSubarray(nums), 8);
}

TEST_P(MaximumErasureValueTest, SelfAuthoredSingleElement) {
    std::vector<int> nums{10};
    EXPECT_EQ(solution.maximumUniqueSubarray(nums), 10);
}

TEST_P(MaximumErasureValueTest, SelfAuthoredAllDistinct) {
    std::vector<int> nums{1, 2, 3, 4, 5};
    EXPECT_EQ(solution.maximumUniqueSubarray(nums), 15);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumErasureValueTestSuite,
    MaximumErasureValueTest,
    ::testing::ValuesIn(MaximumErasureValueSolution().getStrategyNames()));

}  // namespace leetcode::problem_1695
