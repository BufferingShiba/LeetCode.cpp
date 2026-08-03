#include "leetcode/problems/h-index-ii.h"

#include <vector>

namespace leetcode {
namespace problem_275 {

static int hIndexImpl(std::vector<int>& citations) {
  int n = static_cast<int>(citations.size());
  int left = 0;
  int right = n;  // answer can be 0..n

  while (left < right) {
    int mid = left + (right - left) / 2;
    // There are n - mid papers with citations >= citations[mid]
    if (citations[mid] >= n - mid) {
      // This mid satisfies the condition, try to find a smaller mid
      // (which gives a larger h = n - mid)
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  // h = n - left, where left is the first index satisfying the condition
  return n - left;
}

HIndexIiSolution::HIndexIiSolution() {
  setMetaInfo({.id = 275,
               .title = "H-Index II",
               .url = "https://leetcode.com/problems/h-index-ii/"});
  registerStrategy(
      {.name = "binarySearch",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search"}},
      hIndexImpl);
  setDefaultStrategy();
}

int HIndexIiSolution::hIndex(std::vector<int>& citations) {
  return getSolution()(citations);
}

}  // namespace problem_275
}  // namespace leetcode
