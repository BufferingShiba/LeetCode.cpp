#include <algorithm>
#include <cstdlib>

#include "leetcode/problems/minimum-cost-to-make-arrays-identical.h"

namespace leetcode {
namespace problem_3424 {

namespace {

long long minCostImpl(std::vector<int>& arr, std::vector<int>& brr, long long k) {
  const int n = static_cast<int>(arr.size());

  // Cost when we do NOT use the split operation: align by original order.
  long long cost_no_split = 0;
  for (int i = 0; i < n; ++i) {
    cost_no_split += std::llabs(static_cast<long long>(arr[i]) - brr[i]);
  }

  // If we use the split operation (cost k), we can rearrange arr arbitrarily.
  // The optimal pairing after rearrangement is to sort both arrays and pair
  // by position (rearrangement inequality / exchange argument).
  std::vector<int> a(arr);
  std::vector<int> b(brr);
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  long long cost_split = k;
  for (int i = 0; i < n; ++i) {
    cost_split += std::llabs(static_cast<long long>(a[i]) - b[i]);
  }

  return std::min(cost_no_split, cost_split);
}

}  // namespace

MinimumCostToMakeArraysIdenticalSolution::MinimumCostToMakeArraysIdenticalSolution() {
  setMetaInfo({.id = 3424,
               .title = "Minimum Cost to Make Arrays Identical",
               .url = "https://leetcode.com/problems/minimum-cost-to-make-arrays-identical/"});
  registerStrategy(
      {"sort-and-greedy", "Accepted", "O(n log n)", "O(n)",
       {"Array", "Greedy", "Sorting"}},
      [](std::vector<int>& arr, std::vector<int>& brr, long long k) {
        return minCostImpl(arr, brr, k);
      });
}

long long MinimumCostToMakeArraysIdenticalSolution::minCost(
    std::vector<int>& arr, std::vector<int>& brr, long long k) {
  return getSolution()(arr, brr, k);
}

}  // namespace problem_3424
}  // namespace leetcode
