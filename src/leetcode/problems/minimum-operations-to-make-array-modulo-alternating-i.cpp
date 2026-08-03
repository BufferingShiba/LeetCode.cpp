#include "leetcode/problems/minimum-operations-to-make-array-modulo-alternating-i.h"

#include <algorithm>
#include <cstdint>
#include <vector>

namespace leetcode {
namespace problem_3937 {

int MinimumOperationsToMakeArrayModuloAlternatingISolution::
    minOperationsEnumerateXY(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());

  // 返回把值 v 调整为模 k == m 的最小代价（v >= 1）。
  // 对 v = q*k + r，最近的满足 %k == m 的整数是 q*k+m、
  // (q+1)*k+m、以及 (q-1)*k+m 三者之一（对应不跨/上跨/下跨）。
  auto costOf = [k](int64_t v, int m) -> int64_t {
    const int64_t q = v / k;
    const int64_t c_mid =
        std::llabs(v - (q * k + static_cast<int64_t>(m)));
    const int64_t c_up =
        std::llabs(v - ((q + 1) * k + static_cast<int64_t>(m)));
    const int64_t c_down =
        std::llabs(v - ((q - 1) * k + static_cast<int64_t>(m)));
    return std::min({c_mid, c_up, c_down});
  };

  int64_t best = INT64_MAX;
  for (int x = 0; x < k; ++x) {
    for (int y = 0; y < k; ++y) {
      if (x == y) continue;
      int64_t total = 0;
      for (int i = 0; i < n; ++i) {
        const int target = (i % 2 == 0) ? x : y;
        total += costOf(nums[i], target);
        if (total >= best) break;  // 剪枝
      }
      if (total < best) best = total;
    }
  }
  return static_cast<int>(best);
}

}  // namespace problem_3937
}  // namespace leetcode
