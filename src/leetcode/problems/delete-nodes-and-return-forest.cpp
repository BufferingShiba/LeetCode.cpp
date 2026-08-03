#include "leetcode/problems/delete-nodes-and-return-forest.h"

#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_1110 {

static std::vector<TreeNode*> delNodesImpl(TreeNode* root,
                                           std::vector<int>& to_delete) {
  std::unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
  std::vector<TreeNode*> result;

  std::function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* node) -> TreeNode* {
    if (!node) return nullptr;

    node->left = dfs(node->left);
    node->right = dfs(node->right);

    if (to_delete_set.count(node->val)) {
      if (node->left) result.push_back(node->left);
      if (node->right) result.push_back(node->right);
      node->left = nullptr;
      node->right = nullptr;
      delete node;
      return nullptr;
    }

    return node;
  };

  TreeNode* new_root = dfs(root);
  if (new_root) {
    result.push_back(new_root);
  }

  return result;
}

DeleteNodesAndReturnForestSolution::DeleteNodesAndReturnForestSolution() {
  setMetaInfo({.id = 1110,
               .title = "Delete Nodes And Return Forest",
               .url = "https://leetcode.com/problems/delete-nodes-and-return-forest/"});

  registerStrategy(
      {.name = "PostOrder DFS",
       .expected = "Accepted",
       .time_complexity = "O(N)",
       .space_complexity = "O(N)",
       .tags = {"Array", "Hash Table", "Tree", "Depth-First Search",
                "Binary Tree"}},
      delNodesImpl);

  setDefaultStrategy();
}

std::vector<TreeNode*> DeleteNodesAndReturnForestSolution::delNodes(
    TreeNode* root, std::vector<int>& to_delete) {
  return getSolution()(root, to_delete);
}

}  // namespace problem_1110
}  // namespace leetcode
