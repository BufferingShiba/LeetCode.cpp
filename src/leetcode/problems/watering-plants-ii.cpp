#include "leetcode/problems/watering-plants-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_2105 {

static int minimumRefillImpl(std::vector<int>& plants, int capacityA,
                             int capacityB) {
  int n = static_cast<int>(plants.size());
  int i = 0, j = n - 1;
  int canA = capacityA, canB = capacityB;
  int refills = 0;

  while (i < j) {
    // Alice waters plant i
    if (canA < plants[i]) {
      ++refills;
      canA = capacityA;
    }
    canA -= plants[i];
    ++i;

    // Bob waters plant j
    if (canB < plants[j]) {
      ++refills;
      canB = capacityB;
    }
    canB -= plants[j];
    --j;
  }

  // i == j: the middle plant
  if (i == j) {
    if (canA >= canB) {
      // Alice waters
      if (canA < plants[i]) {
        ++refills;
      }
    } else {
      // Bob waters
      if (canB < plants[i]) {
        ++refills;
      }
    }
  }

  return refills;
}

WateringPlantsIiSolution::WateringPlantsIiSolution() {
  setMetaInfo({.id = 2105,
               .title = "Watering Plants II",
               .url = "https://leetcode.com/problems/watering-plants-ii/"});

  registerStrategy(
      {.name = "two-pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Simulation"}},
      minimumRefillImpl);
}

int WateringPlantsIiSolution::minimumRefill(std::vector<int>& plants,
                                            int capacityA, int capacityB) {
  return getSolution()(plants, capacityA, capacityB);
}

}  // namespace problem_2105
}  // namespace leetcode
