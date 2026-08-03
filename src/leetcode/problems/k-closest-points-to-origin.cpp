#include "leetcode/problems/k-closest-points-to-origin.h"

#include <algorithm>

namespace leetcode {
namespace problem_973 {
namespace {

std::vector<std::vector<int>> kClosestImpl(
    std::vector<std::vector<int>>& points, int k) {
  if (k == static_cast<int>(points.size())) {
    return points;
  }
  std::nth_element(
      points.begin(), points.begin() + k, points.end(),
      [](const std::vector<int>& a, const std::vector<int>& b) {
        const long long distance_a =
            static_cast<long long>(a[0]) * a[0] +
            static_cast<long long>(a[1]) * a[1];
        const long long distance_b =
            static_cast<long long>(b[0]) * b[0] +
            static_cast<long long>(b[1]) * b[1];
        return distance_a < distance_b;
      });
  points.resize(k);
  return points;
}

}  // namespace

KClosestPointsToOriginSolution::KClosestPointsToOriginSolution() {
  setMetaInfo({.id = 973,
               .title = "K Closest Points to Origin",
               .url = "https://leetcode.com/problems/k-closest-points-to-origin/"});
  registerStrategy(
      {.name = "nth_element",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Sorting", "Quickselect"}},
      kClosestImpl);
}

std::vector<std::vector<int>> KClosestPointsToOriginSolution::kClosest(
    std::vector<std::vector<int>>& points, int k) {
  return getSolution()(points, k);
}

}  // namespace problem_973
}  // namespace leetcode
