#include "leetcode/problems/maximum-weighted-k-edge-path.h"

#include <bitset>
#include <vector>

namespace leetcode {
namespace problem_3543 {
namespace {

constexpr int kMaxSum = 601;  // sums in [0, 600]; t <= 600, sums >= t are dropped

int maxWeightImpl(int n, std::vector<std::vector<int>>& edges, int k, int t) {
  // cur[v] is a bitset: bit s is set iff a path with the current number of
  // edges can end at node v with total weight s < t (empty start gives sum 0).
  std::vector<std::bitset<kMaxSum>> cur(n), nxt(n);
  for (int v = 0; v < n; ++v) {
    cur[v].set(0);  // start from any node with an empty prefix of weight 0
  }

  // Mask keeping only sums strictly below t.
  std::bitset<kMaxSum> maskBelowT;
  for (int s = 0; s < t; ++s) maskBelowT.set(s);

  for (int e = 1; e <= k; ++e) {
    for (int v = 0; v < n; ++v) nxt[v].reset();
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      nxt[v] |= ((cur[u] << w) & maskBelowT);
    }
    cur.swap(nxt);
  }

  int best = -1;
  for (int v = 0; v < n; ++v) {
    for (int s = t - 1; s >= 0; --s) {
      if (cur[v].test(s)) {
        if (s > best) best = s;
        break;
      }
    }
  }
  return best;
}

}  // namespace

MaximumWeightedKEdgePathSolution::MaximumWeightedKEdgePathSolution() {
  setMetaInfo({.id = 3543,
               .title = "Maximum Weighted K-Edge Path",
               .url = "https://leetcode.com/problems/maximum-weighted-k-edge-path/"});
  registerStrategy(
      {.name = "dynamic-programming",
       .expected = "Accepted",
       .time_complexity = "O(k * m * t / w)",
       .space_complexity = "O(n * t)",
       .tags = {"Dynamic Programming", "Graph Theory", "Hash Table"}},
      maxWeightImpl);
}

int MaximumWeightedKEdgePathSolution::maxWeight(
    int n, std::vector<std::vector<int>>& edges, int k, int t) {
  return getSolution()(n, edges, k, t);
}

}  // namespace problem_3543
}  // namespace leetcode
