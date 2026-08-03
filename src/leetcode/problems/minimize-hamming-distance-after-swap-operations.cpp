#include "leetcode/problems/minimize-hamming-distance-after-swap-operations.h"

#include <numeric>
#include <unordered_map>

namespace leetcode {
namespace problem_1722 {

static int minimumHammingDistanceImpl(vector<int>& source, vector<int>& target,
                                      vector<vector<int>>& allowedSwaps) {
  const int n = static_cast<int>(source.size());

  // Disjoint-set (Union-Find) over indices.
  std::vector<int> parent(n);
  std::iota(parent.begin(), parent.end(), 0);

  std::function<int(int)> find = [&](int x) -> int {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  };

  auto unite = [&](int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) {
      parent[ra] = rb;
    }
  };

  for (const auto& edge : allowedSwaps) {
    unite(edge[0], edge[1]);
  }

  // Group indices by root.
  std::unordered_map<int, std::vector<int>> groups;
  for (int i = 0; i < n; ++i) {
    groups[find(i)].push_back(i);
  }

  int answer = 0;
  for (auto& kv : groups) {
    const auto& indices = kv.second;
    std::unordered_map<int, int> srcFreq;
    std::unordered_map<int, int> tgtFreq;
    for (int idx : indices) {
      ++srcFreq[source[idx]];
      ++tgtFreq[target[idx]];
    }
    // Number of positions that can be matched by a value present in both sides.
    int matched = 0;
    for (const auto& p : tgtFreq) {
      auto it = srcFreq.find(p.first);
      if (it != srcFreq.end()) {
        matched += std::min(p.second, it->second);
      }
    }
    answer += static_cast<int>(indices.size()) - matched;
  }

  return answer;
}

MinimizeHammingDistanceAfterSwapOperationsSolution::MinimizeHammingDistanceAfterSwapOperationsSolution() {
  setMetaInfo({
      .id = 1722,
      .title = "Minimize Hamming Distance After Swap Operations",
      .url = "https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations"
  });
  registerStrategy({.name = "Union Find",
                    .expected = "Accepted",
                    .time_complexity = "O(n + swaps * alpha(n))",
                    .space_complexity = "O(n)",
                    .tags = {"union-find"},
                    .notes = "Group indices by connected component; within each component source values can be freely permuted, so matched count per value is min(srcFreq, tgtFreq)."},
                   minimumHammingDistanceImpl);
}

int MinimizeHammingDistanceAfterSwapOperationsSolution::minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
  return getSolution()(source, target, allowedSwaps);
}

}  // namespace problem_1722
}  // namespace leetcode
