#include "leetcode/problems/longest-continuous-increasing-subsequence.h"
#include <algorithm>

namespace leetcode {
namespace problem_674 {

namespace {

int solveLCIS(std::vector<int>& nums) {
  if (nums.empty()) return 0;
  int max_len = 1;
  int cur = 1;
  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[i - 1]) {
      ++cur;
      max_len = std::max(max_len, cur);
    } else {
      cur = 1;
    }
  }
  return max_len;
}

}  // namespace

LongestContinuousIncreasingSubsequenceSolution::LongestContinuousIncreasingSubsequenceSolution() {
  setMetaInfo({.id = 674,
               .title = "Longest Continuous Increasing Subsequence",
               .url = "https://leetcode.com/problems/longest-continuous-increasing-subsequence/"});
  registerStrategy(
      {.name = "SinglePass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers"}},
      solveLCIS);
}

}  // namespace problem_674
}  // namespace leetcode
