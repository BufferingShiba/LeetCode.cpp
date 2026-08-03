#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "leetcode/problems/all-nodes-distance-k-in-binary-tree.h"

using namespace leetcode;
using namespace leetcode::problem_863;

// Helper: find node pointer by unique value
static TreeNode* findNode(TreeNode* root, int targetVal) {
  if (!root) return nullptr;
  if (root->val == targetVal) return root;
  TreeNode* left = findNode(root->left, targetVal);
  if (left) return left;
  return findNode(root->right, targetVal);
}

class AllNodesDistanceKInBinaryTreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  AllNodesDistanceKInBinaryTreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(AllNodesDistanceKInBinaryTreeTest, Example1) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4});
  TreeNode* target = findNode(root, 5);
  int k = 2;
  auto result = solution.distanceK(root, target, k);
  std::sort(result.begin(), result.end());
  std::vector<int> expected = {7, 4, 1};
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST_P(AllNodesDistanceKInBinaryTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1});
  TreeNode* target = findNode(root, 1);
  int k = 3;
  auto result = solution.distanceK(root, target, k);
  EXPECT_TRUE(result.empty());
}

TEST_P(AllNodesDistanceKInBinaryTreeTest, SelfAuthoredDistanceZero) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{3, 5, 1, 6, 2, 0, 8, std::nullopt,
                                      std::nullopt, 7, 4});
  TreeNode* target = findNode(root, 5);
  int k = 0;
  auto result = solution.distanceK(root, target, k);
  std::vector<int> expected = {5};
  EXPECT_EQ(result, expected);
}

TEST_P(AllNodesDistanceKInBinaryTreeTest, SelfAuthoredTargetIsRoot) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4});
  TreeNode* target = findNode(root, 3);
  int k = 1;
  auto result = solution.distanceK(root, target, k);
  std::sort(result.begin(), result.end());
  std::vector<int> expected = {5, 1};
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST_P(AllNodesDistanceKInBinaryTreeTest, SelfAuthoredGoUpThenDown) {
  // k=3 from 5: 5->3->1->0 (distance 3: 0), 5->3->1->8 (distance 3: 8)
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4});
  TreeNode* target = findNode(root, 5);
  int k = 3;
  auto result = solution.distanceK(root, target, k);
  std::sort(result.begin(), result.end());
  std::vector<int> expected = {0, 8};
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, AllNodesDistanceKInBinaryTreeTest,
    testing::ValuesIn(
        AllNodesDistanceKInBinaryTreeSolution().getStrategyNames()));
