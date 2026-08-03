#include "leetcode/problems/maximum-number-of-subsequences-after-one-inserting.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_3628 {
namespace {

long long numOfSubsequencesImpl(const std::string& s) {
  const std::size_t n = s.size();
  long long totalLC = 0;   // number of "LC" pairs
  long long totalCT = 0;   // number of "CT" pairs
  long long base = 0;      // number of "LCT" subsequences

  // suffix count of 'T' for computing max cntL * sufT at insertion of 'C'
  std::vector<int> sufT(n + 1, 0);
  for (std::size_t i = n; i-- > 0;) {
    sufT[i] = sufT[i + 1] + (s[i] == 'T' ? 1 : 0);
  }

  long long cntL = 0;
  long long cntLC = 0;  // pairs L...C seen so far
  long long maxInsertC = 0;
  long long cntC = 0;

  for (std::size_t i = 0; i < n; ++i) {
    // The inserted C may go in any gap, including one where the original
    // string has no C at all. Evaluate the gap immediately before s[i].
    maxInsertC = std::max(maxInsertC,
                          cntL * static_cast<long long>(sufT[i]));
    if (s[i] == 'L') {
      ++cntL;
    } else if (s[i] == 'C') {
      ++cntC;
      cntLC += cntL;
    } else if (s[i] == 'T') {
      totalCT += cntC;
      base += cntLC;
    }
  }
  totalLC = cntLC;

  long long insertL = base + totalCT;  // insert L at the very front
  long long insertT = base + totalLC;  // insert T at the very end
  long long insertC = base + maxInsertC;

  return std::max(base, std::max(insertL, std::max(insertT, insertC)));
}

}  // namespace

MaximumNumberOfSubsequencesAfterOneInsertingSolution::
    MaximumNumberOfSubsequencesAfterOneInsertingSolution() {
  setMetaInfo({.id = 3628,
               .title = "Maximum Number of Subsequences After One Inserting",
               .url = "https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/"});
  registerStrategy(
      {"PrefixSumGreedy", "Accepted", "O(n)", "O(n)",
       {"String", "Dynamic Programming", "Greedy", "Prefix Sum"}},
      numOfSubsequencesImpl);
}

long long MaximumNumberOfSubsequencesAfterOneInsertingSolution::numOfSubsequences(
    const std::string& s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_3628
