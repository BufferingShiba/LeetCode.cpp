#include "leetcode/problems/maximum-sum-with-exactly-k-elements.h"

#include <algorithm>

namespace leetcode {
namespace problem_2656 {

static int maximizeSumImpl(std::vector<int>& nums, int k) {
  const int mx = *std::max_element(nums.begin(), nums.end());
  return mx * k + k * (k - 1) / 2;
}

MaximumSumWithExactlyKElementsSolution::MaximumSumWithExactlyKElementsSolution() {
  setMetaInfo({.id = 2656,
               .title = "Maximum Sum With Exactly K Elements",
               .url = "https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      maximizeSumImpl);
}

int MaximumSumWithExactlyKElementsSolution::maximizeSum(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2656
}  // namespace leetcode
