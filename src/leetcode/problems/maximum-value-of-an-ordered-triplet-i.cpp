#include "leetcode/problems/maximum-value-of-an-ordered-triplet-i.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2873 {

static long long maximumTripletValueImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());

  // suffix_max[k] = max(nums[k..n-1])
  std::vector<int> suffix_max(n);
  suffix_max[n - 1] = nums[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suffix_max[i] = std::max(nums[i], suffix_max[i + 1]);
  }

  int prefix_max = nums[0];
  long long ans = 0;

  // enumerate middle index j
  for (int j = 1; j < n - 1; ++j) {
    long long diff = static_cast<long long>(prefix_max) - nums[j];
    long long val = diff * suffix_max[j + 1];
    if (val > ans) {
      ans = val;
    }
    if (nums[j] > prefix_max) {
      prefix_max = nums[j];
    }
  }

  return ans;
}

MaximumValueOfAnOrderedTripletISolution::MaximumValueOfAnOrderedTripletISolution() {
  setMetaInfo({.id = 2873,
               .title = "Maximum Value of an Ordered Triplet I",
               .url = "https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/"});

  registerStrategy(
      {.name = "Prefix and Suffix Max",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Prefix Sum"}},
      maximumTripletValueImpl);
}

long long MaximumValueOfAnOrderedTripletISolution::maximumTripletValue(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2873
}  // namespace leetcode
