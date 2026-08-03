#include "leetcode/problems/add-minimum-number-of-rungs.h"

namespace leetcode {
namespace problem_1936 {

namespace {

int addRungsImpl(std::vector<int>& rungs, int dist) {
  long long additions = 0;
  int prev = 0;
  for (int h : rungs) {
    int gap = h - prev;
    if (gap > dist) {
      additions += (gap - 1) / dist;
    }
    prev = h;
  }
  return static_cast<int>(additions);
}

}  // namespace

AddMinimumNumberOfRungsSolution::AddMinimumNumberOfRungsSolution() {
  setMetaInfo({.id = 1936,
               .title = "Add Minimum Number of Rungs",
               .url =
                   "https://leetcode.com/problems/add-minimum-number-of-rungs/"});
  registerStrategy(
      {
          .name = "GreedyGapCount",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(1)",
          .tags = {"Array", "Greedy"},
      },
      addRungsImpl);
}

int AddMinimumNumberOfRungsSolution::addRungs(std::vector<int>& rungs,
                                              int dist) {
  return getSolution()(rungs, dist);
}

}  // namespace problem_1936
}  // namespace leetcode
