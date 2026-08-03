#include "leetcode/problems/finish-time-of-tasks-i.h"

#include <climits>
#include <algorithm>

namespace leetcode {
namespace problem_3965 {

static long solution1(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
  // Build tree rooted at 0.
  vector<vector<int>> children(n);
  for (auto& e : edges) {
    children[e[0]].push_back(e[1]);
  }

  // BFS to obtain a processing order guaranteeing a node comes before its children.
  vector<int> order;
  order.reserve(n);
  order.push_back(0);
  for (int i = 0; i < (int)order.size(); ++i) {
    for (int c : children[order[i]]) order.push_back(c);
  }

  // Process bottom-up: children before parents.
  vector<long long> finish(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    int node = order[i];
    if (children[node].empty()) {
      finish[node] = baseTime[node];
    } else {
      long long latest = LLONG_MIN;
      long long earliest = LLONG_MAX;
      for (int c : children[node]) {
        latest = std::max(latest, finish[c]);
        earliest = std::min(earliest, finish[c]);
      }
      long long ownDuration = (latest - earliest) + baseTime[node];
      finish[node] = latest + ownDuration;
    }
  }
  return finish[0];
}

FinishTimeOfTasksISolution::FinishTimeOfTasksISolution() {
  setMetaInfo({
      .id = 3965,
      .title = "Finish Time of Tasks I",
      .url = "https://leetcode.com/problems/finish-time-of-tasks-i"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

long FinishTimeOfTasksISolution::finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
  return getSolution()(n, edges, baseTime);
}

}  // namespace problem_3965
}  // namespace leetcode
