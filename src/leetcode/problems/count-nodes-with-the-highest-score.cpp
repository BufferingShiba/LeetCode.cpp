#include "leetcode/problems/count-nodes-with-the-highest-score.h"

namespace leetcode {
namespace problem_2049 {

static int countHighestScoreNodesImpl(std::vector<int>& parents) {
  int n = static_cast<int>(parents.size());

  // Build adjacency list of children for each node
  std::vector<std::vector<int>> children(n);
  for (int i = 1; i < n; ++i) {
    children[parents[i]].push_back(i);
  }

  // Compute subtree sizes via iterative post-order DFS
  std::vector<int> subtree_size(n, 0);
  std::vector<int> order;
  order.reserve(n);
  std::vector<int> stack;
  stack.push_back(0);

  while (!stack.empty()) {
    int node = stack.back();
    stack.pop_back();
    order.push_back(node);
    for (int child : children[node]) {
      stack.push_back(child);
    }
  }

  // Process in reverse order (post-order: children before parent)
  for (auto it = order.rbegin(); it != order.rend(); ++it) {
    int node = *it;
    int size = 1;
    for (int child : children[node]) {
      size += subtree_size[child];
    }
    subtree_size[node] = size;
  }

  long long max_score = 0;
  int count = 0;

  for (int node = 0; node < n; ++node) {
    long long score = 1;
    // Multiply sizes of child subtrees
    for (int child : children[node]) {
      score *= subtree_size[child];
    }
    // Multiply the rest of the tree (if node is not root)
    int rest = n - subtree_size[node];
    if (rest > 0) {
      score *= rest;
    }

    if (score > max_score) {
      max_score = score;
      count = 1;
    } else if (score == max_score) {
      ++count;
    }
  }

  return count;
}

CountNodesWithTheHighestScoreSolution::CountNodesWithTheHighestScoreSolution() {
  setMetaInfo({.id = 2049,
               .title = "Count Nodes With the Highest Score",
               .url = "https://leetcode.com/problems/count-nodes-with-the-highest-score/"});
  registerStrategy({.name = "DFS with subtree sizes",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Tree", "Depth-First Search", "Binary Tree"}},
                   countHighestScoreNodesImpl);
}

int CountNodesWithTheHighestScoreSolution::countHighestScoreNodes(
    std::vector<int>& parents) {
  return getSolution()(parents);
}

}  // namespace problem_2049
}  // namespace leetcode
