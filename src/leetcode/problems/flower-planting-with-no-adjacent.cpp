#include "leetcode/problems/flower-planting-with-no-adjacent.h"

namespace leetcode::problem_1042 {

namespace {

std::vector<int> gardenNoAdjImpl(int n, std::vector<std::vector<int>>& paths) {
  std::vector<std::vector<int>> graph(n);
  for (const auto& path : paths) {
    int a = path[0] - 1;
    int b = path[1] - 1;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  std::vector<int> answer(n, 0);
  for (int i = 0; i < n; ++i) {
    bool used[5] = {false, false, false, false, false};
    for (int nb : graph[i]) {
      if (answer[nb] != 0) {
        used[answer[nb]] = true;
      }
    }
    for (int c = 1; c <= 4; ++c) {
      if (!used[c]) {
        answer[i] = c;
        break;
      }
    }
  }
  return answer;
}

}  // namespace

FlowerPlantingWithNoAdjacentSolution::FlowerPlantingWithNoAdjacentSolution() {
  SolutionBase<Func>::StrategyMetadata metadata;
  metadata.name = "Greedy Graph Coloring";
  metadata.expected = "Accepted";
  metadata.time_complexity = "O(n + paths)";
  metadata.space_complexity = "O(n + paths)";
  metadata.tags = {"Greedy", "Graph", "Breadth-First Search"};
  this->setMetaInfo({.id = 1042,
                     .title = "Flower Planting With No Adjacent",
                     .url = "https://leetcode.com/problems/flower-planting-with-no-adjacent/"});
  this->registerStrategy(metadata, gardenNoAdjImpl);
}

std::vector<int> FlowerPlantingWithNoAdjacentSolution::gardenNoAdj(
    int n, std::vector<std::vector<int>>& paths) {
  return this->getSolution()(n, paths);
}

}  // namespace leetcode::problem_1042
