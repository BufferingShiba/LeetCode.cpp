#include "leetcode/problems/n-ary-tree-level-order-traversal.h"

#include <queue>

namespace leetcode {
namespace problem_429 {

static std::vector<std::vector<int>> levelOrderImpl(Node* root) {
  std::vector<std::vector<int>> result;
  if (root == nullptr) {
    return result;
  }
  std::queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int level_size = static_cast<int>(q.size());
    std::vector<int> level;
    level.reserve(level_size);
    for (int i = 0; i < level_size; ++i) {
      Node* node = q.front();
      q.pop();
      level.push_back(node->val);
      for (Node* child : node->children) {
        q.push(child);
      }
    }
    result.push_back(std::move(level));
  }
  return result;
}

NAryTreeLevelOrderTraversalSolution::NAryTreeLevelOrderTraversalSolution() {
  setMetaInfo({
      .id = 429,
      .title = "N-ary Tree Level Order Traversal",
      .url = "https://leetcode.com/problems/n-ary-tree-level-order-traversal"
  });
  registerStrategy({.name = "BFS Level Order", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"BFS", "Tree"}}, levelOrderImpl);
}

std::vector<std::vector<int>> NAryTreeLevelOrderTraversalSolution::levelOrder(Node* root) {
  return getSolution()(root);
}

}  // namespace problem_429
}  // namespace leetcode
