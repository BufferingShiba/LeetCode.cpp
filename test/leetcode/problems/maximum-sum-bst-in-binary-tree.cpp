#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-sum-bst-in-binary-tree.h"

namespace leetcode {
namespace problem_1373 {
namespace {

class MaximumSumBstInBinaryTreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumSumBstInBinaryTreeSolution solution_;
};

TEST_P(MaximumSumBstInBinaryTreeTest, Example1) {
  TreeNode* root = constructTree(
      std::vector<int>{1, 4, 3, 2, 4, 2, 5, -1, -1, -1, -1, -1, -1, 4, 6});
  EXPECT_EQ(20, solution_.maxSumBST(root));
}

TEST_P(MaximumSumBstInBinaryTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{4, 3, -1, 1, 2});
  EXPECT_EQ(2, solution_.maxSumBST(root));
}

TEST_P(MaximumSumBstInBinaryTreeTest, Example3) {
  TreeNode* root = constructTree(std::vector<int>{-4, -2, -5});
  EXPECT_EQ(0, solution_.maxSumBST(root));
}

TEST_P(MaximumSumBstInBinaryTreeTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<int>{5});
  EXPECT_EQ(5, solution_.maxSumBST(root));
}

TEST_P(MaximumSumBstInBinaryTreeTest, SelfAuthoredSingleNegativeNode) {
  TreeNode* root = constructTree(std::vector<int>{-3});
  EXPECT_EQ(0, solution_.maxSumBST(root));
}

TEST_P(MaximumSumBstInBinaryTreeTest, SelfAuthoredNonBstWholeTree) {
  TreeNode* root = constructTree(std::vector<int>{2, 1, 3, 5});
  // Subtree {1} sum 1, {5} sum 5, {3} with left=5 is not a BST.
  EXPECT_EQ(5, solution_.maxSumBST(root));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSumBstInBinaryTreeTestSuite, MaximumSumBstInBinaryTreeTest,
    testing::ValuesIn(MaximumSumBstInBinaryTreeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1373
}  // namespace leetcode
