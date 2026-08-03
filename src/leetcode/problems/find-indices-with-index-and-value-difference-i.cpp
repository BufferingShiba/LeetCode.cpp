#include "leetcode/problems/find-indices-with-index-and-value-difference-i.h"

#include <cstdlib>
#include <vector>

namespace leetcode {
namespace problem_2903 {

namespace {

std::vector<int> findIndicesBruteForce(std::vector<int>& nums,
                                       int indexDifference,
                                       int valueDifference) {
  int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (std::abs(i - j) >= indexDifference &&
          std::abs(nums[i] - nums[j]) >= valueDifference) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

}  // namespace

FindIndicesWithIndexAndValueDifferenceISolution::
    FindIndicesWithIndexAndValueDifferenceISolution() {
  setMetaInfo({.id = 2903,
               .title = "Find Indices With Index and Value Difference I",
               .url = "https://leetcode.com/problems/"
                      "find-indices-with-index-and-value-difference-i/"});

  registerStrategy(
      {.name = "BruteForce",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers"}},
      findIndicesBruteForce);
}

std::vector<int> FindIndicesWithIndexAndValueDifferenceISolution::findIndices(
    std::vector<int>& nums, int indexDifference, int valueDifference) {
  return getSolution()(nums, indexDifference, valueDifference);
}

}  // namespace problem_2903
}  // namespace leetcode
