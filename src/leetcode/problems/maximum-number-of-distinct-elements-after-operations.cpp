#include "leetcode/problems/maximum-number-of-distinct-elements-after-operations.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode::problem_3397 {

namespace {

int maxDistinctElementsImpl(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  long long last = LLONG_MIN;
  int count = 0;
  for (int num : nums) {
    long long low = static_cast<long long>(num) - k;
    long long high = static_cast<long long>(num) + k;
    long long candidate = std::max(low, last + 1);
    if (candidate <= high) {
      last = candidate;
      ++count;
    }
  }
  return count;
}

}  // namespace

MaximumNumberOfDistinctElementsAfterOperationsSolution::
    MaximumNumberOfDistinctElementsAfterOperationsSolution() {
  setMetaInfo({.id = 3397,
               .title = "Maximum Number of Distinct Elements After Operations",
               .url = "https://leetcode.com/problems/maximum-number-of-"
                      "distinct-elements-after-operations/"});
  registerStrategy(
      {"GreedySorting",
       "Accepted",
       "O(n log n)",
       "O(log n) (from sort, ignoring input)",
       {"Array", "Greedy", "Sorting"},
       "Sort then greedily assign each element the smallest available value in "
       "[num-k, num+k]."},
      maxDistinctElementsImpl);
}

int MaximumNumberOfDistinctElementsAfterOperationsSolution::maxDistinctElements(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3397
