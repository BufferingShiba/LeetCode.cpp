#include "leetcode/problems/binary-tree-coloring-game.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1145 {

class BinaryTreeColoringGameTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BinaryTreeColoringGameSolution solution;
};

TEST_P(BinaryTreeColoringGameTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
  EXPECT_TRUE(solution.btreeGameWinningMove(root, 11, 3));
  delete root;
}

TEST_P(BinaryTreeColoringGameTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3});
  EXPECT_FALSE(solution.btreeGameWinningMove(root, 3, 1));
  delete root;
}

TEST_P(BinaryTreeColoringGameTest, RootIsSingleNode) {
  TreeNode* root = constructTree(std::vector<int>{1});
  // n = 1, second player cannot win with a single node.
  EXPECT_FALSE(solution.btreeGameWinningMove(root, 1, 1));
  delete root;
}

TEST_P(BinaryTreeColoringGameTest, LeftSubtreeDominates) {
  // x is root; left subtree {2,4,5} = 3 nodes, right subtree {3,6} = 2 nodes.
  // best = 3, n/2 = 3 -> 3 > 3 is false.
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3, 4, 5, 6, -1});
  EXPECT_FALSE(solution.btreeGameWinningMove(root, 7, 1));
  delete root;
}

TEST_P(BinaryTreeColoringGameTest, RestSideDominates) {
  // Left chain 1-2-3-4(5); x=4 sits at the tail. 4's subtree has only {5}
  // (1 node), so the rest region = 5 - 1 - 1 = 3 > 5/2 => win.
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n4 = new TreeNode(4, n5, nullptr);
  TreeNode* n3 = new TreeNode(3, n4, nullptr);
  TreeNode* n2 = new TreeNode(2, n3, nullptr);
  TreeNode* root = new TreeNode(1, n2, nullptr);
  EXPECT_TRUE(solution.btreeGameWinningMove(root, 5, 4));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, BinaryTreeColoringGameTest,
    ::testing::ValuesIn(BinaryTreeColoringGameSolution().getStrategyNames()));

}  // namespace problem_1145
}  // namespace leetcode
