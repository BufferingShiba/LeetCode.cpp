#include "leetcode/problems/interval-list-intersections.h"

namespace leetcode {
namespace problem_986 {

namespace {

std::vector<std::vector<int>> intervalIntersectionImpl(
    std::vector<std::vector<int>>& firstList,
    std::vector<std::vector<int>>& secondList) {
  std::vector<std::vector<int>> result;
  int i = 0;
  int j = 0;
  const int n = static_cast<int>(firstList.size());
  const int m = static_cast<int>(secondList.size());
  while (i < n && j < m) {
    const int lo = std::max(firstList[i][0], secondList[j][0]);
    const int hi = std::min(firstList[i][1], secondList[j][1]);
    if (lo <= hi) {
      result.push_back({lo, hi});
    }
    if (firstList[i][1] < secondList[j][1]) {
      ++i;
    } else {
      ++j;
    }
  }
  return result;
}

}  // namespace

IntervalListIntersectionsSolution::IntervalListIntersectionsSolution() {
  this->setMetaInfo({.id = 986,
                     .title = "Interval List Intersections",
                     .url = "https://leetcode.com/problems/interval-list-intersections/"});
  this->registerStrategy(
      {.name = "TwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Sweep Line"}},
      intervalIntersectionImpl);
}

std::vector<std::vector<int>> IntervalListIntersectionsSolution::intervalIntersection(
    std::vector<std::vector<int>>& firstList,
    std::vector<std::vector<int>>& secondList) {
  return getSolution()(firstList, secondList);
}

}  // namespace problem_986
}  // namespace leetcode
