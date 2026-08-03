#include "leetcode/problems/remove-element.h"

namespace leetcode {
namespace problem_27 {

namespace {

// Two pointers: write index tracks where the next non-val element goes,
// read index scans the whole array.
int removeElementImpl(std::vector<int>& nums, int val) {
  int write = 0;
  for (int read = 0; read < static_cast<int>(nums.size()); ++read) {
    if (nums[read] != val) {
      nums[write++] = nums[read];
    }
  }
  return write;
}

}  // namespace

RemoveElementSolution::RemoveElementSolution() {
  setMetaInfo({27, "Remove Element", "https://leetcode.com/problems/remove-element/"});

  registerStrategy(
      {.name = "two-pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers"}},
      removeElementImpl);
}

}  // namespace problem_27
}  // namespace leetcode
