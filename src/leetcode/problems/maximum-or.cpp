#include "leetcode/problems/maximum-or.h"

namespace leetcode {
namespace problem_2680 {

namespace {

// 关键洞察：最多 k 次操作，最优点是把所有 k 次集中用在同一个元素上（一次左移 k 位）。
// 因为若分散在多个元素，最高位提升小于 k，收益远低于集中一个元素的贡献。
// 对每个 i，结果为 (nums[i] << k) | others[i]，其中 others[i] 为除 i 外所有元素的 OR。
// 用前缀/后缀 OR 计算 others[i] 达到 O(n)。
long long maximumOr(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());

  // 前缀 OR 和后缀 OR（包括当前位之后）
  std::vector<long long> prefixOr(n + 1, 0);
  std::vector<long long> suffixOr(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    prefixOr[i + 1] = prefixOr[i] | nums[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    suffixOr[i] = suffixOr[i + 1] | nums[i];
  }

  long long best = 0;
  for (int i = 0; i < n; ++i) {
    long long others = prefixOr[i] | suffixOr[i + 1];
    long long candidate = (static_cast<long long>(nums[i]) << k) | others;
    if (candidate > best) best = candidate;
  }
  return best;
}

}  // namespace

MaximumOrSolution::MaximumOrSolution() {
  setMetaInfo({.id = 2680,
               .title = "Maximum OR",
               .url = "https://leetcode.com/problems/maximum-or/"});
  registerStrategy(
      {.name = "greedy-concentrate-k",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Bit Manipulation", "Prefix Sum"}},
      maximumOr);
}

}  // namespace problem_2680
}  // namespace leetcode
