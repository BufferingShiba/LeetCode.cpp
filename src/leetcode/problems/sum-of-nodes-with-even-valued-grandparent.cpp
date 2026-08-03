#include "leetcode/problems/sum-of-nodes-with-even-valued-grandparent.h"

namespace leetcode {
namespace problem_1315 {

static int solution1(TreeNode* root) {
  int sum = 0;
  auto dfs = [&](auto&& self, TreeNode* node, TreeNode* parent,
                 TreeNode* grandparent) -> void {
    if (!node) return;
    // A node's value is added when its grandparent exists and is even-valued.
    if (grandparent && (grandparent->val % 2 == 0)) {
      sum += node->val;
    }
    self(self, node->left, node, parent);
    self(self, node->right, node, parent);
  };
  dfs(dfs, root, nullptr, nullptr);
  return sum;
}

SumOfNodesWithEvenValuedGrandparentSolution::SumOfNodesWithEvenValuedGrandparentSolution() {
  setMetaInfo({
      .id = 1315,
      .title = "Sum of Nodes with Even-Valued Grandparent",
      .url = "https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent"
  });
  registerStrategy({.name = "Brute Force",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(h)",
                    .tags = {"Tree", "DFS"}},
                   solution1);
}

int SumOfNodesWithEvenValuedGrandparentSolution::sumEvenGrandparent(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_1315
}  // namespace leetcode
