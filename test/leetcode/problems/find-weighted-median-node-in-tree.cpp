#include <gtest/gtest.h>

#include "leetcode/problems/find-weighted-median-node-in-tree.h"

using namespace leetcode::problem_3585;

class FindWeightedMedianNodeInTreeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindWeightedMedianNodeInTreeSolution solution;
};

TEST_P(FindWeightedMedianNodeInTreeTest, Example1) {
  int n = 2;
  std::vector<std::vector<int>> edges = {{0, 1, 7}};
  std::vector<std::vector<int>> queries = {{1, 0}, {0, 1}};
  auto result = solution.findMedian(n, edges, queries);
  EXPECT_EQ(result, (std::vector<int>{0, 1}));
}

TEST_P(FindWeightedMedianNodeInTreeTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 2}, {2, 0, 4}};
  std::vector<std::vector<int>> queries = {{0, 1}, {2, 0}, {1, 2}};
  auto result = solution.findMedian(n, edges, queries);
  EXPECT_EQ(result, (std::vector<int>{1, 0, 2}));
}

TEST_P(FindWeightedMedianNodeInTreeTest, Example3) {
  int n = 5;
  std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 5}, {1, 3, 1}, {2, 4, 3}};
  std::vector<std::vector<int>> queries = {{3, 4}, {1, 2}};
  auto result = solution.findMedian(n, edges, queries);
  EXPECT_EQ(result, (std::vector<int>{2, 2}));
}

INSTANTIATE_TEST_SUITE_P(Strategies, FindWeightedMedianNodeInTreeTest,
                         ::testing::ValuesIn(FindWeightedMedianNodeInTreeSolution().getStrategyNames()));
