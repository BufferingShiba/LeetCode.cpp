#include "leetcode/problems/count-stable-subarrays.h"

#include <algorithm>

namespace leetcode {
namespace problem_3748 {

static std::vector<long long> countStableSubarraysImpl(
    std::vector<int>& nums,
    std::vector<std::vector<int>>& queries) {
  int n = static_cast<int>(nums.size());

  // 1. Find all "bad" positions where nums[i] > nums[i+1]
  std::vector<int> bad_positions;
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i] > nums[i + 1]) {
      bad_positions.push_back(i);
    }
  }

  // 2. Build non-decreasing segments
  struct Segment {
    int start;
    int end;  // inclusive
    long long contrib;  // len*(len+1)/2
  };

  std::vector<Segment> segments;
  std::vector<int> seg_starts;  // for binary search
  std::vector<long long> prefix_contrib;  // prefix sum of contrib

  int seg_start = 0;
  int bad_idx = 0;
  int m = static_cast<int>(bad_positions.size());

  for (int i = 0; i < n; ++i) {
    if (bad_idx < m && bad_positions[bad_idx] == i) {
      int len = i - seg_start + 1;
      long long contrib = static_cast<long long>(len) * (len + 1) / 2;
      segments.push_back({seg_start, i, contrib});
      seg_starts.push_back(seg_start);
      seg_start = i + 1;
      ++bad_idx;
    }
  }
  // Last segment
  {
    int len = n - seg_start;
    long long contrib = static_cast<long long>(len) * (len + 1) / 2;
    segments.push_back({seg_start, n - 1, contrib});
    seg_starts.push_back(seg_start);
  }

  int seg_cnt = static_cast<int>(segments.size());
  prefix_contrib.resize(seg_cnt + 1, 0);
  for (int i = 0; i < seg_cnt; ++i) {
    prefix_contrib[i + 1] = prefix_contrib[i] + segments[i].contrib;
  }

  // 3. Answer queries
  std::vector<long long> ans;
  ans.reserve(queries.size());

  for (const auto& q : queries) {
    int L = q[0], R = q[1];

    auto it = std::upper_bound(seg_starts.begin(), seg_starts.end(), L);
    int seg_L = static_cast<int>(it - seg_starts.begin()) - 1;

    it = std::upper_bound(seg_starts.begin(), seg_starts.end(), R);
    int seg_R = static_cast<int>(it - seg_starts.begin()) - 1;

    if (seg_L == seg_R) {
      int len = R - L + 1;
      ans.push_back(static_cast<long long>(len) * (len + 1) / 2);
    } else {
      long long total = 0;

      // Left partial segment
      int left_len = segments[seg_L].end - L + 1;
      total += static_cast<long long>(left_len) * (left_len + 1) / 2;

      // Right partial segment
      int right_len = R - segments[seg_R].start + 1;
      total += static_cast<long long>(right_len) * (right_len + 1) / 2;

      // Full segments in between
      if (seg_L + 1 <= seg_R - 1) {
        total += prefix_contrib[seg_R] - prefix_contrib[seg_L + 1];
      }

      ans.push_back(total);
    }
  }

  return ans;
}

CountStableSubarraysSolution::CountStableSubarraysSolution() {
  setMetaInfo({.id = 3748, .title = "Count Stable Subarrays", .url = "https://leetcode.com/problems/count-stable-subarrays/"});
  registerStrategy({
    .name = "PrefixSumBinarySearch",
    .expected = "Accepted",
    .time_complexity = "O((n + q) log n)",
    .space_complexity = "O(n)",
    .tags = {"Array", "Binary Search", "Prefix Sum"}
  }, countStableSubarraysImpl);
}

std::vector<long long> CountStableSubarraysSolution::countStableSubarrays(
    std::vector<int>& nums,
    std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_3748
}  // namespace leetcode
