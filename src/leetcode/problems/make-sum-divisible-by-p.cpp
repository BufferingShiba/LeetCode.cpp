#include "leetcode/problems/make-sum-divisible-by-p.h"

#include <numeric>
#include <unordered_map>

namespace leetcode::problem_1590 {

namespace {

int minSubarrayImpl(std::vector<int>& nums, int p) {
  long long total = std::accumulate(nums.begin(), nums.end(), 0LL);
  int target = total % p;
  if (target == 0) {
    return 0;
  }

  int n = static_cast<int>(nums.size());
  int ans = n;
  std::unordered_map<int, int> last_pos;
  last_pos[0] = -1;

  long long prefix = 0;
  for (int i = 0; i < n; ++i) {
    prefix += nums[i];
    int cur_mod = prefix % p;
    int need = (cur_mod - target + p) % p;

    auto it = last_pos.find(need);
    if (it != last_pos.end()) {
      ans = std::min(ans, i - it->second);
    }

    last_pos[cur_mod] = i;
  }

  return ans == n ? -1 : ans;
}

}  // namespace

MakeSumDivisibleByPSolution::MakeSumDivisibleByPSolution() {
  setMetaInfo({.id = 1590,
               .title = "Make Sum Divisible by P",
               .url = "https://leetcode.com/problems/make-sum-divisible-by-p/"});
  registerStrategy(
      {.name = "Prefix Sum + Hash Table",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(min(n, p))",
       .tags = {"Array", "Hash Table", "Prefix Sum"}},
      minSubarrayImpl);
}

int MakeSumDivisibleByPSolution::minSubarray(std::vector<int>& nums, int p) {
  return getSolution()(nums, p);
}

}  // namespace leetcode::problem_1590
