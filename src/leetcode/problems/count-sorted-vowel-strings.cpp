#include "leetcode/problems/count-sorted-vowel-strings.h"

namespace leetcode {
namespace problem_1641 {

namespace {

// DP: dp[j] = number of sorted strings of current length ending with vowel j.
// Transition: new_dp[j] = sum(dp[0..j]) since previous char must be <= current.
int countVowelStringsImpl(int n) {
  std::vector<long long> dp(5, 1);  // length 1: each vowel alone.
  for (int i = 2; i <= n; ++i) {
    std::vector<long long> next(5, 0);
    long long running = 0;
    for (int j = 0; j < 5; ++j) {
      running += dp[j];
      next[j] = running;
    }
    dp.swap(next);
  }
  long long total = 0;
  for (int j = 0; j < 5; ++j) total += dp[j];
  return static_cast<int>(total);
}

}  // namespace

CountSortedVowelStringsSolution::CountSortedVowelStringsSolution() {
  setMetaInfo({.id = 1641,
               .title = "Count Sorted Vowel Strings",
               .url = "https://leetcode.com/problems/count-sorted-vowel-strings/"});
  registerStrategy({.name = "dynamic programming",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Dynamic Programming", "Combinatorics"}},
                   countVowelStringsImpl);
}

int CountSortedVowelStringsSolution::countVowelStrings(int n) {
  return getSolution()(n);
}

}  // namespace problem_1641
}  // namespace leetcode
