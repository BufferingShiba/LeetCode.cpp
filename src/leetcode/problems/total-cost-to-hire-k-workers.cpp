#include "leetcode/problems/total-cost-to-hire-k-workers.h"

#include <algorithm>
#include <queue>
#include <utility>

namespace leetcode {
namespace problem_2462 {

static long long solution1(vector<int>& costs, int k, int candidates) {
  const int n = static_cast<int>(costs.size());
  if (2 * candidates >= n) {
    // The entire array is covered by the two windows overlapping.
    // Just pick the k smallest costs.
    vector<int> sorted = costs;
    std::sort(sorted.begin(), sorted.end());
    long long total = 0;
    for (int i = 0; i < k; ++i) {
      total += sorted[i];
    }
    return total;
  }

  // Each entry stores {cost, index}. We want min cost, tie-break by smallest index.
  auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second > b.second;
  };
  using Heap = std::priority_queue<std::pair<int, int>,
                                   std::vector<std::pair<int, int>>, decltype(cmp)>;

  Heap left(cmp), right(cmp);
  int l = 0, r = n - 1;
  // Initialize windows.
  for (int i = 0; i < candidates; ++i) left.emplace(costs[l], l), ++l;
  for (int i = 0; i < candidates; ++i) right.emplace(costs[r], r), --r;

  long long total = 0;
  auto takeLeft = [&]() {
    total += left.top().first;
    left.pop();
    if (l <= r) left.emplace(costs[l], l), ++l;
  };
  auto takeRight = [&]() {
    total += right.top().first;
    right.pop();
    if (l <= r) right.emplace(costs[r], r), --r;
  };

  for (int step = 0; step < k; ++step) {
    // Once all unseen workers have entered the windows, one heap can become
    // empty before the other (for example when k == n).
    if (left.empty()) {
      takeRight();
      continue;
    }
    if (right.empty()) {
      takeLeft();
      continue;
    }

    auto le = left.top();
    auto re = right.top();
    if (le.first != re.first) {
      if (le.first < re.first) {
        takeLeft();
      } else {
        takeRight();
      }
    } else {
      // Tie: choose the worker with the smallest index (left side).
      takeLeft();
    }
  }
  return total;
}

TotalCostToHireKWorkersSolution::TotalCostToHireKWorkersSolution() {
  setMetaInfo({
      .id = 2462,
      .title = "Total Cost to Hire K Workers",
      .url = "https://leetcode.com/problems/total-cost-to-hire-k-workers"
  });
  registerStrategy(
      {.name = "Two Min-Heaps",
       .expected = "Accepted",
       .time_complexity = "O((n + k) log n)",
       .space_complexity = "O(n)",
       .tags = {"Heap", "Two Pointers"}},
      solution1);
}

long long TotalCostToHireKWorkersSolution::totalCost(vector<int>& costs, int k, int candidates) {
  return getSolution()(costs, k, candidates);
}

}  // namespace problem_2462
}  // namespace leetcode
