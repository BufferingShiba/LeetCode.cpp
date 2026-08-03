#include "leetcode/problems/find-the-smallest-balanced-index.h"

#include <cstdint>
#include <limits>

namespace leetcode {
namespace problem_3862 {

namespace {

// Maximum possible left sum: n * 10^9 <= 10^5 * 10^9 = 10^14.
constexpr long long kMaxLeftSum = 100000LL * 1000000000LL;
// Sentinel used for products that exceed kMaxLeftSum (never equal to any left sum).
constexpr long long kOvershoot = kMaxLeftSum + 1;

long long CapProduct(long long value) {
  return value > kMaxLeftSum ? kOvershoot : value;
}

int smallestBalancedIndexImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());

  // suffixProduct[i] = capped product of nums[i..n-1].
  std::vector<long long> suffixProduct(n + 1, 1);
  for (int i = n - 1; i >= 0; --i) {
    const long long value = nums[i];
    long long current;
    if (value != 0 && suffixProduct[i + 1] > kMaxLeftSum / value) {
      current = kOvershoot;
    } else {
      current = CapProduct(suffixProduct[i + 1] * value);
    }
    suffixProduct[i] = current;
  }

  long long leftSum = 0;
  for (int i = 0; i < n; ++i) {
    long long rightProduct = suffixProduct[i + 1];
    if (leftSum == rightProduct) {
      return i;
    }
    leftSum += static_cast<long long>(nums[i]);
  }

  return -1;
}

}  // namespace

FindTheSmallestBalancedIndexSolution::FindTheSmallestBalancedIndexSolution() {
  setMetaInfo({.id = 3862,
               .title = "Find the Smallest Balanced Index",
               .url = "https://leetcode.com/problems/find-the-smallest-balanced-index/"});
  registerStrategy({.name = "PrefixSumSuffixProduct",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Prefix Sum"},
                    .notes = "Capped suffix product to avoid overflow; compare with prefix sum."},
                   &smallestBalancedIndexImpl);
}

int FindTheSmallestBalancedIndexSolution::smallestBalancedIndex(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3862
}  // namespace leetcode
