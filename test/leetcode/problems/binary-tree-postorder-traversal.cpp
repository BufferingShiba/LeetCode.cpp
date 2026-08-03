#include "leetcode/problems/binary-tree-postorder-traversal.h"

#include <gtest/gtest.h>

#include <optional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_145 {

class BinaryTreePostorderTraversalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BinaryTreePostorderTraversalSolution solution;
};

TEST_P(BinaryTreePostorderTraversalTest, Example1) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      1, std::nullopt, 2, 3});
  std::vector<int> expected{3, 2, 1};
  EXPECT_EQ(solution.postorderTraversal(root), expected);
  delete root;
}

TEST_P(BinaryTreePostorderTraversalTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      1, 2, 3, 4, 5, std::nullopt, 8, std::nullopt, std::nullopt, 6, 7, 9});
  std::vector<int> expected{4, 6, 7, 5, 2, 9, 8, 3, 1};
  EXPECT_EQ(solution.postorderTraversal(root), expected);
  delete root;
}

TEST_P(BinaryTreePostorderTraversalTest, Example3EmptyTree) {
  TreeNode* root = nullptr;
  std::vector<int> expected{};
  EXPECT_EQ(solution.postorderTraversal(root), expected);
}

TEST_P(BinaryTreePostorderTraversalTest, Example4SingleNode) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1});
  std::vector<int> expected{1};
  EXPECT_EQ(solution.postorderTraversal(root), expected);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    BinaryTreePostorderTraversalTestSuite, BinaryTreePostorderTraversalTest,
    ::testing::ValuesIn(BinaryTreePostorderTraversalSolution().getStrategyNames()));

}  // namespace problem_145
}  // namespace leetcode
