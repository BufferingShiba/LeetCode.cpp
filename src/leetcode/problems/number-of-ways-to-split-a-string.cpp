#include "leetcode/problems/number-of-ways-to-split-a-string.h"

namespace leetcode {
namespace problem_1573 {
namespace {

const long long kMod = 1000000007LL;

int numWaysImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  int totalOnes = 0;
  for (char c : s) {
    if (c == '1') ++totalOnes;
  }

  if (totalOnes % 3 != 0) {
    return 0;
  }

  if (totalOnes == 0) {
    // C(n-1, 2)
    long long ways = (static_cast<long long>(n - 1) * (n - 2) / 2) % kMod;
    return static_cast<int>(ways);
  }

  const int k = totalOnes / 3;

  // Find first cut: positions after which s1 contains exactly k ones.
  // Position p1 = index of k-th '1', p2 = index of (k+1)-th '1'.
  // cut1 = number of choices for the first split boundary = p2 - p1.
  long long cut1 = 0, cut2 = 0;
  int ones = 0;
  bool firstCutFound = false;
  int p1 = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++ones;
      if (ones == k) {
        p1 = i;
      } else if (ones == k + 1 && p1 != -1) {
        cut1 = i - p1;
        firstCutFound = true;
        break;
      }
    }
  }

  // Now count ones starting from where first cut is found.
  ones = 0;
  int q1 = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++ones;
      if (ones == 2 * k) {
        q1 = i;
      } else if (ones == 2 * k + 1 && q1 != -1) {
        cut2 = i - q1;
        break;
      }
    }
  }

  long long ans = (cut1 * cut2) % kMod;
  return static_cast<int>(ans);
}

}  // namespace

NumberOfWaysToSplitAStringSolution::NumberOfWaysToSplitAStringSolution() {
  setMetaInfo({.id = 1573,
               .title = "Number of Ways to Split a String",
               .url = "https://leetcode.com/problems/number-of-ways-to-split-a-string/"});
  registerStrategy({.name = "Counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String"}},
                   numWaysImpl);
}

int NumberOfWaysToSplitAStringSolution::numWays(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1573
}  // namespace leetcode
