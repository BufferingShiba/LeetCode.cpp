#include "leetcode/problems/divide-an-array-into-subarrays-with-minimum-cost-i.h"

#include <algorithm>

namespace leetcode {
namespace problem_3010 {

namespace {

int minimumCostImpl(std::vector<int>& nums) {
  // The first subarray always starts at nums[0], so nums[0] is included.
  // The other two subarrays' first elements come from nums[1..n-1];
  // pick the two smallest ones.
  std::vector<int> rest(nums.begin() + 1, nums.end());
  std::sort(rest.begin(), rest.end());
  return nums[0] + rest[0] + rest[1];
}

}  // namespace

DivideAnArrayIntoSubarraysWithMinimumCostISolution::
    DivideAnArrayIntoSubarraysWithMinimumCostISolution() {
  setMetaInfo({.id = 3010,
               .title = "Divide an Array Into Subarrays With Minimum Cost I",
               .url = "https://leetcode.com/problems/divide-an-array-into-"
                      "subarrays-with-minimum-cost-i/"});
  registerStrategy({.name = "GreedySort",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Sorting", "Greedy"}},
                   minimumCostImpl);
}

int DivideAnArrayIntoSubarraysWithMinimumCostISolution::minimumCost(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3010
}  // namespace leetcode
