#include "leetcode/problems/maximum-total-importance-of-roads.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2285 {

static long long maximumImportanceImpl(int n,
                                       std::vector<std::vector<int>>& roads) {
  std::vector<int> degree(n, 0);
  for (const auto& road : roads) {
    degree[road[0]]++;
    degree[road[1]]++;
  }
  std::sort(degree.begin(), degree.end());

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    result += static_cast<long long>(degree[i]) * (i + 1);
  }
  return result;
}

MaximumTotalImportanceOfRoadsSolution::
    MaximumTotalImportanceOfRoadsSolution() {
  setMetaInfo({.id = 2285,
               .title = "Maximum Total Importance of Roads",
               .url = "https://leetcode.com/problems/maximum-total-importance-of-roads/"});
  registerStrategy(
      {.name = "greedy_by_degree",
       .expected = "Accepted",
       .time_complexity = "O(n log n + m)",
       .space_complexity = "O(n)",
       .tags = {"Greedy", "Graph Theory", "Sorting"}},
      maximumImportanceImpl);
}

long long MaximumTotalImportanceOfRoadsSolution::maximumImportance(
    int n, std::vector<std::vector<int>>& roads) {
  return getSolution()(n, roads);
}

}  // namespace problem_2285
}  // namespace leetcode
