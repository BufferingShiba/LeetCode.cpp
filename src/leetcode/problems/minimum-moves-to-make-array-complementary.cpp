#include "leetcode/problems/minimum-moves-to-make-array-complementary.h"

#include <algorithm>

namespace leetcode {
namespace problem_1674 {
namespace {

// 差分数组 + 前缀和。
// 对每对 (a, b)，设 lo = min(a, b), hi = max(a, b)。以基础成本 2（双改）出发：
//   - 单改可覆盖 S ∈ [1 + lo, limit + hi]（cost 1）
//   - 双改可覆盖所有 S ∈ [2, 2*limit]（cost 2）
//   - S == a + b 时零改（cost 0）
// 收集所有 n/2 对，用差分累计各 S 的总移动次数，取最小值。
int minMovesImpl(std::vector<int>& nums, int limit) {
  const int n = static_cast<int>(nums.size());
  std::vector<int> diff(2 * limit + 3, 0);

  // 基础成本：全部对用 2 次移动，每个 S 的基线为 2 * (n / 2)。
  const int base = n;  // 2 * (n / 2)

  for (int i = 0; i < n / 2; ++i) {
    const int a = nums[i];
    const int b = nums[n - 1 - i];
    const int lo = std::min(a, b);
    const int hi = std::max(a, b);
    const int sum = a + b;

    // 单改区间 [1 + lo, limit + hi]：成本从 2 降到 1。
    diff[1 + lo] -= 1;
    diff[limit + hi + 1] += 1;
    // 零改点 sum：成本从 1 再降到 0。
    diff[sum] -= 1;
    diff[sum + 1] += 1;
  }

  int best = base;
  int cur = base;
  for (int s = 2; s <= 2 * limit; ++s) {
    cur += diff[s];
    best = std::min(best, cur);
  }
  return best;
}

}  // namespace

MinimumMovesToMakeArrayComplementarySolution::
    MinimumMovesToMakeArrayComplementarySolution() {
  setMetaInfo({1674,
               "Minimum Moves to Make Array Complementary",
               "https://leetcode.com/problems/minimum-moves-to-make-array-complementary/"});
  registerStrategy({.name = "difference-prefix-sum",
                    .expected = "Accepted",
                    .time_complexity = "O(n + limit)",
                    .space_complexity = "O(limit)",
                    .tags = {"Array", "Hash Table", "Prefix Sum"}},
                   minMovesImpl);
}

int MinimumMovesToMakeArrayComplementarySolution::minMoves(
    std::vector<int>& nums, int limit) {
  return getSolution()(nums, limit);
}

}  // namespace problem_1674
}  // namespace leetcode
