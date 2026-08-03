#include "leetcode/problems/path-crossing.h"

#include <set>
#include <utility>

namespace leetcode::problem_1496 {

namespace {
bool isPathCrossingImpl(std::string path) {
  std::set<std::pair<int, int>> visited;
  int x = 0, y = 0;
  visited.insert({x, y});
  for (char c : path) {
    switch (c) {
      case 'N': ++y; break;
      case 'S': --y; break;
      case 'E': ++x; break;
      case 'W': --x; break;
    }
    if (visited.count({x, y})) {
      return true;
    }
    visited.insert({x, y});
  }
  return false;
}
}  // namespace

PathCrossingSolution::PathCrossingSolution() {
  setMetaInfo({.id = 1496,
               .title = "Path Crossing",
               .url = "https://leetcode.com/problems/path-crossing/"});
  registerStrategy({.name = "HashSet",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Hash Table", "String"}},
                   isPathCrossingImpl);
}

bool PathCrossingSolution::isPathCrossing(std::string path) {
  return getSolution()(path);
}

}  // namespace leetcode::problem_1496
