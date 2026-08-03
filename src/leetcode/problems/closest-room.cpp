#include "leetcode/problems/closest-room.h"

#include <algorithm>
#include <set>
#include <utility>

namespace leetcode::problem_1847 {

namespace {

std::vector<int> closestRoomSortedSet(std::vector<std::vector<int>>& rooms,
                                      std::vector<std::vector<int>>& queries) {
  const int n = static_cast<int>(rooms.size());
  const int k = static_cast<int>(queries.size());

  // Sort rooms by size descending.
  std::sort(rooms.begin(), rooms.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[1] > b[1];
            });

  // Build query indices ordered by minSize descending.
  std::vector<int> qorder(k);
  for (int i = 0; i < k; ++i) qorder[i] = i;
  std::sort(qorder.begin(), qorder.end(),
            [&](int i, int j) { return queries[i][1] > queries[j][1]; });

  std::vector<int> ans(k, -1);
  std::set<int> available;  // sorted room ids meeting size requirement
  int ridx = 0;

  for (int q : qorder) {
    int preferred = queries[q][0];
    int minSize = queries[q][1];

    // Add rooms whose size >= minSize.
    while (ridx < n && rooms[ridx][1] >= minSize) {
      available.insert(rooms[ridx][0]);
      ++ridx;
    }

    if (available.empty()) {
      ans[q] = -1;
      continue;
    }

    auto it = available.lower_bound(preferred);
    int best = -1;
    int bestDiff = INT_MAX;

    if (it != available.end()) {
      int cand = *it;
      int d = std::abs(cand - preferred);
      if (d < bestDiff) {
        bestDiff = d;
        best = cand;
      }
    }
    if (it != available.begin()) {
      int cand = *std::prev(it);
      int d = std::abs(cand - preferred);
      if (d < bestDiff || (d == bestDiff && cand < best)) {
        bestDiff = d;
        best = cand;
      }
    }

    ans[q] = best;
  }

  return ans;
}

}  // namespace

ClosestRoomSolution::ClosestRoomSolution() {
  setMetaInfo({.id = 1847,
               .title = "Closest Room",
               .url = "https://leetcode.com/problems/closest-room/"});
  registerStrategy(
      {.name = "sorted-set",
       .expected = "Accepted",
       .time_complexity = "O((n + k) log n)",
       .space_complexity = "O(n + k)",
       .tags = {"Sorting", "Ordered Set", "Binary Search"},
       .notes =
           "Process queries by minSize descending; insert rooms satisfying size "
           "into a std::set; use lower_bound on preferred to find closest id."},
      closestRoomSortedSet);
}

std::vector<int> ClosestRoomSolution::closestRoom(
    std::vector<std::vector<int>>& rooms,
    std::vector<std::vector<int>>& queries) {
  return getSolution()(rooms, queries);
}

}  // namespace leetcode::problem_1847
