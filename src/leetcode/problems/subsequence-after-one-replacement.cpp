#include "leetcode/problems/subsequence-after-one-replacement.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3983 {
namespace {

bool canMakeSubsequenceImpl(const std::string& s, const std::string& t) {
  const int n = static_cast<int>(s.size());
  const int m = static_cast<int>(t.size());

  const int INF = m + 1;
  // pre[i] = smallest prefix length of t containing s[0..i-1] as subsequence.
  std::vector<int> pre(n + 1, INF);
  pre[0] = 0;
  int p = 0;
  for (int i = 0; i < n; ++i) {
    while (p < m && t[p] != s[i]) ++p;
    if (p >= m) break;
    ++p;
    pre[i + 1] = p;
  }

  // No replacement needed.
  if (pre[n] != INF) return true;

  // suf[i] = largest starting index in t such that s[i..n-1] is a subsequence
  // from there to the end, or -1 if impossible. Empty suffix gets suf[n] = m.
  std::vector<int> suf(n + 1, -1);
  suf[n] = m;
  int q = m - 1;
  for (int i = n - 1; i >= 0; --i) {
    while (q >= 0 && t[q] != s[i]) --q;
    if (q < 0) break;
    suf[i] = q;
    --q;
  }

  // Replace one position j: prefix s[0..j-1] and suffix s[j+1..n-1] must
  // leave a non-empty gap in t for the replaced (arbitrary) character.
  // The replaced char needs its own index between pre[j] and suf[j+1], so
  // we require pre[j] < suf[j+1] strictly (gap must contain at least one t
  // position).
  for (int j = 0; j < n; ++j) {
    if (pre[j] == INF || suf[j + 1] == -1) continue;
    if (pre[j] < suf[j + 1]) return true;
  }

  return false;
}

}  // namespace

SubsequenceAfterOneReplacementSolution::SubsequenceAfterOneReplacementSolution() {
  setMetaInfo({.id = 3983,
               .title = "Subsequence After One Replacement",
               .url = "https://leetcode.com/problems/subsequence-after-one-replacement/"});
  registerStrategy(
      {.name = "PrefixSuffixGreedy",
       .expected = "Accepted",
       .time_complexity = "O(|s| + |t|)",
       .space_complexity = "O(|s|)",
       .tags = {"Two Pointers", "Greedy", "String"}},
      [](std::string s, std::string t) -> bool {
        return canMakeSubsequenceImpl(s, t);
      });
}

bool SubsequenceAfterOneReplacementSolution::canMakeSubsequence(
    std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace problem_3983
}  // namespace leetcode
