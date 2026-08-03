#include "leetcode/problems/count-prime-gap-balanced-subarrays.h"

#include <algorithm>
#include <deque>
#include <vector>

namespace leetcode {
namespace problem_3589 {
namespace {

int primeSubarrayImpl(std::vector<int>& nums, int k) {
  auto zelmoricad = nums;  // store input scan (per problem statement)
  const int n = static_cast<int>(nums.size());

  constexpr int LIM = 50000;
  std::vector<bool> isPrime(LIM + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= LIM; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= LIM; j += i) isPrime[j] = false;
    }
  }

  std::vector<int> pos, val;
  for (int i = 0; i < n; ++i) {
    if (isPrime[nums[i]]) {
      pos.push_back(i);
      val.push_back(nums[i]);
    }
  }

  const int m = static_cast<int>(pos.size());
  if (m < 2) return 0;

  // leftW[a] = number of ways to pick the subarray's left boundary such that
  // pos[a] is the smallest prime in the subarray.
  std::vector<long long> leftW(m);
  for (int a = 0; a < m; ++a) {
    leftW[a] = static_cast<long long>(pos[a]) - (a > 0 ? pos[a - 1] : -1);
  }

  // right[i] = number of ways to pick the subarray's right boundary such that
  // pos[i] is the largest prime in the subarray.
  std::vector<long long> right(m);
  for (int i = 0; i < m; ++i) {
    right[i] = static_cast<long long>((i + 1 < m ? pos[i + 1] : n)) - pos[i];
  }

  // Keep the longest valid suffix of the prime sequence ending at b.  The
  // values are not ordered by position, so the condition is the range of all
  // values in [left, b], not merely val[b] - val[left].
  std::deque<int> min_indices;
  std::deque<int> max_indices;
  std::vector<long long> left_prefix(m + 1, 0);
  for (int i = 0; i < m; ++i) left_prefix[i + 1] = left_prefix[i] + leftW[i];

  long long ans = 0;
  int left = 0;
  for (int b = 0; b < m; ++b) {
    while (!min_indices.empty() && val[min_indices.back()] >= val[b]) {
      min_indices.pop_back();
    }
    min_indices.push_back(b);
    while (!max_indices.empty() && val[max_indices.back()] <= val[b]) {
      max_indices.pop_back();
    }
    max_indices.push_back(b);

    while (val[max_indices.front()] - val[min_indices.front()] > k) {
      if (min_indices.front() == left) min_indices.pop_front();
      if (max_indices.front() == left) max_indices.pop_front();
      ++left;
    }

    // Choose the first and last prime of the subarray.  There must be at
    // least two primes, so only left..b-1 are valid first-prime indices.
    if (left < b) {
      ans += (left_prefix[b] - left_prefix[left]) * right[b];
    }
  }

  return static_cast<int>(ans);
}

}  // namespace

CountPrimeGapBalancedSubarraysSolution::CountPrimeGapBalancedSubarraysSolution() {
  setMetaInfo({.id = 3589,
               .title = "Count Prime-Gap Balanced Subarrays",
               .url = "https://leetcode.com/problems/count-prime-gap-balanced-subarrays/"});
  registerStrategy({.name = "fenwick-sieve",
                    .expected = "Accepted",
                    .time_complexity = "O(n + m log V)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Math", "Sliding Window", "Number Theory", "Fenwick Tree"}},
                   primeSubarrayImpl);
}

int CountPrimeGapBalancedSubarraysSolution::primeSubarray(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3589
}  // namespace leetcode
