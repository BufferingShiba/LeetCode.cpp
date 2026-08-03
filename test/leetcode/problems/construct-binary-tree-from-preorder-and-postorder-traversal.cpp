#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/construct-binary-tree-from-preorder-and-postorder-traversal.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_889 {
namespace {

std::string toString(const std::vector<int>& v) {
  std::string s;
  for (size_t i = 0; i < v.size(); ++i) {
    if (i) s += ',';
    s += std::to_string(v[i]);
  }
  return "[" + s + "]";
}

void expectValidTree(TreeNode* root, const std::vector<int>& preorder,
                     const std::vector<int>& postorder) {
  ASSERT_NE(root, nullptr);
  ASSERT_EQ(preorderTraversal(root), preorder)
      << "preorder mismatch, got " << toString(preorderTraversal(root))
      << " expected " << toString(preorder);
  ASSERT_EQ(postorderTraversal(root), postorder)
      << "postorder mismatch, got " << toString(postorderTraversal(root))
      << " expected " << toString(postorder);
}

}  // namespace

class ConstructBinaryTreeFromPreorderAndPostorderTraversalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConstructBinaryTreeFromPreorderAndPostorderTraversalSolution solution;
};

TEST_P(ConstructBinaryTreeFromPreorderAndPostorderTraversalTest, Example1) {
  std::vector<int> preorder{1, 2, 4, 5, 3, 6, 7};
  std::vector<int> postorder{4, 5, 2, 6, 7, 3, 1};
  TreeNode* root = solution.constructFromPrePost(preorder, postorder);
  expectValidTree(root, preorder, postorder);
  delete root;
}

TEST_P(ConstructBinaryTreeFromPreorderAndPostorderTraversalTest, Example2) {
  std::vector<int> preorder{1};
  std::vector<int> postorder{1};
  TreeNode* root = solution.constructFromPrePost(preorder, postorder);
  expectValidTree(root, preorder, postorder);
  delete root;
}

TEST_P(ConstructBinaryTreeFromPreorderAndPostorderTraversalTest, SelfAuthoredSingleLeftChain) {
  // Tree: 1->2->3 (all left). preorder=[1,2,3], postorder=[3,2,1].
  std::vector<int> preorder{1, 2, 3};
  std::vector<int> postorder{3, 2, 1};
  TreeNode* root = solution.constructFromPrePost(preorder, postorder);
  expectValidTree(root, preorder, postorder);
  delete root;
}

TEST_P(ConstructBinaryTreeFromPreorderAndPostorderTraversalTest, SelfAuthoredSingleRightChain) {
  // Tree: 1->2->3 (all right). preorder=[1,2,3], postorder=[3,2,1].
  std::vector<int> preorder{1, 2, 3};
  std::vector<int> postorder{3, 2, 1};
  TreeNode* root = solution.constructFromPrePost(preorder, postorder);
  expectValidTree(root, preorder, postorder);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    ConstructBinaryTreeFromPreorderAndPostorderTraversalTestSuite,
    ConstructBinaryTreeFromPreorderAndPostorderTraversalTest,
    ::testing::ValuesIn(
        ConstructBinaryTreeFromPreorderAndPostorderTraversalSolution()
            .getStrategyNames()));

}  // namespace problem_889
}  // namespace leetcode
