#include "leetcode/problems/rectangle-overlap.h"

namespace leetcode {
namespace problem_836 {

namespace {

bool isRectangleOverlapImpl(std::vector<int>& rec1, std::vector<int>& rec2) {
  return rec1[0] < rec2[2] && rec2[0] < rec1[2] &&
         rec1[1] < rec2[3] && rec2[1] < rec1[3];
}

}  // namespace

RectangleOverlapSolution::RectangleOverlapSolution() {
  setMetaInfo({.id = 836,
               .title = "Rectangle Overlap",
               .url = "https://leetcode.com/problems/rectangle-overlap/"});

  registerStrategy(
      {.name = "interval-overlap",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Geometry"}},
      isRectangleOverlapImpl);
}

bool RectangleOverlapSolution::isRectangleOverlap(std::vector<int>& rec1,
                                                   std::vector<int>& rec2) {
  return getSolution()(rec1, rec2);
}

}  // namespace problem_836
}  // namespace leetcode
