#include "leetcode/problems/lexicographically-smallest-string-after-adjacent-removals.h"

#include <string>
#include <vector>
#include <algorithm>

namespace leetcode {
namespace problem_3563 {

namespace {

// Two characters are "consecutive" in the circular alphabet.
bool IsAdjacent(char a, char b) {
  int d = std::abs(a - b);
  return d == 1 || d == 25;
}

std::string LexicographicallySmallestStringAfterAdjacentRemovalsImpl(std::string s) {
  const int n = static_cast<int>(s.size());

  // emptyable[l][r]: whether substring s[l..r] can be fully eliminated.
  std::vector<std::vector<int>> emptyable(n, std::vector<int>(n, 0));
  for (int len = 2; len <= n; ++len) {
    for (int l = 0; l + len - 1 < n; ++l) {
      const int r = l + len - 1;
      bool ok = false;
      for (int k = l + 1; k <= r && !ok; ++k) {
        if (!IsAdjacent(s[l], s[k])) continue;
        const bool leftEmpty = (l + 1 > k - 1) || emptyable[l + 1][k - 1];
        const bool rightEmpty = (k + 1 > r) || emptyable[k + 1][r];
        if (leftEmpty && rightEmpty) ok = true;
      }
      emptyable[l][r] = ok ? 1 : 0;
    }
  }
  auto isEmpty = [&](int l, int r) -> bool {
    return (l > r) || emptyable[l][r] == 1;
  };

  // best[cur]: lexicographically smallest feasible result starting at position cur,
  // assuming everything before cur is fully handled. best[n] = "".
  std::vector<std::string> best(n + 1);
  std::vector<int> feasible(n + 1, 0);
  best[n] = "";
  feasible[n] = 1;

  for (int cur = n - 1; cur >= 0; --cur) {
    // If the whole suffix can be cleared, "" is optimal (lexicographically smallest).
    if (isEmpty(cur, n - 1)) {
      best[cur] = "";
      feasible[cur] = 1;
      continue;
    }
    std::string cand;
    bool have = false;
    for (int i = cur; i < n; ++i) {
      // The gap s[cur..i-1] must be fully clearable before keeping s[i].
      if (!isEmpty(cur, i - 1)) continue;
      if (!feasible[i + 1]) continue;
      std::string c = s[i] + best[i + 1];
      if (!have || c < cand) {
        cand = c;
        have = true;
      }
    }
    if (have) {
      best[cur] = cand;
      feasible[cur] = 1;
    }
  }
  return best[0];
}

}  // namespace

std::string LexicographicallySmallestStringAfterAdjacentRemovalsSolution::lexicographicallySmallestString(std::string s) {
  return getSolution()(std::move(s));
}

LexicographicallySmallestStringAfterAdjacentRemovalsSolution::LexicographicallySmallestStringAfterAdjacentRemovalsSolution() {
  setMetaInfo({3563, "Lexicographically Smallest String After Adjacent Removals",
               "https://leetcode.com/problems/lexicographically-smallest-string-after-adjacent-removals/"});
  registerStrategy(
      {.name = "IntervalDP+LexicoConstruct",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(n^2)",
       .tags = {"String", "Dynamic Programming"},
       .notes = "Interval-DP computes clearable gaps; then greedily construct the lexicographically "
                "smallest keepable subsequence so every removed gap is fully clearable."},
      LexicographicallySmallestStringAfterAdjacentRemovalsImpl);
}

}  // namespace problem_3563
}  // namespace leetcode
