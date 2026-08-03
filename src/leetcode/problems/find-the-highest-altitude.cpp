#include "leetcode/problems/find-the-highest-altitude.h"

namespace leetcode::problem_1732 {

namespace {

int largestAltitudeImpl(std::vector<int>& gain) {
  int altitude = 0;
  int maxAltitude = 0;
  for (int g : gain) {
    altitude += g;
    if (altitude > maxAltitude) {
      maxAltitude = altitude;
    }
  }
  return maxAltitude;
}

}  // namespace

FindTheHighestAltitudeSolution::FindTheHighestAltitudeSolution() {
  setMetaInfo({.id = 1732,
               .title = "Find the Highest Altitude",
               .url = "https://leetcode.com/problems/find-the-highest-altitude/"});

  registerStrategy({.name = "Prefix Sum",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Prefix Sum"}},
                   largestAltitudeImpl);

  setDefaultStrategy();
}

int FindTheHighestAltitudeSolution::largestAltitude(std::vector<int>& gain) {
  return getSolution()(gain);
}

}  // namespace leetcode::problem_1732
