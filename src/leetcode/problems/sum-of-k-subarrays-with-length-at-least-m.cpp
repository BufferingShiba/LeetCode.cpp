#include "leetcode/problems/sum-of-k-subarrays-with-length-at-least-m.h"

#include <algorithm>
#include <limits>

namespace leetcode {
namespace problem_3473 {

namespace {

int maxSumImpl(std::vector<int>& nums, int k, int m) {
  const int n = static_cast<int>(nums.size());
  const long long NEG = std::numeric_limits<long long>::min() / 4;

  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  // dp0[i][j]: first i elements, j subarrays, nums[i-1] NOT in any subarray.
  // dp1[i][j]: first i elements, j subarrays, nums[i-1] IS in the last subarray.
  std::vector<std::vector<long long>> dp0(n + 1, std::vector<long long>(k + 1, NEG));
  std::vector<std::vector<long long>> dp1(n + 1, std::vector<long long>(k + 1, NEG));

  for (int i = 0; i <= n; ++i) {
    dp0[i][0] = 0;
  }

  for (int j = 1; j <= k; ++j) {
    // runningBest for this j: max over eligible t of bestOf[t][j-1] - prefix[t],
    // where bestOf[t][j-1] = max(dp0[t][j-1], dp1[t][j-1]) is the best value of
    // having (j-1) subarrays within the first t elements, allowing the next
    // subarray to start at index t (adjacent is allowed).
    long long runningBest = NEG;
    // Store bestOf[t][j-1] = max(dp0[t][j-1], dp1[t][j-1]).
    // t enters the window when i reaches t + m (so that length >= m).
    for (int i = 1; i <= n; ++i) {
      // new eligible start index t = i - m for the subarray ending at i-1.
      int t = i - m;
      if (t >= 0) {
        long long bestOf = std::max(dp0[t][j - 1], dp1[t][j - 1]);
        runningBest = std::max(runningBest, bestOf - prefix[t]);
      }

      // dp1[i][j]: nums[i-1] is in the last subarray.
      long long best = NEG;
      if (dp1[i - 1][j] > NEG) {  // extend running subarray
        best = dp1[i - 1][j] + nums[i - 1];
      }
      if (runningBest > NEG) {  // start a new subarray ending here, length >= m
        best = std::max(best, runningBest + prefix[i]);
      }
      dp1[i][j] = best;

      // dp0[i][j]: skip nums[i-1].
      dp0[i][j] = std::max(dp0[i - 1][j], dp1[i - 1][j]);
    }
  }

  return static_cast<int>(std::max(dp0[n][k], dp1[n][k]));
}

}  // namespace

SumOfKSubarraysWithLengthAtLeastMSolution::SumOfKSubarraysWithLengthAtLeastMSolution() {
  setMetaInfo({.id = 3473,
               .title = "Sum of K Subarrays With Length at Least M",
               .url = "https://leetcode.com/problems/sum-of-k-subarrays-with-length-at-least-m/"});
  registerStrategy(
      {.name = "ThreeDPrefix",
       .expected = "Accepted",
       .time_complexity = "O(k * n)",
       .space_complexity = "O(k * n)",
       .tags = {"Array", "Dynamic Programming", "Prefix Sum"}},
      static_cast<Func>(maxSumImpl));
}

int SumOfKSubarraysWithLengthAtLeastMSolution::maxSum(
    std::vector<int>& nums, int k, int m) {
  return getSolution()(nums, k, m);
}

}  // namespace problem_3473
}  // namespace leetcode
