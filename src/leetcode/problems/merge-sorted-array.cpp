#include "leetcode/problems/merge-sorted-array.h"

#include <vector>

namespace leetcode::problem_88 {

namespace {

// Merge two sorted arrays in-place into nums1 using a backward pointer sweep.
// O(m + n) time, O(1) space.
void mergeImpl(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  int p1 = m - 1;
  int p2 = n - 1;
  int p = m + n - 1;
  while (p1 >= 0 && p2 >= 0) {
    if (nums1[p1] > nums2[p2]) {
      nums1[p--] = nums1[p1--];
    } else {
      nums1[p--] = nums2[p2--];
    }
  }
  while (p2 >= 0) {
    nums1[p--] = nums2[p2--];
  }
}

}  // namespace

MergeSortedArraySolution::MergeSortedArraySolution() {
  setMetaInfo({.id = 88,
               .title = "Merge Sorted Array",
               .url = "https://leetcode.com/problems/merge-sorted-array/"});
  registerStrategy(
      {.name = "backward_two_pointers",
       .expected = "Accepted",
       .time_complexity = "O(m + n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Sorting"}},
      mergeImpl);
}

void MergeSortedArraySolution::merge(std::vector<int>& nums1, int m,
                                     std::vector<int>& nums2, int n) {
  return getSolution()(nums1, m, nums2, n);
}

}  // namespace leetcode::problem_88
