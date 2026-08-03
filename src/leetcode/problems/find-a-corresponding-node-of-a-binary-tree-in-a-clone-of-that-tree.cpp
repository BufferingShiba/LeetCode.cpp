#include "leetcode/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree.h"

namespace leetcode::problem_1379 {

static TreeNode* getTargetCopyImpl(TreeNode* original, TreeNode* cloned,
                                   TreeNode* target) {
  if (original == nullptr) return nullptr;
  if (original == target) return cloned;
  TreeNode* left = getTargetCopyImpl(original->left, cloned->left, target);
  if (left != nullptr) return left;
  return getTargetCopyImpl(original->right, cloned->right, target);
}

FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeSolution::
    FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeSolution() {
  setMetaInfo({.id = 1379,
               .title =
                   "Find a Corresponding Node of a Binary Tree in a Clone of "
                   "That Tree",
               .url =
                   "https://leetcode.com/problems/find-a-corresponding-node-"
                   "of-a-binary-tree-in-a-clone-of-that-tree/"});
  registerStrategy(
      {.name = "Synchronous DFS",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
      getTargetCopyImpl);
}

TreeNode*
FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeSolution::getTargetCopy(
    TreeNode* original, TreeNode* cloned, TreeNode* target) {
  return getSolution()(original, cloned, target);
}

}  // namespace leetcode::problem_1379
