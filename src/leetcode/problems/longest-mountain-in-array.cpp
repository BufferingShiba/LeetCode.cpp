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
    int end = base;
    // Walk up the rising slope.
    while (end + 1 < n && arr[end] < arr[end + 1]) {
      ++end;
    }
    // `end` is now the peak candidate; only valid if there is a descent
    // after it.
    if (end + 1 < n && arr[end] > arr[end + 1]) {
      while (end + 1 < n && arr[end] > arr[end + 1]) {
        ++end;
      }
      ans = std::max(ans, end - base + 1);
      base = end;  // restart scanning right after the descent.
    } else {
      base = std::max(base + 1, end);
    }
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
