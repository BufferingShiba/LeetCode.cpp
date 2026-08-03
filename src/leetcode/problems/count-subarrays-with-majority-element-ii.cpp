#include "leetcode/problems/count-subarrays-with-majority-element-ii.h"

namespace leetcode {
namespace problem_3739 {

static long long countMajoritySubarraysImpl(std::vector<int>& nums, int target) {
  int n = static_cast<int>(nums.size());
  int offset = n;
  std::vector<int> cnt(2 * n + 1, 0);
  cnt[0 + offset] = 1;  // P[0] = 0

  long long ans = 0;
  int less = 0;  // 已处理前缀中值 < cur 的个数
  int cur = 0;   // 当前前缀和

  for (int i = 0; i < n; ++i) {
    int val = (nums[i] == target) ? 1 : -1;
    int next = cur + val;

    if (val == 1) {
      // 向上走：值 < next 的 = 原来 < cur 的 + 等于 cur 的
      less = less + cnt[cur + offset];
    } else {
      // 向下走：值 < next 的 = 原来 < cur 的 - 等于 cur-1 的
      less = less - cnt[(cur - 1) + offset];
    }

    ans += less;
    cnt[next + offset]++;
    cur = next;
  }

  return ans;
}

CountSubarraysWithMajorityElementIiSolution::CountSubarraysWithMajorityElementIiSolution() {
  setMetaInfo({.id = 3739,
               .title = "Count Subarrays With Majority Element II",
               .url = "https://leetcode.com/problems/count-subarrays-with-majority-element-ii/"});
  registerStrategy(
      {.name = "Prefix Sum with Frequency Tracking",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Prefix Sum", "Hash Table"}},
      countMajoritySubarraysImpl);
}

long long CountSubarraysWithMajorityElementIiSolution::countMajoritySubarrays(
    std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_3739
}  // namespace leetcode
