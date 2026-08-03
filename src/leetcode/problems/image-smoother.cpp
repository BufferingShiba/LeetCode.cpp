#include "leetcode/problems/image-smoother.h"

namespace leetcode::problem_661 {

namespace {

std::vector<std::vector<int>> imageSmootherImpl(std::vector<std::vector<int>>& img) {
  int m = static_cast<int>(img.size());
  int n = static_cast<int>(img[0].size());
  std::vector<std::vector<int>> result(m, std::vector<int>(n));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int sum = 0;
      int count = 0;
      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          int ni = i + di;
          int nj = j + dj;
          if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            sum += img[ni][nj];
            ++count;
          }
        }
      }
      result[i][j] = sum / count;
    }
  }

  return result;
}

}  // namespace

ImageSmootherSolution::ImageSmootherSolution() {
  setMetaInfo({.id = 661, .title = "Image Smoother", .url = "https://leetcode.com/problems/image-smoother/"});
  registerStrategy(
      {.name = "Brute Force",
       .expected = "Accepted",
       .time_complexity = "O(m * n)",
       .space_complexity = "O(1) auxiliary (excluding output)",
       .tags = {"Array", "Matrix"}},
      imageSmootherImpl);
}

}  // namespace leetcode::problem_661
