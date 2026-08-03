#include "leetcode/problems/count-the-number-of-good-subarrays.h"

#include <unordered_map>
#include <vector>

namespace leetcode::problem_2537 {

static long long countGoodImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  std::unordered_map<int, int> freq;
  long long pairs = 0;
  long long ans = 0;

  int r = 0;
  for (int l = 0; l < n; ++l) {
    // expand right until pairs >= k
    while (r < n && pairs < k) {
      int val = nums[r];
      int cnt = freq[val];
      pairs += cnt;  // new val forms cnt new pairs with existing ones
      freq[val] = cnt + 1;
      ++r;
    }
    if (pairs >= k) {
      // all subarrays starting at l, ending at >= r-1 are good
      ans += n - r + 1;
    }
    // shrink from left: remove nums[l]
    int val = nums[l];
    int cnt = freq[val];
    // removing one occurrence: pairs decrease by (cnt - 1)
    pairs -= cnt - 1;
    freq[val] = cnt - 1;
    if (freq[val] == 0) {
      freq.erase(val);
    }
  }

  return ans;
}

CountTheNumberOfGoodSubarraysSolution::CountTheNumberOfGoodSubarraysSolution() {
  setMetaInfo({.id = 2537,
               .title = "Count the Number of Good Subarrays",
               .url = "https://leetcode.com/problems/count-the-number-of-good-subarrays/"});
  registerStrategy(
      {.name = "Sliding Window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Sliding Window"}},
      countGoodImpl);
}

long long CountTheNumberOfGoodSubarraysSolution::countGood(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_2537
