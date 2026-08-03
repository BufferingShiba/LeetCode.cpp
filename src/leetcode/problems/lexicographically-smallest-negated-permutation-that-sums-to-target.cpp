#include "leetcode/problems/lexicographically-smallest-negated-permutation-that-sums-to-target.h"

namespace leetcode {
namespace problem_3752 {

// Greedy: choose which values to negate.
// Let S = n(n+1)/2 be the sum of 1..n. Negating value v subtracts 2v from the
// total, so we need a subset D of {1..n} with sum(D) = (S - target) / 2 =: T.
// The final array is the ascending order of signed values, i.e. negatives
// (most negative first) followed by positives ascending. To obtain the
// lexicographically smallest array, greedily negate the largest feasible value
// at each step (larger negated values produce smaller leading elements).
static vector<int> solution1(int n, long long target) {
  const long long S = (long long)n * (n + 1) / 2;
  const long long diff = S - target;
  if (diff < 0 || diff % 2 != 0) return {};  // impossible or no integer solution
  const long long T = diff / 2;
  if (T > S) return {};

  std::vector<bool> neg(n + 1, false);
  long long rem = T;
  for (int v = n; v >= 1; --v) {
    // Subset {1..v-1} can produce every sum in [0, (v-1)v/2].
    const long long rest = (long long)(v - 1) * v / 2;
    if ((long long)v <= rem && rem - v <= rest) {
      neg[v] = true;
      rem -= v;
    }
  }
  if (rem != 0) return {};  // safety: should not happen if input feasible

  std::vector<int> res;
  res.reserve(n);
  // Negatives ascending (largest magnitude first), then positives ascending.
  for (int d = n; d >= 1; --d)
    if (neg[d]) res.push_back(-d);
  for (int p = 1; p <= n; ++p)
    if (!neg[p]) res.push_back(p);
  return res;
}

LexicographicallySmallestNegatedPermutationThatSumsToTargetSolution::LexicographicallySmallestNegatedPermutationThatSumsToTargetSolution() {
  setMetaInfo({
      .id = 3752,
      .title = "Lexicographically Smallest Negated Permutation that Sums to Target",
      .url = "https://leetcode.com/problems/lexicographically-smallest-negated-permutation-that-sums-to-target"
  });
  registerStrategy({.name = "Greedy Negation", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"Greedy", "Math"}}, solution1);
}

vector<int> LexicographicallySmallestNegatedPermutationThatSumsToTargetSolution::lexSmallestNegatedPerm(int n, long long target) {
  return getSolution()(n, target);
}

}  // namespace problem_3752
}  // namespace leetcode
