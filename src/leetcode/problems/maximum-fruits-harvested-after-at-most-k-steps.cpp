#include "leetcode/problems/maximum-fruits-harvested-after-at-most-k-steps.h"

#include <algorithm>

namespace leetcode {
namespace problem_2106 {
namespace {

// 滑动窗口 + 前缀和。
// 枚举右端点 r，收缩左端点 l，使窗口 [l, r] 内步数不超过 k。
//
// 窗口覆盖 [pos[l], pos[r]]，从 startPos 出发覆盖该区间所需最少步数：
//   - 全部在右侧 (pos[l] >= startPos):  pos[r] - startPos
//   - 全部在左侧 (pos[r] <= startPos):  startPos - pos[l]
//   - 跨过 startPos: (pos[r]-pos[l]) + min(pos[r]-startPos, startPos-pos[l])
//
// 步数随 l 增大单调不减，因此可用单调滑窗线性求解，配合前缀和求窗口总和。
int maxTotalFruitsImpl(std::vector<std::vector<int>>& fruits, int startPos,
                       int k) {
  const int n = static_cast<int>(fruits.size());
  std::vector<int> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + fruits[i][1];
  }

  auto stepsFor = [&](int l, int r) {
    const int leftPos = fruits[l][0];
    const int rightPos = fruits[r][0];
    if (rightPos <= startPos) {
      return startPos - leftPos;
    }
    if (leftPos >= startPos) {
      return rightPos - startPos;
    }
    return (rightPos - leftPos) +
           std::min(rightPos - startPos, startPos - leftPos);
  };

  int best = 0;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    while (l < r && stepsFor(l, r) > k) {
      ++l;
    }
    if (stepsFor(l, r) <= k) {
      best = std::max(best, prefix[r + 1] - prefix[l]);
    }
  }
  return best;
}

}  // namespace

MaximumFruitsHarvestedAfterAtMostKStepsSolution::
    MaximumFruitsHarvestedAfterAtMostKStepsSolution() {
  setMetaInfo({.id = 2106,
               .title = "Maximum Fruits Harvested After at Most K Steps",
               .url = "https://leetcode.com/problems/maximum-fruits-"
                      "harvested-after-at-most-k-steps/"});
  registerStrategy(
      {.name = "sliding-window-prefix",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Sliding Window", "Prefix Sum"}},
      maxTotalFruitsImpl);
}

}  // namespace problem_2106
}  // namespace leetcode
