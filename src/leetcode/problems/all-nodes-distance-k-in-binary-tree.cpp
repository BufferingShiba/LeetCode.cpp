#include "leetcode/problems/all-nodes-distance-k-in-binary-tree.h"

#include <functional>
#include <queue>
#include <unordered_map>
#include <unordered_set>

namespace leetcode::problem_863 {

static std::vector<int> distanceKImpl(TreeNode* root, TreeNode* target, int k) {
  // Step 1: build parent map via DFS
  std::unordered_map<TreeNode*, TreeNode*> parent;
  std::function<void(TreeNode*, TreeNode*)> dfs =
      [&](TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        dfs(node->left, node);
        dfs(node->right, node);
      };
  dfs(root, nullptr);

  // Step 2: BFS from target
  std::vector<int> result;
  std::unordered_set<TreeNode*> visited;
  std::queue<TreeNode*> q;
  q.push(target);
  visited.insert(target);
  int dist = 0;

  while (!q.empty()) {
    if (dist == k) {
      while (!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
      }
      break;
    }
    int size = static_cast<int>(q.size());
    for (int i = 0; i < size; ++i) {
      TreeNode* node = q.front();
      q.pop();
      for (TreeNode* next : {node->left, node->right, parent[node]}) {
        if (next && !visited.count(next)) {
          visited.insert(next);
          q.push(next);
        }
      }
    }
    ++dist;
  }

  return result;
}

AllNodesDistanceKInBinaryTreeSolution::AllNodesDistanceKInBinaryTreeSolution() {
  setMetaInfo({.id = 863,
               .title = "All Nodes Distance K in Binary Tree",
               .url = "https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/"});
  registerStrategy(
      {.name = "BFS with Parent Map",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Tree", "Depth-First Search",
                "Breadth-First Search", "Binary Tree"}},
      distanceKImpl);
}

std::vector<int> AllNodesDistanceKInBinaryTreeSolution::distanceK(
    TreeNode* root, TreeNode* target, int k) {
  return getSolution()(root, target, k);
}

}  // namespace leetcode::problem_863
