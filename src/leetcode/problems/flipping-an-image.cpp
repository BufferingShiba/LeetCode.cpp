#include "leetcode/problems/flipping-an-image.h"

namespace leetcode {
namespace problem_832 {

static std::vector<std::vector<int>> flipAndInvertImageImpl(std::vector<std::vector<int>>& image) {
  int n = static_cast<int>(image.size());
  for (int i = 0; i < n; ++i) {
    int left = 0, right = n - 1;
    while (left <= right) {
      if (left == right) {
        image[i][left] ^= 1;
      } else if (image[i][left] == image[i][right]) {
        image[i][left] ^= 1;
        image[i][right] ^= 1;
      }
      // else: different values → after flip+invert they stay unchanged
      ++left;
      --right;
    }
  }
  return image;
}

FlippingAnImageSolution::FlippingAnImageSolution() {
  setMetaInfo({.id = 832, .title = "Flipping an Image", .url = "https://leetcode.com/problems/flipping-an-image/"});
  registerStrategy(
      {.name = "TwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Bit Manipulation", "Matrix", "Simulation"}},
      flipAndInvertImageImpl);
}

std::vector<std::vector<int>> FlippingAnImageSolution::flipAndInvertImage(std::vector<std::vector<int>>& image) {
  return getSolution()(image);
}

}  // namespace problem_832
}  // namespace leetcode
