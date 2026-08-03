#include "leetcode/problems/frog-position-after-t-seconds.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1377 {

namespace {

double frogPositionImpl(int n, std::vector<std::vector<int>>& edges, int t,
                        int target) {
  std::vector<std::vector<int>> graph(n + 1);
  for (const auto& e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }

  std::function<double(int, int, int, double)> dfs =
      [&](int node, int parent, int elapsed, double prob) -> double {
    if (node == target) {
      if (elapsed == t) {
        return prob;
      }
      // elapsed < t: check whether the frog still has unvisited children.
      int availChild = 0;
      for (int nb : graph[node]) {
        if (nb != parent) availChild++;
      }
      if (availChild == 0) {
        // Leaf node, frog stays forever -> still on target.
        return prob;
      }
      // Frog would leave the target, so probability eventually drops to 0.
      return 0.0;
    }
    if (elapsed == t) {
      return 0.0;
    }
    int availChild = 0;
    for (int nb : graph[node]) {
      if (nb != parent) availChild++;
    }
    if (availChild == 0) {
      // Cannot move but node != target.
      return 0.0;
    }
    double childProb = prob / availChild;
    for (int nb : graph[node]) {
      if (nb != parent) {
        double res = dfs(nb, node, elapsed + 1, childProb);
        if (res > 0.0) return res;
      }
    }
    return 0.0;
  };

  return dfs(1, 0, 0, 1.0);
}

}  // namespace

FrogPositionAfterTSecondsSolution::FrogPositionAfterTSecondsSolution() {
  setMetaInfo({1377, "Frog Position After T Seconds",
               "https://leetcode.com/problems/frog-position-after-t-seconds/"});
  registerStrategy(
      {"DFS", "Accepted", "O(n)", "O(n)",
       {"Tree", "Depth-First Search", "Breadth-First Search", "Graph Theory"}},
      &frogPositionImpl);
}

double FrogPositionAfterTSecondsSolution::frogPosition(
    int n, std::vector<std::vector<int>>& edges, int t, int target) {
  return getSolution()(n, edges, t, target);
}

}  // namespace problem_1377
}  // namespace leetcode
