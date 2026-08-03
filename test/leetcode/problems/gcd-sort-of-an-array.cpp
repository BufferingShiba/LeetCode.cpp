#include <gtest/gtest.h>

#include "leetcode/problems/gcd-sort-of-an-array.h"

namespace leetcode {
namespace problem_1998 {

class GcdSortOfAnArrayTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
    GcdSortOfAnArraySolution solution;
};

TEST_P(GcdSortOfAnArrayTest, Example1) {
    std::vector<int> nums = {7, 21, 3};
    EXPECT_TRUE(solution.gcdSort(nums));
}

TEST_P(GcdSortOfAnArrayTest, Example2) {
    std::vector<int> nums = {5, 2, 6, 2};
    EXPECT_FALSE(solution.gcdSort(nums));
}

TEST_P(GcdSortOfAnArrayTest, Example3) {
    std::vector<int> nums = {10, 5, 9, 3, 15};
    EXPECT_TRUE(solution.gcdSort(nums));
}

TEST_P(GcdSortOfAnArrayTest, SelfAuthoredSingleElement) {
    std::vector<int> nums = {2};
    EXPECT_TRUE(solution.gcdSort(nums));
}

INSTANTIATE_TEST_SUITE_P(
    GcdSortOfAnArrayTestCases, GcdSortOfAnArrayTest,
    ::testing::ValuesIn(GcdSortOfAnArraySolution().getStrategyNames()));

}  // namespace problem_1998
}  // namespace leetcode
