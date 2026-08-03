#include <gtest/gtest.h>
#include "leetcode/problems/find-k-pairs-with-smallest-sums.h"

using namespace leetcode::problem_373;

class FindKPairsWithSmallestSumsTest : public testing::TestWithParam<std::string> {
protected:
    FindKPairsWithSmallestSumsSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(FindKPairsWithSmallestSumsTest, Example1) {
    std::vector<int> nums1 = {1, 7, 11};
    std::vector<int> nums2 = {2, 4, 6};
    int k = 3;
    auto result = solution.kSmallestPairs(nums1, nums2, k);
    std::vector<std::vector<int>> expected = {{1, 2}, {1, 4}, {1, 6}};
    EXPECT_EQ(result, expected);
}

TEST_P(FindKPairsWithSmallestSumsTest, Example2) {
    std::vector<int> nums1 = {1, 1, 2};
    std::vector<int> nums2 = {1, 2, 3};
    int k = 2;
    auto result = solution.kSmallestPairs(nums1, nums2, k);
    std::vector<std::vector<int>> expected = {{1, 1}, {1, 1}};
    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    All,
    FindKPairsWithSmallestSumsTest,
    testing::ValuesIn(FindKPairsWithSmallestSumsSolution().getStrategyNames()));
