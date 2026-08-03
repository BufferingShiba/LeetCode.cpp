#include "leetcode/problems/number-of-excellent-pairs.h"

#include <array>
#include <unordered_set>

namespace leetcode {
namespace problem_2354 {
namespace {

int popcount32(int x) {
  return __builtin_popcount(static_cast<unsigned int>(x));
}

long long countExcellentPairsImpl(std::vector<int>& nums, int k) {
  // Key identity: popcount(a AND b) + popcount(a OR b) = popcount(a) + popcount(b).
  // So condition becomes popcount(a) + popcount(b) >= k.
  //
  // Distinct pairs: dedupe nums, then bucket by popcount. The resulting count
  // only depends on the popcount multiset. For ordered pairs, pick popcount x
  // and y (both values available) with x + y >= k.
  //   - if x == y: contribute freq[x] * freq[x]
  //   - else:      contribute 2 * freq[x] * freq[y]

  std::unordered_set<int> distinct(nums.begin(), nums.end());
  std::array<long long, 31> freq = {};  // nums[i] <= 1e9 < 2^30, so popcount <= 30
  for (int v : distinct) {
    freq[popcount32(v)] += 1;
  }

  long long total = 0;
  for (int x = 0; x <= 30; ++x) {
    if (freq[x] == 0) continue;
    for (int y = x; y <= 30; ++y) {
      if (freq[y] == 0) continue;
      if (x + y < k) continue;
      if (x == y) {
        total += freq[x] * freq[x];
      } else {
        total += 2 * freq[x] * freq[y];
      }
    }
  }
  return total;
}

}  // namespace

NumberOfExcellentPairsSolution::NumberOfExcellentPairsSolution() {
  setMetaInfo({.id = 2354,
               .title = "Number of Excellent Pairs",
               .url = "https://leetcode.com/problems/number-of-excellent-pairs/"});
  registerStrategy(
      {.name = "popcount bucket counting",
       .expected = "Accepted",
       .time_complexity = "O(n log V + 31^2)",
       .space_complexity = "O(n)",
       .tags = {"Bit Manipulation", "Hash Table"},
       .notes = "popcount(a AND b) + popcount(a OR b) = popcount(a) + popcount(b); "
                "bucket unique nums by popcount and count ordered pairs."},
      countExcellentPairsImpl);
}

long long NumberOfExcellentPairsSolution::countExcellentPairs(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2354
}  // namespace leetcode
