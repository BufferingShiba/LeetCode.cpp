#include "leetcode/problems/find-target-indices-after-sorting-array.h"

namespace leetcode {
namespace problem_2089 {

static std::vector<int> targetIndicesImpl(std::vector<int>& nums, int target) {
  int less = 0, equal = 0;
  for (int x : nums) {
    if (x < target) {
      ++less;
    } else if (x == target) {
      ++equal;
    }
  }
  std::vector<int> result;
  result.reserve(equal);
  for (int i = 0; i < equal; ++i) {
    result.push_back(less + i);
  }
  return result;
}

FindTargetIndicesAfterSortingArraySolution::FindTargetIndicesAfterSortingArraySolution() {
  setMetaInfo({.id = 2089,
               .title = "Find Target Indices After Sorting Array",
               .url = "https://leetcode.com/problems/find-target-indices-after-sorting-array/"});
  registerStrategy({.name = "Counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Sorting", "Counting"}},
                   targetIndicesImpl);
}

std::vector<int> FindTargetIndicesAfterSortingArraySolution::targetIndices(
    std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_2089
}  // namespace leetcode
