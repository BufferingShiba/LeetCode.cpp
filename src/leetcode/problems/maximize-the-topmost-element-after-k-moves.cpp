#include "leetcode/problems/maximize-the-topmost-element-after-k-moves.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2202 {
namespace {

int maximumTopImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  if (n == 1) {
    // Only element must be popped/re-added in alternation.
    return (k % 2 == 1) ? -1 : nums[0];
  }
  // n >= 2
  int res = -1;
  // Candidates reachable by popping a prefix and (optionally) re-adding.
  if (k >= 1) {
    const int lim = std::min(k - 1, n);
    for (int i = 0; i < lim; ++i) res = std::max(res, nums[i]);
  }
  // Pop the first k elements so nums[k] (if exists) becomes the top.
  if (k <= n - 1) res = std::max(res, nums[k]);
  return res;
}

}  // namespace

MaximizeTheTopmostElementAfterKMovesSolution::
    MaximizeTheTopmostElementAfterKMovesSolution() {
  setMetaInfo({.id = 2202,
               .title = "Maximize the Topmost Element After K Moves",
               .url = "https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/"});
  registerStrategy({.name = "greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(min(k, n))",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy"}},
                   maximumTopImpl);
}

int MaximizeTheTopmostElementAfterKMovesSolution::maximumTop(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2202
}  // namespace leetcode
