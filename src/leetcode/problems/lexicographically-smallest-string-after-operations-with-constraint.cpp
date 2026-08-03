#include "leetcode/problems/lexicographically-smallest-string-after-operations-with-constraint.h"

namespace leetcode {
namespace problem_3106 {

// Greedy: process characters left to right. At each position, use the minimal
// cyclic distance to turn the character into 'a' if the remaining budget allows;
// otherwise lower the character by the full remaining budget (keeping >= 'a').
// Because distance is a sum of independent per-position costs and lexicographic
// order is prefix-dominant, greedily minimizing early characters is optimal.
std::string LexicographicallySmallestStringAfterOperationsWithConstraintSolution::
    getSmallestStringGreedy(std::string s, int k) {
  const int n = static_cast<int>(s.size());
  for (int i = 0; i < n && k > 0; ++i) {
    int cur = s[i] - 'a';
    // Minimal cyclic distance from current letter to 'a'.
    int toA = std::min(cur, 26 - cur);
    if (toA <= k) {
      s[i] = 'a';
      k -= toA;
    } else {
      // Not enough budget to reach 'a'; move downward as much as possible.
      s[i] = static_cast<char>('a' + (cur - k));
      k = 0;
    }
  }
  return s;
}

}  // namespace problem_3106
}  // namespace leetcode
