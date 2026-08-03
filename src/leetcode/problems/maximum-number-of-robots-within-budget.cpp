#include "leetcode/problems/maximum-number-of-robots-within-budget.h"

#include <deque>
#include <vector>

namespace leetcode::problem_2398 {

static int maximumRobotsImpl(std::vector<int>& chargeTimes,
                             std::vector<int>& runningCosts,
                             long long budget) {
  int n = static_cast<int>(chargeTimes.size());
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + runningCosts[i];
  }

  std::deque<int> dq;  // monotonic decreasing queue, stores indices
  int ans = 0;
  int l = 0;

  for (int r = 0; r < n; ++r) {
    // maintain decreasing order
    while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r]) {
      dq.pop_back();
    }
    dq.push_back(r);

    // shrink window when cost > budget
    while (l <= r) {
      long long maxCharge = chargeTimes[dq.front()];
      long long sumRun = prefix[r + 1] - prefix[l];
      int k = r - l + 1;
      long long cost = maxCharge + k * sumRun;
      if (cost <= budget) break;

      // move left
      if (dq.front() == l) {
        dq.pop_front();
      }
      ++l;
    }

    // window is valid (may be empty if no valid window starting at l)
    if (l <= r) {
      ans = std::max(ans, r - l + 1);
    }
  }

  return ans;
}

MaximumNumberOfRobotsWithinBudgetSolution::MaximumNumberOfRobotsWithinBudgetSolution() {
  setMetaInfo({.id = 2398,
               .title = "Maximum Number of Robots Within Budget",
               .url = "https://leetcode.com/problems/maximum-number-of-robots-within-budget/"});

  registerStrategy(
      {.name = "Sliding Window + Monotonic Queue",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Binary Search", "Queue", "Sliding Window", "Heap (Priority Queue)",
                "Prefix Sum", "Monotonic Queue"}},
      maximumRobotsImpl);
}

int MaximumNumberOfRobotsWithinBudgetSolution::maximumRobots(
    std::vector<int>& chargeTimes,
    std::vector<int>& runningCosts,
    long long budget) {
  return getSolution()(chargeTimes, runningCosts, budget);
}

}  // namespace leetcode::problem_2398
