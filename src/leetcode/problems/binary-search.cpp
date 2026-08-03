#include "leetcode/problems/binary-search.h"

namespace leetcode::problem_704 {

namespace {
int searchImpl(std::vector<int>& nums, int target) {
  int lo = 0;
  int hi = static_cast<int>(nums.size()) - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] < target) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return -1;
}
}  // namespace

BinarySearchSolution::BinarySearchSolution() {
  setMetaInfo(
      {.id = 704,
       .title = "Binary Search",
       .url = "https://leetcode.com/problems/binary-search/"});
  registerStrategy({.name = "IterativeBinarySearch",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Binary Search"}},
                   searchImpl);
}

int BinarySearchSolution::search(std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace leetcode::problem_704
