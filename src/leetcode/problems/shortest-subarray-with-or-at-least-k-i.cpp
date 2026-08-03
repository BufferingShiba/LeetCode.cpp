#include "leetcode/problems/shortest-subarray-with-or-at-least-k-i.h"

#include <algorithm>
#include <vector>

namespace {

int minimumSubarrayLengthImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  int ans = n + 1;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = i; j < n; ++j) {
      cur |= nums[j];
      if (cur >= k) {
        ans = std::min(ans, j - i + 1);
        break;
      }
    }
  }
  return ans > n ? -1 : ans;
}

}  // namespace

namespace leetcode {
namespace problem_3095 {

ShortestSubarrayWithOrAtLeastKISolution::
    ShortestSubarrayWithOrAtLeastKISolution() {
  setMetaInfo({.id = 3095,
               .title = "Shortest Subarray With OR at Least K I",
               .url = "https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/"});
  registerStrategy(
      {.name = "brute_force",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Bit Manipulation", "Sliding Window"}},
      minimumSubarrayLengthImpl);
}

int ShortestSubarrayWithOrAtLeastKISolution::minimumSubarrayLength(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3095
}  // namespace leetcode
