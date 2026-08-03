#include "leetcode/problems/stable-subarrays-with-equal-boundary-and-interior-sum.h"

#include <map>

namespace leetcode {
namespace problem_3728 {

static long long solution1(vector<int>& capacity) {
  const int n = static_cast<int>(capacity.size());
  if (n < 3) return 0LL;

  // Prefix sums: P[i] = sum of capacity[0..i-1]
  vector<long long> P(n + 1, 0LL);
  for (int i = 0; i < n; ++i) P[i + 1] = P[i] + capacity[i];

  long long ans = 0;
  // For a subarray [l..r] (l <= r-2), the condition is:
  //   capacity[l] == capacity[r] and interior_sum == capacity[l]
  // interior_sum = P[r] - P[l+1], and capacity[l] == capacity[r], so:
  //   P[r] - P[l+1] == capacity[r]  ==>  P[l] == P[r] - 2*capacity[r]
  // While scanning r from left to right, the map holds left endpoints l in
  // [0, r-2] keyed by (capacity[l], P[l]); count matches for key
  // (capacity[r], P[r] - 2*capacity[r]).
  std::map<std::pair<long long, long long>, int> seen;
  for (int r = 0; r < n; ++r) {
    if (r >= 2) {
      int l = r - 2;
      ++seen[{static_cast<long long>(capacity[l]), P[l]}];
    }
    auto it = seen.find({static_cast<long long>(capacity[r]), P[r] - 2LL * capacity[r]});
    if (it != seen.end()) ans += it->second;
  }
  return ans;
}

StableSubarraysWithEqualBoundaryAndInteriorSumSolution::StableSubarraysWithEqualBoundaryAndInteriorSumSolution() {
  setMetaInfo({
      .id = 3728,
      .title = "Stable Subarrays With Equal Boundary and Interior Sum",
      .url = "https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum"
  });
  registerStrategy(
      {.name = "Prefix Sum + Counting",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Prefix Sum"}},
      solution1);
}

long long StableSubarraysWithEqualBoundaryAndInteriorSumSolution::countStableSubarrays(vector<int>& capacity) {
  return getSolution()(capacity);
}

}  // namespace problem_3728
}  // namespace leetcode
