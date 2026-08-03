#include "leetcode/problems/maximum-sum-of-m-non-overlapping-subarrays-i.h"

#include <algorithm>
#include <deque>
#include <vector>

namespace leetcode {
namespace problem_3956 {
namespace {

const long long kNegInf = -(1LL << 62);

// Sliding window / monotonic queue DP.
//
// We select at least one and at most m non-overlapping subarrays, each with
// length in [l, r], maximizing the total sum.
//
// Let P[i] be prefix sum of nums[0..i-1].
//   f[k][i] = max total using at most k subarrays in nums[0..i-1] (zero allowed).
//   A[k][i] = max total using at most k subarrays in nums[0..i-1] with at least
//             one subarray selected (-INF if impossible).
//
// For a subarray ending at prefix i with length len in [l, r] (start = i-len):
//   value = (P[i] - P[i-len]) + f[k-1][i-len]
//         = P[i] + (f[k-1][t] - P[t]),  t = i-len in [i-r, i-l].
//
// The term max over t in [i-r, i-l] of (f[k-1][t] - P[t]) is a fixed-width
// sliding-window maximum, handled by a monotonic deque in O(1) amortized.
// Total time O(n*m), space O(n).
long long maximumSumImpl(std::vector<int>& nums, int m, int l, int r) {
  const int n = static_cast<int>(nums.size());

  std::vector<long long> P(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    P[i + 1] = P[i] + nums[i];
  }

  // f_prev is row (k-1) with at-most semantics (f[0][i] = 0 for all i).
  std::vector<long long> f_prev(n + 1, 0);

  long long answer = kNegInf;
  std::vector<long long> val(n + 1, 0);
  std::vector<long long> smax(n + 1, kNegInf);

  for (int k = 1; k <= m; ++k) {
    // val[t] = f_prev[t] - P[t]
    for (int t = 0; t <= n; ++t) {
      val[t] = f_prev[t] - P[t];
    }

    // Compute sliding window maximum over t in [i-r, i-l] (clamped to valid).
    std::deque<int> dq;
    for (int i = 0; i <= n; ++i) {
      int addIdx = i - l;
      if (addIdx >= 0) {
        while (!dq.empty() && val[dq.back()] <= val[addIdx]) {
          dq.pop_back();
        }
        dq.push_back(addIdx);
      }
      int low = i - r;
      while (!dq.empty() && dq.front() < low) {
        dq.pop_front();
      }
      smax[i] = dq.empty() ? kNegInf : val[dq.front()];
    }

    // Build row k: at-most (zero allowed) and at-least-one versions.
    std::vector<long long> f_cur(n + 1, kNegInf);
    std::vector<long long> A_cur(n + 1, kNegInf);
    f_cur[0] = 0;
    A_cur[0] = kNegInf;  // cannot select anything from empty prefix.
    for (int i = 1; i <= n; ++i) {
      f_cur[i] = std::max(f_cur[i - 1], P[i] + smax[i]);
      A_cur[i] = std::max(A_cur[i - 1], P[i] + smax[i]);
      if (f_cur[i] == kNegInf) f_cur[i] = 0;  // at-most: empty allowed
    }

    if (k == m) {
      answer = A_cur[n];
    }
    f_prev = std::move(f_cur);
  }

  return answer;
}

}  // namespace

MaximumSumOfMNonOverlappingSubarraysISolution::
    MaximumSumOfMNonOverlappingSubarraysISolution() {
  setMetaInfo({
      .id = 3956,
      .title = "Maximum Sum of M Non-Overlapping Subarrays I",
      .url = "https://leetcode.com/problems/maximum-sum-of-m-non-overlapping-subarrays-i/",
  });
  registerStrategy(
      {
          .name = "SlidingWindowMonotonicQueue",
          .expected = "Accepted",
          .time_complexity = "O(n*m)",
          .space_complexity = "O(n)",
          .tags = {"Dynamic Programming", "Sliding Window", "Monotonic Queue", "Prefix Sum"},
      },
      maximumSumImpl);
}

long long MaximumSumOfMNonOverlappingSubarraysISolution::maximumSum(
    std::vector<int>& nums, int m, int l, int r) {
  return getSolution()(nums, m, l, r);
}

}  // namespace problem_3956
}  // namespace leetcode
