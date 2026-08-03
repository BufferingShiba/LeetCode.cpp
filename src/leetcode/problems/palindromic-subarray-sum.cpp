#include "leetcode/problems/palindromic-subarray-sum.h"

#include <algorithm>
#include <cstddef>
#include <vector>

namespace leetcode {
namespace problem_3985 {

namespace {

long long getSumImpl(std::vector<int>& nums) {
  const std::size_t n = nums.size();
  if (n == 0) return 0;

  // Prefix sums (pref[i] = sum of nums[0..i-1]).
  std::vector<long long> pref(n + 1, 0);
  for (std::size_t i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + nums[i];
  }

  long long ans = nums[0];

  // Odd-length palindromes. d1[i] = j means palindrome [i-j+1, i+j-1] (length 2j-1).
  std::vector<int> d1(n);
  for (int i = 0, l = 0, r = -1; i < static_cast<int>(n); ++i) {
    int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
    while (i - k >= 0 && i + k < static_cast<int>(n) &&
           nums[i - k] == nums[i + k]) {
      ++k;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }

  // Even-length palindromes. d2[i] = j means palindrome [i-j, i+j-1] (length 2j).
  std::vector<int> d2(n);
  for (int i = 0, l = 0, r = -1; i < static_cast<int>(n); ++i) {
    int k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
    while (i + k < static_cast<int>(n) && i - k - 1 >= 0 &&
           nums[i + k] == nums[i - k - 1]) {
      ++k;
    }
    d2[i] = k;
    if (i + k - 1 > r) {
      l = i - k;
      r = i + k - 1;
    }
  }

  // Odd centers: sum of [i - d1[i] + 1, i + d1[i] - 1], exclusive hi = i + d1[i].
  for (int i = 0; i < static_cast<int>(n); ++i) {
    int lo = i - d1[i] + 1;
    int hi = i + d1[i];
    ans = std::max(ans, pref[hi] - pref[lo]);
  }

  // Even centers: sum of [i - d2[i], i + d2[i] - 1], exclusive hi = i + d2[i].
  for (int i = 0; i < static_cast<int>(n); ++i) {
    if (d2[i] == 0) continue;
    int lo = i - d2[i];
    int hi = i + d2[i];
    ans = std::max(ans, pref[hi] - pref[lo]);
  }

  return ans;
}

}  // namespace

PalindromicSubarraySumSolution::PalindromicSubarraySumSolution() {
  setMetaInfo({.id = 3985,
               .title = "Palindromic Subarray Sum",
               .url = "https://leetcode.com/problems/palindromic-subarray-sum/"});
  registerStrategy({.name = "Manacher + PrefixSum",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Manacher", "prefix-sum", "palindrome"}},
                   getSumImpl);
}

long long PalindromicSubarraySumSolution::getSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3985
}  // namespace leetcode
