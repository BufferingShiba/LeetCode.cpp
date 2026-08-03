#include "leetcode/problems/partition-array-into-two-arrays-to-minimize-sum-difference.h"

#include <algorithm>
#include <cstdlib>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_2035 {
namespace {

int minimumDifferenceMitM(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size()) / 2;
  long long total = 0;
  for (int v : nums) total += v;

  // For each half, group subset sums by number of chosen elements.
  // group[k] contains all sums of subsets that pick exactly k elements.
  auto buildGroups = [](const std::vector<int>& half) {
    int m = static_cast<int>(half.size());
    std::vector<std::vector<long long>> groups(m + 1);
    for (int mask = 0; mask < (1 << m); ++mask) {
      int cnt = __builtin_popcount(mask);
      long long sum = 0;
      for (int j = 0; j < m; ++j) {
        if (mask & (1 << j)) sum += half[j];
      }
      groups[cnt].push_back(sum);
    }
    for (auto& g : groups) std::sort(g.begin(), g.end());
    return groups;
  };

  std::vector<int> left(nums.begin(), nums.begin() + n);
  std::vector<int> right(nums.begin() + n, nums.end());
  auto leftGroups = buildGroups(left);
  auto rightGroups = buildGroups(right);

  long long best = LLONG_MAX;
  for (int i = 0; i <= n; ++i) {
    const auto& L = leftGroups[i];
    const auto& R = rightGroups[n - i];
    if (L.empty() || R.empty()) continue;
    for (long long ls : L) {
      long long target = total / 2 - ls;  // want 2*(ls+rs)-total = 0 => rs = total/2 - ls
      auto it = std::lower_bound(R.begin(), R.end(), target);
      if (it != R.end()) {
        best = std::min(best, std::llabs(2 * (ls + *it) - total));
      }
      if (it != R.begin()) {
        --it;
        best = std::min(best, std::llabs(2 * (ls + *it) - total));
      }
    }
  }
  return static_cast<int>(best);
}

}  // namespace

PartitionArrayIntoTwoArraysToMinimizeSumDifferenceSolution::
    PartitionArrayIntoTwoArraysToMinimizeSumDifferenceSolution() {
  setMetaInfo({
      .id = 2035,
      .title = "Partition Array Into Two Arrays to Minimize Sum Difference",
      .url = "https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/",
  });
  registerStrategy(
      {
          .name = "MeetInTheMiddle",
          .expected = "Accepted",
          .time_complexity = "O(2^n * n * log(2^n))",
          .space_complexity = "O(2^n)",
          .tags = {"Array", "Binary Search", "Bitmask", "Sorting"},
          .notes = "Enumerate subset sums by half using bitmask, then binary search the best pairing.",
      },
      minimumDifferenceMitM);
}

int PartitionArrayIntoTwoArraysToMinimizeSumDifferenceSolution::minimumDifference(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2035
}  // namespace leetcode
