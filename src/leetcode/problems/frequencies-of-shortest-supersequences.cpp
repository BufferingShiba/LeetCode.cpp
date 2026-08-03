#include "leetcode/problems/frequencies-of-shortest-supersequences.h"

#include <array>
#include <climits>
#include <functional>
#include <set>
#include <utility>

namespace leetcode {
namespace problem_3435 {
namespace {

bool isDag(const std::array<std::array<bool, 26>, 26>& hard) {
  int color[26] = {};  // 0 unvisited, 1 in-stack, 2 done
  std::function<bool(int)> dfs = [&](int u) -> bool {
    color[u] = 1;
    for (int v = 0; v < 26; ++v) {
      if (!hard[u][v]) continue;
      if (color[v] == 1) return false;
      if (color[v] == 0 && !dfs(v)) return false;
    }
    color[u] = 2;
    return true;
  };
  for (int u = 0; u < 26; ++u) {
    if (color[u] == 0 && !dfs(u)) return false;
  }
  return true;
}

std::vector<std::vector<int>> supersequencesImpl(std::vector<std::string>& words) {
  std::vector<int> letters;
  bool present[26] = {};
  bool selfLoop[26] = {};
  for (const auto& w : words) {
    present[w[0] - 'a'] = true;
    present[w[1] - 'a'] = true;
    if (w[0] == w[1]) selfLoop[w[0] - 'a'] = true;
  }
  for (int c = 0; c < 26; ++c) {
    if (present[c]) letters.push_back(c);
  }
  int k = static_cast<int>(letters.size());

  std::vector<std::pair<int, int>> edges;
  for (const auto& w : words) {
    int a = w[0] - 'a', b = w[1] - 'a';
    if (a != b) edges.push_back({a, b});
  }

  int bestLen = INT_MAX;
  std::set<std::vector<int>> bestFreqs;

  for (int mask = 0; mask < (1 << k); ++mask) {
    std::array<bool, 26> twice = {};
    for (int i = 0; i < k; ++i) {
      if (mask & (1 << i)) twice[letters[i]] = true;
    }
    bool ok = true;
    for (int c = 0; c < 26; ++c) {
      if (selfLoop[c] && !twice[c]) { ok = false; break; }
    }
    if (!ok) continue;

    std::array<std::array<bool, 26>, 26> hard = {};
    for (const auto& e : edges) {
      int a = e.first, b = e.second;
      if (!twice[a] && !twice[b]) hard[a][b] = true;
    }
    if (!isDag(hard)) continue;

    std::vector<int> freq(26, 0);
    int len = 0;
    for (int c = 0; c < 26; ++c) {
      if (present[c]) {
        freq[c] = twice[c] ? 2 : 1;
        len += freq[c];
      }
    }
    if (len < bestLen) {
      bestLen = len;
      bestFreqs.clear();
      bestFreqs.insert(freq);
    } else if (len == bestLen) {
      bestFreqs.insert(freq);
    }
  }

  return std::vector<std::vector<int>>(bestFreqs.begin(), bestFreqs.end());
}

}  // namespace

FrequenciesOfShortestSupersequencesSolution::FrequenciesOfShortestSupersequencesSolution() {
  this->setMetaInfo({
      3435,
      "Frequencies of Shortest Supersequences",
      "https://leetcode.com/problems/frequencies-of-shortest-supersequences/",
  });
  this->registerStrategy(
      {"Graph mask enumeration", "Accepted", "O(2^k * E)", "O(2^k)",
       {"Array", "String", "Bit Manipulation", "Graph Theory", "Topological Sort", "Enumeration"}},
      supersequencesImpl);
}

std::vector<std::vector<int>>
FrequenciesOfShortestSupersequencesSolution::supersequences(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_3435
}  // namespace leetcode
