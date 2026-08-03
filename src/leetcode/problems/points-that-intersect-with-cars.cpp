#include "leetcode/problems/points-that-intersect-with-cars.h"

#include <algorithm>

namespace leetcode {
namespace problem_2848 {

namespace {

int numberOfPointsImpl(std::vector<std::vector<int>>& nums) {
  std::vector<bool> covered(101, false);
  for (const auto& interval : nums) {
    for (int p = interval[0]; p <= interval[1]; ++p) {
      covered[p] = true;
    }
  }
  return static_cast<int>(
      std::count(covered.begin(), covered.end(), true));
}

}  // namespace

PointsThatIntersectWithCarsSolution::PointsThatIntersectWithCarsSolution() {
  setMetaInfo({.id = 2848,
               .title = "Points That Intersect With Cars",
               .url = "https://leetcode.com/problems/points-that-intersect-with-cars/"});
  registerStrategy(
      {.name = "BooleanMarking",
       .expected = "Accepted",
       .time_complexity = "O(n * range)",
       .space_complexity = "O(range)",
       .tags = {"Array", "Hash Table", "Prefix Sum"}},
      numberOfPointsImpl);
}

int PointsThatIntersectWithCarsSolution::numberOfPoints(
    std::vector<std::vector<int>>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2848
}  // namespace leetcode
