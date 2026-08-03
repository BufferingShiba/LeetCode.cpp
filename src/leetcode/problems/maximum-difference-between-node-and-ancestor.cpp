#include "leetcode/problems/maximum-difference-between-node-and-ancestor.h"

#include <algorithm>
#include <functional>

namespace leetcode {
namespace problem_1026 {

namespace {

int maxAncestorDiffImpl(TreeNode* root) {
  int result = 0;
  std::function<void(TreeNode*, int, int)> dfs =
      [&](TreeNode* node, int minVal, int maxVal) {
        if (node == nullptr) return;
        minVal = std::min(minVal, node->val);
        maxVal = std::max(maxVal, node->val);
        result = std::max(result, maxVal - minVal);
        dfs(node->left, minVal, maxVal);
        dfs(node->right, minVal, maxVal);
      };
  dfs(root, root->val, root->val);
  return result;
}

}  // namespace

int MaximumDifferenceBetweenNodeAndAncestorSolution::maxAncestorDiff(
    TreeNode* root) {
  return getSolution()(root);
}

void MaximumDifferenceBetweenNodeAndAncestorSolution::registerStrategy() {
  setMetaInfo(
      {.id = 1026,
       .title = "Maximum Difference Between Node and Ancestor",
       .url = "https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/"});

  SolutionBase<Func>::registerStrategy(
      {.name = "dfs-min-max",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "DFS"}},
      maxAncestorDiffImpl);
}

}  // namespace problem_1026
}  // namespace leetcode
