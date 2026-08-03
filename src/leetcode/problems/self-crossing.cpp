#include "leetcode/problems/self-crossing.h"

namespace leetcode {
namespace problem_335 {

static bool isSelfCrossingImpl(std::vector<int>& distance) {
  int n = distance.size();
  if (n < 4) return false;

  for (int i = 3; i < n; ++i) {
    // Case 1: edge i crosses edge i-3
    if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
      return true;
    }
    // Case 2: edge i overlaps/touches edge i-4
    if (i >= 4 && distance[i - 1] == distance[i - 3] &&
        distance[i] + distance[i - 4] >= distance[i - 2]) {
      return true;
    }
    // Case 3: edge i crosses edge i-5
    if (i >= 5 && distance[i - 2] >= distance[i - 4] &&
        distance[i] + distance[i - 4] >= distance[i - 2] &&
        distance[i - 1] <= distance[i - 3] &&
        distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
      return true;
    }
  }
  return false;
}

SelfCrossingSolution::SelfCrossingSolution() {
  setMetaInfo({.id = 335,
               .title = "Self Crossing",
               .url = "https://leetcode.com/problems/self-crossing/"});
  registerStrategy(
      {.name = "SpiralPatternCheck",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Geometry"}},
      isSelfCrossingImpl);
}

bool SelfCrossingSolution::isSelfCrossing(std::vector<int>& distance) {
  return getSolution()(distance);
}

}  // namespace problem_335
}  // namespace leetcode
