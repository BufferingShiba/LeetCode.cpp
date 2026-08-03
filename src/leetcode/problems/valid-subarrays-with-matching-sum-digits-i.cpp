#include "leetcode/problems/valid-subarrays-with-matching-sum-digits-i.h"

namespace leetcode {
namespace problem_3969 {

namespace {

int firstDigit(long long n) {
  while (n >= 10) {
    n /= 10;
  }
  return static_cast<int>(n);
}

int countValidSubarraysImpl(std::vector<int>& nums, int x) {
  int n = static_cast<int>(nums.size());
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    long long sum = 0;
    for (int j = i; j < n; ++j) {
      sum += nums[j];
      if (sum % 10 == x && firstDigit(sum) == x) {
        ++ans;
      }
    }
  }

  return ans;
}

}  // namespace

ValidSubarraysWithMatchingSumDigitsISolution::
    ValidSubarraysWithMatchingSumDigitsISolution() {
  setMetaInfo({.id = 3969,
               .title = "Valid Subarrays With Matching Sum Digits I",
               .url = "https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/"});

  registerStrategy(
      {.name = "Brute Force",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      countValidSubarraysImpl);
}

int ValidSubarraysWithMatchingSumDigitsISolution::countValidSubarrays(
    std::vector<int>& nums, int x) {
  return getSolution()(nums, x);
}

}  // namespace problem_3969
}  // namespace leetcode
