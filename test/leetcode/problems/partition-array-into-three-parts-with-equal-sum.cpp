#include <gtest/gtest.h>

#include "leetcode/problems/partition-array-into-three-parts-with-equal-sum.h"

namespace leetcode::problem_1013 {

class PartitionArrayIntoThreePartsWithEqualSumTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    PartitionArrayIntoThreePartsWithEqualSumSolution solution_;
};

TEST_P(PartitionArrayIntoThreePartsWithEqualSumTest, Example1) {
    std::vector<int> arr = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    EXPECT_TRUE(solution_.canThreePartsEqualSum(arr));
}

TEST_P(PartitionArrayIntoThreePartsWithEqualSumTest, Example2) {
    std::vector<int> arr = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    EXPECT_FALSE(solution_.canThreePartsEqualSum(arr));
}

TEST_P(PartitionArrayIntoThreePartsWithEqualSumTest, Example3) {
    std::vector<int> arr = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    EXPECT_TRUE(solution_.canThreePartsEqualSum(arr));
}

TEST_P(PartitionArrayIntoThreePartsWithEqualSumTest, NotDivisibleByThree) {
    std::vector<int> arr = {1, 2, 3};
    EXPECT_FALSE(solution_.canThreePartsEqualSum(arr));
}

TEST_P(PartitionArrayIntoThreePartsWithEqualSumTest, SelfAuthoredEqualParts) {
    std::vector<int> arr = {1, 2, 3, 0, 3};
    EXPECT_TRUE(solution_.canThreePartsEqualSum(arr));
}

INSTANTIATE_TEST_SUITE_P(
    PartitionArrayIntoThreePartsWithEqualSumTestCases,
    PartitionArrayIntoThreePartsWithEqualSumTest,
    ::testing::ValuesIn(
        PartitionArrayIntoThreePartsWithEqualSumSolution().getStrategyNames()));

}  // namespace leetcode::problem_1013
