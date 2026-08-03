#include "leetcode/problems/string-compression-ii.h"

#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>

namespace leetcode {
namespace problem_1531 {

namespace {

int encodedLength(int count) {
  if (count == 0) return 0;
  if (count == 1) return 1;
  if (count <= 9) return 2;
  if (count <= 99) return 3;
  return 4;  // count == 100
}

int getLengthOfOptimalCompressionImpl(std::string s, int k) {
  int n = static_cast<int>(s.size());
  // dp[i][kk] = min compressed length for suffix s[i..n-1] with at most kk deletions
  // We use a 2D vector: (n+1) x (k+1), initialized to a large value.
  const int INF = 1e9;
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, INF));

  // Base: empty suffix
  for (int kk = 0; kk <= k; ++kk) {
    dp[n][kk] = 0;
  }

  // Fill DP backwards
  for (int i = n - 1; i >= 0; --i) {
    for (int kk = 0; kk <= k; ++kk) {
      // Option 1: delete s[i]
      if (kk > 0) {
        dp[i][kk] = std::min(dp[i][kk], dp[i + 1][kk - 1]);
      }

      // Option 2: keep s[i] and build a run
      int same = 0;
      int diff = 0;
      for (int j = i; j < n; ++j) {
        if (s[j] == s[i]) {
          ++same;
        } else {
          ++diff;
        }
        if (diff > kk) break;
        dp[i][kk] = std::min(dp[i][kk], encodedLength(same) + dp[j + 1][kk - diff]);
      }
    }
  }

  return dp[0][k];
}

}  // namespace

StringCompressionIiSolution::StringCompressionIiSolution() {
  setMetaInfo({.id = 1531, .title = "String Compression II", .url = "https://leetcode.com/problems/string-compression-ii/"});

  registerStrategy(
      {.name = "DP suffix O(n^2*k)",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * k)",
       .space_complexity = "O(n * k)",
       .tags = {"String", "Dynamic Programming"}},
      getLengthOfOptimalCompressionImpl);

  setDefaultStrategy();
}

int StringCompressionIiSolution::getLengthOfOptimalCompression(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace problem_1531
}  // namespace leetcode
