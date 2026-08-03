#include "leetcode/problems/find-the-distinct-difference-array.h"

#include <unordered_set>

namespace leetcode {
namespace problem_2670 {
namespace {

std::vector<int> distinctDifferenceArrayImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());

  // suffixDistinct[i] = number of distinct elements in nums[i..n-1]
  std::vector<int> suffixDistinct(n, 0);
  std::unordered_set<int> seen;
  for (int i = n - 1; i >= 0; --i) {
    seen.insert(nums[i]);
    suffixDistinct[i] = static_cast<int>(seen.size());
  }

  std::vector<int> diff(n, 0);
  seen.clear();
  for (int i = 0; i < n; ++i) {
    seen.insert(nums[i]);
    int suffix = (i + 1 < n) ? suffixDistinct[i + 1] : 0;
    diff[i] = static_cast<int>(seen.size()) - suffix;
  }
  return diff;
}

}  // namespace

FindTheDistinctDifferenceArraySolution::FindTheDistinctDifferenceArraySolution() {
  setMetaInfo({.id = 2670,
               .title = "Find the Distinct Difference Array",
               .url = "https://leetcode.com/problems/find-the-distinct-difference-array/"});
  registerStrategy({.name = "prefix-suffix-distinct",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   distinctDifferenceArrayImpl);
}

std::vector<int> FindTheDistinctDifferenceArraySolution::distinctDifferenceArray(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2670
}  // namespace leetcode
