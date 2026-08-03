#include "leetcode/problems/count-the-number-of-beautiful-subarrays.h"

#include <unordered_map>

namespace leetcode {
namespace problem_2588 {

static long long beautifulSubarraysImpl(std::vector<int>& nums) {
  std::unordered_map<int, long long> prefix_count;
  prefix_count[0] = 1;

  int prefix = 0;
  long long result = 0;

  for (int num : nums) {
    prefix ^= num;
    result += prefix_count[prefix];
    ++prefix_count[prefix];
  }

  return result;
}

CountTheNumberOfBeautifulSubarraysSolution::
    CountTheNumberOfBeautifulSubarraysSolution() {
  setMetaInfo({.id = 2588,
               .title = "Count the Number of Beautiful Subarrays",
               .url = "https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/"});

  registerStrategy(
      {.name = "Prefix XOR + Hash Map",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Bit Manipulation", "Prefix Sum"}},
      beautifulSubarraysImpl);
}

long long CountTheNumberOfBeautifulSubarraysSolution::beautifulSubarrays(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2588
}  // namespace leetcode
