#include "leetcode/problems/minimum-moves-to-balance-circular-array.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3776 {

namespace {

long long minMovesImpl(std::vector<int>& balance) {
  const int n = static_cast<int>(balance.size());

  // Compute total sum; if negative, impossible.
  long long total = 0;
  int neg_idx = -1;
  for (int i = 0; i < n; ++i) {
    total += balance[i];
    if (balance[i] < 0) {
      neg_idx = i;
    }
  }

  if (total < 0) {
    return -1;
  }

  // No negative position → already balanced.
  if (neg_idx == -1) {
    return 0;
  }

  long long need = -static_cast<long long>(balance[neg_idx]);

  // Maximum possible circular distance is n / 2 (floor).
  const int max_dist = n / 2;
  // buckets[d] = total positive balance at distance d from the negative index.
  std::vector<long long> buckets(max_dist + 1, 0);

  for (int i = 0; i < n; ++i) {
    if (i == neg_idx) continue;
    if (balance[i] <= 0) continue;  // non-positive positions don't help

    int cw = (neg_idx - i + n) % n;   // clockwise distance
    int ccw = (i - neg_idx + n) % n;  // counter-clockwise distance
    int d = std::min(cw, ccw);

    buckets[d] += balance[i];
  }

  long long ans = 0;
  for (int d = 1; d <= max_dist && need > 0; ++d) {
    if (buckets[d] == 0) continue;
    long long take = std::min(need, buckets[d]);
    ans += take * d;
    need -= take;
  }

  // need should be 0 here because total >= 0 guarantees enough supply.
  return ans;
}

}  // namespace

MinimumMovesToBalanceCircularArraySolution::MinimumMovesToBalanceCircularArraySolution() {
  setMetaInfo({.id = 3776,
               .title = "Minimum Moves to Balance Circular Array",
               .url = "https://leetcode.com/problems/minimum-moves-to-balance-circular-array/"});

  registerStrategy(
      {.name = "greedy_bucket",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Sorting"}},
      minMovesImpl);
}

long long MinimumMovesToBalanceCircularArraySolution::minMoves(std::vector<int>& balance) {
  return getSolution()(balance);
}

}  // namespace problem_3776
}  // namespace leetcode
