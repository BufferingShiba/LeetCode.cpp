#include "leetcode/problems/remove-duplicates-from-sorted-array-ii.h"

#include <vector>

namespace leetcode {
namespace problem_80 {
namespace {

int removeDuplicatesImpl(std::vector<int>& nums) {
  int write = 0;
  for (int read = 0; read < (int)nums.size(); ++read) {
    if (write < 2 || nums[read] != nums[write - 2]) {
      nums[write++] = nums[read];
    }
  }
  return write;
}

}  // namespace

RemoveDuplicatesFromSortedArrayIiSolution::RemoveDuplicatesFromSortedArrayIiSolution() {
  setMetaInfo({.id = 80,
               .title = "Remove Duplicates from Sorted Array II",
               .url = "https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/"});
  registerStrategy({.name = "two-pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers"}},
                   removeDuplicatesImpl);
}

int RemoveDuplicatesFromSortedArrayIiSolution::removeDuplicates(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_80
}  // namespace leetcode
