#include "leetcode/problems/find-the-grid-of-region-average.h"

#include <vector>

namespace leetcode {
namespace problem_3030 {
namespace {

std::vector<std::vector<int>> resultGridImpl(
    std::vector<std::vector<int>>& image, int threshold) {
  int m = static_cast<int>(image.size());
  int n = static_cast<int>(image[0].size());

  // sum[i][j] accumulates the sum of region-averages covering pixel (i,j),
  // count[i][j] accumulates how many regions cover pixel (i,j).
  std::vector<std::vector<long long>> sum(m, std::vector<long long>(n, 0));
  std::vector<std::vector<int>> count(m, std::vector<int>(n, 0));

  for (int i = 0; i + 2 < m; ++i) {
    for (int j = 0; j + 2 < n; ++j) {
      bool valid = true;
      // Check all 12 adjacent pairs within the 3x3 subgrid.
      for (int r = i; r < i + 3 && valid; ++r) {
        for (int c = j; c < j + 3 && valid; ++c) {
          if (r + 1 < i + 3 &&
              std::abs(image[r][c] - image[r + 1][c]) > threshold) {
            valid = false;
          }
          if (valid && c + 1 < j + 3 &&
              std::abs(image[r][c] - image[r][c + 1]) > threshold) {
            valid = false;
          }
        }
      }
      if (!valid) continue;

      long long total = 0;
      for (int r = i; r < i + 3; ++r) {
        for (int c = j; c < j + 3; ++c) {
          total += image[r][c];
        }
      }
      int avg = static_cast<int>(total / 9);  // rounded down
      for (int r = i; r < i + 3; ++r) {
        for (int c = j; c < j + 3; ++c) {
          sum[r][c] += avg;
          ++count[r][c];
        }
      }
    }
  }

  std::vector<std::vector<int>> result = image;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (count[i][j] > 0) {
        result[i][j] = static_cast<int>(sum[i][j] / count[i][j]);
      }
    }
  }
  return result;
}

}  // namespace

FindTheGridOfRegionAverageSolution::FindTheGridOfRegionAverageSolution() {
  setMetaInfo({.id = 3030,
               .title = "Find the Grid of Region Average",
               .url = "https://leetcode.com/problems/find-the-grid-of-region-average/"});
  registerStrategy(
      {.name = "brute-force-3x3", .expected = "Accepted",
       .time_complexity = "O(m*n)", .space_complexity = "O(m*n)",
       .tags = {"Array", "Matrix"}},
      resultGridImpl);
}

std::vector<std::vector<int>> FindTheGridOfRegionAverageSolution::resultGrid(
    std::vector<std::vector<int>>& image, int threshold) {
  return getSolution()(image, threshold);
}

}  // namespace problem_3030
}  // namespace leetcode
