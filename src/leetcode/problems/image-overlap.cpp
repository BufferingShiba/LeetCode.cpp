#include "leetcode/problems/image-overlap.h"

#include <algorithm>
#include <utility>

namespace leetcode::problem_835 {

namespace {

int largestOverlapImpl(std::vector<std::vector<int>>& img1,
                       std::vector<std::vector<int>>& img2) {
  const int n = static_cast<int>(img1.size());

  std::vector<std::pair<int, int>> ones1;
  std::vector<std::pair<int, int>> ones2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (img1[i][j] == 1) ones1.emplace_back(i, j);
      if (img2[i][j] == 1) ones2.emplace_back(i, j);
    }
  }

  // 统计每个偏移量 (dr, dc) 能产生的重叠 1 的数量。
  // 偏移量范围是 [-(n-1), n-1]，编码为 dr*(2n-1) + dc + (n-1) 防负。
  const int base = n - 1;
  const int width = 2 * n - 1;
  std::vector<int> counts(width * width, 0);

  int best = 0;
  for (const auto& [i1, j1] : ones1) {
    for (const auto& [i2, j2] : ones2) {
      const int dr = i2 - i1;
      const int dc = j2 - j1;
      const int idx = (dr + base) * width + (dc + base);
      int v = ++counts[idx];
      if (v > best) best = v;
    }
  }
  return best;
}

}  // namespace

ImageOverlapSolution::ImageOverlapSolution() {
  setMetaInfo({.id = 835,
               .title = "Image Overlap",
               .url = "https://leetcode.com/problems/image-overlap/"});

  registerStrategy(
      {.name = "offset_counter",
       .expected = "Accepted",
       .time_complexity = "O(n^4)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Matrix"}},
      largestOverlapImpl);
}

int ImageOverlapSolution::largestOverlap(
    std::vector<std::vector<int>>& img1,
    std::vector<std::vector<int>>& img2) {
  return getSolution()(img1, img2);
}

}  // namespace leetcode::problem_835
