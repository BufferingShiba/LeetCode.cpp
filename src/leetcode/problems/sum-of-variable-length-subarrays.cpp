#include "leetcode/problems/sum-of-variable-length-subarrays.h"

#include <algorithm>

namespace leetcode {
namespace problem_3427 {

static int subarraySumImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  int total = 0;
  for (int i = 0; i < n; ++i) {
    int start = std::max(0, i - nums[i]);
    total += prefix[i + 1] - prefix[start];
  }
  return total;
}

SumOfVariableLengthSubarraysSolution::SumOfVariableLengthSubarraysSolution() {
  setMetaInfo({.id = 3427,
               .title = "Sum of Variable Length Subarrays",
               .url = "https://leetcode.com/problems/sum-of-variable-length-subarrays/"});
  registerStrategy({.name = "prefix_sum",
                     .expected = "Accepted",
                     .time_complexity = "O(n)",
                     .space_complexity = "O(n)",
                     .tags = {"Array", "Prefix Sum"}},
                   subarraySumImpl);
  setDefaultStrategy();
}

int SumOfVariableLengthSubarraysSolution::subarraySum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3427
}  // namespace leetcode
