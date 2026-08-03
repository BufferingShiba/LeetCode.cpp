#include "leetcode/problems/squares-of-a-sorted-array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_977 {

class SquaresOfASortedArrayTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    SquaresOfASortedArraySolution solution;
};

TEST_P(SquaresOfASortedArrayTest, Example1) {
    std::vector<int> nums{-4, -1, 0, 3, 10};
    const std::vector<int> expected{0, 1, 9, 16, 100};
    EXPECT_EQ(expected, solution.sortedSquares(nums));
}

TEST_P(SquaresOfASortedArrayTest, Example2) {
    std::vector<int> nums{-7, -3, 2, 3, 11};
    const std::vector<int> expected{4, 9, 9, 49, 121};
    EXPECT_EQ(expected, solution.sortedSquares(nums));
}

TEST_P(SquaresOfASortedArrayTest, SelfAuthoredSingleElement) {
    std::vector<int> nums{-5};
    const std::vector<int> expected{25};
    EXPECT_EQ(expected, solution.sortedSquares(nums));
}

TEST_P(SquaresOfASortedArrayTest, SelfAuthoredAllNegative) {
    std::vector<int> nums{-3, -2, -1};
    const std::vector<int> expected{1, 4, 9};
    EXPECT_EQ(expected, solution.sortedSquares(nums));
}

TEST_P(SquaresOfASortedArrayTest, SelfAuthoredAllZero) {
    std::vector<int> nums{0, 0, 0};
    const std::vector<int> expected{0, 0, 0};
    EXPECT_EQ(expected, solution.sortedSquares(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SquaresOfASortedArrayTestCases,
    SquaresOfASortedArrayTest,
    ::testing::ValuesIn(SquaresOfASortedArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_977
