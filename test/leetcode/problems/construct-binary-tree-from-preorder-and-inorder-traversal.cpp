#include <gtest/gtest.h>

#include "leetcode/problems/construct-binary-tree-from-preorder-and-inorder-traversal.h"

using namespace leetcode;
using namespace leetcode::problem_105;

class ConstructBinaryTreeFromPreorderAndInorderTraversalTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConstructBinaryTreeFromPreorderAndInorderTraversalSolution solution_;
};

TEST_P(ConstructBinaryTreeFromPreorderAndInorderTraversalTest, Example1) {
  std::vector<int> preorder = {3, 9, 20, 15, 7};
  std::vector<int> inorder = {9, 3, 15, 20, 7};

  TreeNode* result = solution_.buildTree(preorder, inorder);
  TreeNode* expected = constructTree(
      std::vector<std::optional<int>>{3, 9, 20, std::nullopt, std::nullopt, 15, 7});

  EXPECT_TRUE(isSameTree(result, expected));

  delete expected;
  delete result;
}

TEST_P(ConstructBinaryTreeFromPreorderAndInorderTraversalTest, Example2) {
  std::vector<int> preorder = {-1};
  std::vector<int> inorder = {-1};

  TreeNode* result = solution_.buildTree(preorder, inorder);
  auto* expected = new TreeNode(-1);

  EXPECT_TRUE(isSameTree(result, expected));

  delete expected;
  delete result;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ConstructBinaryTreeFromPreorderAndInorderTraversalTest,
    testing::ValuesIn(ConstructBinaryTreeFromPreorderAndInorderTraversalSolution()
                          .getStrategyNames()));
