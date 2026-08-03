#include "leetcode/problems/range-sum-of-bst.h"

namespace leetcode {
namespace problem_938 {

// BST 剪枝 DFS：利用 BST 有序性质跳过不相关子树
static int rangeSumBSTImpl(TreeNode* root, int low, int high) {
  if (root == nullptr) return 0;

  int val = root->val;

  // 当前值太小，左子树全小于 low，只搜右子树
  if (val < low) {
    return rangeSumBSTImpl(root->right, low, high);
  }

  // 当前值太大，右子树全大于 high，只搜左子树
  if (val > high) {
    return rangeSumBSTImpl(root->left, low, high);
  }

  // 当前值在 [low, high] 内，累加并搜索两侧
  return val + rangeSumBSTImpl(root->left, low, high) +
         rangeSumBSTImpl(root->right, low, high);
}

RangeSumOfBstSolution::RangeSumOfBstSolution() {
  setMetaInfo({.id = 938,
               .title = "Range Sum of BST",
               .url = "https://leetcode.com/problems/range-sum-of-bst/"});
  registerStrategy(
      {.name = "bstPruneDFS",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Binary Search Tree",
                "Binary Tree"}},
      rangeSumBSTImpl);
}

int RangeSumOfBstSolution::rangeSumBST(TreeNode* root, int low, int high) {
  return getSolution()(root, low, high);
}

}  // namespace problem_938
}  // namespace leetcode
