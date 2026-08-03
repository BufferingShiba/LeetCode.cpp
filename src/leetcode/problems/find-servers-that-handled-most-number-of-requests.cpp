#include "leetcode/problems/find-servers-that-handled-most-number-of-requests.h"

#include <queue>
#include <set>
#include <vector>

namespace leetcode {
namespace problem_1606 {

static std::vector<int> busiestServersImpl(int k, std::vector<int>& arrival,
                                            std::vector<int>& load) {
  std::set<int> available;
  for (int i = 0; i < k; ++i) {
    available.insert(i);
  }

  // min-heap: (finish_time, server_id)
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<>>
      busy;

  std::vector<int> count(k, 0);
  int n = static_cast<int>(arrival.size());

  for (int i = 0; i < n; ++i) {
    long long at = arrival[i];

    // Free servers that have completed their tasks
    while (!busy.empty() && busy.top().first <= at) {
      available.insert(busy.top().second);
      busy.pop();
    }

    if (available.empty()) {
      continue;  // drop the request
    }

    // Find the first available server starting from i % k
    int target = i % k;
    auto it = available.lower_bound(target);
    if (it == available.end()) {
      it = available.begin();  // wrap around
    }

    int server = *it;
    available.erase(it);
    count[server]++;
    busy.push({at + load[i], server});
  }

  int max_cnt = 0;
  for (int c : count) {
    if (c > max_cnt) max_cnt = c;
  }

  std::vector<int> result;
  for (int i = 0; i < k; ++i) {
    if (count[i] == max_cnt) {
      result.push_back(i);
    }
  }

  return result;
}

FindServersThatHandledMostNumberOfRequestsSolution::
    FindServersThatHandledMostNumberOfRequestsSolution() {
  setMetaInfo(
      {.id = 1606,
       .title = "Find Servers That Handled Most Number of Requests",
       .url =
           "https://leetcode.com/problems/find-servers-that-handled-most-"
           "number-of-requests/"});
  registerStrategy(
      {.name = "Ordered Set + Min Heap",
       .expected = "Accepted",
       .time_complexity = "O(n log k)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Heap (Priority Queue)", "Simulation", "Ordered Set"}},
      busiestServersImpl);
}

std::vector<int> FindServersThatHandledMostNumberOfRequestsSolution::busiestServers(
    int k, std::vector<int>& arrival, std::vector<int>& load) {
  return getSolution()(k, arrival, load);
}

}  // namespace problem_1606
}  // namespace leetcode
