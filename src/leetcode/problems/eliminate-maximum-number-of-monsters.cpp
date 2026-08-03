#include "leetcode/problems/eliminate-maximum-number-of-monsters.h"

#include <algorithm>

namespace leetcode {
namespace problem_1921 {
namespace {

int eliminateMaximumImpl(std::vector<int>& dist, std::vector<int>& speed) {
  const int n = static_cast<int>(dist.size());
  std::vector<int> arrival(n);
  for (int i = 0; i < n; ++i) {
    // ceil(dist[i] / speed[i])
    arrival[i] = (dist[i] + speed[i] - 1) / speed[i];
  }
  std::sort(arrival.begin(), arrival.end());
  for (int i = 0; i < n; ++i) {
    // At time i (i-th shot), the monster with arrival <= i already reached.
    if (arrival[i] <= i) {
      return i;
    }
  }
  return n;
}

}  // namespace

EliminateMaximumNumberOfMonstersSolution::EliminateMaximumNumberOfMonstersSolution() {
  setMetaInfo({.id = 1921,
               .title = "Eliminate Maximum Number of Monsters",
               .url = "https://leetcode.com/problems/eliminate-maximum-number-of-monsters/"});
  registerStrategy({.name = "GreedySorting",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Greedy", "Sorting"}},
                   eliminateMaximumImpl);
}

int EliminateMaximumNumberOfMonstersSolution::eliminateMaximum(std::vector<int>& dist,
                                                               std::vector<int>& speed) {
  return getSolution()(dist, speed);
}

}  // namespace problem_1921
}  // namespace leetcode
