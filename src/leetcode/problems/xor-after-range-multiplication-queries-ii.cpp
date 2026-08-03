#include "leetcode/problems/xor-after-range-multiplication-queries-ii.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

namespace leetcode::problem_3655 {

namespace {
constexpr int MOD = 1'000'000'007;

int xorAfterQueriesImpl(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
  int n = static_cast<int>(nums.size());
  int q = static_cast<int>(queries.size());

  int B = static_cast<int>(std::sqrt(n));
  if (B < 1) B = 1;

  // Precompute modular inverses for v up to 100000 (linear algorithm)
  constexpr int MAX_V = 100'000;
  std::vector<int> inv_table(MAX_V + 1);
  inv_table[1] = 1;
  for (int i = 2; i <= MAX_V; ++i) {
    inv_table[i] = static_cast<int>((1LL * (MOD - MOD / i) * inv_table[MOD % i]) % MOD);
  }

  // Group small-step queries: small_groups[k][l % k] = list of queries
  std::vector<std::vector<std::vector<std::vector<int>>>> small_groups(B + 1);
  for (int k = 1; k <= B; ++k) {
    small_groups[k].resize(k);
  }

  // Partition queries: large-step processed immediately, small-step collected
  for (const auto& query : queries) {
    int l = query[0], r = query[1], k = query[2], v = query[3];
    if (k > B) {
      // Direct brute-force for large step
      long long factor = v;
      for (int idx = l; idx <= r; idx += k) {
        nums[idx] = static_cast<int>((1LL * nums[idx] * factor) % MOD);
      }
    } else {
      small_groups[k][l % k].push_back(query);
    }
  }

  // Process small-step queries with event-driven scan on each arithmetic progression
  for (int k = 1; k <= B; ++k) {
    for (int r_mod = 0; r_mod < k; ++r_mod) {
      const auto& group = small_groups[k][r_mod];
      if (group.empty()) continue;

      // Build events: (position, factor)
      std::vector<std::pair<int, int>> events;
      events.reserve(group.size() * 2);
      for (const auto& qry : group) {
        int l = qry[0], r = qry[1], v = qry[3];
        int last = l + ((r - l) / k) * k;
        events.emplace_back(l, v);
        if (last + k < n) {
          events.emplace_back(last + k, inv_table[v]);
        }
      }
      std::sort(events.begin(), events.end());

      // Scan the arithmetic progression i = r_mod, r_mod+k, r_mod+2k, ...
      size_t ev_idx = 0;
      long long cur = 1;
      for (int i = r_mod; i < n; i += k) {
        while (ev_idx < events.size() && events[ev_idx].first == i) {
          cur = cur * events[ev_idx].second % MOD;
          ++ev_idx;
        }
        if (cur != 1) {
          nums[i] = static_cast<int>((1LL * nums[i] * cur) % MOD);
        }
      }
    }
  }

  // Compute final XOR
  int ans = 0;
  for (int x : nums) {
    ans ^= x;
  }
  return ans;
}
}  // anonymous namespace

XorAfterRangeMultiplicationQueriesIiSolution::XorAfterRangeMultiplicationQueriesIiSolution() {
  setMetaInfo({.id = 3655, .title = "XOR After Range Multiplication Queries II", .url = "https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/"});
  registerStrategy({
    .name = "sqrt_decomposition",
    .expected = "Accepted",
    .time_complexity = "O((n + q) * sqrt(n))",
    .space_complexity = "O(n + q)",
    .tags = {"Array", "Divide and Conquer", "Prefix Sum", "Sqrt Decomposition"}
  }, xorAfterQueriesImpl);
}

int XorAfterRangeMultiplicationQueriesIiSolution::xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace leetcode::problem_3655
