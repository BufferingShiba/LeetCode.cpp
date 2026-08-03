#include "leetcode/problems/remove-methods-from-project.h"

#include <queue>

namespace leetcode {
namespace problem_3310 {

namespace {

std::vector<int> removeMethodsBfs(int n, int k,
                                  std::vector<std::vector<int>>& invocations) {
  std::vector<std::vector<int>> graph(n);
  for (const auto& edge : invocations) {
    graph[edge[0]].push_back(edge[1]);
  }

  std::vector<bool> suspicious(n, false);
  std::queue<int> q;
  suspicious[k] = true;
  q.push(k);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : graph[u]) {
      if (!suspicious[v]) {
        suspicious[v] = true;
        q.push(v);
      }
    }
  }

  // 检查是否有 outside 方法直接调用 suspicious 组内方法。
  for (const auto& edge : invocations) {
    if (!suspicious[edge[0]] && suspicious[edge[1]]) {
      std::vector<int> all(n);
      for (int i = 0; i < n; ++i) all[i] = i;
      return all;
    }
  }

  std::vector<int> res;
  res.reserve(n);
  for (int i = 0; i < n; ++i) {
    if (!suspicious[i]) res.push_back(i);
  }
  return res;
}

}  // namespace

RemoveMethodsFromProjectSolution::RemoveMethodsFromProjectSolution() {
  setMetaInfo({.id = 3310,
               .title = "Remove Methods From Project",
               .url = "https://leetcode.com/problems/remove-methods-from-project/"});
  registerStrategy(
      {.name = "bfs",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n + m)",
       .tags = {"BFS", "Graph"}},
      removeMethodsBfs);
}

std::vector<int> RemoveMethodsFromProjectSolution::remainingMethods(
    int n, int k, std::vector<std::vector<int>>& invocations) {
  return getSolution()(n, k, invocations);
}

}  // namespace problem_3310
}  // namespace leetcode
