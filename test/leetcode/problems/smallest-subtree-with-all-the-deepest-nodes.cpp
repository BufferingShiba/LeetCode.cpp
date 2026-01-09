#include "leetcode/problems/smallest-subtree-with-all-the-deepest-nodes.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_865 {

class SmallestSubtreeWithAllTheDeepestNodesTest
    : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestSubtreeWithAllTheDeepestNodesSolution solution;
};

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, Example1) {
  vector<optional<int>> values = {3, 5, 1, 6, 2, 0, 8, nullopt, nullopt, 7, 4};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 2);
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, Example2) {
  vector<int> values = {1};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 1);
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, Example3) {
  vector<optional<int>> values = {0, 1, 3, nullopt, 2};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 2);
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, SingleNode) {
  vector<int> values = {42};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 42);
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, PerfectBinaryTree) {
  // 构建一个完美的二叉树，所有叶子节点都在同一层
  //       1
  //     /   \
  //    2     3
  //   / \   / \
  //  4   5 6   7
  vector<int> values = {1, 2, 3, 4, 5, 6, 7};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 1);  // 根节点是所有最深节点的最近公共祖先
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, SimpleRightSkewedTree) {
  // 构建一个简单的右偏树：1 -> 2 -> 3
  //       1
  //        \
  //         2
  //          \
  //           3
  vector<optional<int>> values = {1, nullopt, 2, nullopt, 3};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  // 最深节点是3，它本身就是结果
  EXPECT_EQ(result->val, 3);
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, SimpleLeftSkewedTree) {
  // 构建一个简单的左偏树：1 -> 2 -> 3
  //       1
  //      /
  //     2
  //    /
  //   3
  vector<optional<int>> values = {1, 2, nullopt, 3};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  // 最深节点是3，它本身就是结果
  EXPECT_EQ(result->val, 3);
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, TwoDeepestNodesSameParent) {
  // 构建树：最深节点是兄弟节点
  //       1
  //     /   \
  //    2     3
  //   / \   / \
  //  4   5 6   7
  //           / \
  //          8   9
  vector<optional<int>> values = {1,       2,       3,       4,       5,
                                  6,       7,       nullopt, nullopt, nullopt,
                                  nullopt, nullopt, nullopt, 8,       9};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 7);  // 节点7是节点8和9的最近公共祖先
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, ThreeDeepestNodes) {
  // 构建树：有三个最深节点
  //       1
  //     /   \
  //    2     3
  //   / \   / \
  //  4   5 6   7
  //     /     / \
  //    8     9   10
  vector<optional<int>> values = {1,       2,       3,       4, 5,
                                  6,       7,       nullopt, 8, nullopt,
                                  nullopt, nullopt, nullopt, 9, 10};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  // 最深节点是8, 9, 10，它们的最近公共祖先是根节点1
  EXPECT_EQ(result->val, 1);
}

TEST_P(SmallestSubtreeWithAllTheDeepestNodesTest, DeepestNodeIsLeaf) {
  // 构建树：最深节点是一个叶子节点
  //       1
  //     /   \
  //    2     3
  //   /
  //  4
  vector<int> values = {1, 2, 3, 4};
  TreeNode* root = constructTree(values);

  TreeNode* result = solution.subtreeWithAllDeepest(root);
  EXPECT_NE(result, nullptr);
  // 最深节点是4，它本身就是结果
  EXPECT_EQ(result->val, 4);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SmallestSubtreeWithAllTheDeepestNodesTest,
    ::testing::ValuesIn(
        SmallestSubtreeWithAllTheDeepestNodesSolution().getStrategyNames()));

}  // namespace problem_865
}  // namespace leetcode