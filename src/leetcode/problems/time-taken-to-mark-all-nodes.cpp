#include "leetcode/problems/time-taken-to-mark-all-nodes.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3241 {
namespace {

// Rerooting DP.
//
// Marking propagates along an edge from u to v taking delay(v) time, where
//   delay(x) = 1 if x is odd, else 2.
// For a starting node i, times[i] equals the maximum total propagation time
// to reach the farthest node. This is the classic "farthest node in tree"
// problem with node-dependent edge weights, solvable via rerooting DP in O(n).
std::vector<int> timeTakenImpl(std::vector<std::vector<int>>& edges) {
  const int n = static_cast<int>(edges.size()) + 1;
  std::vector<std::vector<int>> adj(n);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  auto delay = [](int node) { return (node % 2 == 1) ? 1 : 2; };

  std::vector<int> parent(n, -1), order;
  order.reserve(n);
  parent[0] = -1;
  std::vector<int> stack = {0};
  while (!stack.empty()) {
    int u = stack.back();
    stack.pop_back();
    order.push_back(u);
    for (int w : adj[u]) {
      if (w == parent[u]) continue;
      parent[w] = u;
      stack.push_back(w);
    }
  }

  // down[u] = longest propagation from u restricted to u's subtree.
  std::vector<int> down(n, 0);
  for (int idx = n - 1; idx >= 0; --idx) {
    int u = order[idx];
    int best = 0;
    for (int w : adj[u]) {
      if (w == parent[u]) continue;
      best = std::max(best, delay(w) + down[w]);
    }
    down[u] = best;
  }

  // up[u] = longest propagation from u restricted to the parent side.
  std::vector<int> up(n, 0);
  std::vector<int> ans(n, 0);

  for (int u : order) {
    int best1 = 0, best2 = 0, best1src = -1;
    for (int x : adj[u]) {
      int contrib;
      if (parent[x] == u) {
        contrib = delay(x) + down[x];
      } else if (parent[u] == x) {
        contrib = up[u];
      } else {
        continue;  // unreachable
      }
      if (contrib > best1) {
        best2 = best1;
        best1 = contrib;
        best1src = x;
      } else if (contrib > best2) {
        best2 = contrib;
      }
    }
    ans[u] = best1;

    for (int c : adj[u]) {
      if (parent[c] != u) continue;
      int best_without_c = (best1src == c) ? best2 : best1;
      up[c] = delay(u) + best_without_c;
    }
  }

  return ans;
}

}  // namespace

TimeTakenToMarkAllNodesSolution::TimeTakenToMarkAllNodesSolution() {
  setMetaInfo({.id = 3241,
               .title = "Time Taken to Mark All Nodes",
               .url = "https://leetcode.com/problems/time-taken-to-mark-all-nodes/"});
  registerStrategy({.name = "rerooting-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Dynamic Programming", "Tree", "Depth-First Search"}},
                   timeTakenImpl);
}

std::vector<int> TimeTakenToMarkAllNodesSolution::timeTaken(std::vector<std::vector<int>>& edges) {
  return getSolution()(edges);
}

}  // namespace problem_3241
}  // namespace leetcode
