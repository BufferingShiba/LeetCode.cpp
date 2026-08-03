#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

#include "leetcode/problems/find-subsequence-of-length-k-with-the-largest-sum.h"

namespace leetcode {
namespace problem_2099 {

static std::vector<int> maxSubsequenceImpl(std::vector<int>& nums, int k) {
  std::vector<int> idx(nums.size());
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [&](int a, int b) {
    return nums[a] > nums[b];
  });
  std::vector<int> top(idx.begin(), idx.begin() + k);
  std::sort(top.begin(), top.end());
  std::vector<int> result;
  result.reserve(k);
  for (int i : top) {
    result.push_back(nums[i]);
  }
  return result;
}

FindSubsequenceOfLengthKWithTheLargestSumSolution::FindSubsequenceOfLengthKWithTheLargestSumSolution() {
  setMetaInfo({.id = 2099,
               .title = "Find Subsequence of Length K With the Largest Sum",
               .url = "https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/"});
  registerStrategy(
      {.name = "SortIndices",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sorting"}},
      maxSubsequenceImpl);
}

std::vector<int> FindSubsequenceOfLengthKWithTheLargestSumSolution::maxSubsequence(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2099
}  // namespace leetcode
