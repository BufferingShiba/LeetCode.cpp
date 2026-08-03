#include "leetcode/problems/process-restricted-friend-requests.h"

namespace leetcode::problem_2076 {

namespace {

struct DSU {
  std::vector<int> parent;
  std::vector<int> rank;

  explicit DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) std::swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b]) ++rank[a];
  }
};

std::vector<bool> friendRequestsImpl(int n,
                                     std::vector<std::vector<int>>& restrictions,
                                     std::vector<std::vector<int>>& requests) {
  DSU dsu(n);
  std::vector<bool> result;
  result.reserve(requests.size());

  for (const auto& req : requests) {
    int u = req[0];
    int v = req[1];
    int ru = dsu.find(u);
    int rv = dsu.find(v);
    bool ok = true;
    for (const auto& rest : restrictions) {
      int a = dsu.find(rest[0]);
      int b = dsu.find(rest[1]);
      if ((a == ru && b == rv) || (a == rv && b == ru)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      dsu.unite(u, v);
    }
    result.push_back(ok);
  }
  return result;
}

}  // namespace

ProcessRestrictedFriendRequestsSolution::ProcessRestrictedFriendRequestsSolution() {
  this->setMetaInfo({.id = 2076,
                     .title = "Process Restricted Friend Requests",
                     .url = "https://leetcode.com/problems/process-restricted-friend-requests/"});
  this->registerStrategy(
      {.name = "union-find-check-constraints",
       .expected = "Accepted",
       .time_complexity = "O(R * Q * α(n))",
       .space_complexity = "O(n + R)",
       .tags = {"Union-Find", "Graph Theory"}},
      friendRequestsImpl);
}

std::vector<bool> ProcessRestrictedFriendRequestsSolution::friendRequests(
    int n, std::vector<std::vector<int>>& restrictions,
    std::vector<std::vector<int>>& requests) {
  return getSolution()(n, restrictions, requests);
}

}  // namespace leetcode::problem_2076
