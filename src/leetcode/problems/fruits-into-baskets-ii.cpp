#include "leetcode/problems/fruits-into-baskets-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3477 {

namespace {

int numOfUnplacedFruitsImpl(std::vector<int>& fruits,
                            std::vector<int>& baskets) {
  const int n = static_cast<int>(fruits.size());
  std::vector<bool> used(n, false);
  int unplaced = 0;
  for (int i = 0; i < n; ++i) {
    bool placed = false;
    for (int j = 0; j < n; ++j) {
      if (!used[j] && baskets[j] >= fruits[i]) {
        used[j] = true;
        placed = true;
        break;
      }
    }
    if (!placed) {
      ++unplaced;
    }
  }
  return unplaced;
}

}  // namespace

FruitsIntoBasketsIiSolution::FruitsIntoBasketsIiSolution() {
  setMetaInfo({.id = 3477,
               .title = "Fruits Into Baskets II",
               .url = "https://leetcode.com/problems/fruits-into-baskets-ii/"});

  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation"}},
      numOfUnplacedFruitsImpl);
}

int FruitsIntoBasketsIiSolution::numOfUnplacedFruits(
    std::vector<int>& fruits, std::vector<int>& baskets) {
  return getSolution()(fruits, baskets);
}

}  // namespace problem_3477
}  // namespace leetcode
