#include "leetcode/problems/two-sum-iv-input-is-a-bst.h"

#include <unordered_set>

namespace leetcode {
namespace problem_653 {

namespace {

bool findTargetImpl(TreeNode* root, int k) {
  std::unordered_set<int> seen;
  std::vector<TreeNode*> stack;
  TreeNode* node = root;
  while (node || !stack.empty()) {
    while (node) {
      stack.push_back(node);
      node = node->left;
    }
    node = stack.back();
    stack.pop_back();
    if (seen.count(k - node->val)) {
      return true;
    }
    seen.insert(node->val);
    node = node->right;
  }
  return false;
}

}  // namespace

TwoSumIvInputIsABstSolution::TwoSumIvInputIsABstSolution() {
  this->setMetaInfo({.id = 653,
                     .title = "Two Sum IV - Input is a BST",
                     .url = "https://leetcode.com/problems/two-sum-iv-input-is-a-bst/"});
  this->registerStrategy(
      {.name = "HashSet DFS",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Tree", "Depth-First Search", "Binary Search Tree",
                "Binary Tree"}},
      findTargetImpl);
}

bool TwoSumIvInputIsABstSolution::findTarget(TreeNode* root, int k) {
  return getSolution()(root, k);
}

}  // namespace problem_653
}  // namespace leetcode
