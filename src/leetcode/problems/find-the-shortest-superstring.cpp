#include "leetcode/problems/find-the-shortest-superstring.h"

#include <algorithm>
#include <climits>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_943 {

namespace {

// Compute the maximum overlap length when appending word `b` after word `a`.
// overlap[i][j] = max k such that suffix of words[i] of length k equals
// prefix of words[j] of length k.
int calcOverlap(const std::string& a, const std::string& b) {
  int maxLen = std::min(a.size(), b.size());
  for (int k = maxLen; k > 0; --k) {
    if (a.compare(a.size() - k, k, b, 0, k) == 0) {
      return k;
    }
  }
  return 0;
}

std::string shortestSuperstringImpl(std::vector<std::string>& words) {
  int n = static_cast<int>(words.size());
  if (n == 0) return "";
  if (n == 1) return words[0];

  // Precompute overlap matrix
  std::vector<std::vector<int>> overlap(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        overlap[i][j] = calcOverlap(words[i], words[j]);
      }
    }
  }

  int totalStates = 1 << n;
  const int INF = 1e9;

  // dp[mask][i] = minimum total length of superstring that contains all words
  // in `mask` and ends with `words[i]`.
  std::vector<std::vector<int>> dp(totalStates, std::vector<int>(n, INF));
  // parent[mask][i] = previous word index (j) that leads to this state
  std::vector<std::vector<int>> parent(totalStates, std::vector<int>(n, -1));

  // Base cases: single word states
  for (int i = 0; i < n; ++i) {
    dp[1 << i][i] = static_cast<int>(words[i].size());
  }

  // DP transitions
  for (int mask = 1; mask < totalStates; ++mask) {
    for (int i = 0; i < n; ++i) {
      if (!(mask & (1 << i))) continue;  // i must be in mask
      if (dp[mask][i] >= INF) continue;

      // Try to extend with word j not yet in mask
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) continue;  // j already used
        int newMask = mask | (1 << j);
        int newLen = dp[mask][i] + static_cast<int>(words[j].size()) - overlap[i][j];
        if (newLen < dp[newMask][j]) {
          dp[newMask][j] = newLen;
          parent[newMask][j] = i;
        }
      }
    }
  }

  // Find the best ending word for the full mask
  int fullMask = totalStates - 1;
  int bestEnd = 0;
  int bestLen = INF;
  for (int i = 0; i < n; ++i) {
    if (dp[fullMask][i] < bestLen) {
      bestLen = dp[fullMask][i];
      bestEnd = i;
    }
  }

  // Reconstruct the optimal word order
  std::vector<int> order;
  int mask = fullMask;
  int cur = bestEnd;
  while (cur != -1) {
    order.push_back(cur);
    int prev = parent[mask][cur];
    if (prev == -1) break;
    mask ^= (1 << cur);  // remove cur from mask
    cur = prev;
  }
  std::reverse(order.begin(), order.end());

  // Build the final superstring
  std::string result = words[order[0]];
  for (size_t k = 1; k < order.size(); ++k) {
    int prevIdx = order[k - 1];
    int curIdx = order[k];
    int ov = overlap[prevIdx][curIdx];
    result += words[curIdx].substr(ov);
  }

  return result;
}

}  // namespace

std::string FindTheShortestSuperstringSolution::shortestSuperstring(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

FindTheShortestSuperstringSolution::FindTheShortestSuperstringSolution() {
  setMetaInfo({.id = 943,
               .title = "Find the Shortest Superstring",
               .url = "https://leetcode.com/problems/find-the-shortest-superstring/"});

  registerStrategy(
      {.name = "DP + Bitmask (TSP variant)",
       .expected = "Accepted",
       .time_complexity = "O(N^2 * 2^N + N^2 * L)",
       .space_complexity = "O(N * 2^N)",
       .tags = {"Array", "String", "Dynamic Programming", "Bit Manipulation",
                "Bitmask"}},
      shortestSuperstringImpl);
}

}  // namespace problem_943
}  // namespace leetcode
