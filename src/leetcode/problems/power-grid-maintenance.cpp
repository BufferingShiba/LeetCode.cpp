#include "leetcode/problems/power-grid-maintenance.h"

#include <functional>
#include <set>
#include <unordered_map>
#include <vector>

namespace leetcode::problem_3607 {

namespace {

template <typename T>
class DSUUnion {
 public:
  explicit DSUUnion(int n) : parent_(n) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
  }

  int find(int x) {
    if (parent_[x] != x) parent_[x] = find(parent_[x]);
    return parent_[x];
  }

  void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra != rb) parent_[ra] = rb;
  }

 private:
  std::vector<int> parent_;
};

std::vector<int> processQueriesImpl(int c, std::vector<std::vector<int>>& connections,
                                    std::vector<std::vector<int>>& queries) {
  // Connectivity structure never changes: offline nodes stay in their grid.
  // Compute connected components once via DSU.
  DSUUnion<int> dsu(c + 1);
  for (const auto& e : connections) dsu.unite(e[0], e[1]);

  // Assign each node a stable component id.
  std::unordered_map<int, int> compIdOfRoot;
  std::vector<int> comp(c + 1, -1);
  int nextComp = 0;
  for (int i = 1; i <= c; ++i) {
    int root = dsu.find(i);
    auto it = compIdOfRoot.find(root);
    if (it == compIdOfRoot.end()) {
      it = compIdOfRoot.emplace(root, nextComp++).first;
    }
    comp[i] = it->second;
  }

  // Per-component ordered set of currently online nodes (keeps smallest id at
  // begin()).
  std::vector<std::set<int>> onlineSets(nextComp);
  for (int i = 1; i <= c; ++i) onlineSets[comp[i]].insert(i);

  std::vector<char> online(c + 1, 1);
  std::vector<int> result;
  result.reserve(queries.size());

  for (const auto& q : queries) {
    int type = q[0], x = q[1];
    if (type == 1) {
      if (online[x]) {
        result.push_back(x);
      } else {
        auto& st = onlineSets[comp[x]];
        result.push_back(st.empty() ? -1 : *st.begin());
      }
    } else {  // type == 2, station x goes offline
      if (online[x]) {
        online[x] = 0;
        onlineSets[comp[x]].erase(x);
      }
    }
  }
  return result;
}

}  // namespace

PowerGridMaintenanceSolution::PowerGridMaintenanceSolution() {
  setMetaInfo({.id = 3607,
               .title = "Power Grid Maintenance",
               .url = "https://leetcode.com/problems/power-grid-maintenance/"});
  registerStrategy(
      {.name = "DSUComponentsOrderset",
       .expected = "Accepted",
       .time_complexity = "O(c + n + q log c)",
       .space_complexity = "O(c + n)",
       .tags = {"Array", "Hash Table", "Union-Find", "Ordered Set",
                "Graph Theory"}},
      processQueriesImpl);
}

std::vector<int> PowerGridMaintenanceSolution::processQueries(
    int c, std::vector<std::vector<int>>& connections,
    std::vector<std::vector<int>>& queries) {
  return getSolution()(c, connections, queries);
}

}  // namespace leetcode::problem_3607
