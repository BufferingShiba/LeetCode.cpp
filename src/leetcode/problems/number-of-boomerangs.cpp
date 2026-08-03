#include "leetcode/problems/number-of-boomerangs.h"

#include <unordered_map>

namespace leetcode::problem_447 {

static int numberOfBoomerangsImpl(std::vector<std::vector<int>>& points) {
  int n = static_cast<int>(points.size());
  if (n < 3) return 0;

  int result = 0;
  for (int i = 0; i < n; ++i) {
    std::unordered_map<long long, int> distCount;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      long long dx =
          static_cast<long long>(points[i][0]) - points[j][0];
      long long dy =
          static_cast<long long>(points[i][1]) - points[j][1];
      long long distSq = dx * dx + dy * dy;
      ++distCount[distSq];
    }
    for (const auto& [dist, count] : distCount) {
      result += count * (count - 1);
    }
  }
  return result;
}

NumberOfBoomerangsSolution::NumberOfBoomerangsSolution() {
  setMetaInfo({.id = 447,
               .title = "Number of Boomerangs",
               .url = "https://leetcode.com/problems/number-of-boomerangs/"});
  registerStrategy(
      {.name = "HashTable",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Math"}},
      numberOfBoomerangsImpl);
}

int NumberOfBoomerangsSolution::numberOfBoomerangs(
    std::vector<std::vector<int>>& points) {
  return getSolution()(points);
}

}  // namespace leetcode::problem_447
