// LeetCode 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/

#include "leetcode/problems/find-mode-in-binary-search-tree.h"

namespace leetcode::problem_501 {

namespace {

void findModeImpl(TreeNode* node, int& prevVal, int& curCount, int& maxCount,
                  std::vector<int>& result) {
  if (node == nullptr) {
    return;
  }
  findModeImpl(node->left, prevVal, curCount, maxCount, result);

  if (curCount == 0 || node->val != prevVal) {
    curCount = 1;
    prevVal = node->val;
  } else {
    ++curCount;
  }

  if (curCount > maxCount) {
    maxCount = curCount;
    result.clear();
    result.push_back(node->val);
  } else if (curCount == maxCount) {
    result.push_back(node->val);
  }

  findModeImpl(node->right, prevVal, curCount, maxCount, result);
}

}  // namespace

FindModeInBinarySearchTreeSolution::FindModeInBinarySearchTreeSolution() {
  this->setMetaInfo({.id = 501,
                     .title = "Find Mode in Binary Search Tree",
                     .url =
                         "https://leetcode.com/problems/find-mode-in-binary-"
                         "search-tree/"});
  this->registerStrategy(
      {.name = "inorder-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .notes =
           "In-order traversal of a BST yields sorted values; track the "
           "current run length and max run length to collect all modes."},
      [](TreeNode* root) -> std::vector<int> {
        std::vector<int> result;
        int prevVal = 0;
        int curCount = 0;
        int maxCount = 0;
        findModeImpl(root, prevVal, curCount, maxCount, result);
        return result;
      });
}

std::vector<int> FindModeInBinarySearchTreeSolution::findMode(TreeNode* root) {
  return this->getSolution()(root);
}

}  // namespace leetcode::problem_501
