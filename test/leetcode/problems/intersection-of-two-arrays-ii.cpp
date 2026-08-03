#include "leetcode/problems/intersection-of-two-arrays-ii.h"

#include <gtest/gtest.h>

namespace leetcode::problem_350 {

class IntersectionOfTwoArraysIiTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    IntersectionOfTwoArraysIiSolution solution_;
};

INSTANTIATE_TEST_SUITE_P(
    IntersectionOfTwoArraysIiTestCases, IntersectionOfTwoArraysIiTest,
    ::testing::ValuesIn(IntersectionOfTwoArraysIiSolution().getStrategyNames()));

TEST_P(IntersectionOfTwoArraysIiTest, Example1) {
    std::vector<int> nums1{1, 2, 2, 1};
    std::vector<int> nums2{2, 2};
    auto result = solution_.intersect(nums1, nums2);
    std::vector<int> expected{2, 2};
    std::sort(result.begin(), result.end());
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(result, expected);
}

TEST_P(IntersectionOfTwoArraysIiTest, Example2) {
    std::vector<int> nums1{4, 9, 5};
    std::vector<int> nums2{9, 4, 9, 8, 4};
    auto result = solution_.intersect(nums1, nums2);
    std::vector<int> expected{4, 9};
    std::sort(result.begin(), result.end());
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(result, expected);
}

TEST_P(IntersectionOfTwoArraysIiTest, SelfAuthoredNoCommonElements) {
    std::vector<int> nums1{1, 2, 3};
    std::vector<int> nums2{4, 5, 6};
    auto result = solution_.intersect(nums1, nums2);
    EXPECT_TRUE(result.empty());
}

TEST_P(IntersectionOfTwoArraysIiTest, SelfAuthoredRepeatedWithinSameArray) {
    std::vector<int> nums1{1, 1, 1, 2, 2};
    std::vector<int> nums2{1, 1, 2, 3};
    auto result = solution_.intersect(nums1, nums2);
    std::vector<int> expected{1, 1, 2};
    std::sort(result.begin(), result.end());
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(result, expected);
}

}  // namespace leetcode::problem_350
