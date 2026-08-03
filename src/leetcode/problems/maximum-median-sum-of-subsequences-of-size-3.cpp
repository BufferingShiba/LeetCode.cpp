#include "leetcode/problems/maximum-median-sum-of-subsequences-of-size-3.h"

#include <algorithm>

namespace leetcode {
namespace problem_3627 {

// Greedy:
// Sort ascending. Every triple contributes its median (the middle of the sorted
// triple). Since each median needs one element not larger than it (the
// "first") and one element not smaller than it (the "third"), the k = n/3
// smallest elements are forced to be the "firsts", and the largest element can
// only ever be a "third". To maximize the median sum we take, scanning the top
// of the sorted array downward, the elements a[n-2], a[n-4], ..., a[n-2k] as
// medians. This is constructive: pair median a[t] with third a[t+1] and any of
// the k smallest elements as its first.
static long long solution1(vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  const int n = static_cast<int>(nums.size());
  const int k = n / 3;  // number of subsequences of size 3
  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += nums[n - 2 - 2 * i];
  }
  return ans;
}

MaximumMedianSumOfSubsequencesOfSize3Solution::MaximumMedianSumOfSubsequencesOfSize3Solution() {
  setMetaInfo({
      .id = 3627,
      .title = "Maximum Median Sum of Subsequences of Size 3",
      .url = "https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3"
  });
  registerStrategy({.name = "Greedy Sort", .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)", .tags = {"Greedy", "Sorting"}},
                   solution1);
}

long long MaximumMedianSumOfSubsequencesOfSize3Solution::maximumMedianSum(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3627
}  // namespace leetcode
