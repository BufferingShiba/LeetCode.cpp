#include "leetcode/problems/concatenated-words.h"

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_472 {
namespace {

std::vector<std::string> findAllConcatenatedWordsInADictImpl(std::vector<std::string>& words) {
  std::unordered_set<std::string> dict(words.begin(), words.end());
  const int INF = words.size() + 1;
  std::vector<std::string> result;

  for (const std::string& w : words) {
    const int n = static_cast<int>(w.size());
    // dp[i] = minimum number of dictionary words that can form w[0..i).
    std::vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        // Skip using the entire word as a single segment (j==0 and i==n), since
        // a concatenated word must consist of at least two shorter words.
        if (j == 0 && i == n) continue;
        if (dp[j] == INF) continue;
        std::string sub = w.substr(j, i - j);
        if (dict.find(sub) == dict.end()) continue;
        dp[i] = std::min(dp[i], dp[j] + 1);
      }
    }
    if (dp[n] >= 2 && dp[n] < INF) {
      result.push_back(w);
    }
  }
  return result;
}

}  // namespace

ConcatenatedWordsSolution::ConcatenatedWordsSolution() {
  setMetaInfo({472, "Concatenated Words",
               "https://leetcode.com/problems/concatenated-words/"});
  registerStrategy(
      {"DpWithHashSet", "Accepted", "O(S * L)", "O(S)",
       {"Array", "String", "Dynamic Programming"}},
      findAllConcatenatedWordsInADictImpl);
}

std::vector<std::string> ConcatenatedWordsSolution::findAllConcatenatedWordsInADict(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_472
}  // namespace leetcode
