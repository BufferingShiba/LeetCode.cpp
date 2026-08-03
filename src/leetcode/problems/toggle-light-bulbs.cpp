#include "leetcode/problems/toggle-light-bulbs.h"

namespace leetcode {
namespace problem_3842 {

namespace {

std::vector<int> toggleLightBulbsImpl(std::vector<int>& bulbs) {
  std::vector<bool> on(101, false);
  for (int b : bulbs) {
    on[b] = !on[b];
  }
  std::vector<int> result;
  for (int i = 1; i <= 100; ++i) {
    if (on[i]) {
      result.push_back(i);
    }
  }
  return result;
}

}  // namespace

ToggleLightBulbsSolution::ToggleLightBulbsSolution() {
  setMetaInfo({.id = 3842,
               .title = "Toggle Light Bulbs",
               .url = "https://leetcode.com/problems/toggle-light-bulbs/"});
  registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Simulation"}},
      toggleLightBulbsImpl);
}

std::vector<int> ToggleLightBulbsSolution::toggleLightBulbs(std::vector<int>& bulbs) {
  return getSolution()(bulbs);
}

}  // namespace problem_3842
}  // namespace leetcode
