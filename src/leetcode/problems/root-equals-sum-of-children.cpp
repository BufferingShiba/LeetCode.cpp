#include "leetcode/problems/root-equals-sum-of-children.h"

#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_2236 {

namespace {

bool checkTree(TreeNode* root) {
  return root->val == root->left->val + root->right->val;
}

}  // namespace

RootEqualsSumOfChildrenSolution::RootEqualsSumOfChildrenSolution() {
  setMetaInfo({.id = 2236,
               .title = "Root Equals Sum of Children",
               .url = "https://leetcode.com/problems/root-equals-sum-of-children/"});
  registerStrategy(
      {.name = "direct-comparison",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Tree", "Binary Tree"},
       .notes = "The tree has exactly 3 nodes, so simply compare the root value against the sum of the two children."},
      checkTree);
}

}  // namespace problem_2236
}  // namespace leetcode
