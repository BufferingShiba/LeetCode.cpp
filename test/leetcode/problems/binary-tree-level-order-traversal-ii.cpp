#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/binary-tree-level-order-traversal-ii.h"

namespace leetcode {
namespace problem_107 {

class BinaryTreeLevelOrderTraversalIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BinaryTreeLevelOrderTraversalIiSolution solution;
};

TEST_P(BinaryTreeLevelOrderTraversalIiTest, Example1) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{3, 9, 20,
                                                                    std::nullopt,
                                                                    std::nullopt,
                                                                    15,
                                                                    7});
  std::vector<std::vector<int>> expected = {{15, 7}, {9, 20}, {3}};
  EXPECT_EQ(solution.levelOrderBottom(root), expected);
  delete root;
}

TEST_P(BinaryTreeLevelOrderTraversalIiTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1});
  std::vector<std::vector<int>> expected = {{1}};
  EXPECT_EQ(solution.levelOrderBottom(root), expected);
  delete root;
}

TEST_P(BinaryTreeLevelOrderTraversalIiTest, Example3) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{});
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(solution.levelOrderBottom(root), expected);
}

TEST_P(BinaryTreeLevelOrderTraversalIiTest, SelfAuthoredSingleLeftChain) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1, 2, std::nullopt,
                                                                    3,
                                                                    std::nullopt,
                                                                    std::nullopt,
                                                                    4});
  std::vector<std::vector<int>> expected = {{4}, {3}, {2}, {1}};
  EXPECT_EQ(solution.levelOrderBottom(root), expected);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    BinaryTreeLevelOrderTraversalIiTestSuite,
    BinaryTreeLevelOrderTraversalIiTest,
    ::testing::ValuesIn(BinaryTreeLevelOrderTraversalIiSolution().getStrategyNames()));

}  // namespace problem_107
}  // namespace leetcode
