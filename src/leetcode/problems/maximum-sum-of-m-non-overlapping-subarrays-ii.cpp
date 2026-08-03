#include "leetcode/problems/maximum-sum-of-m-non-overlapping-subarrays-ii.h"

#include <climits>
#include <deque>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3957 {

namespace {

struct Item {
  int idx;
  long long val;
  int cnt;
};

// Returns (max_dp, count) when each subarray is penalized by lambda.
std::pair<long long, int> solve(const std::vector<int>& nums, int l, int r,
                                 long long lambda) {
  int n = static_cast<int>(nums.size());
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  std::vector<long long> dp(n + 1, 0);
  std::vector<int> cnt(n + 1, 0);
  std::deque<Item> dq;

  for (int i = 1; i <= n; ++i) {
    // Add j = i - l into sliding window
    int add_j = i - l;
    if (add_j >= 0) {
      long long val = dp[add_j] - prefix[add_j];
      int cnt_val = cnt[add_j];
      while (!dq.empty() && (dq.back().val < val ||
                             (dq.back().val == val && dq.back().cnt <= cnt_val))) {
        dq.pop_back();
      }
      dq.push_back({add_j, val, cnt_val});
    }

    // Remove j < i - r from window
    int remove_bound = i - r;
    while (!dq.empty() && dq.front().idx < remove_bound) {
      dq.pop_front();
    }

    // Option 1: skip subarray ending at i
    dp[i] = dp[i - 1];
    cnt[i] = cnt[i - 1];

    // Option 2: take a subarray ending at i (with penalty lambda)
    if (!dq.empty()) {
      long long cand = dq.front().val + prefix[i] - lambda;
      int cand_cnt = dq.front().cnt + 1;
      if (cand > dp[i]) {
        dp[i] = cand;
        cnt[i] = cand_cnt;
      } else if (cand == dp[i] && cand_cnt > cnt[i]) {
        cnt[i] = cand_cnt;
      }
    }
  }

  return {dp[n], cnt[n]};
}

// Maximum sum of a single subarray whose length in [l, r].
long long maxSingleSubarray(const std::vector<int>& nums, int l, int r) {
  int n = static_cast<int>(nums.size());
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  std::deque<std::pair<int, long long>> dq;  // (idx, -prefix[idx])
  long long ans = LLONG_MIN;

  for (int i = 1; i <= n; ++i) {
    int add_j = i - l;
    if (add_j >= 0) {
      long long val = -prefix[add_j];
      while (!dq.empty() && dq.back().second <= val) {
        dq.pop_back();
      }
      dq.push_back({add_j, val});
    }

    int remove_bound = i - r;
    while (!dq.empty() && dq.front().first < remove_bound) {
      dq.pop_front();
    }

    if (!dq.empty()) {
      long long cand = dq.front().second + prefix[i];  // prefix[i] - prefix[j]
      if (cand > ans) ans = cand;
    }
  }

  return ans;
}

long long maximumSumImpl(std::vector<int>& nums, int m, int l, int r) {
  // Binary search lambda (penalty)
  long long lo = 0;
  long long hi = 100000000005LL;  // 1e11 + 5, safe upper bound

  while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    auto [dp_val, cnt_val] = solve(nums, l, r, mid);
    if (cnt_val <= m) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  auto [dp_final, cnt_final] = solve(nums, l, r, lo);

  if (cnt_final == 0) {
    // Must pick at least one subarray; fallback to best single subarray.
    return maxSingleSubarray(nums, l, r);
  }

  return dp_final + lo * m;
}

}  // namespace

MaximumSumOfMNonOverlappingSubarraysIiSolution::
    MaximumSumOfMNonOverlappingSubarraysIiSolution() {
  setMetaInfo({.id = 3957,
               .title = "Maximum Sum of M Non-Overlapping Subarrays II",
               .url = "https://leetcode.com/problems/maximum-sum-of-m-non-overlapping-subarrays-ii/"});

  registerStrategy(
      {.name = "AliensTrick",
       .expected = "Accepted",
       .time_complexity = "O(n log U)",
       .space_complexity = "O(n)",
       .tags = {"Binary Search", "Dynamic Programming", "Sliding Window",
                "Monotonic Queue", "Prefix Sum"}},
      maximumSumImpl);
}

long long MaximumSumOfMNonOverlappingSubarraysIiSolution::maximumSum(
    std::vector<int>& nums, int m, int l, int r) {
  return getSolution()(nums, m, l, r);
}

}  // namespace problem_3957
}  // namespace leetcode
