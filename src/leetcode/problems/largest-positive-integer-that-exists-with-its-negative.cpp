#include "leetcode/problems/largest-positive-integer-that-exists-with-its-negative.h"

#include <algorithm>
#include <unordered_set>

namespace leetcode {
namespace problem_2441 {

static int findMaxKImpl(std::vector<int>& nums) {
  std::unordered_set<int> seen(nums.begin(), nums.end());
  int maxK = -1;
  for (int x : nums) {
    if (x > 0 && seen.count(-x)) {
      maxK = std::max(maxK, x);
    }
  }
  return maxK;
}

LargestPositiveIntegerThatExistsWithItsNegativeSolution::
    LargestPositiveIntegerThatExistsWithItsNegativeSolution() {
  setMetaInfo(
      {.id = 2441,
       .title = "Largest Positive Integer That Exists With Its Negative",
       .url =
           "https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/"});
  registerStrategy(
      {.name = "hashset",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      findMaxKImpl);
  setDefaultStrategy();
}

int LargestPositiveIntegerThatExistsWithItsNegativeSolution::findMaxK(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2441
}  // namespace leetcode
