#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/construct-binary-search-tree-from-preorder-traversal.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_1008 {
namespace {

class ConstructBinarySearchTreeFromPreorderTraversalTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConstructBinarySearchTreeFromPreorderTraversalSolution solution;
};

TEST_P(ConstructBinarySearchTreeFromPreorderTraversalTest, Example1) {
  std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
  leetcode::TreeNode* expected =
      leetcode::constructTree(std::vector<int>{8, 5, 10, 1, 7, -1, 12});
  leetcode::TreeNode* result = solution.bstFromPreorder(preorder);

  EXPECT_TRUE(leetcode::isSameTree(expected, result));
  delete expected;
  delete result;
}

TEST_P(ConstructBinarySearchTreeFromPreorderTraversalTest, Example2) {
  std::vector<int> preorder = {1, 3};
  leetcode::TreeNode* expected =
      leetcode::constructTree(std::vector<int>{1, -1, 3});
  leetcode::TreeNode* result = solution.bstFromPreorder(preorder);

  EXPECT_TRUE(leetcode::isSameTree(expected, result));
  delete expected;
  delete result;
}

TEST_P(ConstructBinarySearchTreeFromPreorderTraversalTest, LeftSkewedChain) {
  // 5 -> left 4 -> left 3 -> left 2 -> left 1 (a pure left-skewed chain).
  std::vector<int> preorder = {5, 4, 3, 2, 1};
  leetcode::TreeNode* expected = leetcode::constructTree(
      std::vector<int>{5, 4, -1, 3, -1, 2, -1, 1, -1, -1, -1});
  leetcode::TreeNode* result = solution.bstFromPreorder(preorder);

  EXPECT_TRUE(leetcode::isSameTree(expected, result));
  delete expected;
  delete result;
}

TEST_P(ConstructBinarySearchTreeFromPreorderTraversalTest, SingleNode) {
  std::vector<int> preorder = {10};
  leetcode::TreeNode* result = solution.bstFromPreorder(preorder);

  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 10);
  EXPECT_EQ(result->left, nullptr);
  EXPECT_EQ(result->right, nullptr);
  delete result;
}

INSTANTIATE_TEST_SUITE_P(
    ConstructBinarySearchTreeFromPreorderTraversalTestSuite,
    ConstructBinarySearchTreeFromPreorderTraversalTest,
    testing::ValuesIn(
        ConstructBinarySearchTreeFromPreorderTraversalSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_1008
}  // namespace leetcode
