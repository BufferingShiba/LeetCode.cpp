#include <gtest/gtest.h>

#include "leetcode/problems/second-minimum-node-in-a-binary-tree.h"

using namespace leetcode;
using namespace leetcode::problem_671;

class SecondMinimumNodeInABinaryTreeTest : public testing::TestWithParam<std::string> {
 protected:
  SecondMinimumNodeInABinaryTreeSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SecondMinimumNodeInABinaryTreeTest, Example1) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{2, 2, 5, std::nullopt, std::nullopt, 5, 7});
  EXPECT_EQ(solution.findSecondMinimumValue(root), 5);
  delete root;
}

TEST_P(SecondMinimumNodeInABinaryTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{2, 2, 2});
  EXPECT_EQ(solution.findSecondMinimumValue(root), -1);
  delete root;
}

TEST_P(SecondMinimumNodeInABinaryTreeTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{5});
  EXPECT_EQ(solution.findSecondMinimumValue(root), -1);
  delete root;
}

TEST_P(SecondMinimumNodeInABinaryTreeTest, SelfAuthoredAllSameMultiLevel) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{3, 3, 3, 3, 3, std::nullopt, std::nullopt});
  EXPECT_EQ(solution.findSecondMinimumValue(root), -1);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    SecondMinimumNodeInABinaryTree,
    SecondMinimumNodeInABinaryTreeTest,
    testing::ValuesIn(SecondMinimumNodeInABinaryTreeSolution().getStrategyNames()));
