#include <gtest/gtest.h>

#include <functional>
#include <optional>
#include <string>
#include <vector>

#include "leetcode/problems/flatten-binary-tree-to-linked-list.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_114 {

class FlattenBinaryTreeToLinkedListTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

 public:
  FlattenBinaryTreeToLinkedListSolution solution;
};

TEST_P(FlattenBinaryTreeToLinkedListTest, Example1) {
  leetcode::TreeNode* root =
      constructTree(std::vector<int>{1, 2, 5, 3, 4, -1, 6});
  solution.flatten(root);
  leetcode::TreeNode* cur = root;
  std::vector<int> flat;
  while (cur != nullptr) {
    flat.push_back(cur->val);
    EXPECT_EQ(cur->left, nullptr);
    cur = cur->right;
  }
  EXPECT_EQ(flat, (std::vector<int>{1, 2, 3, 4, 5, 6}));
  delete root;
}

TEST_P(FlattenBinaryTreeToLinkedListTest, Example2_Empty) {
  leetcode::TreeNode* root = nullptr;
  solution.flatten(root);
  EXPECT_EQ(root, nullptr);
}

TEST_P(FlattenBinaryTreeToLinkedListTest, Example3_SingleNode) {
  leetcode::TreeNode* root = constructTree(std::vector<int>{0});
  solution.flatten(root);
  leetcode::TreeNode* cur = root;
  std::vector<int> flat;
  while (cur != nullptr) {
    flat.push_back(cur->val);
    EXPECT_EQ(cur->left, nullptr);
    cur = cur->right;
  }
  EXPECT_EQ(flat, (std::vector<int>{0}));
  delete root;
}

TEST_P(FlattenBinaryTreeToLinkedListTest, SelfAuthoredLeftOnlyTree) {
  leetcode::TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, std::nullopt, 3});
  solution.flatten(root);
  leetcode::TreeNode* cur = root;
  std::vector<int> flat;
  while (cur != nullptr) {
    flat.push_back(cur->val);
    EXPECT_EQ(cur->left, nullptr);
    cur = cur->right;
  }
  EXPECT_EQ(flat, (std::vector<int>{1, 2, 3}));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    FlattenBinaryTreeToLinkedListStrategies,
    FlattenBinaryTreeToLinkedListTest,
    ::testing::ValuesIn(
        FlattenBinaryTreeToLinkedListSolution().getStrategyNames()));

}  // namespace leetcode::problem_114
