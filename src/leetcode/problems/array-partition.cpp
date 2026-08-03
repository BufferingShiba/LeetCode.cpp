#include "leetcode/problems/array-partition.h"

#include <algorithm>
#include <cstddef>

namespace leetcode {
namespace problem_561 {

namespace {

int arrayPairSumImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int sum = 0;
  for (std::size_t i = 0; i < nums.size(); i += 2) {
    sum += nums[i];
  }
  return sum;
}

}  // namespace

ArrayPartitionSolution::ArrayPartitionSolution() {
  setMetaInfo({.id = 561,
               .title = "Array Partition",
               .url = "https://leetcode.com/problems/array-partition/"});
  registerStrategy(
      {.name = "SortAndPair",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1) (O(log n) for sort stack)",
       .tags = {"Array", "Greedy", "Sorting"}},
      arrayPairSumImpl);
}

int ArrayPartitionSolution::arrayPairSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_561
}  // namespace leetcode
