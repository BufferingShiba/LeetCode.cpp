#include "leetcode/problems/swim-in-rising-water.h"

#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_778 {
namespace {

constexpr int kDirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Dijkstra-style: the "cost" to reach a cell is the maximum elevation on the
// path so far. We minimize that cost to find the earliest time we can arrive.
int swimInWaterDijkstra(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  constexpr int kInf = (1 << 30);
  std::vector<int> best(n * n, kInf);

  using State = std::pair<int, int>;  // {cost, index}
  std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

  const int startCost = grid[0][0];
  best[0] = startCost;
  pq.emplace(startCost, 0);

  const int target = n * n - 1;
  while (!pq.empty()) {
    const auto [cost, idx] = pq.top();
    pq.pop();
    if (idx == target) return cost;
    if (cost > best[idx]) continue;

    const int r = idx / n;
    const int c = idx % n;
    for (const auto& d : kDirs) {
      const int nr = r + d[0];
      const int nc = c + d[1];
      if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
      const int nextIdx = nr * n + nc;
      const int nextCost = std::max(cost, grid[nr][nc]);
      if (nextCost < best[nextIdx]) {
        best[nextIdx] = nextCost;
        pq.emplace(nextCost, nextIdx);
      }
    }
  }
  return best[target];
}

}  // namespace

SwimInRisingWaterSolution::SwimInRisingWaterSolution() {
  setMetaInfo({778, "Swim in Rising Water",
               "https://leetcode.com/problems/swim-in-rising-water/"});
  registerStrategy(
      {"DijkstraMinMax", "Accepted", "O(n^2 log n)", "O(n^2)",
       {"Heap (Priority Queue)", "Matrix"}},
      swimInWaterDijkstra);
}

int SwimInRisingWaterSolution::swimInWater(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_778
}  // namespace leetcode
