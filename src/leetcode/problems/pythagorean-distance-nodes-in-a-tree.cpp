#include <queue>
#include <utility>
#include <vector>

#include "leetcode/problems/pythagorean-distance-nodes-in-a-tree.h"

namespace leetcode {
namespace problem_3820 {
namespace {

std::vector<int> distancesFrom(const std::vector<std::vector<int>>& adj, int n,
                               int src) {
  std::vector<int> dist(n, -1);
  std::queue<int> q;
  dist[src] = 0;
  q.push(src);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist;
}

bool isPythagorean(int a, int b, int c) {
  long long aa = static_cast<long long>(a) * a;
  long long bb = static_cast<long long>(b) * b;
  long long cc = static_cast<long long>(c) * c;
  return aa + bb == cc;
}

int specialNodesImpl(int n, std::vector<std::vector<int>>& edges, int x, int y,
                     int z) {
  std::vector<std::vector<int>> adj(n);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  std::vector<int> dx = distancesFrom(adj, n, x);
  std::vector<int> dy = distancesFrom(adj, n, y);
  std::vector<int> dz = distancesFrom(adj, n, z);

  int count = 0;
  for (int u = 0; u < n; ++u) {
    int a = dx[u], b = dy[u], c = dz[u];
    if (a > b) std::swap(a, b);
    if (a > c) std::swap(a, c);
    if (b > c) std::swap(b, c);
    if (isPythagorean(a, b, c)) {
      ++count;
    }
  }
  return count;
}

}  // namespace

PythagoreanDistanceNodesInATreeSolution::PythagoreanDistanceNodesInATreeSolution() {
  setMetaInfo({.id = 3820,
               .title = "Pythagorean Distance Nodes in a Tree",
               .url = "https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree/"});
  registerStrategy(
      {.name = "bfs_three_sources",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Breadth-First Search"}},
      specialNodesImpl);
}

int PythagoreanDistanceNodesInATreeSolution::specialNodes(
    int n, std::vector<std::vector<int>>& edges, int x, int y, int z) {
  return getSolution()(n, edges, x, y, z);
}

}  // namespace problem_3820
}  // namespace leetcode
