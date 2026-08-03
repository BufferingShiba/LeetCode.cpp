#include "leetcode/problems/construct-string-from-binary-tree.h"

namespace leetcode {
namespace problem_606 {

static void dfs(TreeNode* node, string& out) {
  if (node == nullptr) return;
  out += std::to_string(node->val);
  if (node->left != nullptr || node->right != nullptr) {
    out += '(';
    dfs(node->left, out);
    out += ')';
    if (node->right != nullptr) {
      out += '(';
      dfs(node->right, out);
      out += ')';
    }
  }
}

static string solution1(TreeNode* root) {
  string out;
  dfs(root, out);
  return out;
}

ConstructStringFromBinaryTreeSolution::ConstructStringFromBinaryTreeSolution() {
  setMetaInfo({
      .id = 606,
      .title = "Construct String from Binary Tree",
      .url = "https://leetcode.com/problems/construct-string-from-binary-tree"
  });
  registerStrategy({.name = "Preorder DFS",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(h)",
                    .tags = {"Tree", "DFS", "Binary Tree"}},
                   solution1);
}

string ConstructStringFromBinaryTreeSolution::tree2str(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_606
}  // namespace leetcode
