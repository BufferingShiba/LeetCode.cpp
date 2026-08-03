#include "leetcode/problems/total-distance-traveled.h"

namespace leetcode {
namespace problem_2739 {

static int distanceTraveledImpl(int mainTank, int additionalTank) {
  int totalDistance = 0;
  int consumedSinceTransfer = 0;
  while (mainTank > 0) {
    mainTank--;
    totalDistance += 10;
    consumedSinceTransfer++;
    if (consumedSinceTransfer == 5 && additionalTank > 0) {
      additionalTank--;
      mainTank++;
      consumedSinceTransfer = 0;
    }
  }
  return totalDistance;
}

TotalDistanceTraveledSolution::TotalDistanceTraveledSolution() {
  setMetaInfo({.id = 2739,
               .title = "Total Distance Traveled",
               .url = "https://leetcode.com/problems/total-distance-traveled/"});
  registerStrategy({.name = "Simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(mainTank)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Simulation"}},
                   distanceTraveledImpl);
  setDefaultStrategy();
}

int TotalDistanceTraveledSolution::distanceTraveled(int mainTank,
                                                    int additionalTank) {
  return getSolution()(mainTank, additionalTank);
}

}  // namespace problem_2739
}  // namespace leetcode
