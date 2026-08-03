#include "leetcode/problems/search-insert-position.h"

namespace leetcode {
namespace problem_35 {
namespace {

int searchInsertImpl(std::vector<int>& nums, int target) {
  int left = 0;
  int right = static_cast<int>(nums.size());
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

}  // namespace

SearchInsertPositionSolution::SearchInsertPositionSolution() {
  setMetaInfo({.id = 35,
               .title = "Search Insert Position",
               .url = "https://leetcode.com/problems/search-insert-position/"});
  registerStrategy({.name = "binary-search",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Binary Search"}},
                   searchInsertImpl);
}

int SearchInsertPositionSolution::searchInsert(std::vector<int>& nums,
                                                int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_35
}  // namespace leetcode
