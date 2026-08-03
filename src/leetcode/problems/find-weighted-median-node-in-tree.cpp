#include "leetcode/problems/find-weighted-median-node-in-tree.h"

#include <algorithm>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3585 {

namespace {

constexpr int LOG = 18;  // 2^17 = 131072 > 1e5

std::vector<int> findMedianImpl(int n, std::vector<std::vector<int>>& edges,
                                std::vector<std::vector<int>>& queries) {
  std::vector<std::vector<std::pair<int, long long>>> adj(n);
  for (const auto& e : edges) {
    int u = e[0], v = e[1];
    long long w = e[2];
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  std::vector<std::vector<int>> up(LOG, std::vector<int>(n, -1));
  std::vector<std::vector<long long>> dist_up(LOG, std::vector<long long>(n, 0));
  std::vector<int> depth(n, 0);
  std::vector<long long> dist_root(n, 0);

  // iterative DFS: node, parent, depth, distance from root
  std::stack<std::tuple<int, int, int, long long>> st;
  st.emplace(0, -1, 0, 0LL);
  while (!st.empty()) {
    auto [node, parent, d, dr] = st.top();
    st.pop();
    depth[node] = d;
    dist_root[node] = dr;
    up[0][node] = parent;
    if (parent != -1) {
      dist_up[0][node] = dr - dist_root[parent];
    }
    for (auto& [nb, w] : adj[node]) {
      if (nb == parent) continue;
      st.emplace(nb, node, d + 1, dr + w);
    }
  }

  // binary lifting
  for (int k = 1; k < LOG; ++k) {
    for (int i = 0; i < n; ++i) {
      int mid = up[k - 1][i];
      if (mid != -1) {
        up[k][i] = up[k - 1][mid];
        dist_up[k][i] = dist_up[k - 1][i] + dist_up[k - 1][mid];
      } else {
        up[k][i] = -1;
        dist_up[k][i] = dist_up[k - 1][i];
      }
    }
  }

  auto getLCA = [&](int u, int v) -> int {
    if (depth[u] < depth[v]) std::swap(u, v);
    int diff = depth[u] - depth[v];
    for (int k = 0; k < LOG; ++k) {
      if (diff & (1 << k)) u = up[k][u];
    }
    if (u == v) return u;
    for (int k = LOG - 1; k >= 0; --k) {
      if (up[k][u] != up[k][v]) {
        u = up[k][u];
        v = up[k][v];
      }
    }
    return up[0][u];
  };

  std::vector<int> ans;
  ans.reserve(queries.size());

  for (const auto& q : queries) {
    int u = q[0], v = q[1];
    if (u == v) {
      ans.push_back(u);
      continue;
    }
    int lca = getLCA(u, v);
    long long total = dist_root[u] + dist_root[v] - 2 * dist_root[lca];
    long long d_u_lca = dist_root[u] - dist_root[lca];

    if (d_u_lca * 2 >= total) {
      // answer lies on the path from u up to lca
      int cur = u;
      long long cum = 0;
      for (int k = LOG - 1; k >= 0; --k) {
        if (depth[cur] - (1 << k) >= depth[lca]) {
          if ((cum + dist_up[k][cur]) * 2 < total) {
            cum += dist_up[k][cur];
            cur = up[k][cur];
          }
        }
      }
      ans.push_back(up[0][cur]);
    } else {
      // answer lies on the path from lca down to v
      long long floor_half = total / 2;
      int cur = v;
      for (int k = LOG - 1; k >= 0; --k) {
        if (depth[cur] - (1 << k) >= depth[lca]) {
          long long dist_v_to_up = dist_root[v] - dist_root[up[k][cur]];
          if (dist_v_to_up <= floor_half) {
            cur = up[k][cur];
          }
        }
      }
      ans.push_back(cur);
    }
  }

  return ans;
}

}  // namespace

FindWeightedMedianNodeInTreeSolution::FindWeightedMedianNodeInTreeSolution() {
  setMetaInfo({.id = 3585,
               .title = "Find Weighted Median Node in Tree",
               .url = "https://leetcode.com/problems/find-weighted-median-node-in-tree/"});
  registerStrategy({.name = "BinaryLifting",
                    .expected = "Accepted",
                    .time_complexity = "O((N+Q) log N)",
                    .space_complexity = "O(N log N)",
                    .tags = {"Array", "Binary Search", "Dynamic Programming", "Bit Manipulation", "Tree",
                             "Depth-First Search"}},
                   findMedianImpl);
}

std::vector<int> FindWeightedMedianNodeInTreeSolution::findMedian(
    int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& queries) {
  return getSolution()(n, edges, queries);
}

}  // namespace problem_3585
}  // namespace leetcode
