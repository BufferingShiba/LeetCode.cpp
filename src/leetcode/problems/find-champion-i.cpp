#include "leetcode/problems/find-champion-i.h"

namespace leetcode {
namespace problem_2923 {

namespace {

// Champion is a team that no other team is stronger than.
// A team b is stronger than team a iff grid[b][a] == 1.
// So champion c must satisfy grid[b][c] == 0 for all b != c.
int findChampionImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  for (int c = 0; c < n; ++c) {
    bool beaten = false;
    for (int r = 0; r < n; ++r) {
      if (r != c && grid[r][c] == 1) {
        beaten = true;
        break;
      }
    }
    if (!beaten) {
      return c;
    }
  }
  return -1;  // unreachable; the input guarantees a unique champion
}

}  // namespace

FindChampionISolution::FindChampionISolution() {
  setMetaInfo({.id = 2923,
               .title = "Find Champion I",
               .url = "https://leetcode.com/problems/find-champion-i/"});
  registerStrategy({.name = "Column scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Matrix"}},
                   findChampionImpl);
}

}  // namespace problem_2923
}  // namespace leetcode
