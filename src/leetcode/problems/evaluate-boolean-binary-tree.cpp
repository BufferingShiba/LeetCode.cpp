#include "leetcode/problems/evaluate-boolean-binary-tree.h"

namespace leetcode {
namespace problem_2331 {

namespace {

bool evaluateTreeImpl(TreeNode* root) {
  if (root == nullptr) {
    return false;
  }
  // Leaf node.
  if (root->left == nullptr && root->right == nullptr) {
    return root->val == 1;
  }
  bool left = evaluateTreeImpl(root->left);
  bool right = evaluateTreeImpl(root->right);
  if (root->val == 2) {  // OR
    return left || right;
  }
  return left && right;  // AND
}

}  // namespace

EvaluateBooleanBinaryTreeSolution::EvaluateBooleanBinaryTreeSolution() {
  setMetaInfo({.id = 2331,
               .title = "Evaluate Boolean Binary Tree",
               .url = "https://leetcode.com/problems/evaluate-boolean-binary-tree/"});
  registerStrategy(
      {"RecursiveDFS", "Accepted", "O(n)", "O(n)",
       {"Tree", "Depth-First Search", "Binary Tree"}},
      evaluateTreeImpl);
}

bool EvaluateBooleanBinaryTreeSolution::evaluateTree(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_2331
}  // namespace leetcode
