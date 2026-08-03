#include "leetcode/problems/shortest-distance-after-road-addition-queries-ii.h"

#include <set>

namespace leetcode {
namespace problem_3244 {

namespace {

std::vector<int> shortestDistanceAfterQueriesImpl(int n,
                                                  std::vector<std::vector<int>>& queries) {
  // Maintain the set of cities on the current shortest path from 0 to n-1.
  // Initially path is 0 -> 1 -> ... -> n-1, set = {1, ..., n-1}.
  // Path length equals set.size() since 0 connects to the first element and
  // each consecutive set element is one hop.
  std::set<int> path;
  for (int i = 1; i < n; ++i) {
    path.insert(i);
  }

  std::vector<int> answer;
  answer.reserve(queries.size());

  for (const auto& q : queries) {
    int u = q[0];
    int v = q[1];
    // Remove every city strictly between u and v on the path.
    auto it = path.upper_bound(u);
    bool removedAny = false;
    while (it != path.end() && *it < v) {
      it = path.erase(it);
      removedAny = true;
    }
    // A query that removes nothing is entirely contained inside an already
    // shortcut region, so it is redundant and must be ignored (otherwise the
    // new hop node would spuriously lengthen the path).
    if (removedAny) {
      path.insert(v);
    }
    answer.push_back(static_cast<int>(path.size()));
  }

  return answer;
}

}  // namespace

ShortestDistanceAfterRoadAdditionQueriesIiSolution::
    ShortestDistanceAfterRoadAdditionQueriesIiSolution() {
  setMetaInfo({.id = 3244,
               .title = "Shortest Distance After Road Addition Queries II",
               .url = "https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii/"});

  registerStrategy(
      {.name = "ordered-set-greedy",
       .expected = "Accepted",
       .time_complexity = "O((n + q) log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Graph Theory", "Ordered Set"}},
      shortestDistanceAfterQueriesImpl);
}

}  // namespace problem_3244
}  // namespace leetcode
