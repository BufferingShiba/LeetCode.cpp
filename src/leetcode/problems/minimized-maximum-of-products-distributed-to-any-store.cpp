#include "leetcode/problems/minimized-maximum-of-products-distributed-to-any-store.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2064 {

namespace {

bool canDistribute(int x, int n, const std::vector<int>& quantities) {
  long long stores = 0;
  for (int q : quantities) {
    stores += (q + x - 1) / x;
    if (stores > n) return false;
  }
  return stores <= n;
}

int minimizedMaximumImpl(int n, std::vector<int>& quantities) {
  int lo = 1;
  int hi = *std::max_element(quantities.begin(), quantities.end());
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (canDistribute(mid, n, quantities)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

}  // namespace

MinimizedMaximumOfProductsDistributedToAnyStoreSolution::
    MinimizedMaximumOfProductsDistributedToAnyStoreSolution() {
  setMetaInfo({.id = 2064,
               .title = "Minimized Maximum of Products Distributed to Any Store",
               .url = "https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/"});
  registerStrategy(
      {.name = "Binary Search",
       .expected = "Accepted",
       .time_complexity = "O(m * log(max(quantities)))",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search", "Greedy"}},
      minimizedMaximumImpl);
}

int MinimizedMaximumOfProductsDistributedToAnyStoreSolution::minimizedMaximum(
    int n, std::vector<int>& quantities) {
  return getSolution()(n, quantities);
}

}  // namespace problem_2064
}  // namespace leetcode
