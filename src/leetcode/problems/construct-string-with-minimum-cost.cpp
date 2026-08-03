#include "leetcode/problems/construct-string-with-minimum-cost.h"

#include <algorithm>
#include <array>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_3213 {

namespace {

// Aho-Corasick automaton + DP.
// dp[i] = minimum cost to form target[0..i).
// Scan target once with the automaton.  At each position j, the current node
// cur and its fail-chain encode every word that is a suffix of target[0..j]
// (equivalently every word that starts at j - length + 1).  For each such word
// of length len ending at node v, update dp[j+1] = min(dp[j+1],
// dp[j+1-len] + minCost[v]).  We use a "jump" pointer to skip straight to the
// nearest word-end on the fail chain (and from there to further word-ends) to
// avoid walking the long non-word fail chain repeatedly.
int minimumCostAhoCorasick(std::string target, std::vector<std::string>& words,
                           std::vector<int>& costs) {
  struct Node {
    std::array<int, 26> next;
    int fail = 0;
    int jump = -1;
    int depth = 0;
    int cost = -1;
  };

  std::vector<Node> trie;
  trie.emplace_back();  // root = 0

  for (size_t w = 0; w < words.size(); ++w) {
    int cur = 0;
    for (char ch : words[w]) {
      int id = ch - 'a';
      if (trie[cur].next[id] == 0) {
        trie[cur].next[id] = static_cast<int>(trie.size());
        trie.emplace_back();
      }
      cur = trie[cur].next[id];
    }
    trie[cur].depth = static_cast<int>(words[w].size());
    trie[cur].cost = (trie[cur].cost == -1) ? costs[w] : std::min(trie[cur].cost, costs[w]);
  }

  std::queue<int> q;
  for (int id = 0; id < 26; ++id) {
    if (trie[0].next[id] != 0) {
      int v = trie[0].next[id];
      trie[v].fail = 0;
      trie[v].jump = -1;
      q.push(v);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int id = 0; id < 26; ++id) {
      if (trie[u].next[id] != 0) {
        int v = trie[u].next[id];
        trie[v].fail = trie[trie[u].fail].next[id];
        int f = trie[v].fail;
        trie[v].jump = (trie[f].cost != -1) ? f : trie[f].jump;
        q.push(v);
      } else {
        trie[u].next[id] = trie[trie[u].fail].next[id];
      }
    }
  }

  const long long INF = static_cast<long long>(1e18);
  std::vector<long long> dp(target.size() + 1, INF);
  dp[0] = 0;

  int cur = 0;
  for (int j = 0; j < static_cast<int>(target.size()); ++j) {
    cur = trie[cur].next[target[j] - 'a'];

    if (cur == 0) continue;  // no match starting at any recent position

    if (trie[cur].cost != -1) {
      int start = j + 1 - trie[cur].depth;
      if (dp[start] != INF) {
        dp[j + 1] = std::min(dp[j + 1], dp[start] + trie[cur].cost);
      }
    }
    for (int v = trie[cur].jump; v != -1; v = trie[v].jump) {
      if (trie[v].cost == -1) continue;
      int start = j + 1 - trie[v].depth;
      if (dp[start] != INF) {
        dp[j + 1] = std::min(dp[j + 1], dp[start] + trie[v].cost);
      }
    }
  }

  return dp[target.size()] == INF ? -1 : static_cast<int>(dp[target.size()]);
}

}  // namespace

ConstructStringWithMinimumCostSolution::ConstructStringWithMinimumCostSolution() {
  setMetaInfo({.id = 3213,
               .title = "Construct String with Minimum Cost",
               .url = "https://leetcode.com/problems/construct-string-with-minimum-cost/"});
  registerStrategy(
      {.name = "AhoCorasickDp",
       .expected = "Accepted",
       .time_complexity = "O(n + total_words_len + total_word_match_ends)",
       .space_complexity = "O(total_words_len + n)",
       .tags = {"Dynamic Programming", "Trie", "Aho-Corasick"},
       .notes =
           "Build an AC automaton. Scan target once; for each position, use the "
           "fail/jump chain to enumerate all words that end at this position, "
           "then update dp. Avoids re-walking from every start position."},
      minimumCostAhoCorasick);
}

}  // namespace problem_3213
}  // namespace leetcode
