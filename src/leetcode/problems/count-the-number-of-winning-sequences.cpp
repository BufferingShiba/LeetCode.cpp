#include "leetcode/problems/count-the-number-of-winning-sequences.h"

#include <array>
#include <string>
#include <vector>

namespace leetcode::problem_3320 {

namespace {

constexpr int kMod = 1000000007;

// Map a creature char to index: F->0, W->1, E->2.
int toIndex(char c) {
  if (c == 'F') return 0;
  if (c == 'W') return 1;
  return 2;  // 'E'
}

// Bob's delta for round where Bob plays b and Alice plays a.
// Winning rule: F beats E, E beats W, W beats F  (x beats y iff y == (x+2)%3).
int roundDelta(int a, int b) {
  if (a == b) return 0;
  // Bob's move b beats Alice's a iff a == (b + 2) % 3.
  if (((b + 2) % 3) == a) return 1;
  return -1;
}

int countWinningSequencesImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  // Offset for the score difference so negative indices become valid.
  const int offset = n;
  const int width = 2 * n + 1;

  // dp[last] = array over score difference for sequences ending with `last`.
  std::array<std::vector<int64_t>, 3> dp;
  std::array<std::vector<int64_t>, 3> ndp;
  for (int i = 0; i < 3; ++i) {
    dp[i].assign(width, 0);
    ndp[i].assign(width, 0);
  }

  int a0 = toIndex(s[0]);
  for (int b = 0; b < 3; ++b) {
    int delta = roundDelta(a0, b);
    dp[b][offset + delta] = 1;
  }

  for (int i = 1; i < n; ++i) {
    int ai = toIndex(s[i]);
    for (auto& row : ndp) {
      std::fill(row.begin(), row.end(), 0);
    }
    for (int last = 0; last < 3; ++last) {
      for (int c = 0; c < width; ++c) {
        int64_t val = dp[last][c];
        if (val == 0) continue;
        for (int b = 0; b < 3; ++b) {
          if (b == last) continue;
          int delta = roundDelta(ai, b);
          int nc = c + delta;
          if (nc < 0 || nc >= width) continue;
          ndp[b][nc] = (ndp[b][nc] + val) % kMod;
        }
      }
    }
    dp.swap(ndp);
  }

  int64_t ans = 0;
  for (int last = 0; last < 3; ++last) {
    for (int c = offset + 1; c < width; ++c) {
      ans = (ans + dp[last][c]) % kMod;
    }
  }
  return static_cast<int>(ans);
}

}  // namespace

CountTheNumberOfWinningSequencesSolution::CountTheNumberOfWinningSequencesSolution() {
  setMetaInfo({.id = 3320,
               .title = "Count The Number of Winning Sequences",
               .url = "https://leetcode.com/problems/count-the-number-of-winning-sequences/"});
  registerStrategy(
      {.name = "dp_rolling",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"String", "Dynamic Programming"}},
      countWinningSequencesImpl);
}

int CountTheNumberOfWinningSequencesSolution::countWinningSequences(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3320
