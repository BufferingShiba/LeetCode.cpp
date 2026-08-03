#include "leetcode/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_1477 {

static int minSumOfLengthsImpl(std::vector<int>& arr, int target) {
  int n = static_cast<int>(arr.size());
  const int INF = INT_MAX / 2;

  // Step 1: sliding window to find all subarrays summing to target
  std::vector<std::pair<int, int>> intervals;  // (left, right)
  int left = 0;
  int sum = 0;
  for (int right = 0; right < n; ++right) {
    sum += arr[right];
    while (sum > target && left <= right) {
      sum -= arr[left];
      ++left;
    }
    if (sum == target) {
      intervals.emplace_back(left, right);
    }
  }

  if (intervals.size() < 2) return -1;

  // Step 2: record minimum length ending at each position
  std::vector<int> prefix_min(n, INF);
  for (const auto& interval : intervals) {
    int l = interval.first;
    int r = interval.second;
    int len = r - l + 1;
    prefix_min[r] = std::min(prefix_min[r], len);
  }

  // Step 3: propagate prefix minimum (left to right)
  for (int i = 1; i < n; ++i) {
    prefix_min[i] = std::min(prefix_min[i], prefix_min[i - 1]);
  }

  // Step 4: find best non-overlapping pair
  int ans = INF;
  for (const auto& interval : intervals) {
    int l = interval.first;
    int r = interval.second;
    int len = r - l + 1;
    if (l > 0 && prefix_min[l - 1] != INF) {
      ans = std::min(ans, len + prefix_min[l - 1]);
    }
  }

  return (ans == INF) ? -1 : ans;
}

FindTwoNonOverlappingSubArraysEachWithTargetSumSolution::FindTwoNonOverlappingSubArraysEachWithTargetSumSolution() {
  setMetaInfo({.id = 1477,
               .title = "Find Two Non-overlapping Sub-arrays Each With Target Sum",
               .url = "https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/"});
  registerStrategy(
      {.name = "PrefixMinimum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sliding Window", "Dynamic Programming"}},
      minSumOfLengthsImpl);
}

int FindTwoNonOverlappingSubArraysEachWithTargetSumSolution::minSumOfLengths(std::vector<int>& arr, int target) {
  return getSolution()(arr, target);
}

}  // namespace problem_1477
}  // namespace leetcode