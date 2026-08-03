#include <gtest/gtest.h>

#include "leetcode/problems/degree-of-an-array.h"

namespace leetcode {
namespace problem_697 {

class DegreeOfAnArrayTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    DegreeOfAnArraySolution solution;
};

TEST_P(DegreeOfAnArrayTest, Example1) {
    std::vector<int> nums{1, 2, 2, 3, 1};
    EXPECT_EQ(2, solution.findShortestSubArray(nums));
}

TEST_P(DegreeOfAnArrayTest, Example2) {
    std::vector<int> nums{1, 2, 2, 3, 1, 4, 2};
    EXPECT_EQ(6, solution.findShortestSubArray(nums));
}

TEST_P(DegreeOfAnArrayTest, SelfAuthoredSingleElement) {
    std::vector<int> nums{5};
    EXPECT_EQ(1, solution.findShortestSubArray(nums));
}

TEST_P(DegreeOfAnArrayTest, SelfAuthoredAllSame) {
    std::vector<int> nums{3, 3, 3, 3};
    EXPECT_EQ(4, solution.findShortestSubArray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    DegreeOfAnArrayTestCases, DegreeOfAnArrayTest,
    ::testing::ValuesIn(DegreeOfAnArraySolution().getStrategyNames()));

}  // namespace problem_697
}  // namespace leetcode
