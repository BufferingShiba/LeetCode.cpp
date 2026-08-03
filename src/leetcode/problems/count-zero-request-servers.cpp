#include "leetcode/problems/count-zero-request-servers.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2747 {

namespace {

std::vector<int> countServersImpl(int n, std::vector<std::vector<int>>& logs, int x,
                                  std::vector<int>& queries) {
  int m = static_cast<int>(logs.size());
  int q = static_cast<int>(queries.size());

  // Sort logs by request time.
  std::sort(logs.begin(), logs.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[1] < b[1];
            });

  // Index-sort queries ascending.
  std::vector<std::pair<int, int>> idx(q);
  for (int i = 0; i < q; ++i) idx[i] = {queries[i], i};
  std::sort(idx.begin(), idx.end());

  std::vector<int> freq(n + 1, 0);
  int active = 0;  // distinct servers currently inside the window
  int left = 0;    // left pointer over sorted logs
  int right = 0;   // right pointer over sorted logs
  std::vector<int> ans(q);

  for (int i = 0; i < q; ++i) {
    int query = idx[i].first;
    int lo = query - x;  // inclusive lower bound
    int hi = query;      // inclusive upper bound

    // Extend right: add logs with time <= hi.
    while (right < m && logs[right][1] <= hi) {
      int server = logs[right][0];
      if (freq[server] == 0) ++active;
      ++freq[server];
      ++right;
    }

    // Shrink left: remove logs with time < lo.
    while (left < right && logs[left][1] < lo) {
      int server = logs[left][0];
      --freq[server];
      if (freq[server] == 0) --active;
      ++left;
    }

    ans[idx[i].second] = n - active;
  }

  return ans;
}

}  // namespace

CountZeroRequestServersSolution::CountZeroRequestServersSolution() {
  setMetaInfo({.id = 2747,
               .title = "Count Zero Request Servers",
               .url = "https://leetcode.com/problems/count-zero-request-servers/"});
  registerStrategy(
      {.name = "sliding-window",
       .expected = "Accepted",
       .time_complexity = "O((m + q) log m)",
       .space_complexity = "O(m + q)",
       .tags = {"Array", "Hash Table", "Sliding Window", "Sorting"}},
      countServersImpl);
}

std::vector<int> CountZeroRequestServersSolution::countServers(
    int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries) {
  return getSolution()(n, logs, x, queries);
}

}  // namespace problem_2747
}  // namespace leetcode
