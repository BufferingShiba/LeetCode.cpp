#include "leetcode/problems/minimum-weighted-subgraph-with-the-required-paths-ii.h"

#include <algorithm>
#include <queue>
#include <vector>

namespace leetcode::problem_3553 {

namespace {

constexpr int kMaxLog = 18;  // 2^17 = 131072 > 1e5

// LCA helper: binary lifting
class TreeLCA {
 public:
  TreeLCA(int n, const std::vector<std::vector<std::pair<int, int>>>& adj)
      : n_(n), log_(kMaxLog) {
    up_.assign(log_, std::vector<int>(n_, -1));
    depth_.assign(n_, 0);
    dist_from_root_.assign(n_, 0LL);
    Build(adj);
  }

  int Lca(int u, int v) const {
    if (depth_[u] < depth_[v]) std::swap(u, v);
    // Lift u to same depth as v
    int diff = depth_[u] - depth_[v];
    for (int k = 0; k < log_; ++k) {
      if (diff & (1 << k)) {
        u = up_[k][u];
      }
    }
    if (u == v) return u;
    for (int k = log_ - 1; k >= 0; --k) {
      if (up_[k][u] != up_[k][v]) {
        u = up_[k][u];
        v = up_[k][v];
      }
    }
    return up_[0][u];
  }

  long long Dist(int u, int v) const {
    int lca = Lca(u, v);
    return dist_from_root_[u] + dist_from_root_[v] -
           2LL * dist_from_root_[lca];
  }

 private:
  int n_, log_;
  std::vector<std::vector<int>> up_;
  std::vector<int> depth_;
  std::vector<long long> dist_from_root_;

  void Build(const std::vector<std::vector<std::pair<int, int>>>& adj) {
    // BFS to avoid recursion stack overflow (tree may be a chain of 1e5)
    std::queue<int> q;
    q.push(0);
    up_[0][0] = 0;  // root's parent is itself
    depth_[0] = 0;
    dist_from_root_[0] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (const auto& [v, w] : adj[u]) {
        if (v == up_[0][u]) continue;
        up_[0][v] = u;
        depth_[v] = depth_[u] + 1;
        dist_from_root_[v] = dist_from_root_[u] + w;
        q.push(v);
      }
    }
    // Fill binary lifting table
    for (int k = 1; k < log_; ++k) {
      for (int i = 0; i < n_; ++i) {
        int mid = up_[k - 1][i];
        up_[k][i] = (mid == -1) ? -1 : up_[k - 1][mid];
      }
    }
  }
};

std::vector<int> minimumWeightImpl(std::vector<std::vector<int>>& edges,
                                   std::vector<std::vector<int>>& queries) {
  int n = static_cast<int>(edges.size()) + 1;
  std::vector<std::vector<std::pair<int, int>>> adj(n);
  for (const auto& e : edges) {
    int u = e[0], v = e[1], w = e[2];
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  TreeLCA lca(n, adj);

  std::vector<int> answer;
  answer.reserve(queries.size());
  for (const auto& q : queries) {
    int a = q[0], b = q[1], c = q[2];
    long long dab = lca.Dist(a, b);
    long long dbc = lca.Dist(b, c);
    long long dca = lca.Dist(c, a);
    long long total = (dab + dbc + dca) / 2LL;
    answer.push_back(static_cast<int>(total));
  }
  return answer;
}

}  // namespace

MinimumWeightedSubgraphWithTheRequiredPathsIiSolution::
    MinimumWeightedSubgraphWithTheRequiredPathsIiSolution() {
  setMetaInfo({.id = 3553,
               .title = "Minimum Weighted Subgraph With the Required Paths II",
               .url = "https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths-ii/"});
  registerStrategy(
      {.name = "BinaryLiftingLCA",
       .expected = "Accepted",
       .time_complexity = "O((n + q) log n)",
       .space_complexity = "O(n log n)",
       .tags = {"Tree", "LCA", "Binary Lifting", "Depth-First Search"}},
      minimumWeightImpl);
}

std::vector<int>
MinimumWeightedSubgraphWithTheRequiredPathsIiSolution::minimumWeight(
    std::vector<std::vector<int>>& edges,
    std::vector<std::vector<int>>& queries) {
  return getSolution()(edges, queries);
}

}  // namespace leetcode::problem_3553
