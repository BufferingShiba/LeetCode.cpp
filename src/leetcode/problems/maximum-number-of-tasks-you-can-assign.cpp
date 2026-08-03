#include "leetcode/problems/maximum-number-of-tasks-you-can-assign.h"

#include <algorithm>
#include <set>
#include <vector>

namespace leetcode {
namespace problem_2071 {

namespace {

bool canAssign(int k, const std::vector<int>& tasks,
               const std::vector<int>& workers, int pills, int strength) {
  if (k == 0) return true;
  // 取最强的 k 个工人
  std::multiset<int> ws(workers.end() - k, workers.end());
  int pillsLeft = pills;
  // 从最难到最简单遍历任务
  for (int i = k - 1; i >= 0; --i) {
    int t = tasks[i];
    // 优先直接完成
    auto it = ws.lower_bound(t);
    if (it != ws.end()) {
      ws.erase(it);
    } else {
      // 尝试嗑药
      if (pillsLeft == 0) return false;
      it = ws.lower_bound(t - strength);
      if (it == ws.end()) return false;
      ws.erase(it);
      --pillsLeft;
    }
  }
  return true;
}

int maxTaskAssignImpl(std::vector<int>& tasks, std::vector<int>& workers,
                      int pills, int strength) {
  std::sort(tasks.begin(), tasks.end());
  std::sort(workers.begin(), workers.end());

  int n = static_cast<int>(tasks.size());
  int m = static_cast<int>(workers.size());
  int lo = 0;
  int hi = std::min(n, m);
  int ans = 0;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (canAssign(mid, tasks, workers, pills, strength)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return ans;
}

}  // namespace

MaximumNumberOfTasksYouCanAssignSolution::
    MaximumNumberOfTasksYouCanAssignSolution() {
  setMetaInfo({2071, "Maximum Number of Tasks You Can Assign",
               "https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/"});
  registerStrategy(
      {"binary_search_greedy", "Accepted",
       "O((n+m) log(min(n,m)) log m)", "O(m)",
       {"Binary Search", "Greedy", "Sorting"}, ""},
      maxTaskAssignImpl);
}

int MaximumNumberOfTasksYouCanAssignSolution::maxTaskAssign(
    std::vector<int>& tasks, std::vector<int>& workers, int pills,
    int strength) {
  return getSolution()(tasks, workers, pills, strength);
}

}  // namespace problem_2071
}  // namespace leetcode
