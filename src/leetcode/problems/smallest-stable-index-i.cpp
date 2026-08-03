#include "leetcode/problems/smallest-stable-index-i.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3903 {

namespace {

int firstStableIndexImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());

  // prefixMax[i] = max(nums[0..i])
  std::vector<int> prefixMax(n);
  prefixMax[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    prefixMax[i] = std::max(prefixMax[i - 1], nums[i]);
  }

  // suffixMin[i] = min(nums[i..n-1])
  std::vector<int> suffixMin(n);
  suffixMin[n - 1] = nums[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suffixMin[i] = std::min(suffixMin[i + 1], nums[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (prefixMax[i] - suffixMin[i] <= k) {
      return i;
    }
  }

  return -1;
}

}  // namespace

SmallestStableIndexISolution::SmallestStableIndexISolution() {
  setMetaInfo({.id = 3903,
               .title = "Smallest Stable Index I",
               .url = "https://leetcode.com/problems/smallest-stable-index-i/"});

  registerStrategy(
      {.name = "Prefix and Suffix Arrays",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Prefix Sum"}},
      firstStableIndexImpl);

  setDefaultStrategy();
}

int SmallestStableIndexISolution::firstStableIndex(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3903
}  // namespace leetcode
