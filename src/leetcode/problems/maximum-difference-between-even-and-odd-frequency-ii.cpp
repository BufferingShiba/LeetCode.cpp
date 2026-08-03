#include "leetcode/problems/maximum-difference-between-even-and-odd-frequency-ii.h"
#include <deque>
#include <limits>
#include <vector>

namespace leetcode::problem_3445 {

namespace {

int maxDifferenceImpl(const std::string& s, int k) {
  const int n = static_cast<int>(s.size());
  int ans = std::numeric_limits<int>::min();
  for (int a = 0; a < 5; ++a) {
    for (int b = 0; b < 5; ++b) {
      if (a == b) continue;
      std::vector<int> prefA(n), prefB(n);
      for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        prefA[i] = (i ? prefA[i - 1] : 0) + (d == a ? 1 : 0);
        prefB[i] = (i ? prefB[i - 1] : 0) + (d == b ? 1 : 0);
      }
      // Window (l, i] with l in [-1, i-k]; needed diff uses prefix at l.
      // Represent left boundary l by idx = l + 1 in [0, i-k+1]; idx==0 => empty prefix.
      std::deque<int> dqVal[4];
      std::deque<int> dqPos[4];
      int nextIdx = 0;
      int collectedUpTo = -1;
      int lastB = -1;
      for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        if (d == b) lastB = i;
        if (i - k + 1 > collectedUpTo) collectedUpTo = i - k + 1;
        while (nextIdx <= collectedUpTo && nextIdx <= lastB) {
          int l = nextIdx - 1;
          int pa = (l >= 0) ? prefA[l] : 0;
          int pb = (l >= 0) ? prefB[l] : 0;
          int st = (pa & 1) * 2 + (pb & 1);
          int v = pa - pb;
          while (!dqVal[st].empty() && dqVal[st].back() >= v) {
            dqVal[st].pop_back();
            dqPos[st].pop_back();
          }
          dqVal[st].push_back(v);
          dqPos[st].push_back(nextIdx);
          ++nextIdx;
        }
        int needA = (prefA[i] & 1) ^ 1;
        int needB = prefB[i] & 1;
        int st = needA * 2 + needB;
        if (!dqVal[st].empty()) {
          int cur = (prefA[i] - prefB[i]) - dqVal[st].front();
          if (cur > ans) ans = cur;
        }
      }
    }
  }
  return ans;
}

}  // namespace

MaximumDifferenceBetweenEvenAndOddFrequencyIiSolution::
    MaximumDifferenceBetweenEvenAndOddFrequencyIiSolution() {
  setMetaInfo({.id = 3445,
               .title = "Maximum Difference Between Even and Odd Frequency II",
               .url = "https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii"});
  registerStrategy(
      {.name = "enumerate-pairs-prefix-state",
       .expected = "Accepted",
       .time_complexity = "O(20 * n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Sliding Window", "Enumeration", "Prefix Sum"},
       .notes =
           "Enumerate ordered char pairs (a,b); maintain per-parity-state "
           "monotonic deques of prefix diffs for left boundaries including the "
           "empty prefix, gating by required parity and b-nonzero + length>=k."},
      &maxDifferenceImpl);
}

int MaximumDifferenceBetweenEvenAndOddFrequencyIiSolution::maxDifference(
    std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace leetcode::problem_3445
