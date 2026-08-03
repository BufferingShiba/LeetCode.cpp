#include "leetcode/problems/transform-array-by-parity.h"

namespace leetcode::problem_3467 {

static std::vector<int> transformArrayImpl(std::vector<int>& nums) {
  int evenCount = 0;
  for (int num : nums) {
    if (num % 2 == 0) {
      ++evenCount;
    }
  }

  std::vector<int> result(nums.size(), 1);
  for (int i = 0; i < evenCount; ++i) {
    result[i] = 0;
  }
  return result;
}

TransformArrayByParitySolution::TransformArrayByParitySolution() {
  setMetaInfo({.id = 3467,
               .title = "Transform Array by Parity",
               .url = "https://leetcode.com/problems/transform-array-by-parity/"});
  registerStrategy(
      {.name = "Counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Counting"}},
      transformArrayImpl);
}

std::vector<int> TransformArrayByParitySolution::transformArray(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3467
