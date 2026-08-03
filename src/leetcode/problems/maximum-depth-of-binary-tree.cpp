#include "leetcode/problems/maximum-depth-of-binary-tree.h"

#include <algorithm>

namespace leetcode {
namespace problem_104 {

namespace {
int maxDepthImpl(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + std::max(maxDepthImpl(root->left), maxDepthImpl(root->right));
}
}  // namespace

MaximumDepthOfBinaryTreeSolution::MaximumDepthOfBinaryTreeSolution() {
  setMetaInfo({104, "Maximum Depth of Binary Tree",
               "https://leetcode.com/problems/maximum-depth-of-binary-tree/"});
  registerStrategy(
      {"RecursiveDFS", "Accepted", "O(n)", "O(height)",
       {"Tree", "Depth-First Search", "Binary Tree"},
       "递归：每个节点的最大深度 = 1 + max(左/右子树深度)"},
      [](TreeNode* root) -> int { return maxDepthImpl(root); });
}

int MaximumDepthOfBinaryTreeSolution::maxDepth(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_104
}  // namespace leetcode
