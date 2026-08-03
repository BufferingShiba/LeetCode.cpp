// Copyright leetcode.cpp contributors
#include "leetcode/problems/maximum-area-of-longest-diagonal-rectangle.h"

#include <vector>

namespace leetcode {
namespace problem_3000 {

namespace {

int areaOfMaxDiagonalImpl(std::vector<std::vector<int>>& dimensions) {
  int bestDiag = 0;
  int bestArea = 0;
  for (const auto& dim : dimensions) {
    int l = dim[0];
    int w = dim[1];
    int diag = l * l + w * w;
    int area = l * w;
    if (diag > bestDiag || (diag == bestDiag && area > bestArea)) {
      bestDiag = diag;
      bestArea = area;
    }
  }
  return bestArea;
}

}  // namespace

MaximumAreaOfLongestDiagonalRectangleSolution::
    MaximumAreaOfLongestDiagonalRectangleSolution() {
  setMetaInfo({.id = 3000,
               .title = "Maximum Area of Longest Diagonal Rectangle",
               .url = "https://leetcode.com/problems/"
                      "maximum-area-of-longest-diagonal-rectangle/"});
  registerStrategy(
      {"SinglePass", "Accepted", "O(n)", "O(1)", {"Array"}},
      areaOfMaxDiagonalImpl);
}

int MaximumAreaOfLongestDiagonalRectangleSolution::areaOfMaxDiagonal(
    std::vector<std::vector<int>>& dimensions) {
  return getSolution()(dimensions);
}

}  // namespace problem_3000
}  // namespace leetcode
