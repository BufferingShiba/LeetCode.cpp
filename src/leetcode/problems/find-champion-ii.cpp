#include "leetcode/problems/find-champion-ii.h"

#include <vector>

namespace leetcode {
namespace problem_2924 {

static int findChampionImpl(int n, std::vector<std::vector<int>>& edges) {
  std::vector<int> indegree(n, 0);
  for (const auto& e : edges) {
    indegree[e[1]]++;
  }
  int champion = -1;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0) {
      if (champion != -1) {
        return -1;  // more than one candidate
      }
      champion = i;
    }
  }
  return champion;  // -1 if none
}

FindChampionIiSolution::FindChampionIiSolution() {
  setMetaInfo({2924, "Find Champion II",
               "https://leetcode.com/problems/find-champion-ii/"});
  registerStrategy(
      {"IndegreeCounting", "Accepted", "O(n + m)", "O(n)",
       {"Graph Theory"}},
      findChampionImpl);
}

int FindChampionIiSolution::findChampion(int n,
                                        std::vector<std::vector<int>>& edges) {
  return getSolution()(n, edges);
}

}  // namespace problem_2924
}  // namespace leetcode
