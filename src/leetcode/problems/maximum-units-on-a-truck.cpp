#include "leetcode/problems/maximum-units-on-a-truck.h"

#include <algorithm>

namespace leetcode::problem_1710 {

namespace {

int maximumUnitsImpl(std::vector<std::vector<int>>& boxTypes, int truckSize) {
  std::sort(boxTypes.begin(), boxTypes.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[1] > b[1];
            });
  int total = 0;
  for (const auto& box : boxTypes) {
    int take = std::min(truckSize, box[0]);
    total += take * box[1];
    truckSize -= take;
    if (truckSize == 0) break;
  }
  return total;
}

}  // namespace

MaximumUnitsOnATruck::MaximumUnitsOnATruck() {
  setMetaInfo({.id = 1710,
               .title = "Maximum Units on a Truck",
               .url = "https://leetcode.com/problems/maximum-units-on-a-truck/"});

  registerStrategy(
      {"greedy-sort", "Accepted", "O(n log n)", "O(1)", {"Greedy", "Sorting"}},
      maximumUnitsImpl);
}

int MaximumUnitsOnATruck::maximumUnits(std::vector<std::vector<int>>& boxTypes,
                                       int truckSize) {
  return getSolution()(boxTypes, truckSize);
}

}  // namespace leetcode::problem_1710
