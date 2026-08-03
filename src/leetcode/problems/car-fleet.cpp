#include "leetcode/problems/car-fleet.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_853 {

static int carFleetImpl(int target, std::vector<int>& position,
                        std::vector<int>& speed) {
  int n = static_cast<int>(position.size());
  std::vector<std::pair<int, int>> cars;
  cars.reserve(n);
  for (int i = 0; i < n; ++i) {
    cars.emplace_back(position[i], speed[i]);
  }

  // 按起始位置降序排序：离 target 近的车先处理
  std::sort(cars.begin(), cars.end(),
            [](const auto& a, const auto& b) { return a.first > b.first; });

  int fleets = 0;
  double max_time = 0.0;
  for (const auto& [pos, spd] : cars) {
    double time = static_cast<double>(target - pos) / spd;
    if (time > max_time) {
      ++fleets;
      max_time = time;
    }
  }
  return fleets;
}

CarFleetSolution::CarFleetSolution() {
  setMetaInfo({.id = 853,
               .title = "Car Fleet",
               .url = "https://leetcode.com/problems/car-fleet/"});
  registerStrategy(
      {.name = "Sort by Position",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Stack", "Sorting", "Monotonic Stack"}},
      carFleetImpl);
}

int CarFleetSolution::carFleet(int target, std::vector<int>& position,
                               std::vector<int>& speed) {
  return getSolution()(target, position, speed);
}

}  // namespace problem_853
}  // namespace leetcode
