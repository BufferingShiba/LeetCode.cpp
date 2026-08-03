#include "leetcode/problems/partition-array-such-that-maximum-difference-is-k.h"

#include <algorithm>

namespace leetcode {
namespace problem_2294 {

namespace {

int partitionArrayImpl(std::vector<int>& nums, int k) {
  if (nums.empty()) {
    return 0;
  }
  std::sort(nums.begin(), nums.end());
  int groups = 1;
  int groupMin = nums[0];
  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] - groupMin > k) {
      ++groups;
      groupMin = nums[i];
    }
  }
  return groups;
}

}  // namespace

PartitionArraySuchThatMaximumDifferenceIsKSolution::
    PartitionArraySuchThatMaximumDifferenceIsKSolution() {
  setMetaInfo({.id = 2294,
               .title = "Partition Array Such That Maximum Difference Is K",
               .url = "https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/"});
  registerStrategy({.name = "GreedyAfterSort",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Array", "Greedy", "Sorting"}},
                   partitionArrayImpl);
}

int PartitionArraySuchThatMaximumDifferenceIsKSolution::partitionArray(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2294
}  // namespace leetcode
