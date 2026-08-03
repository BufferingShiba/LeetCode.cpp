#include <gtest/gtest.h>

#include "leetcode/problems/sum-of-perfect-square-ancestors.h"

using namespace leetcode::problem_3715;

class SumOfPerfectSquareAncestorsTest
    : public testing::TestWithParam<std::string> {
 protected:
  SumOfPerfectSquareAncestorsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

// 官方示例
TEST_P(SumOfPerfectSquareAncestorsTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};
  std::vector<int> nums = {2, 8, 2};
  EXPECT_EQ(solution.sumOfAncestors(n, edges, nums), 3);
}

TEST_P(SumOfPerfectSquareAncestorsTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}};
  std::vector<int> nums = {1, 2, 4};
  EXPECT_EQ(solution.sumOfAncestors(n, edges, nums), 1);
}

TEST_P(SumOfPerfectSquareAncestorsTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}};
  std::vector<int> nums = {1, 2, 9, 4};
  EXPECT_EQ(solution.sumOfAncestors(n, edges, nums), 2);
}

// 边界：单节点树
TEST_P(SumOfPerfectSquareAncestorsTest, SelfAuthoredSingleNode) {
  int n = 1;
  std::vector<std::vector<int>> edges = {};
  std::vector<int> nums = {7};
  EXPECT_EQ(solution.sumOfAncestors(n, edges, nums), 0);
}

// 边界：所有节点值相同（全为 1）
TEST_P(SumOfPerfectSquareAncestorsTest, SelfAuthoredAllOnes) {
  int n = 5;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  std::vector<int> nums = {1, 1, 1, 1, 1};
  // 链：t₁=1, t₂=2, t₃=3, t₄=4 → sum = 10
  EXPECT_EQ(solution.sumOfAncestors(n, edges, nums), 10);
}

// 边界：全为平方数（4,9,16 等），core 均为 1
TEST_P(SumOfPerfectSquareAncestorsTest, SelfAuthoredAllPerfectSquares) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}};
  std::vector<int> nums = {4, 9, 16, 25};
  // core: all 1 → t₁=1, t₂=1, t₃=2 → sum=4
  EXPECT_EQ(solution.sumOfAncestors(n, edges, nums), 4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, SumOfPerfectSquareAncestorsTest,
    testing::ValuesIn(
        SumOfPerfectSquareAncestorsSolution().getStrategyNames()));
