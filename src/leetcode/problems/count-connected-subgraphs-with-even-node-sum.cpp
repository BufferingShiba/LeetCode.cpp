#include "leetcode/problems/count-connected-subgraphs-with-even-node-sum.h"

#include <stack>

namespace leetcode {
namespace problem_3910 {
namespace {

// Enumerate every non-empty node subset via a bitmask, check whether the
// induced subgraph is connected (DFS from the first node in the mask) and
// whether the sum of node values is even.
int evenSumSubgraphsImpl(std::vector<int>& nums,
                         std::vector<std::vector<int>>& edges) {
  const int n = static_cast<int>(nums.size());
  std::vector<std::vector<int>> adj(n);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  int result = 0;
  const int full = 1 << n;
  for (int mask = 1; mask < full; ++mask) {
    // Compute the parity-adjusted sum and find the first set bit.
    int sum = 0;
    int bitCount = 0;
    int first = -1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        sum += nums[i];
        ++bitCount;
        if (first == -1) first = i;
      }
    }
    if ((sum & 1) != 0) continue;  // odd sum -> skip.

    // DFS over the induced subgraph restricted to the mask.
    int visitedMask = 0;
    std::stack<int> st;
    st.push(first);
    visitedMask |= (1 << first);
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      for (int v : adj[u]) {
        if ((mask & (1 << v)) && !(visitedMask & (1 << v))) {
          visitedMask |= (1 << v);
          st.push(v);
        }
      }
    }
    if (__builtin_popcount(visitedMask) == bitCount) ++result;
  }
  return result;
}

}  // namespace

CountConnectedSubgraphsWithEvenNodeSumSolution::
    CountConnectedSubgraphsWithEvenNodeSumSolution() {
  setMetaInfo({.id = 3910,
               .title = "Count Connected Subgraphs with Even Node Sum",
               .url = "https://leetcode.com/problems/count-connected-subgraphs-with-even-node-sum/"});
  registerStrategy(
      {.name = "bitmask-enumeration",
       .expected = "Accepted",
       .time_complexity = "O(2^n * (n + m))",
       .space_complexity = "O(n)",
       .tags = {"Bit Manipulation", "Depth-First Search", "Enumeration"}},
      evenSumSubgraphsImpl);
}

int CountConnectedSubgraphsWithEvenNodeSumSolution::evenSumSubgraphs(
    std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
  return getSolution()(nums, edges);
}

}  // namespace problem_3910
}  // namespace leetcode
