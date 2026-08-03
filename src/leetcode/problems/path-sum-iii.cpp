#include "leetcode/problems/path-sum-iii.h"

#include <functional>
#include <unordered_map>

namespace leetcode::problem_437 {
namespace {

int pathSumImpl(TreeNode* root, long long targetSum) {
  if (root == nullptr) {
    return 0;
  }

  std::unordered_map<long long, int> prefix;
  prefix[0] = 1;

  int count = 0;

  std::function<void(TreeNode*, long long)> dfs;
  dfs = [&](TreeNode* node, long long current) {
    if (node == nullptr) {
      return;
    }
    current += node->val;
    count += prefix[current - targetSum];
    ++prefix[current];
    dfs(node->left, current);
    dfs(node->right, current);
    --prefix[current];
  };

  dfs(root, 0);
  return count;
}

}  // namespace

PathSumIiiSolution::PathSumIiiSolution() {
  this->setMetaInfo({.id = 437,
                     .title = "Path Sum III",
                     .url = "https://leetcode.com/problems/path-sum-iii/"});
  this->registerStrategy(
      {.name = "prefix_sum_dfs",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Depth-First Search", "Prefix Sum", "Hash Table"}},
      [](TreeNode* root, int targetSum) {
        return pathSumImpl(root, static_cast<long long>(targetSum));
      });
}

int PathSumIiiSolution::pathSum(TreeNode* root, int targetSum) {
  return getSolution()(root, targetSum);
}

}  // namespace leetcode::problem_437
