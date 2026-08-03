#include "leetcode/problems/minimum-cost-to-merge-sorted-lists.h"

#include <climits>
#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3801 {

namespace {

long long minMergeCostImpl(std::vector<std::vector<int>>& lists) {
  int n = static_cast<int>(lists.size());
  int total_masks = 1 << n;

  // --- Global sorted array with source indices ---
  // Multi-way merge of all already-sorted lists
  using Element = std::pair<int, int>;  // value, source_index
  auto cmp = [](const Element& a, const Element& b) {
    return a.first > b.first;  // min-heap
  };
  std::priority_queue<Element, std::vector<Element>, decltype(cmp)> pq(cmp);
  std::vector<int> pointers(n, 0);

  for (int i = 0; i < n; ++i) {
    if (!lists[i].empty()) {
      pq.push({lists[i][0], i});
    }
  }

  std::vector<int> global_values;
  std::vector<int> global_sources;
  while (!pq.empty()) {
    auto [val, src] = pq.top();
    pq.pop();
    global_values.push_back(val);
    global_sources.push_back(src);
    pointers[src]++;
    if (pointers[src] < static_cast<int>(lists[src].size())) {
      pq.push({lists[src][pointers[src]], src});
    }
  }

  int global_size = static_cast<int>(global_values.size());

  // --- precompute length of each original list ---
  std::vector<int> len_of_list(n);
  for (int i = 0; i < n; ++i) {
    len_of_list[i] = static_cast<int>(lists[i].size());
  }

  // --- total_len[mask] ---
  std::vector<int> total_len(total_masks, 0);
  // bit -> index lookup for single-bit masks
  std::vector<int> bit_idx(total_masks, -1);
  for (int i = 0; i < n; ++i) {
    int bit = 1 << i;
    bit_idx[bit] = i;
  }
  for (int mask = 1; mask < total_masks; ++mask) {
    int low = mask & -mask;
    int idx = bit_idx[low];
    total_len[mask] = total_len[mask ^ low] + len_of_list[idx];
  }

  // --- median[mask] ---
  std::vector<long long> median(total_masks, 0);
  for (int mask = 1; mask < total_masks; ++mask) {
    int target = (total_len[mask] - 1) / 2;  // 0-indexed position of median
    int cnt = 0;
    for (int i = 0; i < global_size; ++i) {
      if ((mask >> global_sources[i]) & 1) {
        if (cnt == target) {
          median[mask] = global_values[i];
          break;
        }
        ++cnt;
      }
    }
  }

  // --- DP over masks ---
  const long long INF = LLONG_MAX / 4;
  std::vector<long long> dp(total_masks, INF);

  for (int mask = 1; mask < total_masks; ++mask) {
    if ((mask & (mask - 1)) == 0) {
      // single list — nothing to merge
      dp[mask] = 0;
      continue;
    }

    int low = mask & -mask;
    int remaining = mask ^ low;
    // enumerate non-empty subsets of 'remaining'
    for (int sub = remaining;; sub = (sub - 1) & remaining) {
      int left = sub | low;        // always contains 'low', hence non-empty
      int right = mask ^ left;     // the complement
      if (right != 0) {
        long long cost =
            static_cast<long long>(total_len[left]) + total_len[right] +
            (median[left] > median[right] ? median[left] - median[right]
                                         : median[right] - median[left]);
        long long cand = dp[left] + dp[right] + cost;
        if (cand < dp[mask]) {
          dp[mask] = cand;
        }
      }
      if (sub == 0) break;
    }
  }

  return dp[total_masks - 1];
}

}  // namespace

MinimumCostToMergeSortedListsSolution::
    MinimumCostToMergeSortedListsSolution() {
  setMetaInfo({.id = 3801,
               .title = "Minimum Cost to Merge Sorted Lists",
               .url = "https://leetcode.com/problems/minimum-cost-to-merge-sorted-lists/"});
  registerStrategy(
      {.name = "DP with Bitmask",
       .expected = "Accepted",
       .time_complexity = "O(3^n + 2^n * total_elements)",
       .space_complexity = "O(2^n + total_elements)",
       .tags = {"Dynamic Programming", "Bit Manipulation", "Two Pointers",
                "Binary Search"}},
      minMergeCostImpl);
}

long long MinimumCostToMergeSortedListsSolution::minMergeCost(
    std::vector<std::vector<int>>& lists) {
  return getSolution()(lists);
}

}  // namespace problem_3801
}  // namespace leetcode
