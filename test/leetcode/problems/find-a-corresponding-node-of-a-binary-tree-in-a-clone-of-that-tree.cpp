#include <gtest/gtest.h>

#include <optional>

#include "leetcode/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree.h"

namespace leetcode::problem_1379 {

static TreeNode* findNode(TreeNode* root, int val) {
  if (root == nullptr) return nullptr;
  if (root->val == val) return root;
  TreeNode* left = findNode(root->left, val);
  if (left != nullptr) return left;
  return findNode(root->right, val);
}

class FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeTest, Example1) {
  auto* original = constructTree(std::vector<std::optional<int>>{
      7, 4, 3, std::nullopt, std::nullopt, 6, 19});
  auto* cloned = constructTree(std::vector<std::optional<int>>{
      7, 4, 3, std::nullopt, std::nullopt, 6, 19});
  auto* target = findNode(original, 3);
  auto* result = solution.getTargetCopy(original, cloned, target);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 3);
  EXPECT_NE(result, target);
  delete original;
  delete cloned;
}

TEST_P(FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeTest, Example2) {
  auto* original = constructTree(std::vector<std::optional<int>>{7});
  auto* cloned = constructTree(std::vector<std::optional<int>>{7});
  auto* target = findNode(original, 7);
  auto* result = solution.getTargetCopy(original, cloned, target);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 7);
  EXPECT_NE(result, target);
  delete original;
  delete cloned;
}

TEST_P(FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeTest, Example3) {
  auto* original = constructTree(std::vector<std::optional<int>>{
      8, std::nullopt, 6, std::nullopt, 5, std::nullopt, 4, std::nullopt, 3,
      std::nullopt, 2, std::nullopt, 1});
  auto* cloned = constructTree(std::vector<std::optional<int>>{
      8, std::nullopt, 6, std::nullopt, 5, std::nullopt, 4, std::nullopt, 3,
      std::nullopt, 2, std::nullopt, 1});
  auto* target = findNode(original, 4);
  auto* result = solution.getTargetCopy(original, cloned, target);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 4);
  EXPECT_NE(result, target);
  delete original;
  delete cloned;
}

TEST_P(FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeTest,
       SelfAuthoredLeftChild) {
  auto* original = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, 4, 5});
  auto* cloned = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, 4, 5});
  auto* target = findNode(original, 2);
  auto* result = solution.getTargetCopy(original, cloned, target);
  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->val, 2);
  EXPECT_NE(result, target);
  delete original;
  delete cloned;
}

INSTANTIATE_TEST_SUITE_P(
    , FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeTest,
    ::testing::ValuesIn(
        FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1379
