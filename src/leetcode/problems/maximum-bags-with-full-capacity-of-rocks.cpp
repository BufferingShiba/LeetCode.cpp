#include "leetcode/problems/maximum-bags-with-full-capacity-of-rocks.h"

#include <algorithm>

namespace leetcode::problem_2279 {

namespace {

int maximumBagsImpl(std::vector<int>& capacity, std::vector<int>& rocks,
                    int additionalRocks) {
  const int n = static_cast<int>(capacity.size());
  for (int i = 0; i < n; ++i) {
    capacity[i] -= rocks[i];
  }
  std::sort(capacity.begin(), capacity.end());
  int count = 0;
  long long remaining = additionalRocks;
  for (int i = 0; i < n; ++i) {
    if (capacity[i] == 0) {
      ++count;
    } else if (capacity[i] <= remaining) {
      remaining -= capacity[i];
      ++count;
    } else {
      break;
    }
  }
  return count;
}

}  // namespace

MaximumBagsWithFullCapacityOfRocksSolution::
    MaximumBagsWithFullCapacityOfRocksSolution() {
  setMetaInfo({.id = 2279,
               .title = "Maximum Bags With Full Capacity of Rocks",
               .url =
                   "https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/"});

  registerStrategy(
      {.name = "greedy-sort",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Sorting"}},
      maximumBagsImpl);
}

int MaximumBagsWithFullCapacityOfRocksSolution::maximumBags(
    std::vector<int>& capacity, std::vector<int>& rocks,
    int additionalRocks) {
  return getSolution()(capacity, rocks, additionalRocks);
}

}  // namespace leetcode::problem_2279
