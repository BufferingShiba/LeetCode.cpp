#include "leetcode/problems/maximum-tastiness-of-candy-basket.h"

#include <algorithm>

namespace leetcode {
namespace problem_2517 {

static bool canPick(const std::vector<int>& sorted, int k, int d) {
  int count = 1;
  int last = sorted[0];
  const int n = static_cast<int>(sorted.size());
  for (int i = 1; i < n; ++i) {
    if (sorted[i] - last >= d) {
      ++count;
      last = sorted[i];
      if (count >= k) return true;
    }
  }
  return count >= k;
}

// Binary search on the minimum absolute difference d.
// For a candidate d, greedily pick k candies each at least d apart
// (feasible iff count >= k); find the largest feasible d.
static int solution1(vector<int>& price, int k) {
  std::sort(price.begin(), price.end());
  int lo = 0;
  int hi = price.back() - price.front();
  int ans = 0;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (canPick(price, k, mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}

MaximumTastinessOfCandyBasketSolution::MaximumTastinessOfCandyBasketSolution() {
  setMetaInfo({
      .id = 2517,
      .title = "Maximum Tastiness of Candy Basket",
      .url = "https://leetcode.com/problems/maximum-tastiness-of-candy-basket"
  });
  registerStrategy({.name = "Binary Search + Greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n + n log M)",
                    .space_complexity = "O(log n)",
                    .tags = {"Array", "Binary Search", "Sorting", "Greedy"}},
                   solution1);
}

int MaximumTastinessOfCandyBasketSolution::maximumTastiness(vector<int>& price, int k) {
  return getSolution()(price, k);
}

}  // namespace problem_2517
}  // namespace leetcode
