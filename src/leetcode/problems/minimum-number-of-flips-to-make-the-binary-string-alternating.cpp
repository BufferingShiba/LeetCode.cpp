#include "leetcode/problems/minimum-number-of-flips-to-make-the-binary-string-alternating.h"

namespace leetcode {
namespace problem_1888 {

namespace {

// Type-1 operation equals considering every cyclic shift of s.
// A window [l, l+n) of s+s is the rotated string. Its j-th char must match
// either pattern "0101..." (c0) or "1010..." (c1); the best cost is
// min(c0, c1) for this rotation.
// Use an absolute-index reference R[i] = s2[i] vs '0' + (i%2). Let m be the
// number of window positions where s2[i] != R[i]. Then per position the char
// equals exactly one of R[i]/!R[i], so mismatches vs the "0101" aligned
// pattern and vs "1010" sum to n. Hence the best cost for every window is
// min(m, n - m). Maintain the running mismatch count m across the window in
// O(n) sliding fashion.
int minFlipsImpl(const std::string& s) {
  const int n = static_cast<int>(s.size());
  if (n <= 1) return 0;

  std::string s2 = s + s;

  // Count mismatches of the first window [0, n) against R[i] = '0' + (i%2).
  int m = 0;
  for (int i = 0; i < n; ++i) {
    if (s2[i] != static_cast<char>('0' + (i % 2))) {
      ++m;
    }
  }

  int best = std::min(m, n - m); // l = 0

  // Slide the window to each subsequent start l in [1, n-1].
  for (int l = 1; l < n; ++l) {
    int prev = l - 1;
    if (s2[prev] != static_cast<char>('0' + (prev % 2))) {
      --m;
    }
    int next = l + n - 1;
    if (s2[next] != static_cast<char>('0' + (next % 2))) {
      ++m;
    }
    best = std::min(best, std::min(m, n - m));
  }

  return best;
}

}  // namespace

MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingSolution::MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingSolution() {
  setMetaInfo({.id = 1888,
               .title = "Minimum Number of Flips to Make the Binary String Alternating",
               .url = "https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/"});
  registerStrategy({.name = "SlidingWindow",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Sliding Window"}},
                   minFlipsImpl);
}

int MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingSolution::minFlips(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_1888
}  // namespace leetcode
