#include "leetcode/problems/adjacent-increasing-subarrays-detection-i.h"

namespace leetcode {
namespace problem_3349 {

static bool hasIncreasingSubarraysImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  std::vector<bool> inc(n, false);

  // Precompute: inc[i] = whether subarray starting at i (length k) is strictly increasing
  for (int i = 0; i + k <= n; ++i) {
    bool ok = true;
    for (int j = i; j < i + k - 1; ++j) {
      if (nums[j] >= nums[j + 1]) {
        ok = false;
        break;
      }
    }
    inc[i] = ok;
  }

  // Check adjacent pairs
  for (int i = 0; i + 2 * k <= n; ++i) {
    if (inc[i] && inc[i + k]) {
      return true;
    }
  }
  return false;
}

AdjacentIncreasingSubarraysDetectionISolution::AdjacentIncreasingSubarraysDetectionISolution() {
  setMetaInfo({.id = 3349,
               .title = "Adjacent Increasing Subarrays Detection I",
               .url = "https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/"});
  registerStrategy({.name = "PrecomputeIncreasingSegments",
                    .expected = "Accepted",
                    .time_complexity = "O(n*k)",
                    .space_complexity = "O(n)",
                    .tags = {"Array"}},
                   hasIncreasingSubarraysImpl);
}

bool AdjacentIncreasingSubarraysDetectionISolution::hasIncreasingSubarrays(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3349
}  // namespace leetcode
