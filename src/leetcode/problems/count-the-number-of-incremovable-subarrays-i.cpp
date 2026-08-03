#include "leetcode/problems/count-the-number-of-incremovable-subarrays-i.h"

namespace leetcode {
namespace problem_2970 {

static int incremovableSubarrayCountImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int count = 0;

  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      bool ok = true;
      int prev = -1;
      for (int i = 0; i < n; ++i) {
        if (i >= l && i <= r) continue;
        if (prev != -1 && nums[i] <= prev) {
          ok = false;
          break;
        }
        prev = nums[i];
      }
      if (ok) ++count;
    }
  }
  return count;
}

int CountTheNumberOfIncremovableSubarraysISolution::incremovableSubarrayCount(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

CountTheNumberOfIncremovableSubarraysISolution::CountTheNumberOfIncremovableSubarraysISolution() {
  setMetaInfo({.id = 2970,
               .title = "Count the Number of Incremovable Subarrays I",
               .url = "https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/"});
  registerStrategy(
      {.name = "enumeration",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      incremovableSubarrayCountImpl);
}

}  // namespace problem_2970
}  // namespace leetcode
