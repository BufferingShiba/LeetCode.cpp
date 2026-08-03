#include "leetcode/problems/construct-binary-tree-from-preorder-and-postorder-traversal.h"

#include <unordered_map>

namespace leetcode {
namespace problem_889 {

namespace {

TreeNode* constructFromPrePostImpl(std::vector<int>& preorder,
                                   std::vector<int>& postorder,
                                   const std::unordered_map<int, int>& post_index,
                                   int pre_left, int pre_right, int post_left,
                                   int post_right) {
  if (pre_left > pre_right) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(preorder[pre_left]);
  if (pre_left == pre_right) {
    return root;
  }
  // preorder[pre_left + 1] is the root of the left subtree (may be empty).
  int left_root = preorder[pre_left + 1];
  int left_root_post_idx = post_index.at(left_root);
  int left_size = left_root_post_idx - post_left + 1;
  root->left = constructFromPrePostImpl(preorder, postorder, post_index,
                                        pre_left + 1, pre_left + left_size,
                                        post_left, left_root_post_idx);
  root->right = constructFromPrePostImpl(
      preorder, postorder, post_index, pre_left + left_size + 1, pre_right,
      left_root_post_idx + 1, post_right - 1);
  return root;
}

}  // namespace

ConstructBinaryTreeFromPreorderAndPostorderTraversalSolution::
    ConstructBinaryTreeFromPreorderAndPostorderTraversalSolution() {
  setMetaInfo({889, "Construct Binary Tree from Preorder and Postorder Traversal",
               "https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/"});
  registerStrategy({
    .name = "DivideAndConquer",
    .expected = "Accepted",
    .time_complexity = "O(n)",
    .space_complexity = "O(n)",
    .tags = {"Divide & Conquer", "Hash Table", "Tree"}},
    [](std::vector<int>& preorder, std::vector<int>& postorder) -> TreeNode* {
      int n = static_cast<int>(preorder.size());
      std::unordered_map<int, int> post_index;
      for (int i = 0; i < n; ++i) {
        post_index[postorder[i]] = i;
      }
      return constructFromPrePostImpl(preorder, postorder, post_index, 0,
                                      n - 1, 0, n - 1);
    });
}

TreeNode*
ConstructBinaryTreeFromPreorderAndPostorderTraversalSolution::constructFromPrePost(
    std::vector<int>& preorder, std::vector<int>& postorder) {
  return getSolution()(preorder, postorder);
}

}  // namespace problem_889
}  // namespace leetcode
