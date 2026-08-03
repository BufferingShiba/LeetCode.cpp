#include "leetcode/problems/second-minimum-node-in-a-binary-tree.h"

#include <functional>

namespace leetcode {
namespace problem_671 {

static int findSecondMinimumValueImpl(TreeNode* root) {
  if (!root) return -1;

  int minVal = root->val;
  long long ans = -1;

  std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
    if (!node) return;
    if (node->val > minVal) {
      if (ans == -1 || node->val < ans) {
        ans = node->val;
      }
      return;  // no need to go deeper, subtree values are all >= node->val
    }
    // node->val == minVal, must explore children
    dfs(node->left);
    dfs(node->right);
  };

  dfs(root);
  return static_cast<int>(ans);
}

SecondMinimumNodeInABinaryTreeSolution::SecondMinimumNodeInABinaryTreeSolution() {
  setMetaInfo({.id = 671,
               .title = "Second Minimum Node In a Binary Tree",
               .url = "https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/"});
  registerStrategy({.name = "DFS",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(h)",
                    .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
                   findSecondMinimumValueImpl);
}

int SecondMinimumNodeInABinaryTreeSolution::findSecondMinimumValue(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_671
}  // namespace leetcode
