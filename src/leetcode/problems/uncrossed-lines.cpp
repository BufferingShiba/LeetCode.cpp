#include "leetcode/problems/uncrossed-lines.h"

#include <vector>

namespace leetcode {
namespace problem_1035 {

namespace {

// Standard LCS DP with a single row to store previous values.
int maxUncrossedLinesImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  const int n = static_cast<int>(nums1.size());
  const int m = static_cast<int>(nums2.size());
  std::vector<int> dp(m + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int prev = 0;
    for (int j = 1; j <= m; ++j) {
      int cur = dp[j];
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[j] = prev + 1;
      } else {
        dp[j] = std::max(dp[j], dp[j - 1]);
      }
      prev = cur;
    }
  }
  return dp[m];
}

}  // namespace

int UncrossedLinesSolution::maxUncrossedLines(std::vector<int>& nums1,
                                               std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

UncrossedLinesSolution::UncrossedLinesSolution() {
  setMetaInfo({.id = 1035, .title = "Uncrossed Lines", .url =
                   "https://leetcode.com/problems/uncrossed-lines/"});
  registerStrategy({.name = "LCS DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n*m)",
                    .space_complexity = "O(m)",
                    .tags = {"Array", "Dynamic Programming"}},
                   maxUncrossedLinesImpl);
}

}  // namespace problem_1035
}  // namespace leetcode
