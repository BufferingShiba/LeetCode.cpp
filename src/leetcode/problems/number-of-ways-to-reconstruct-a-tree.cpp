#include "leetcode/problems/number-of-ways-to-reconstruct-a-tree.h"

#include <algorithm>
#include <bitset>
#include <climits>

namespace leetcode {
namespace problem_1719 {

namespace {

int checkWaysImpl(std::vector<std::vector<int>>& pairs) {
  constexpr int kMaxVal = 500;
  std::vector<std::bitset<kMaxVal + 1>> adj(kMaxVal + 1);
  std::vector<int> degree(kMaxVal + 1, 0);
  std::vector<bool> present(kMaxVal + 1, false);

  for (const auto& p : pairs) {
    int u = p[0], v = p[1];
    adj[u].set(v);
    adj[v].set(u);
    present[u] = true;
    present[v] = true;
  }

  // collect all distinct nodes
  std::vector<int> nodes;
  for (int i = 1; i <= kMaxVal; ++i) {
    if (present[i]) {
      degree[i] = static_cast<int>(adj[i].count());
      nodes.push_back(i);
    }
  }

  int n = static_cast<int>(nodes.size());
  if (n == 0) return 0;

  // sort by degree descending
  std::sort(nodes.begin(), nodes.end(),
            [&](int a, int b) { return degree[a] > degree[b]; });

  int root = nodes[0];
  if (degree[root] != n - 1) return 0;

  std::vector<int> parent(kMaxVal + 1, -1);
  parent[root] = 0;  // mark root as having no parent
  bool multiple = false;

  for (int i = 1; i < n; ++i) {
    int u = nodes[i];

    // find parent: among neighbours with degree >= degree[u],
    // pick the one with the smallest degree
    int p = -1;
    int min_deg = INT_MAX;
    for (int v = 1; v <= kMaxVal; ++v) {
      if (present[v] && adj[u].test(v) && degree[v] >= degree[u]) {
        if (degree[v] < min_deg) {
          min_deg = degree[v];
          p = v;
        }
      }
    }

    if (p == -1) return 0;  // no valid parent

    // verify subset condition: adj[u] \ {p}  ⊆  adj[p]
    for (int w = 1; w <= kMaxVal; ++w) {
      if (present[w] && w != p && adj[u].test(w)) {
        if (!adj[p].test(w)) return 0;
      }
    }

    parent[u] = p;
    if (degree[u] == degree[p]) {
      multiple = true;
    }
  }

  return multiple ? 2 : 1;
}

}  // namespace

NumberOfWaysToReconstructATreeSolution::NumberOfWaysToReconstructATreeSolution() {
  setMetaInfo({.id = 1719,
               .title = "Number Of Ways To Reconstruct A Tree",
               .url = "https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/"});
  registerStrategy(
      {.name = "DegreeBased",
       .expected = "Accepted",
       .time_complexity = "O(N^2 + P)",
       .space_complexity = "O(N^2)",
       .tags = {"Array", "Hash Table", "Tree", "Graph Theory", "Simulation"}},
      checkWaysImpl);
}

int NumberOfWaysToReconstructATreeSolution::checkWays(
    std::vector<std::vector<int>>& pairs) {
  return getSolution()(pairs);
}

}  // namespace problem_1719
}  // namespace leetcode
