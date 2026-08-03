#include "leetcode/problems/longest-subsequence-with-limited-sum.h"

#include <algorithm>

namespace leetcode {
namespace problem_2389 {
namespace {

// Sort + prefix sum + binary search (upper_bound).
static std::vector<int> answerQueriesImpl(std::vector<int>& nums,
                                          std::vector<int>& queries) {
  std::sort(nums.begin(), nums.end());

  std::vector<int> prefix(nums.size());
  prefix[0] = nums[0];
  for (std::size_t i = 1; i < nums.size(); ++i) {
    prefix[i] = prefix[i - 1] + nums[i];
  }

  std::vector<int> result(queries.size());
  for (std::size_t i = 0; i < queries.size(); ++i) {
    // Number of prefix elements <= queries[i]
    result[i] = static_cast<int>(
        std::upper_bound(prefix.begin(), prefix.end(), queries[i]) -
        prefix.begin());
  }
  return result;
}

}  // namespace

LongestSubsequenceWithLimitedSumSolution::
    LongestSubsequenceWithLimitedSumSolution() {
  setMetaInfo({.id = 2389,
               .title = "Longest Subsequence With Limited Sum",
               .url = "https://leetcode.com/problems/longest-subsequence-with-limited-sum/"});
  registerStrategy(
      {.name = "SortPrefixSumBinarySearch",
       .expected = "Accepted",
       .time_complexity = "O(n log n + m log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Binary Search", "Greedy", "Sorting",
                "Prefix Sum"}},
      answerQueriesImpl);
}

std::vector<int> LongestSubsequenceWithLimitedSumSolution::answerQueries(
    std::vector<int>& nums, std::vector<int>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_2389
}  // namespace leetcode
