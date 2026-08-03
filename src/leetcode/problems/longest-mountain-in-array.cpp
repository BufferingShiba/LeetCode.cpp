#include "leetcode/problems/longest-mountain-in-array.h"

#include <algorithm>

namespace leetcode {
namespace problem_845 {

static int solution1(vector<int>& arr) {
  int n = static_cast<int>(arr.size());
  if (n < 3) return 0;
  int ans = 0;
  int base = 0;
  while (base < n) {
    int peak = base;
    while (peak + 1 < n && arr[peak] < arr[peak + 1]) {
      ++peak;
    }
    // A descending run without an ascent is not a mountain.
    if (peak == base) {
      ++base;
      continue;
    }

    int end = peak;
    while (end + 1 < n && arr[end] > arr[end + 1]) {
      ++end;
    }
    if (end > peak) {
      ans = std::max(ans, end - base + 1);
    }
    base = std::max(end, base + 1);
  }
  return ans;
}

LongestMountainInArraySolution::LongestMountainInArraySolution() {
  setMetaInfo({
      .id = 845,
      .title = "Longest Mountain in Array",
      .url = "https://leetcode.com/problems/longest-mountain-in-array"
  });
  registerStrategy({
      .name = "Two Pointer Single Pass",
      .expected = "Accepted",
      .time_complexity = "O(n)",
      .space_complexity = "O(1)",
      .tags = {"Two Pointers"},
      .notes =
          "Scan with base/end pointers: walk up the rising slope to find a "
          "peak, then walk down; restart after each descent."
  }, solution1);
}

int LongestMountainInArraySolution::longestMountain(vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_845
}  // namespace leetcode
