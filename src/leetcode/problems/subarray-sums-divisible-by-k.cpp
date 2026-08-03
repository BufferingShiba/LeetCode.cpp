#include "leetcode/problems/subarray-sums-divisible-by-k.h"

#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_974 {

static int subarraysDivByKImpl(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> count;
  count[0] = 1;  // 空前缀的和为 0，余数为 0

  int prefix = 0;
  int ans = 0;

  for (int x : nums) {
    prefix += x;
    // 保证余数非负：[0, k-1]
    int rem = ((prefix % k) + k) % k;
    ans += count[rem];
    ++count[rem];
  }

  return ans;
}

SubarraySumsDivisibleByKSolution::SubarraySumsDivisibleByKSolution() {
  setMetaInfo({.id = 974,
               .title = "Subarray Sums Divisible by K",
               .url = "https://leetcode.com/problems/subarray-sums-divisible-by-k/"});

  registerStrategy(
      {.name = "Prefix Sum with Hash Map",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Hash Table", "Prefix Sum"}},
      subarraysDivByKImpl);
}

int SubarraySumsDivisibleByKSolution::subarraysDivByK(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_974
}  // namespace leetcode
