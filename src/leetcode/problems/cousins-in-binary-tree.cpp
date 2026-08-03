#include "leetcode/problems/cousins-in-binary-tree.h"

namespace leetcode {
namespace problem_993 {

namespace {

using Depths = std::unordered_map<int, int>;
using Parents = std::unordered_map<int, TreeNode*>;

void dfs(TreeNode* node, TreeNode* parent, int depth, Depths& depths,
         Parents& parents) {
  if (node == nullptr) return;
  depths[node->val] = depth;
  parents[node->val] = parent;
  dfs(node->left, node, depth + 1, depths, parents);
  dfs(node->right, node, depth + 1, depths, parents);
}

bool isCousinsImpl(TreeNode* root, int x, int y) {
  Depths depths;
  Parents parents;
  dfs(root, nullptr, 0, depths, parents);
  return depths[x] == depths[y] && parents[x] != parents[y];
}

}  // namespace

CousinsInBinaryTreeSolution::CousinsInBinaryTreeSolution() {
  setMetaInfo({.id = 993,
               .title = "Cousins in Binary Tree",
               .url = "https://leetcode.com/problems/cousins-in-binary-tree/"});
  registerStrategy(
      {"DFS", "Accepted", "O(n)", "O(h)", {"Tree", "Depth-First Search"}},
      isCousinsImpl);
}

bool CousinsInBinaryTreeSolution::isCousins(TreeNode* root, int x, int y) {
  return getSolution()(root, x, y);
}

}  // namespace problem_993
}  // namespace leetcode
