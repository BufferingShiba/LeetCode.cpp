#include "leetcode/problems/convert-sorted-array-to-binary-search-tree.h"

#include <vector>

namespace leetcode::problem_108 {

namespace {

leetcode::TreeNode* buildTree(const std::vector<int>& nums, int left,
                              int right) {
  if (left > right) {
    return nullptr;
  }
  int mid = left + (right - left) / 2;
  leetcode::TreeNode* node = new leetcode::TreeNode(nums[mid]);
  node->left = buildTree(nums, left, mid - 1);
  node->right = buildTree(nums, mid + 1, right);
  return node;
}

}  // namespace

leetcode::TreeNode* ConvertSortedArrayToBinarySearchTreeSolution::
    sortedArrayToBST(std::vector<int>& nums) {
  return getSolution()(nums);
}

leetcode::TreeNode* ConvertSortedArrayToBinarySearchTreeSolution::
    sortedArrayToBSTImpl(std::vector<int>& nums) {
  return buildTree(nums, 0, static_cast<int>(nums.size()) - 1);
}

}  // namespace leetcode::problem_108
