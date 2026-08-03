#include "leetcode/problems/subsequence-with-the-minimum-score.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2565 {

namespace {

int minimumScoreImpl(const std::string& s, const std::string& t) {
  const int n = static_cast<int>(s.size());
  const int m = static_cast<int>(t.size());
  const int INF = n + 1;

  // pre[i]: smallest s index that matches t[i], when greedily matching
  // t[0..i] left-to-right. INF if t[0..i] not a subsequence.
  std::vector<int> pre(m, INF);
  int si = 0;
  for (int i = 0; i < m; ++i) {
    while (si < n && s[si] != t[i]) ++si;
    if (si >= n) break;
    pre[i] = si;
    ++si;
  }

  // sufEnd[i]: largest s index that matches t[i], when greedily matching
  // t[i..m-1] right-to-left (maximally to the right). INF if impossible.
  std::vector<int> sufEnd(m, INF);
  int ei = n - 1;
  for (int i = m - 1; i >= 0; --i) {
    while (ei >= 0 && s[ei] != t[i]) --ei;
    if (ei < 0) break;
    sufEnd[i] = ei;
    --ei;
  }

  // Whole t is already a subsequence.
  if (pre[m - 1] != INF) return 0;

  // Keep prefix t[0..l-1] and suffix t[js..m-1]; remove interval [l, js-1].
  // Valid iff sufEnd[js] > pre[l-1] (suffix strictly to the right of prefix).
  // Both boundaries are monotonic -> two pointers.
  int ans = m;
  int js = 0;
  for (int l = 0; l <= m; ++l) {
    if (l > 0 && pre[l - 1] == INF) break;
    const int prefixEnd = (l == 0) ? -1 : pre[l - 1];
    if (js < l) js = l;
    while (js < m && (sufEnd[js] == INF || sufEnd[js] <= prefixEnd)) {
      ++js;
    }
    if (js == m) {
      // Suffix empty: remove [l, m-1].
      ans = std::min(ans, m - l);
    } else {
      ans = std::min(ans, js - l);
    }
  }

  return ans;
}

}  // namespace

SubsequenceWithTheMinimumScoreSolution::SubsequenceWithTheMinimumScoreSolution() {
  setMetaInfo({2565, "Subsequence With the Minimum Score",
               "https://leetcode.com/problems/subsequence-with-the-minimum-score/"});
  registerStrategy(
      {"two-pointers", "Accepted", "O(n+m)", "O(m)",
       {"Two Pointers", "String"}},
      minimumScoreImpl);
}

int SubsequenceWithTheMinimumScoreSolution::minimumScore(std::string s,
                                                          std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace problem_2565
}  // namespace leetcode
