#include "leetcode/problems/minimum-k-to-reduce-array-within-limit.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

namespace leetcode {
namespace problem_3824 {

static int minimumKImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int maxVal = *std::max_element(nums.begin(), nums.end());
  int hi = std::max(maxVal, static_cast<int>(std::ceil(std::sqrt(n))));

  auto check = [&](int k) -> bool {
    std::int64_t total = 0;
    std::int64_t limit = static_cast<std::int64_t>(k) * k;
    for (int x : nums) {
      total += (x + k - 1) / k;  // ceil(x / k)
      if (total > limit) return false;
    }
    return total <= limit;
  };

  int lo = 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

MinimumKToReduceArrayWithinLimitSolution::
    MinimumKToReduceArrayWithinLimitSolution() {
  setMetaInfo({.id = 3824,
               .title = "Minimum K to Reduce Array Within Limit",
               .url = "https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/"});

  registerStrategy(
      {.name = "Binary Search",
       .expected = "Accepted",
       .time_complexity = "O(n log M)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search"}},
      minimumKImpl);

  setDefaultStrategy();
}

int MinimumKToReduceArrayWithinLimitSolution::minimumK(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3824
}  // namespace leetcode
