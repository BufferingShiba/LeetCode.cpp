#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/invert-binary-tree.h"

namespace leetcode {
namespace problem_226 {

class InvertBinaryTreeTest : public ::testing::TestWithParam<std::string> {
 protected:
  InvertBinaryTreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

// Helper to build expected inverted tree and compare.
static bool checkInversion(TreeNode* root, TreeNode* expected) {
  if (root == nullptr && expected == nullptr) return true;
  if (root == nullptr || expected == nullptr) return false;
  return root->val == expected->val &&
         checkInversion(root->left, expected->left) &&
         checkInversion(root->right, expected->right);
}

TEST_P(InvertBinaryTreeTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{4, 2, 7, 1, 3, 6, 9});
  TreeNode* expected = constructTree(std::vector<int>{4, 7, 2, 9, 6, 3, 1});
  TreeNode* result = solution.invertTree(root);
  EXPECT_TRUE(checkInversion(result, expected));
}

TEST_P(InvertBinaryTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{2, 1, 3});
  TreeNode* expected = constructTree(std::vector<int>{2, 3, 1});
  TreeNode* result = solution.invertTree(root);
  EXPECT_TRUE(checkInversion(result, expected));
}

TEST_P(InvertBinaryTreeTest, Example3_Empty) {
  TreeNode* root = nullptr;
  TreeNode* result = solution.invertTree(root);
  EXPECT_EQ(result, nullptr);
}

TEST_P(InvertBinaryTreeTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<int>{5});
  TreeNode* result = solution.invertTree(root);
  EXPECT_EQ(result->val, 5);
  EXPECT_EQ(result->left, nullptr);
  EXPECT_EQ(result->right, nullptr);
}

INSTANTIATE_TEST_SUITE_P(
    InvertBinaryTreeTests, InvertBinaryTreeTest,
    ::testing::ValuesIn(InvertBinaryTreeSolution().getStrategyNames()));

}  // namespace problem_226
}  // namespace leetcode
