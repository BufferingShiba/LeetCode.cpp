#include "leetcode/problems/maximum-product-of-splitted-binary-tree.h"

#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

namespace leetcode {
namespace problem_1339 {

namespace {

long long subtreeSum(TreeNode* root, std::vector<long long>& sums) {
  if (root == nullptr) return 0;
  long long left = subtreeSum(root->left, sums);
  long long right = subtreeSum(root->right, sums);
  long long sum = static_cast<long long>(root->val) + left + right;
  sums.push_back(sum);
  return sum;
}

int maxProductImpl(TreeNode* root) {
  const long long kMod = 1000000007LL;
  std::vector<long long> sums;
  long long total = subtreeSum(root, sums);

  long long best = 0;
  for (long long sub : sums) {
    // sub 是某个子树的节点和，切掉其与父节点的边，两侧乘积为
    // sub * (total - sub)。total 本身也在 sums 中（等于整棵树），但
    // total * (total - total) = 0，不影响最大值，无需特别过滤。
    best = std::max(best, sub * (total - sub));
  }
  return static_cast<int>(best % kMod);
}

}  // namespace

int MaximumProductOfSplittedBinaryTreeSolution::maxProduct(TreeNode* root) {
  return getSolution()(root);
}

MaximumProductOfSplittedBinaryTreeSolution::
    MaximumProductOfSplittedBinaryTreeSolution() {
  setMetaInfo({1339, "Maximum Product of Splitted Binary Tree",
               "https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/"});
  registerStrategy(
      {.name = "postorder-dfs",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
      maxProductImpl);
}

}  // namespace problem_1339
}  // namespace leetcode
