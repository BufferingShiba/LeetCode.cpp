#include "leetcode/problems/maximum-value-of-an-ordered-triplet-ii.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_2874 {

static long long maximumTripletValueImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  long long max_i = nums[0];
  long long max_diff = LLONG_MIN;
  long long ans = 0;

  for (int k = 1; k < n; ++k) {
    // current element as k: use the best (nums[i] - nums[j]) so far
    if (max_diff != LLONG_MIN) {
      ans = std::max(ans, max_diff * nums[k]);
    }

    // current element as j: update max_diff with best (max_i - nums[j])
    max_diff = std::max(max_diff, max_i - nums[k]);

    // current element as future i: update max_i
    max_i = std::max(max_i, static_cast<long long>(nums[k]));
  }

  return ans;
}

MaximumValueOfAnOrderedTripletIiSolution::MaximumValueOfAnOrderedTripletIiSolution() {
  setMetaInfo({.id = 2874,
               .title = "Maximum Value of an Ordered Triplet II",
               .url = "https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/"});

  registerStrategy(
      {.name = "one-pass greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      maximumTripletValueImpl);
}

long long MaximumValueOfAnOrderedTripletIiSolution::maximumTripletValue(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2874
}  // namespace leetcode
