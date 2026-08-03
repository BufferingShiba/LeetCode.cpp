#include <gtest/gtest.h>

#include "leetcode/problems/smallest-index-with-equal-value.h"

#include <string>
#include <vector>

namespace leetcode::problem_2057 {

class SmallestIndexWithEqualValueTest : public ::testing::TestWithParam<std::string> {
protected:
    SmallestIndexWithEqualValueSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(SmallestIndexWithEqualValueTest, Example1) {
    std::vector<int> nums = {0, 1, 2};
    EXPECT_EQ(0, solution.smallestEqual(nums));
}

TEST_P(SmallestIndexWithEqualValueTest, Example2) {
    std::vector<int> nums = {4, 3, 2, 1};
    EXPECT_EQ(2, solution.smallestEqual(nums));
}

TEST_P(SmallestIndexWithEqualValueTest, Example3) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    EXPECT_EQ(-1, solution.smallestEqual(nums));
}

TEST_P(SmallestIndexWithEqualValueTest, SelfAuthoredMatchAtOne) {
    std::vector<int> nums = {1, 1, 1, 1, 1};
    EXPECT_EQ(1, solution.smallestEqual(nums));
}

TEST_P(SmallestIndexWithEqualValueTest, SelfAuthoredIndexTen) {
    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
    EXPECT_EQ(0, solution.smallestEqual(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SmallestIndexWithEqualValueTestSuite,
    SmallestIndexWithEqualValueTest,
    ::testing::ValuesIn(SmallestIndexWithEqualValueSolution().getStrategyNames()));

}  // namespace leetcode::problem_2057
