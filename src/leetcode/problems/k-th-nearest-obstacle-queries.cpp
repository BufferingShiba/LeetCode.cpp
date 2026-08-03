#include "leetcode/problems/k-th-nearest-obstacle-queries.h"

#include <cstdlib>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_3275 {

static std::vector<int> resultsArrayImpl(std::vector<std::vector<int>>& queries,
                                         int k) {
  std::vector<int> results;
  results.reserve(queries.size());

  std::priority_queue<int> maxHeap;  // 维护 k 个最小距离

  for (const auto& q : queries) {
    int dist = std::abs(q[0]) + std::abs(q[1]);

    if (static_cast<int>(maxHeap.size()) < k) {
      maxHeap.push(dist);
    } else if (dist < maxHeap.top()) {
      maxHeap.pop();
      maxHeap.push(dist);
    }

    if (static_cast<int>(maxHeap.size()) < k) {
      results.push_back(-1);
    } else {
      results.push_back(maxHeap.top());
    }
  }

  return results;
}

KThNearestObstacleQueriesSolution::KThNearestObstacleQueriesSolution() {
  setMetaInfo({.id = 3275,
               .title = "K-th Nearest Obstacle Queries",
               .url = "https://leetcode.com/problems/k-th-nearest-obstacle-queries/"});

  registerStrategy(
      {.name = "MaxHeap",
       .expected = "Accepted",
       .time_complexity = "O(n log k)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Heap (Priority Queue)"}},
      resultsArrayImpl);
}

std::vector<int> KThNearestObstacleQueriesSolution::resultsArray(
    std::vector<std::vector<int>>& queries, int k) {
  return getSolution()(queries, k);
}

}  // namespace problem_3275
}  // namespace leetcode
