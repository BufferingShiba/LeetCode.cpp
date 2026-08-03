#include "leetcode/problems/find-elements-in-a-contaminated-binary-tree.h"

namespace leetcode::problem_1261 {

namespace {

// Recover the tree in DFS order and record every real value into set.
void recoverDFS(TreeNode* node, int val, std::unordered_set<int>& values) {
  if (node == nullptr) {
    return;
  }
  node->val = val;
  values.insert(val);
  recoverDFS(node->left, 2 * val + 1, values);
  recoverDFS(node->right, 2 * val + 2, values);
}

}  // namespace

FindElements::FindElements(TreeNode* root) {
  if (root != nullptr) {
    recoverDFS(root, 0, values_);
  }
}

bool FindElements::find(int target) {
  return values_.count(target) > 0;
}

}  // namespace leetcode::problem_1261
