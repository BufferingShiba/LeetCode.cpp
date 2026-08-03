#include "leetcode/problems/merge-two-binary-trees.h"

namespace leetcode {
namespace problem_617 {

static TreeNode* cloneTree(TreeNode* root) {
  if (root == nullptr) return nullptr;
  auto* node = new TreeNode(root->val);
  node->left = cloneTree(root->left);
  node->right = cloneTree(root->right);
  return node;
}

static TreeNode* mergeTreesImpl(TreeNode* root1, TreeNode* root2) {
  if (root1 == nullptr) return cloneTree(root2);
  if (root2 == nullptr) return cloneTree(root1);

  auto* merged = new TreeNode(root1->val + root2->val);
  merged->left = mergeTreesImpl(root1->left, root2->left);
  merged->right = mergeTreesImpl(root1->right, root2->right);
  return merged;
}

MergeTwoBinaryTreesSolution::MergeTwoBinaryTreesSolution() {
  setMetaInfo({.id = 617,
               .title = "Merge Two Binary Trees",
               .url = "https://leetcode.com/problems/merge-two-binary-trees/"});

  registerStrategy(
      {.name = "DFS Recursive",
       .expected = "Accepted",
       .time_complexity = "O(N1 + N2)",
       .space_complexity = "O(max(H1, H2))",
       .tags = {"Tree", "DFS", "Binary Tree"}},
      mergeTreesImpl);

  setDefaultStrategy();
}

TreeNode* MergeTwoBinaryTreesSolution::mergeTrees(TreeNode* root1,
                                                  TreeNode* root2) {
  return getSolution()(root1, root2);
}

}  // namespace problem_617
}  // namespace leetcode
