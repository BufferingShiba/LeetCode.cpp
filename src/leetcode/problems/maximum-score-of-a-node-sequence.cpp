#include "leetcode/problems/maximum-score-of-a-node-sequence.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2242 {

static int maximumScoreImpl(std::vector<int>& scores,
                            std::vector<std::vector<int>>& edges) {
  int n = static_cast<int>(scores.size());

  // adjacency list
  std::vector<std::vector<int>> adj(n);
  for (auto& e : edges) {
    int u = e[0], v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // For each node, keep only top-3 neighbors by score
  for (int i = 0; i < n; ++i) {
    auto& nb = adj[i];
    if (nb.size() > 3) {
      std::nth_element(nb.begin(), nb.begin() + 3, nb.end(),
                       [&](int a, int b) { return scores[a] > scores[b]; });
      nb.resize(3);
    } else {
      std::sort(nb.begin(), nb.end(),
                [&](int a, int b) { return scores[a] > scores[b]; });
    }
  }

  int ans = -1;

  for (auto& e : edges) {
    int b = e[0], c = e[1];

    for (int a : adj[b]) {
      if (a == c) continue;
      for (int d : adj[c]) {
        if (d == b || d == a) continue;
        int total = scores[a] + scores[b] + scores[c] + scores[d];
        if (total > ans) ans = total;
      }
    }
  }

  return ans;
}

MaximumScoreOfANodeSequenceSolution::MaximumScoreOfANodeSequenceSolution() {
  setMetaInfo({.id = 2242,
               .title = "Maximum Score of a Node Sequence",
               .url = "https://leetcode.com/problems/maximum-score-of-a-node-sequence/"});
  registerStrategy(
      {.name = "EnumMiddleEdge",
       .expected = "Accepted",
       .time_complexity = "O(E)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Graph Theory", "Sorting", "Enumeration"}},
      maximumScoreImpl);
  setDefaultStrategy();
}

int MaximumScoreOfANodeSequenceSolution::maximumScore(
    std::vector<int>& scores,
    std::vector<std::vector<int>>& edges) {
  return getSolution()(scores, edges);
}

}  // namespace problem_2242
}  // namespace leetcode
