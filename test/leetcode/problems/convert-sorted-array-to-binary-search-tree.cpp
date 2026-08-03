#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/convert-sorted-array-to-binary-search-tree.h"

namespace leetcode::problem_108 {
namespace {

using leetcode::inorderTraversal;
using leetcode::isBBST;
using leetcode::isBST;

}  // namespace

class ConvertSortedArrayToBinarySearchTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConvertSortedArrayToBinarySearchTreeSolution solution_;
};

TEST_P(ConvertSortedArrayToBinarySearchTreeTest, Example1) {
  std::vector<int> nums = {-10, -3, 0, 5, 9};
  leetcode::TreeNode* root = solution_.sortedArrayToBST(nums);

  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->val, 0);
  EXPECT_TRUE(isBST(root));
  EXPECT_TRUE(isBBST(root));
}

TEST_P(ConvertSortedArrayToBinarySearchTreeTest, Example2) {
  std::vector<int> nums = {1, 3};
  leetcode::TreeNode* root = solution_.sortedArrayToBST(nums);

  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->left, nullptr);
  ASSERT_NE(root->right, nullptr);
  EXPECT_EQ(root->right->val, 3);
  EXPECT_TRUE(isBST(root));
  EXPECT_TRUE(isBBST(root));
}

TEST_P(ConvertSortedArrayToBinarySearchTreeTest, SingleElement) {
  std::vector<int> nums = {7};
  leetcode::TreeNode* root = solution_.sortedArrayToBST(nums);

  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->val, 7);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
}

INSTANTIATE_TEST_SUITE_P(
    ConvertSortedArrayToBinarySearchTreeTestInstance,
    ConvertSortedArrayToBinarySearchTreeTest,
    ::testing::ValuesIn(
        ConvertSortedArrayToBinarySearchTreeSolution().getStrategyNames()));

}  // namespace leetcode::problem_108
