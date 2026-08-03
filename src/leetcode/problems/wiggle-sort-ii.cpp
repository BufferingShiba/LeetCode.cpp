#include "leetcode/problems/wiggle-sort-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_324 {
namespace {

void wiggleSortImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n <= 1) return;

  auto it = nums.begin() + n / 2;
  // nth_element moves the n-th smallest element into position it,
  // with smaller elements before it and larger after it.
  std::nth_element(nums.begin(), it, nums.end());
  const int median = *it;

  // Virtual indexing that maps original positions to wiggle positions.
  // For n odd:  [n/2, n/2-1, ..., 0, n-1, n-2, ..., 1].
  // For n even: [n/2, n/2-1, ..., 0, n-1, ...].
  // index mapping: new index = (1 + 2*old) % (n | 1).
  auto reindex = [n](int i) -> int {
    return (1 + 2 * i) % (n | 1);
  };

  // Dutch National Flag three-way partition using the virtual indices.
  int left = 0, i = 0, right = n - 1;
  while (i <= right) {
    const int vi = reindex(i);
    if (nums[vi] > median) {
      std::swap(nums[reindex(left)], nums[vi]);
      ++left;
      ++i;
    } else if (nums[vi] < median) {
      std::swap(nums[vi], nums[reindex(right)]);
      --right;
    } else {
      ++i;
    }
  }
}

}  // namespace

WiggleSortIiSolution::WiggleSortIiSolution() {
  setMetaInfo({.id = 324,
               .title = "Wiggle Sort II",
               .url = "https://leetcode.com/problems/wiggle-sort-ii/"});
  registerStrategy(
      {.name = "nth_element + three-way partition + virtual index",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"quickselect", "virtual-index", "divide-and-conquer"}},
      wiggleSortImpl);
}

void WiggleSortIiSolution::wiggleSort(std::vector<int>& nums) {
  getSolution()(nums);
}

}  // namespace leetcode::problem_324
