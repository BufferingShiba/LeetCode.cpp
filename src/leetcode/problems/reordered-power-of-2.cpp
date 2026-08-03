#include "leetcode/problems/reordered-power-of-2.h"

namespace leetcode {
namespace problem_869 {

static bool reorderedPowerOf2Impl(int n) {
  // Count digits of n
  int cnt[10] = {0};
  int tmp = n;
  while (tmp > 0) {
    cnt[tmp % 10]++;
    tmp /= 10;
  }

  // Check all powers of 2 up to 10^9 (2^0 ~ 2^29)
  for (int i = 0; i <= 29; ++i) {
    int power = 1 << i;
    int pCnt[10] = {0};
    int p = power;
    while (p > 0) {
      pCnt[p % 10]++;
      p /= 10;
    }

    bool match = true;
    for (int d = 0; d < 10; ++d) {
      if (cnt[d] != pCnt[d]) {
        match = false;
        break;
      }
    }
    if (match) return true;
  }

  return false;
}

ReorderedPowerOf2Solution::ReorderedPowerOf2Solution() {
  setMetaInfo({.id = 869,
               .title = "Reordered Power of 2",
               .url = "https://leetcode.com/problems/reordered-power-of-2/"});

  registerStrategy(
      {.name = "DigitCount",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "Math", "Sorting", "Counting", "Enumeration"}},
      reorderedPowerOf2Impl);
}

}  // namespace problem_869
}  // namespace leetcode
