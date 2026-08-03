#include <gtest/gtest.h>
#include "leetcode/problems/kth-smallest-path-xor-sum.h"

#include <string>
#include <vector>

using leetcode::problem_3590::KthSmallestPathXorSumSolution;

class KthSmallestPathXorSumTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }
    KthSmallestPathXorSumSolution solution;
};

TEST_P(KthSmallestPathXorSumTest, Example1) {
    std::vector<int> par = {-1, 0, 0};
    std::vector<int> vals = {1, 1, 1};
    std::vector<std::vector<int>> queries = {{0, 1}, {0, 2}, {0, 3}};
    std::vector<int> expected = {0, 1, -1};
    EXPECT_EQ(solution.kthSmallest(par, vals, queries), expected);
}

TEST_P(KthSmallestPathXorSumTest, Example2) {
    std::vector<int> par = {-1, 0, 1};
    std::vector<int> vals = {5, 2, 7};
    std::vector<std::vector<int>> queries = {{0, 1}, {1, 2}, {1, 3}, {2, 1}};
    std::vector<int> expected = {0, 7, -1, 0};
    EXPECT_EQ(solution.kthSmallest(par, vals, queries), expected);
}

TEST_P(KthSmallestPathXorSumTest, SelfAuthoredSingleNode) {
    std::vector<int> par = {-1};
    std::vector<int> vals = {5};
    std::vector<std::vector<int>> queries = {{0, 1}};
    std::vector<int> expected = {5};
    EXPECT_EQ(solution.kthSmallest(par, vals, queries), expected);
}

TEST_P(KthSmallestPathXorSumTest, SelfAuthoredChainWithDuplicateXor) {
    // vals: 1 ^ 0 ^ 1 ^ 0 = px[0]=1, px[1]=0, px[2]=1, px[3]=0 (duplicates across path)
    std::vector<int> par = {-1, 0, 1, 2};
    std::vector<int> vals = {1, 1, 1, 1};
    std::vector<std::vector<int>> queries = {{3, 1}, {0, 2}, {0, 3}};
    // px: node0=1, node1=0, node2=1, node3=0. distinct subtree of 0 = {0,1}.
    std::vector<int> expected = {0, 1, -1};
    EXPECT_EQ(solution.kthSmallest(par, vals, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    KthSmallestPathXorSumSuite,
    KthSmallestPathXorSumTest,
    ::testing::ValuesIn(KthSmallestPathXorSumSolution().getStrategyNames()));
