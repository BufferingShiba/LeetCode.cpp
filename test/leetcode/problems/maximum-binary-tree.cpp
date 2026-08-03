#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-binary-tree.h"

namespace leetcode {
namespace problem_654 {

class MaximumBinaryTreeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumBinaryTreeSolution solution;
};

TEST_P(MaximumBinaryTreeTest, Example1) {
  std::vector<int> nums = {3, 2, 1, 6, 0, 5};
  TreeNode* root = solution.constructMaximumBinaryTree(nums);
  TreeNode* expected = constructTree(std::vector<std::optional<int>>{
      6, 3, 5, std::nullopt, 2, 0, std::nullopt, std::nullopt, 1});
  EXPECT_TRUE(isSameTree(expected, root));
  delete root;
  delete expected;
}

TEST_P(MaximumBinaryTreeTest, Example2) {
  std::vector<int> nums = {3, 2, 1};
  TreeNode* root = solution.constructMaximumBinaryTree(nums);
  TreeNode* expected = constructTree(std::vector<std::optional<int>>{
      3, std::nullopt, 2, std::nullopt, 1});
  EXPECT_TRUE(isSameTree(expected, root));
  delete root;
  delete expected;
}

TEST_P(MaximumBinaryTreeTest, SingleElement) {
  std::vector<int> nums = {5};
  TreeNode* root = solution.constructMaximumBinaryTree(nums);
  TreeNode* expected = constructTree(std::vector<std::optional<int>>{5});
  EXPECT_TRUE(isSameTree(expected, root));
  delete root;
  delete expected;
}

TEST_P(MaximumBinaryTreeTest, Increasing) {
  // Strictly increasing array -> max at the end, left subtree is left chain.
  std::vector<int> nums = {1, 2, 3, 4};
  TreeNode* root = solution.constructMaximumBinaryTree(nums);
  TreeNode* expected = constructTree(std::vector<std::optional<int>>{
      4, 3, std::nullopt, 2, std::nullopt, 1});
  EXPECT_TRUE(isSameTree(expected, root));
  delete root;
  delete expected;
}

INSTANTIATE_TEST_SUITE_P(MaximumBinaryTreeStrategies, MaximumBinaryTreeTest,
                         ::testing::ValuesIn(
                             MaximumBinaryTreeSolution().getStrategyNames()));

}  // namespace problem_654
}  // namespace leetcode
