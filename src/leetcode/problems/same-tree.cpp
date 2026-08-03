#include "leetcode/problems/same-tree.h"

namespace leetcode {
namespace problem_100 {

namespace {

bool isSameTreeImpl(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr) {
    return true;
  }
  if (p == nullptr || q == nullptr) {
    return false;
  }
  return p->val == q->val && isSameTreeImpl(p->left, q->left) &&
         isSameTreeImpl(p->right, q->right);
}

}  // namespace

SameTreeSolution::SameTreeSolution() {
  setMetaInfo({.id = 100,
               .title = "Same Tree",
               .url = "https://leetcode.com/problems/same-tree/"});

  registerStrategy({.name = "recursive-dfs",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(h)",
                    .tags = {"Tree", "Depth-First Search"}},
                   isSameTreeImpl);
}

bool SameTreeSolution::isSameTree(TreeNode* p, TreeNode* q) {
  return getSolution()(p, q);
}

}  // namespace problem_100
}  // namespace leetcode
