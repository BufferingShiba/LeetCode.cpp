#include "leetcode/problems/minimum-swaps-to-move-zeros-to-end.h"

#include <vector>

namespace leetcode {
namespace problem_3936 {
namespace {

int minimumSwapsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int zeros = 0;
  for (int x : nums) {
    if (x == 0) ++zeros;
  }
  // The last `zeros` positions must become all zeros. Each non-zero element
  // sitting in this zone needs one zero<->non-zero swap to be fixed.
  int swaps = 0;
  for (int i = n - zeros; i < n; ++i) {
    if (nums[i] != 0) ++swaps;
  }
  return swaps;
}

}  // namespace

MinimumSwapsToMoveZerosToEndSolution::MinimumSwapsToMoveZerosToEndSolution() {
  setMetaInfo({.id = 3936,
               .title = "Minimum Swaps to Move Zeros to End",
               .url =
                   "https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/"});
  registerStrategy(
      {"Two Pointers", "Accepted", "O(n)", "O(1)", {"Array", "Two Pointers"}},
      minimumSwapsImpl);
}

int MinimumSwapsToMoveZerosToEndSolution::minimumSwaps(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3936
}  // namespace leetcode
