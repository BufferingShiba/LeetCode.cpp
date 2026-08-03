#include "leetcode/problems/properties-graph.h"

#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_3493 {

namespace {

class DSU {
  std::vector<int> parent;

 public:
  explicit DSU(int n) : parent(n) {
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) parent[rx] = ry;
  }
};

int numberOfComponentsImpl(std::vector<std::vector<int>>& properties, int k) {
  int n = static_cast<int>(properties.size());
  std::vector<std::unordered_set<int>> sets(n);
  for (int i = 0; i < n; ++i) {
    for (int val : properties[i]) {
      sets[i].insert(val);
    }
  }

  DSU dsu(n);
  int components = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int common = 0;
      if (sets[i].size() > sets[j].size()) {
        for (int val : sets[j]) {
          if (sets[i].count(val)) ++common;
        }
      } else {
        for (int val : sets[i]) {
          if (sets[j].count(val)) ++common;
        }
      }
      if (common >= k) {
        if (dsu.find(i) != dsu.find(j)) {
          dsu.unite(i, j);
          --components;
        }
      }
    }
  }
  return components;
}

}  // namespace

int PropertiesGraphSolution::numberOfComponents(
    std::vector<std::vector<int>>& properties, int k) {
  return getSolution()(properties, k);
}

PropertiesGraphSolution::PropertiesGraphSolution() {
  setMetaInfo({.id = 3493,
               .title = "Properties Graph",
               .url = "https://leetcode.com/problems/properties-graph/"});
  registerStrategy(
      {.name = "DSU with unordered_set",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * m)",
       .space_complexity = "O(n * m)",
       .tags = {"Array", "Hash Table", "Union-Find", "Graph Theory"}},
      numberOfComponentsImpl);
  setDefaultStrategy();
}

}  // namespace problem_3493
}  // namespace leetcode
