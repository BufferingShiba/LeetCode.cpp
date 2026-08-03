#include "leetcode/problems/longest-palindromic-path-in-graph.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_3615 {

namespace {

int maxLenImpl(int n, const std::vector<std::vector<int>>& edges,
               const std::string& label) {
  std::vector<int> adj(n, 0);
  for (const auto& e : edges) {
    adj[e[0]] |= 1 << e[1];
    adj[e[1]] |= 1 << e[0];
  }

  const int full = (1 << n) - 1;

  std::vector<int> memo(1 << (n + 8), -1);

  std::function<int(int, int, int)> expand = [&](int u, int v, int mask) {
    int state = (mask << 8) | (u << 4) | v;
    if (memo[state] != -1) return memo[state];
    int best = 0;
    int nu_adj = adj[u] & mask;
    int nv_adj = adj[v] & mask;
    for (int nu = nu_adj; nu; nu &= nu - 1) {
      int abit = nu & (-nu);
      int a = __builtin_ctz(abit);
      for (int nv = nv_adj; nv; nv &= nv - 1) {
        int bbit = nv & (-nv);
        int b = __builtin_ctz(bbit);
        if (a == b) continue;
        if (label[a] != label[b]) continue;
        int nmask = mask & ~(abit | bbit);
        int sub = expand(a, b, nmask);
        best = std::max(best, 1 + sub);
      }
    }
    memo[state] = best;
    return best;
  };

  int ans = 1;

  for (int c = 0; c < n; ++c) {
    int mask = full & ~(1 << c);
    int pairs = expand(c, c, mask);
    ans = std::max(ans, 1 + 2 * pairs);
  }

  for (int u = 0; u < n; ++u) {
    for (int v = u + 1; v < n; ++v) {
      if (!(adj[u] & (1 << v))) continue;
      if (label[u] != label[v]) continue;
      int mask = full & ~((1 << u) | (1 << v));
      int pairs = expand(u, v, mask);
      ans = std::max(ans, 2 + 2 * pairs);
    }
  }

  return ans;
}

}  // namespace

LongestPalindromicPathInGraphSolution::LongestPalindromicPathInGraphSolution() {
  setMetaInfo({.id = 3615,
               .title = "Longest Palindromic Path in Graph",
               .url = "https://leetcode.com/problems/longest-palindromic-path-in-graph/"});
  registerStrategy(
      {"bitmask-dp", "Accepted", "O(2^n*n^2*deg^2)", "O(2^n*n^2)",
       {"Dynamic Programming", "Bit Manipulation", "Graph Theory", "String"}},
      [](int n, std::vector<std::vector<int>>& edges,
         std::string label) -> int {
        return maxLenImpl(n, edges, label);
      });
}

int LongestPalindromicPathInGraphSolution::maxLen(
    int n, std::vector<std::vector<int>>& edges, std::string label) {
  return getSolution()(n, edges, label);
}

}  // namespace leetcode::problem_3615
