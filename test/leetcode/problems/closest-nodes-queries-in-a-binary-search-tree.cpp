#include "leetcode/problems/closest-nodes-queries-in-a-binary-search-tree.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2476 {

class ClosestNodesQueriesInABinarySearchTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ClosestNodesQueriesInABinarySearchTreeSolution solution;
};

TEST_P(ClosestNodesQueriesInABinarySearchTreeTest, Example1) {
  TreeNode* root =
      constructTree(std::vector<std::optional<int>>{6, 2, 13, 1, 4, 9, 15,
                                                    std::nullopt, std::nullopt,
                                                    std::nullopt, std::nullopt,
                                                    std::nullopt, std::nullopt,
                                                    14});
  std::vector<int> queries{2, 5, 16};
  std::vector<std::vector<int>> expected{{2, 2}, {4, 6}, {15, -1}};
  EXPECT_EQ(solution.closestNodes(root, queries), expected);
}

TEST_P(ClosestNodesQueriesInABinarySearchTreeTest, Example2) {
  TreeNode* root =
      constructTree(std::vector<std::optional<int>>{4, std::nullopt, 9});
  std::vector<int> queries{3};
  std::vector<std::vector<int>> expected{{-1, 4}};
  EXPECT_EQ(solution.closestNodes(root, queries), expected);
}

TEST_P(ClosestNodesQueriesInABinarySearchTreeTest, SelfAuthoredQueryEqualToMin) {
  // root = [6,2,13], queries = [2]
  TreeNode* root = constructTree(std::vector<std::optional<int>>{6, 2, 13});
  std::vector<int> queries{2};
  std::vector<std::vector<int>> expected{{2, 2}};
  EXPECT_EQ(solution.closestNodes(root, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ClosestNodesQueriesInABinarySearchTreeTests,
    ClosestNodesQueriesInABinarySearchTreeTest,
    ::testing::ValuesIn(
        ClosestNodesQueriesInABinarySearchTreeSolution().getStrategyNames()));

}  // namespace problem_2476
}  // namespace leetcode
