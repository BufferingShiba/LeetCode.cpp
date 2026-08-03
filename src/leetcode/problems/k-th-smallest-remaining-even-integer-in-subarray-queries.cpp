#include "leetcode/problems/k-th-smallest-remaining-even-integer-in-subarray-queries.h"

#include <algorithm>

namespace leetcode {
namespace problem_3911 {

namespace {

// For a query [l, r, k]: from the evens 2,4,6,... remove values that appear in
// nums[l..r]. Answer is the k-th smallest remaining even.
//
// We binary search the answer x (a positive even). Among 2,4,...,x there are
// x/2 evens total. Some of nums[l..r]'s even values <= x are removed. Let c be
// the number of even values in nums[l..r] that are <= x. Then (# remaining
// evens <= x) = x/2 - c. The answer is the smallest even x with x/2 - c >= k.
//
// With a prefix sum of even-counts over the strictly-increasing nums, c can be
// computed in O(log n): locate the boundary index p of the first value > x via
// upper_bound, then count evens in nums[l..min(r, p-1)].
std::vector<int> kthRemainingIntegerImpl(std::vector<int>& nums,
                                         std::vector<std::vector<int>>& queries) {
  const int n = static_cast<int>(nums.size());

  // pref[i] = number of even values in nums[0..i-1].
  std::vector<int> pref(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + (nums[i] % 2 == 0 ? 1 : 0);
  }

  auto countEvenLE = [&](int l, int r, long long x) -> int {
    // Count even values in nums[l..r] that are <= x.
    auto it = std::upper_bound(nums.begin(), nums.end(), x);
    int p = static_cast<int>(it - nums.begin());  // first index with nums > x
    int hi = std::min(r, p - 1);
    if (hi < l) return 0;
    return pref[hi + 1] - pref[l];
  };

  std::vector<int> ans;
  ans.reserve(queries.size());
  for (const auto& q : queries) {
    int l = q[0];
    int r = q[1];
    long long k = q[2];

    // x/2 - c >= k  <=>  x >= 2*(k + c). The upper bound: at most all removed,
    // so taking x up to 2*(k + n) is always sufficient.
    long long lo = 2;                  // smallest even
    long long hi = 2LL * (k + n + 2);  // safe upper bound
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (mid % 2 != 0) mid -= 1;  // keep mid even
      int c = countEvenLE(l, r, mid);
      if (mid / 2 - c >= k) {
        hi = mid;
      } else {
        lo = mid + 2;
      }
    }
    ans.push_back(static_cast<int>(lo));
  }
  return ans;
}

}  // namespace

KThSmallestRemainingEvenIntegerInSubarrayQueriesSolution::
    KThSmallestRemainingEvenIntegerInSubarrayQueriesSolution() {
  setMetaInfo({
      .id = 3911,
      .title = "K-th Smallest Remaining Even Integer in Subarray Queries",
      .url =
          "https://leetcode.com/problems/k-th-smallest-remaining-even-integer-in-subarray-queries/",
  });
  registerStrategy(
      {
          .name = "prefix-sum-upper-bound-binary-search",
          .expected = "Accepted",
          .time_complexity = "O(q * logV * log n)",
          .space_complexity = "O(n)",
          .tags = {"Array", "Binary Search", "Prefix Sum"},
          .notes =
              "For each query binary-search the answer x over evens; count how "
              "many evens <= x are removed via prefix sum of parity over the "
              "strictly-increasing nums.",
      },
      kthRemainingIntegerImpl);
}

std::vector<int> KThSmallestRemainingEvenIntegerInSubarrayQueriesSolution::
    kthRemainingInteger(std::vector<int>& nums,
                        std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_3911
}  // namespace leetcode
