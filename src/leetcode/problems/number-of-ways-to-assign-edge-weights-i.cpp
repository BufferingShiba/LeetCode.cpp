#include "leetcode/problems/number-of-ways-to-assign-edge-weights-i.h"

#include <cstdint>
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3558 {
namespace {

constexpr int64_t kMod = 1000000007;

int64_t modPow(int64_t base, int64_t exp) {
  int64_t result = 1;
  base %= kMod;
  while (exp > 0) {
    if (exp & 1) result = result * base % kMod;
    base = base * base % kMod;
    exp >>= 1;
  }
  return result;
}

// 对路径上每一条边，权重为1或2。路径总代价奇偶由权重为1的边数决定：
// 奇数条边权重为1时总代价为奇数，否则为偶数。
// 故从 d 条边中选奇数个赋值为1的组合数 = 2^(d-1)（d>=1）；d==0 时方案数为0。
int assignEdgeWeightsImpl(std::vector<std::vector<int>>& edges) {
  const int n = static_cast<int>(edges.size()) + 1;
  std::vector<std::vector<int>> adj(n + 1);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  int maxDepth = 0;
  std::function<void(int, int, int)> dfs =
      [&](int u, int parent, int depth) {
        if (depth > maxDepth) maxDepth = depth;
        for (int v : adj[u]) {
          if (v != parent) dfs(v, u, depth + 1);
        }
      };
  dfs(1, 0, 0);

  if (maxDepth == 0) return 0;
  return static_cast<int>(modPow(2, maxDepth - 1));
}

}  // namespace

NumberOfWaysToAssignEdgeWeightsISolution::NumberOfWaysToAssignEdgeWeightsISolution() {
  setMetaInfo({3558, "Number of Ways to Assign Edge Weights I",
               "https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/"});
  registerStrategy(
      {"CombinationParityDFS", "Accepted", "O(n)", "O(n)",
       {"Math", "Tree", "Depth-First Search"},
       "路径总代价为奇数当且仅当奇数条边权重为1，方案数为2^(d-1)"},
      assignEdgeWeightsImpl);
}

int NumberOfWaysToAssignEdgeWeightsISolution::assignEdgeWeights(
    std::vector<std::vector<int>>& edges) {
  return getSolution()(edges);
}

}  // namespace problem_3558
}  // namespace leetcode
