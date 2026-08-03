#include "leetcode/problems/groups-of-strings.h"

#include <numeric>
#include <unordered_map>

namespace leetcode::problem_2157 {

namespace {

std::vector<int> groupStringsImpl(std::vector<std::string>& words) {
  const int n = static_cast<int>(words.size());
  std::vector<int> parent(n), sz(n, 1);
  std::iota(parent.begin(), parent.end(), 0);
  std::function<int(int)> find = [&](int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
  };
  auto unite = [&](int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) std::swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  };

  std::unordered_map<int, int> mask_to_idx;
  std::vector<int> mask(n, 0);
  for (int i = 0; i < n; ++i) {
    int m = 0;
    for (char c : words[i]) m |= (1 << (c - 'a'));
    mask[i] = m;
    auto it = mask_to_idx.find(m);
    if (it == mask_to_idx.end()) {
      mask_to_idx[m] = i;
    } else {
      unite(i, it->second);  // identical masks belong to the same group
    }
  }

  for (int i = 0; i < n; ++i) {
    int m = mask[i];
    // replace a present bit with an absent bit (also covers delete+add)
    for (int b = 0; b < 26; ++b) {
      if (m >> b & 1) {
        for (int nb = 0; nb < 26; ++nb) {
          if (nb != b && !(m >> nb & 1)) {
            int nm = (m ^ (1 << b)) | (1 << nb);
            auto it = mask_to_idx.find(nm);
            if (it != mask_to_idx.end()) unite(i, it->second);
          }
        }
      } else {
        // add bit b
        int nm = m | (1 << b);
        auto it = mask_to_idx.find(nm);
        if (it != mask_to_idx.end()) unite(i, it->second);
      }
    }
  }

  std::unordered_map<int, int> comp_sz;
  for (int i = 0; i < n; ++i) comp_sz[find(i)]++;
  int groups = static_cast<int>(comp_sz.size());
  int max_sz = 0;
  for (const auto& kv : comp_sz) max_sz = std::max(max_sz, kv.second);
  return {groups, max_sz};
}

}  // namespace

GroupsOfStringsSolution::GroupsOfStringsSolution() {
  setMetaInfo({.id = 2157,
               .title = "Groups of Strings",
               .url =
                   "https://leetcode.com/problems/groups-of-strings/"});
  registerStrategy(
      {.name = "UnionFind Bitmask",
       .expected = "Accepted",
       .time_complexity = "O(n * 26^2)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Bit Manipulation", "Union-Find"}},
      groupStringsImpl);
}

std::vector<int> GroupsOfStringsSolution::groupStrings(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace leetcode::problem_2157
