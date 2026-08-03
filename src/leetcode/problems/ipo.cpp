#include "leetcode/problems/ipo.h"

#include <algorithm>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_502 {

namespace {

int findMaximizedCapitalImpl(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
  int n = static_cast<int>(profits.size());

  // Pair (capital, profit) for each project
  std::vector<std::pair<int, int>> projects;
  projects.reserve(n);
  for (int i = 0; i < n; ++i) {
    projects.emplace_back(capital[i], profits[i]);
  }

  // Sort by capital ascending
  std::sort(projects.begin(), projects.end());

  // Max-heap of profits of available projects
  std::priority_queue<int> maxHeap;

  int idx = 0;
  for (int i = 0; i < k; ++i) {
    // Push all projects we can now afford
    while (idx < n && projects[idx].first <= w) {
      maxHeap.push(projects[idx].second);
      ++idx;
    }

    if (maxHeap.empty()) {
      break;  // No more projects available
    }

    w += maxHeap.top();
    maxHeap.pop();
  }

  return w;
}

}  // namespace

IpoSolution::IpoSolution() {
  setMetaInfo({.id = 502, .title = "IPO", .url = "https://leetcode.com/problems/ipo/"});

  registerStrategy(
      {.name = "Greedy + Max Heap",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Sorting", "Heap (Priority Queue)"}},
      findMaximizedCapitalImpl);
}

int IpoSolution::findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
  return getSolution()(k, w, profits, capital);
}

}  // namespace problem_502
}  // namespace leetcode
