#include "leetcode/problems/construct-binary-tree-from-preorder-and-inorder-traversal.h"

#include <unordered_map>
#include <functional>

namespace leetcode {
namespace problem_105 {

static TreeNode* buildTreeImpl(std::vector<int>& preorder,
                               std::vector<int>& inorder) {
  std::unordered_map<int, int> inorderIndex;
  for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
    inorderIndex[inorder[i]] = i;
  }

  std::function<TreeNode*(int, int, int, int)> build =
      [&](int preStart, int preEnd, int inStart, int inEnd) -> TreeNode* {
    if (preStart > preEnd) return nullptr;

    int rootVal = preorder[preStart];
    auto* root = new TreeNode(rootVal);

    int inRootIdx = inorderIndex[rootVal];
    int leftSize = inRootIdx - inStart;

    root->left =
        build(preStart + 1, preStart + leftSize, inStart, inRootIdx - 1);
    root->right =
        build(preStart + leftSize + 1, preEnd, inRootIdx + 1, inEnd);

    return root;
  };

  return build(0, static_cast<int>(preorder.size()) - 1,
               0, static_cast<int>(inorder.size()) - 1);
}

ConstructBinaryTreeFromPreorderAndInorderTraversalSolution::
    ConstructBinaryTreeFromPreorderAndInorderTraversalSolution() {
  setMetaInfo({.id = 105,
               .title = "Construct Binary Tree from Preorder and Inorder Traversal",
               .url = "https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/"});
  registerStrategy(
      {.name = "Recursive with HashMap",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Divide and Conquer", "Tree",
                "Binary Tree"}},
      buildTreeImpl);
}

TreeNode* ConstructBinaryTreeFromPreorderAndInorderTraversalSolution::buildTree(
    std::vector<int>& preorder, std::vector<int>& inorder) {
  return getSolution()(preorder, inorder);
}

}  // namespace problem_105
}  // namespace leetcode
