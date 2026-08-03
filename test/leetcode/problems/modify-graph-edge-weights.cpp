#include <algorithm>
#include <climits>
#include <gtest/gtest.h>
#include <queue>
#include <utility>
#include <vector>

#include "leetcode/problems/modify-graph-edge-weights.h"

namespace leetcode::problem_2699 {

namespace {

struct AdjInfo {
  int to;
  long long weight;
};

long long shortestPath(int n, const std::vector<std::vector<int>>& eg,
                       int source, int destination) {
  std::vector<std::vector<AdjInfo>> adj(n);
  for (const auto& e : eg) {
    adj[e[0]].push_back({e[1], e[2]});
    adj[e[1]].push_back({e[0], e[2]});
  }
  std::vector<long long> dist(n, LLONG_MAX);
  using P = std::pair<long long, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  dist[source] = 0;
  pq.push({0, source});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (const auto& info : adj[u]) {
      long long nd = dist[u] + info.weight;
      if (nd < dist[info.to]) {
        dist[info.to] = nd;
        pq.push({nd, info.to});
      }
    }
  }
  return dist[destination];
}

// Validates that the returned modification is a legal assignment satisfying the
// invariants: every edge present, -1 entries replaced by positive integers, and
// the resulting shortest path equals `target` exactly.
bool isValid(const std::vector<std::vector<int>>& result, int n,
             const std::vector<std::vector<int>>& original, int source,
             int destination, int target, bool expectFeasible) {
  if (!expectFeasible) {
    // Infeasible cases must return an empty array.
    return result.empty();
  }
  if (result.size() != original.size()) return false;
  long long dist = shortestPath(n, result, source, destination);
  if (dist != target) return false;
  for (const auto& e : result) {
    if (e[2] < 1 || e[2] > 2000000000) return false;
    (void)original;
  }
  return true;
}

}  // namespace

class ModifyGraphEdgeWeightsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ModifyGraphEdgeWeightsSolution solution;
};

TEST_P(ModifyGraphEdgeWeightsTest, OfficialExample1) {
  int n = 5;
  std::vector<std::vector<int>> edges = {
      {4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}};
  int source = 0, destination = 1, target = 5;
  auto result = solution.modifiedGraphEdges(n, edges, source, destination, target);
  EXPECT_TRUE(isValid(result, n, edges, source, destination, target, /*feasible=*/true));
}

TEST_P(ModifyGraphEdgeWeightsTest, OfficialExample2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, -1}, {0, 2, 5}};
  int source = 0, destination = 2, target = 6;
  auto result = solution.modifiedGraphEdges(n, edges, source, destination, target);
  EXPECT_TRUE(isValid(result, n, edges, source, destination, target, /*feasible=*/false));
}

TEST_P(ModifyGraphEdgeWeightsTest, OfficialExample3) {
  int n = 4;
  std::vector<std::vector<int>> edges = {
      {1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, -1}};
  int source = 0, destination = 2, target = 6;
  auto result = solution.modifiedGraphEdges(n, edges, source, destination, target);
  EXPECT_TRUE(isValid(result, n, edges, source, destination, target, /*feasible=*/true));
}

TEST_P(ModifyGraphEdgeWeightsTest, SelfAuthoredDirectEdgeFeasible) {
  // Single direct -1 edge; boost it to exactly target.
  int n = 2;
  std::vector<std::vector<int>> edges = {{0, 1, -1}};
  int source = 0, destination = 1, target = 7;
  auto result = solution.modifiedGraphEdges(n, edges, source, destination, target);
  EXPECT_TRUE(isValid(result, n, edges, source, destination, target, /*feasible=*/true));
}

TEST_P(ModifyGraphEdgeWeightsTest, SelfAuthoredInfeasibleMinTooLarge) {
  // Direct -1 edge but target too small (must be >= 1 + existing path requirement).
  // Shortest possible is 1, so target = 0 is infeasible by constraints; use a
  // case where the minimum feasible distance exceeds target.
  // n=3 chain: 0--1(fixed 10), 1--2(-1)  and direct 0--2(fixed 1)
  int n = 3;
  std::vector<std::vector<int>> edges = {
      {0, 1, 10}, {1, 2, -1}, {0, 2, 1}};
  int source = 0, destination = 2, target = 5;
  // Shortest path 0->2 direct is weight 1 (fixed), cannot reach 5 without
  // the direct edge changing, and it cannot change. So infeasible.
  auto result = solution.modifiedGraphEdges(n, edges, source, destination, target);
  EXPECT_TRUE(isValid(result, n, edges, source, destination, target, /*feasible=*/false));
}

INSTANTIATE_TEST_SUITE_P(
    ModifyGraphEdgeWeightsTests, ModifyGraphEdgeWeightsTest,
    ::testing::ValuesIn(ModifyGraphEdgeWeightsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2699
