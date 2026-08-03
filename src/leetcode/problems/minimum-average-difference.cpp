#include "leetcode/problems/minimum-average-difference.h"

#include <algorithm>
#include <cstdlib>

namespace leetcode {
namespace problem_2256 {
namespace {

int prefixSumStrategy(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  long long total = 0;
  for (int v : nums) total += v;

  long long prefix = 0;
  long long best = -1;
  int bestIdx = 0;
  for (int i = 0; i < n; ++i) {
    prefix += nums[i];
    const long long leftAvg = prefix / (i + 1);
    const long long rightAvg =
        (i == n - 1) ? 0 : (total - prefix) / (n - i - 1);
    const long long diff = std::llabs(leftAvg - rightAvg);
    if (best == -1 || diff < best) {
      best = diff;
      bestIdx = i;
    }
  }
  return bestIdx;
}

}  // namespace

MinimumAverageDifferenceSolution::MinimumAverageDifferenceSolution() {
  setMetaInfo({.id = 2256,
               .title = "Minimum Average Difference",
               .url = "https://leetcode.com/problems/minimum-average-difference/"});
  registerStrategy(
      {.name = "PrefixSum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Prefix Sum"}},
      prefixSumStrategy);
}

}  // namespace problem_2256
}  // namespace leetcode
