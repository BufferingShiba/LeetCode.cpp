#include "leetcode/problems/check-if-it-is-a-straight-line.h"

namespace leetcode {
namespace problem_1232 {

namespace {

bool checkStraightLineImpl(std::vector<std::vector<int>>& coordinates) {
  const int n = static_cast<int>(coordinates.size());
  if (n <= 2) {
    return true;
  }
  const int x0 = coordinates[0][0];
  const int y0 = coordinates[0][1];
  const int dx = coordinates[1][0] - x0;
  const int dy = coordinates[1][1] - y0;
  for (int i = 2; i < n; ++i) {
    const int dxi = coordinates[i][0] - x0;
    const int dyi = coordinates[i][1] - y0;
    if (dx * dyi - dy * dxi != 0) {
      return false;
    }
  }
  return true;
}

}  // namespace

CheckIfItIsAStraightLineSolution::CheckIfItIsAStraightLineSolution() {
  setMetaInfo({.id = 1232,
               .title = "Check If It Is a Straight Line",
               .url = "https://leetcode.com/problems/check-if-it-is-a-straight-line/"});
  registerStrategy(
      {.name = "cross-product",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Geometry"}},
      checkStraightLineImpl);
}

bool CheckIfItIsAStraightLineSolution::checkStraightLine(
    std::vector<std::vector<int>>& coordinates) {
  return getSolution()(coordinates);
}

}  // namespace problem_1232
}  // namespace leetcode
