#include "leetcode/problems/longest-alternating-subarray.h"

#include <vector>

namespace leetcode {
namespace problem_2765 {

namespace {

int alternatingSubarrayImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int best = -1;
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i + 1] != nums[i] + 1) {
      continue;
    }
    int len = 2;
    for (int j = i + 2; j < n; ++j) {
      if (nums[j] == nums[i] + ((j - i) % 2)) {
        ++len;
      } else {
        break;
      }
    }
    if (len > best) {
      best = len;
    }
  }
  return best;
}

}  // namespace

LongestAlternatingSubarraySolution::LongestAlternatingSubarraySolution() {
  setMetaInfo({.id = 2765,
               .title = "Longest Alternating Subarray",
               .url = "https://leetcode.com/problems/longest-alternating-subarray/"});
  registerStrategy(
      {.name = "enumeration",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      alternatingSubarrayImpl);
}

int LongestAlternatingSubarraySolution::alternatingSubarray(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2765
}  // namespace leetcode
