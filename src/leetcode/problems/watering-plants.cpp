#include "leetcode/problems/watering-plants.h"

namespace leetcode {
namespace problem_2079 {

static int wateringPlantsImpl(std::vector<int>& plants, int capacity) {
  int steps = 0;
  int cur = capacity;
  int pos = -1;
  int n = static_cast<int>(plants.size());
  for (int i = 0; i < n; ++i) {
    if (cur < plants[i]) {
      // go back to river and return to plant i
      steps += (pos + 1) + (i + 1);
      cur = capacity;
    } else {
      steps += i - pos;
    }
    cur -= plants[i];
    pos = i;
  }
  return steps;
}

WateringPlantsSolution::WateringPlantsSolution() {
  setMetaInfo({.id = 2079, .title = "Watering Plants", .url = "https://leetcode.com/problems/watering-plants/"});
  registerStrategy({.name = "simulation", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"Array", "Simulation"}}, wateringPlantsImpl);
}

int WateringPlantsSolution::wateringPlants(std::vector<int>& plants, int capacity) {
  return getSolution()(plants, capacity);
}

}  // namespace problem_2079
}  // namespace leetcode
