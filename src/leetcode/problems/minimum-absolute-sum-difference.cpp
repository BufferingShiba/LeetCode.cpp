#include "leetcode/problems/minimum-absolute-sum-difference.h"

#include <algorithm>
#include <cstdlib>
#include <cmath>

namespace leetcode {
namespace problem_1818 {

namespace {

constexpr long long kMod = 1000000007LL;

// 排序 + 二分查找：
// 对每个位置 i，在 nums1 中找最接近 nums2[i] 的值 v，
// 那么用该值替换 nums1[i] 的最大改进量 maxDelta 即最优解改进。
int minAbsoluteSumDiff(std::vector<int>& nums1, std::vector<int>& nums2) {
  const int n = static_cast<int>(nums1.size());
  std::vector<int> sorted = nums1;
  std::sort(sorted.begin(), sorted.end());

  long long total = 0;
  long long maxDelta = 0;
  for (int i = 0; i < n; ++i) {
    const long long orig = std::llabs(static_cast<long long>(nums1[i]) - nums2[i]);
    total += orig;

    // 在 sorted 中二分查找最接近 nums2[i] 的值。
    const long long target = nums2[i];
    auto it = std::lower_bound(sorted.begin(), sorted.end(), target);
    long long best = orig;  // 初始为不替换的情况（nums1[i] 本身在 sorted 中）
    if (it != sorted.end()) {
      best = std::min(best, std::llabs(*it - target));
    }
    if (it != sorted.begin()) {
      auto prev = it - 1;
      best = std::min(best, std::llabs(*prev - target));
    }

    const long long delta = orig - best;
    if (delta > maxDelta) {
      maxDelta = delta;
    }
  }

  return static_cast<int>((total - maxDelta) % kMod);
}

}  // namespace

MinimumAbsoluteSumDifferenceSolution::MinimumAbsoluteSumDifferenceSolution() {
  setMetaInfo({.id = 1818,
               .title = "Minimum Absolute Sum Difference",
               .url = "https://leetcode.com/problems/minimum-absolute-sum-difference/"});
  registerStrategy({"SortAndBinarySearch", "Accepted", "O(n log n)", "O(n)",
                     {"Array", "Binary Search", "Sorting"}},
                    minAbsoluteSumDiff);
}

}  // namespace problem_1818
}  // namespace leetcode
