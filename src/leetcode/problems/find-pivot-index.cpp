#include "leetcode/problems/find-pivot-index.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_724 {
namespace {

int pivotIndexImpl(std::vector<int>& nums) {
  int total = std::accumulate(nums.begin(), nums.end(), 0);
  int leftSum = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (leftSum == total - leftSum - nums[i]) {
      return i;
    }
    leftSum += nums[i];
  }
  return -1;
}

}  // namespace

FindPivotIndexSolution::FindPivotIndexSolution() {
  setMetaInfo({.id = 724,
               .title = "Find Pivot Index",
               .url = "https://leetcode.com/problems/find-pivot-index/"});
  registerStrategy({.name = "PrefixSum",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Prefix Sum"}},
                   pivotIndexImpl);
}

int FindPivotIndexSolution::pivotIndex(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_724
}  // namespace leetcode
