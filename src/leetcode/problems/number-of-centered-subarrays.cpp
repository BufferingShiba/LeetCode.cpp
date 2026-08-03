#include "leetcode/problems/number-of-centered-subarrays.h"

#include <cstdint>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_3804 {

static int centeredSubarraysImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int64_t sum = 0;
    std::unordered_set<int64_t> seen;
    for (int j = i; j < n; ++j) {
      sum += nums[j];
      seen.insert(nums[j]);
      if (seen.count(sum)) {
        ++ans;
      }
    }
  }
  return ans;
}

NumberOfCenteredSubarraysSolution::NumberOfCenteredSubarraysSolution() {
  setMetaInfo({.id = 3804,
               .title = "Number of Centered Subarrays",
               .url = "https://leetcode.com/problems/number-of-centered-subarrays/"});
  registerStrategy(
      {.name = "EnumerationWithHashSet",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Enumeration"}},
      centeredSubarraysImpl);
}

int NumberOfCenteredSubarraysSolution::centeredSubarrays(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3804
}  // namespace leetcode
