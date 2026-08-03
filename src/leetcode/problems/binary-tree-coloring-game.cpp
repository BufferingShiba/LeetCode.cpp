#include "leetcode/problems/binary-tree-coloring-game.h"

namespace leetcode {
namespace problem_1145 {

static TreeNode* findNode(TreeNode* root, int x) {
  if (!root) return nullptr;
  if (root->val == x) return root;
  if (TreeNode* l = findNode(root->left, x)) return l;
  return findNode(root->right, x);
}

static int countNodes(TreeNode* root) {
  if (!root) return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

static bool solution1(TreeNode* root, int n, int x) {
  TreeNode* node = findNode(root, x);
  int left = countNodes(node->left);
  int right = countNodes(node->right);
  int rest = n - 1 - left - right;
  int best = std::max(left, std::max(right, rest));
  return best > n / 2;
}

BinaryTreeColoringGameSolution::BinaryTreeColoringGameSolution() {
  setMetaInfo({
      .id = 1145,
      .title = "Binary Tree Coloring Game",
      .url = "https://leetcode.com/problems/binary-tree-coloring-game"
  });
  registerStrategy({.name = "Brute Force", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"Tree"}}, solution1);
}

bool BinaryTreeColoringGameSolution::btreeGameWinningMove(TreeNode* root, int n, int x) {
  return getSolution()(root, n, x);
}

}  // namespace problem_1145
}  // namespace leetcode
