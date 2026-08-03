#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/binary-tree-preorder-traversal.h"

namespace leetcode::problem_144 {

class BinaryTreePreorderTraversalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  BinaryTreePreorderTraversalSolution solution_;
};

TEST_P(BinaryTreePreorderTraversalTest, Example1) {
  // [1,null,2,3]
  TreeNode* root = constructTree(std::vector<int>{1, -1, 2, 3, -1});
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(solution_.preorderTraversal(root), expected);
}

TEST_P(BinaryTreePreorderTraversalTest, Example2) {
  // [1,2,3,4,5,null,8,null,null,6,7,9]
  TreeNode* root = constructTree(
      std::vector<int>{1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
  std::vector<int> expected = {1, 2, 4, 5, 6, 7, 3, 8, 9};
  EXPECT_EQ(solution_.preorderTraversal(root), expected);
}

TEST_P(BinaryTreePreorderTraversalTest, Example3Empty) {
  std::vector<int> expected = {};
  EXPECT_EQ(solution_.preorderTraversal(nullptr), expected);
}

TEST_P(BinaryTreePreorderTraversalTest, Example4SingleNode) {
  TreeNode* root = constructTree(std::vector<int>{1});
  std::vector<int> expected = {1};
  EXPECT_EQ(solution_.preorderTraversal(root), expected);
}

INSTANTIATE_TEST_SUITE_P(
    BinaryTreePreorderTraversalTestSuite, BinaryTreePreorderTraversalTest,
    ::testing::ValuesIn(
        BinaryTreePreorderTraversalSolution().getStrategyNames()));

}  // namespace leetcode::problem_144
