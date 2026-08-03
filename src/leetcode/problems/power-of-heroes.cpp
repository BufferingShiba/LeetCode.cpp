#include "leetcode/problems/power-of-heroes.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_2681 {
namespace {

constexpr long long kMod = 1000000007LL;

// Sort asc, then for each element a[i] as the max of a group, the min can be
// a[j] for j <= i with intermediate elements chosen freely.
// Contribution = a[i]^2 * (a[i] + sum_{j<i} a[j] * 2^(i-j-1)).
int sumOfPowerImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  long long ans = 0;
  long long pow2 = 1;   // 2^k accumulator for terms from previous positions
  long long sumTerm = 0;  // sum_{j<i} a[j] * 2^(i-j-1)
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    long long v = nums[i];
    long long cur = (v % kMod) * (v % kMod) % kMod;
    long long inner = (v % kMod + sumTerm) % kMod;
    ans = (ans + cur * inner) % kMod;
    // advance sumTerm for next index i+1: sum_{j<=i} a[j]*2^(i-j)
    sumTerm = (sumTerm * 2 % kMod + v % kMod) % kMod;
    (void)pow2;
  }
  return static_cast<int>(ans);
}

}  // namespace

PowerOfHeroesSolution::PowerOfHeroesSolution() {
  setMetaInfo({2681, "Power of Heroes",
               "https://leetcode.com/problems/power-of-heroes/"});
  registerStrategy(
      {"SortAndPrefixSum", "Accepted", "O(n log n)", "O(log n) (sort), O(1) extra",
       {"Array", "Math", "Dynamic Programming", "Sorting", "Prefix Sum"},
       "Sort ascending; each a[i] acts as max, min chosen among prefix with 2^(i-j-1) subsets"},
      sumOfPowerImpl);
}

}  // namespace problem_2681
}  // namespace leetcode
