#include "leetcode/problems/rotate-non-negative-elements.h"

#include <vector>

namespace leetcode {
namespace problem_3819 {

namespace {

// Extract non-negative elements, left-rotate them by k positions cyclically,
// and write them back into the original non-negative positions.
std::vector<int> rotateElementsImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());

  // Collect non-negative values in their original relative order.
  std::vector<int> positives;
  positives.reserve(n);
  for (int v : nums) {
    if (v >= 0) positives.push_back(v);
  }

  int m = static_cast<int>(positives.size());
  if (m > 0) {
    int shift = k % m;
    if (shift != 0) {
      // Left rotate by shift.
      std::vector<int> rotated(m);
      for (int i = 0; i < m; ++i) {
        rotated[i] = positives[(i + shift) % m];
      }
      positives.swap(rotated);
    }
  }

  // Write rotated values back into non-negative positions.
  int idx = 0;
  for (int& v : nums) {
    if (v >= 0) {
      v = positives[idx++];
    }
  }
  return nums;
}

}  // namespace

RotateNonNegativeElementsSolution::RotateNonNegativeElementsSolution() {
  setMetaInfo({3819, "Rotate Non Negative Elements",
               "https://leetcode.com/problems/rotate-non-negative-elements/"});
  registerStrategy(
      {.name = "collect-and-rotate",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation"}},
      rotateElementsImpl);
}

std::vector<int> RotateNonNegativeElementsSolution::rotateElements(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3819
}  // namespace leetcode
