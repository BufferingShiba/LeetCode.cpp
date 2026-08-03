#include "leetcode/problems/make-array-elements-equal-to-zero.h"

#include <vector>

namespace leetcode::problem_3354 {

namespace {

// For each index where nums[i] == 0, try moving left and right.
// Simulate the process and check whether the whole array becomes zero.
int solve(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int valid = 0;

  for (int start = 0; start < n; ++start) {
    if (nums[start] != 0) {
      continue;
    }
    // direction = +1 (right) or -1 (left)
    for (int dir : {1, -1}) {
      std::vector<int> arr = nums;
      int curr = start;
      int d = dir;
      while (curr >= 0 && curr < n) {
        if (arr[curr] == 0) {
          curr += d;
        } else {
          --arr[curr];
          d = -d;
          curr += d;
        }
      }
      bool allZero = true;
      for (int v : arr) {
        if (v != 0) {
          allZero = false;
          break;
        }
      }
      if (allZero) {
        ++valid;
      }
    }
  }
  return valid;
}

}  // namespace

MakeArrayElementsEqualToZeroSolution::MakeArrayElementsEqualToZeroSolution() {
  setMetaInfo({.id = 3354,
               .title = "Make Array Elements Equal to Zero",
               .url = "https://leetcode.com/problems/make-array-elements-equal-to-zero/"});
  registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(n * sum(nums))",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation"}},
      solve);
}

}  // namespace leetcode::problem_3354
